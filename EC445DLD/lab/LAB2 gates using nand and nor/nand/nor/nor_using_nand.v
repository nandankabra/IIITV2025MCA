module nor_using_nand(a, b, y);
  input a, b;
  output reg y;

  always @(a or b) begin
    y = ~(~(~(a & a) & ~(b & b)) & ~(~(a & a) & ~(b & b)));
  end
endmodule
