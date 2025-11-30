// NOT gate implemented using only a NOR gate (Behavioral Modeling)
module not_using_nor(a, y);
  input a;        // input
  output reg y;   // output

  // Behavioral block
  always @(a) begin
    // NOR with both inputs tied together:
    // ~(a | a) = ~a
    y = ~(a | a);
  end
endmodule
