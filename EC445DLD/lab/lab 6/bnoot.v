module booth4_mul(
    input  signed [3:0] multiplicand, // M
    input  signed [3:0] multiplier,   // Q
    output reg signed [7:0] product   // 8-bit signed product
);
    // Internal registers
    reg signed [4:0] A;      // Accumulator (one extra bit for sign)
    reg signed [4:0] M_ext;  // Sign-extended multiplicand
    reg [3:0] Q_reg;         // Multiplier register
    reg Q_1;                 // Q(-1) bit
    integer i;
    reg [9:0] concat;        // Temporary register for shift

    always @(*) begin
        // Initialization
        A     = 5'b0;//  5 means  5 bit b means binary and intal value 00000
        M_ext = {multiplicand[3], multiplicand}; // sign extend
        Q_reg = multiplier;
        Q_1   = 1'b0;

        // Perform 4 iterations (since inputs are 4-bit)
        for (i = 0; i < 4; i = i + 1) begin
            // Booth encoding logic
            case ({Q_reg[0], Q_1})
                2'b01: A = A + M_ext;
                2'b10: A = A - M_ext;
                default: ; // no change
            endcase

            // Arithmetic right shift of {A, Q_reg, Q_1}
            concat = {A, Q_reg, Q_1};
            concat = {concat[9], concat[9:1]}; // preserve sign
            {A, Q_reg, Q_1} = concat;
        end

        // Combine to get final product
        product = {A[4:1], Q_reg};
    end
endmodule

`timescale 1ns/1ps
module tb_booth4;
    reg signed [3:0] M;
    reg signed [3:0] Q;
    wire signed [7:0] P;

    booth4_mul uut (.multiplicand(M), .multiplier(Q), .product(P));

    initial begin
        $display("Time\tM\tQ\tProduct (dec)\tProduct (bin)");
        $monitor("%0dns\t%d\t%d\t%d\t%b", $time, M, Q, P, P);

        M =  4'd3; Q =  4'd2; #10;  // 6
        M = -4'd3; Q =  4'd2; #10;  // -6
        M =  4'd7; Q = -4'd2; #10;  // -14
        M = -4'd4; Q = -4'd2; #10;  // 8
        M =  4'd5; Q =  4'd5; #10;  // 25
        M = -4'd8; Q =  4'd1; #10;  // -8

        $stop;
    end
endmodule