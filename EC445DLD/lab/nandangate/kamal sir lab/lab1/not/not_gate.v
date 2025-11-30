// NOT gate in Verilog
module not_gate (
    input a,        // input
    output y        // output
);
    assign y = ~a;  // NOT operation
endmodule
