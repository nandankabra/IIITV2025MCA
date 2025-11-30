// XOR gate using only NAND gates
module xor_using_nand (
    input a, b,   // inputs
    output y      // output
);

    wire n1, n2, n3;

    assign n1 = ~(a & b);      // N1 = A NAND B
    assign n2 = ~(a & n1);     // N2 = A NAND N1
    assign n3 = ~(b & n1);     // N3 = B NAND N1
    assign y = ~(n2 & n3);     // Y = N2 NAND N3

endmodule
