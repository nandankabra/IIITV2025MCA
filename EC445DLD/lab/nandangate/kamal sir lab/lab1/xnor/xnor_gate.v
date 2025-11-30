// Behavioral model of 2-input XNOR gate
module xnor_gate(c, a, b);
  input a, b;
  output reg c;

  always @(a or b) begin
    c = ~(a ^ b);   // XNOR = NOT(XOR)
    // alternatively: c = a ~^ b;
  end
endmodule
