module nor_gate_b(a, b, y);
  input a, b;
  output reg y;

  always @(a or b) begin
    y = ~(a | b);
  end
endmodule
