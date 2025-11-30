// OR gate implemented using only NOR gates (Behavioral Modeling)
module or_using_nor(a, b, y);
  input a, b;       // inputs
  output reg y;     // output

  // Behavioral block
  always @(a or b) begin
    // Step 1: na = ~(a | a) → NOT A
    // Step 2: nb = ~(b | b) → NOT B
    // Step 3: y  = ~(na | nb) → NOR of NOT A and NOT B = A OR B
    y = ~(~(a | a) | ~(b | b));
  end
endmodule
