// NOT gate implemented using only a NAND gate (Behavioral Modeling)
module not_using_nand(a, y);
  input a;          // input
  output reg y;     // output

  // Behavioral block
  always @(a) begin
    // NAND with both inputs tied together:
    // ~(a & a) = ~a
    y = ~(a & a);
  end
endmodule
