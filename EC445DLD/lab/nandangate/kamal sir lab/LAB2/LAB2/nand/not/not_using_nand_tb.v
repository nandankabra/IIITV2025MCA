// Testbench for NOT gate using NAND
module not_using_nand_tb;

  reg a;       // input
  wire y;      // output

  // Instantiate the DUT
  not_using_nand uut (.a(a), .y(y));

  initial begin
    // Dump waveform
    $dumpfile("not_using_nand.vcd");
    $dumpvars(0, not_using_nand_tb);

    // Print truth table
    $display("A | Y (NOT)");
    $display("---------");

    a = 0; #10; $display("%b |   %b", a, y);
    a = 1; #10; $display("%b |   %b", a, y);

    $finish;
  end

endmodule
