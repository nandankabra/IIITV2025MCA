module nor_gate_d (
    input a,     
    input b,      // input b
    output y      // output y
);
    assign y = ~(a | b);   // NOR operation
endmodule
