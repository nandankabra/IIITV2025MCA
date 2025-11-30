`timescale 1ns/1ps

// =======================================================
// regbank_fixed.v
// Corrected 32x32 register file + self-checking testbench
// (portable: no $fatal so it works with older Icarus builds)
// =======================================================

// ------------------ regbank module ------------------
module regbank (
  input  wire        clock,
  input  wire        reset,
  input  wire        write,
  input  wire [4:0]  rs1, rs2, dr,
  input  wire [31:0] wrdata,
  output wire [31:0] rdata1, rdata2
);
  reg [31:0] regbank1 [0:31];
  integer i;
  assign rdata1 = regbank1[rs1];
  assign rdata2 = regbank1[rs2];

  always @(posedge clock) begin
    if (reset) begin // if your reset is 1 then your block will execute
      for (i = 0; i < 32; i = i + 1)
        regbank1[i] <= 32'b0;
    end else begin
      if (write) begin
        regbank1[dr] <= wrdata;
      end
    end
  end
endmodule // regbank


// ------------------ Self-checking testbench (portable) ------------------
module regbank_tb;
  reg [4:0]  rs1, rs2, dr;
  reg        clock, write, reset;
  reg [31:0] wrdata;
  wire [31:0] rdata1, rdata2;
  integer k;
  integer failures;

  // instantiate DUT
  regbank dut (
    .clock(clock),
    .reset(reset),
    .write(write),
    .rs1(rs1),
    .rs2(rs2),
    .dr(dr),
    .wrdata(wrdata),
    .rdata1(rdata1),
    .rdata2(rdata2)
  );

  // clock generation: period = 10 ns
  initial clock = 0;
  always #5 clock = ~clock;

  initial begin
    $display("\n=== regbank self-checking testbench (portable) ===");
    $dumpfile("regbank_fixed.vcd");
    $dumpvars(0, regbank_tb);

    // initialize
    failures = 0;
    write  = 0;
    dr     = 0;
    wrdata = 0;
    rs1    = 0;
    rs2    = 0;

    // synchronous reset: hold reset asserted for >1 clock edge
    reset = 1;
    #12;           // ensure at least one posedge while reset=1
    $display("Reset asserted at time=%0t (clock=%0b)", $time, clock);
    reset = 0;
    #2;
    $display("Reset deasserted at time=%0t\n", $time);

    // WRITE PHASE: write reg[k] = 10*k for k=0..31
    for (k = 0; k < 32; k = k + 1) begin
      @(negedge clock);
        dr     = k[4:0];
        wrdata = 32'd10 * k;
        write  = 1;
        //k[0] --> 10*0 == 00000000
        //k[1] --> 10*1 == 00000010
        //k[2] --> 10*2 == 00000020
        // and so on.....
        $display("Setup write at time=%0t: dr=%0d, wrdata=%0d, write=%0b", $time, dr, wrdata, write);
      @(posedge clock);
        #1;
        $display("After posedge at time=%0t: sampled write=%0b, dr=%0d", $time, write, dr);
        write = 0;
    end

    // allow writes to settle
    #10;

    // READ & VERIFY PHASE
    $display("\nVerifying all registers...");
    for (k = 0; k < 32; k = k + 1) begin
      rs1 = k;
      #1; // settle
      if (rdata1 !== (10 * k)) begin
        $display("ERROR: reg[%0d] = %0d, expected %0d at time %0t", k, rdata1, 10*k, $time);
        failures = failures + 1;
      end else begin
        $display("OK   reg[%0d] = %0d", k, rdata1);
      end
    end

    // Summary and exit
    if (failures == 0) begin
      $display("\nAll registers verified successfully. PASS.");
    end else begin
      $display("\nVerification finished with %0d failures. FAIL.", failures);
    end

    #10 $finish;
  end
endmodule // regbank_tb
