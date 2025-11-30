// Testbench for OR gate
module or_gate_tb;

  reg a, b;     
  wire y;       

  or_gate_d uut (.a(a), .b(b), .y(y));

  initial begin
    $dumpfile("or_gate.vcd");   
    $dumpvars(0, or_gate_tb);   

    $display("A B | Y");   // header
    $display("-----------");

    a = 0; b = 0; #10; $display("%b %b | %b", a, b, y);
    a = 0; b = 1; #10; $display("%b %b | %b", a, b, y);
    a = 1; b = 0; #10; $display("%b %b | %b", a, b, y);
    a = 1; b = 1; #10; $display("%b %b | %b", a, b, y);

    $finish;   
  end

endmodule