`timescale 1ns/1ps
module and_gate_tb;
  reg a, b;
  wire c;

  // Instantiate the AND gate
  and_gate uut (c, a, b);

  initial begin
    $monitor("Time=%0t | a=%b b=%b | c=%b", $time, a, b, c);

    // Test cases
    a=0; b=0; #10;
    a=0; b=1; #10;
    a=1; b=0; #10;
    a=1; b=1; #10;

    $finish;
  end
endmodule
