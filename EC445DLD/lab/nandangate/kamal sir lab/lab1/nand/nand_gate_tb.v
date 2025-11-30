// Testbench for NAND gate
module nand_gate_tb;

  reg a, b;     // inputs
  wire y;       // output

  // Instantiate the DUT (Design Under Test)
  nand_gate_d uut (.a(a), .b(b), .y(y));

  initial begin
    // Dumping waveform data
    $dumpfile("nand_gate.vcd");   // Name of the dump file
    $dumpvars(0, nand_gate_tb);   // Dump all signals in testbench

    // Print truth table header
    $display("A B | Y");
    $display("-----------");

    // Test cases
    a = 0; b = 0; #10; $display("%b %b | %b", a, b, y);
    a = 0; b = 1; #10; $display("%b %b | %b", a, b, y);
    a = 1; b = 0; #10; $display("%b %b | %b", a, b, y);
    a = 1; b = 1; #10; $display("%b %b | %b", a, b, y);

    $finish;   // End simulation
  end

endmodule
