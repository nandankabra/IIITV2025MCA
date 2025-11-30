`timescale 1ns/1ps
module xnor_gate_tb;
  reg a, b;
  wire c;

  // Instantiate XNOR gate
  xnor_gate uut (c, a, b);

  initial begin
    // For GTKWave waveform dump
    $dumpfile("xnor_wave.vcd");
    $dumpvars(0, xnor_gate_tb);

    $monitor("Time=%0t | a=%b b=%b | c=%b", $time, a, b, c);

    // Test all input combinations
    a=0; b=0; #10;
    a=0; b=1; #10;
    a=1; b=0; #10;
    a=1; b=1; #10;

    $finish;
  end
endmodule
