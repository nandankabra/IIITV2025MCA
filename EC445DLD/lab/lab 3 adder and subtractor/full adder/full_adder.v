// Full Adder Module
module full_adder (
    input a, b, cin,    // inputs
    output sum, cout    // outputs
);
    assign sum  = a ^ b ^ cin;                       // XOR for sum
    assign cout = (a & b) | (b & cin) | (a & cin);   // Majority logic
endmodule
