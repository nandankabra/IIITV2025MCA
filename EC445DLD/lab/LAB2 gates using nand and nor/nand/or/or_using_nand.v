// OR gate implemented using only NAND gates (Behavioral Modeling)
module or_using_nand(a, b, y);
  input a, b;       // inputs
  output reg y;     // output

  // Behavioral block
  always @(a or b) begin
    // Step 1: ~(a & a) = NOT A
    // Step 2: ~(b & b) = NOT B
    // Step 3: ~(NOT A & NOT B) = OR
    y = ~(~(a & a) & ~(b & b));
  end
endmodule
