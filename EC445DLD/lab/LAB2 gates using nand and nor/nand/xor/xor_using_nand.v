// XOR gate implemented using only NAND gates (Behavioral Modeling)
module xor_using_nand(a, b, y);
  input a, b;       // inputs
  output reg y;     // output

  // Behavioral block
  always @(a or b) begin
    // Step 1: n1 = ~(a & b)         → NAND of inputs
    // Step 2: n2 = ~(a & n1)        → NAND of A and n1
    // Step 3: n3 = ~(b & n1)        → NAND of B and n1
    // Step 4: y  = ~(n2 & n3)       → NAND of n2 and n3 → XOR
    y = ~(~(a & ~(a & b)) & ~(b & ~(a & b)));
  end
endmodule
