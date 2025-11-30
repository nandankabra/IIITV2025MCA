// AND gate using only NOR gates
module and_using_nor (
    input a, b,   // inputs
    output y      // output
);

    wire na, nb;

    assign na = ~(a | a);      // NOT A using NOR
    assign nb = ~(b | b);      // NOT B using NOR
    assign y  = ~(na | nb);    // NOR(NA, NB) = A AND B

endmodule
