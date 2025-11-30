// NOT gate using only NAND gate
module not_using_nand (
    input a,      // input
    output y      // output
);

    assign y = ~(a & a); // NAND with both inputs = NOT

endmodule
