// Behavioral model of 2-input OR gate
module or_gate(c, a, b);
  input a, b;
  output reg c;

  always @(a or b) begin
    c = a | b;   // OR operation
  end
endmodule
