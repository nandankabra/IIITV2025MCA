module ram (
    input [7:0] Data_in,
    input [9:0] Address_Line,
    input Write,
    input Chip_Select,
    output reg [7:0] Data_out
);

    // 1KB memory (1024 x 8 bits)
    reg [7:0] mem [1023:0];

    // Write operation
    always @(*) begin
        if (Chip_Select && Write)
            mem[Address_Line] = Data_in;
    end

    // Read operation
    always @(*) begin
        if (Chip_Select && !Write)
            Data_out = mem[Address_Line];
        else
            Data_out = 8'bz; // High impedance when not selected
    end

endmodule

`timescale 1ns / 1ps

module ram_tb;

    reg [7:0] Data_in;
    reg [9:0] Address_Line;
    reg Write;
    reg Chip_Select;
    wire [7:0] Data_out;

    // Instantiate the RAM module
    ram uut (
        .Data_in(Data_in),
        .Address_Line(Address_Line),
        .Write(Write),
        .Chip_Select(Chip_Select),
        .Data_out(Data_out)
    );

    initial begin

        $dumpfile("ram_tb.vcd");       // Name of waveform file
        $dumpvars(0, ram_tb);          // Dump all signals in this module
        
        // Initialize signals
        Data_in = 8'b0;
        Address_Line = 10'b0;
        Write = 0;
        Chip_Select = 0;

        // Start simulation
        $display("---- RAM Testbench Started ----");

        // 1️⃣ Write operation
        #10 Chip_Select = 1; Write = 1;
        Address_Line = 10'd5;
        Data_in = 8'hA5;
        #10 $display("Write: Addr=%d, Data=%h", Address_Line, Data_in);

        // 2️⃣ Read operation
        #10 Write = 0; // disable write for read
        #10 $display("Read: Addr=%d, Data_out=%h", Address_Line, Data_out);

        // 3️⃣ Another write and read
        #10 Write = 1; Address_Line = 10'd100; Data_in = 8'h3C;
        #10 $display("Write: Addr=%d, Data=%h", Address_Line, Data_in);
        #10 Write = 0;
        #10 $display("Read: Addr=%d, Data_out=%h", Address_Line, Data_out);

        // 4️⃣ Chip select disable test
        #10 Chip_Select = 0;
        Address_Line = 10'd5;
        #10 $display("Chip_Select OFF: Addr=%d, Data_out=%h", Address_Line, Data_out);

        // End simulation
        #10 $display("---- RAM Testbench Completed ----");
        #10 $finish;
    end

endmodule