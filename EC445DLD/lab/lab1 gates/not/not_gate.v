module not_gate_b(a, y);
  input a;
  output reg y;

  always @(a) begin
    y = ~a;
  end
endmodule
