// NOR gate using only NAND gates
module nor_using_nand (
    input a, b,   // inputs
    output y      // output
);

    wire na, nb, or_ab;

    assign na = ~(a & a);      // NOT A
    assign nb = ~(b & b);      // NOT B
    assign or_ab = ~(na & nb); // OR using NAND
    assign y = ~(or_ab & or_ab); // NOT(OR) = NOR

endmodule
