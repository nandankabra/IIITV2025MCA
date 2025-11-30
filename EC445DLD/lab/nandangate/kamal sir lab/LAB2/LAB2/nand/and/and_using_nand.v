// AND gate implemented using only NAND gates
module and_using_nand (
    input a, b,     // inputs
    output y        // output
);

    wire nand_out;

    // First NAND gate
    assign nand_out = ~(a & b);

    // Second NAND gate (gives AND)
    assign y = ~(nand_out & nand_out);

endmodule
