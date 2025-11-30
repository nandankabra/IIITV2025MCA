// XOR gate using only NOR gates
module xor_using_nor (
    input a, b,    // inputs
    output y       // output
);

    wire n1, n2, n3;

    assign n1 = ~(a | b);   // N1 = A NOR B
    assign n2 = ~(a | n1);  // N2 = A NOR (A NOR B)
    assign n3 = ~(b | n1);  // N3 = B NOR (A NOR B)
    assign y  = ~(n2 | n3); // Final XOR

endmodule
