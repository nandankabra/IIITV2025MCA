// Half Adder Module
module half_adder (
    input a, b,        // inputs
    output sum, carry  // outputs
);
    assign sum   = a ^ b;  // XOR for SUM
    assign carry = a & b;  // AND for CARRY
endmodule
