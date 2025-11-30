// NOT gate using only NOR gate
module not_using_nor (
    input a,     // input
    output y     // output
);

    assign y = ~(a | a); // NOR with both inputs = NOT

endmodule
