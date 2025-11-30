// Testbench for Half Adder
module half_adder_tb;

  reg a, b;        // inputs
  wire sum, carry; // outputs

  // Instantiate the DUT (Design Under Test)
  half_adder uut (.a(a), .b(b), .sum(sum), .carry(carry));

  initial begin
    // Dump waveform data
    $dumpfile("half_adder.vcd");
    $dumpvars(0, half_adder_tb);

    // Print truth table header
    $display("A B | SUM CARRY");
    $display("----------------");

    // Test cases
    a = 0; b = 0; #10; $display("%b %b |  %b     %b", a, b, sum, carry);
    a = 0; b = 1; #10; $display("%b %b |  %b     %b", a, b, sum, carry);
    a = 1; b = 0; #10; $display("%b %b |  %b     %b", a, b, sum, carry);
    a = 1; b = 1; #10; $display("%b %b |  %b     %b", a, b, sum, carry);

    $finish;   // End simulation
  end

endmodule
