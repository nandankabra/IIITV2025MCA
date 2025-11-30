// Testbench for OR gate using NAND
module or_using_nand_tb;

  reg a, b;    // inputs
  wire y;      // output

  // Instantiate the DUT
  or_using_nand uut (.a(a), .b(b), .y(y));

  initial begin
    // Dump waveform
    $dumpfile("or_using_nand.vcd");
    $dumpvars(0, or_using_nand_tb);

    // Print truth table
    $display("A B | Y (OR)");
    $display("-------------");

    a = 0; b = 0; #10; $display("%b %b |   %b", a, b, y);
    a = 0; b = 1; #10; $display("%b %b |   %b", a, b, y);
    a = 1; b = 0; #10; $display("%b %b |   %b", a, b, y);
    a = 1; b = 1; #10; $display("%b %b |   %b", a, b, y);

    $finish;
  end

endmodule
