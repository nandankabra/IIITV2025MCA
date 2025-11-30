// Testbench for NOT gate
module not_gate_tb;

  reg a;      // input
  wire y;     // output

  // Instantiate the DUT
  not_gate uut (.a(a), .y(y));

  initial begin
    // Dump waveform
    $dumpfile("not_gate.vcd");
    $dumpvars(0, not_gate_tb);

    // Print header
    $display("A | Y");
    $display("-----");

    // Test cases
    a = 0; #10; $display("%b | %b", a, y);
    a = 1; #10; $display("%b | %b", a, y);

    $finish;
  end

endmodule
