// OR gate using only NAND gates
module or_using_nand (
    input a, b,   // inputs
    output y      // output
);

    wire na, nb;

    assign na = ~(a & a); // NOT A using NAND
    assign nb = ~(b & b); // NOT B using NAND

    assign y = ~(na & nb); // NAND of inverted inputs = OR

endmodule
