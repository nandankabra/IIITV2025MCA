// XOR gate implemented using only NOR gates (Behavioral Modeling)
module xor_using_nor(a, b, y);
  input a, b;       // inputs
  output reg y;     // output

  // Behavioral block
  always @(a or b) begin
    // Step 1: n1 = ~(a | b)          → NOR of inputs
    // Step 2: n2 = ~(a | n1)         → NOR of A and n1
    // Step 3: n3 = ~(b | n1)         → NOR of B and n1
    // Step 4: y  = ~(n2 | n3)        → Final NOR = XOR
    y = ~(~(a | ~(a | b)) | ~(b | ~(a | b)));
  end
endmodule
