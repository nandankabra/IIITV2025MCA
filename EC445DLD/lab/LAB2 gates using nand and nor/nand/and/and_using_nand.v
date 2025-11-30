module and_using_nand(a, b, y);
  input a, b;
  output reg y;

  always @(a or b) begin
    y = ~(~(a & b) & ~(a & b));
  end
endmodule
