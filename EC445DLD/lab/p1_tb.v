
module p1_tb;

  reg a, b;    
  wire y;     
 
  p1 uut (.a(a), .b(b), .y(y));

  initial begin 
    $dumpfile("xor_using_nand.vcd");
    $dumpvars(0, xor_using_nand_tb);
 
    $display("A B | Y (XOR)");
    $display("-------------");

    a = 0; b = 0; #10; $display("%b %b |   %b", a, b, y);
    a = 0; b = 1; #10; $display("%b %b |   %b", a, b, y);
    a = 1; b = 0; #10; $display("%b %b |   %b", a, b, y);
    a = 1; b = 1; #10; $display("%b %b |   %b", a, b, y);

    $finish;
  end

endmodule
