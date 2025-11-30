// NAND gate module
module nand_gate_d (
    input a,      // input a
    input b,      // input b
    output y      // output y
);
    assign y = ~(a & b);   // NAND operation
endmodule
