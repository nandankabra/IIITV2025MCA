// Behavioral model of 2-input AND gate
module and_gate(c, a, b);
  input a, b;
  output reg c;

  always @(a or b) begin
    c = a & b;   // behavioral assignment
  end
endmodule
