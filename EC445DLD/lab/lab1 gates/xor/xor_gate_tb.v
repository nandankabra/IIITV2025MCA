// Testbench for XOR gate
module xor_gate_tb;

  reg a, b;     // inputs
  wire y;       // output

  // Instantiate the DUT (Design Under Test)
  xor_gate_d uut (.a(a), .b(b), .y(y));

  initial begin
    // Dump waveform data
    $dumpfile("xor_gate.vcd");   // creates VCD file
    $dumpvars(0, xor_gate_tb);   // dump all signals

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
