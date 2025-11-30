/**and gate **/
module and_gate_b(a,b,y);
input a, b;
output y;
always @(a,b)
y=a&b;
endmodule

/**test beanch **/
module and_gate_tb;
reg a,b;
wire y;
and_gate_s uut(a,b,y);
initial begin
    a=0;b=0;
    #10; $display("%b %b | %b", a, b, y); 
    a=1;b=0;
    #10; $display("%b %b | %b", a, b, y);
    a=0;b=1;
    #10; $display("%b %b | %b", a, b, y);
    a=1;b=1;
    #10; $display("%b %b | %b", a, b, y);
    $finish();
end
endmodule
/*********************/
/**or gate**/
module or_gate_b(a,b,y);
inout  a,b;
output y;
always @(a,b)
y = a|b;
endmodule
/**test beanch **/
module or_gate_tb;
reg a,b;
wire y;
or_gate_s uut(a,b,y);
initial begin
    a=0;b=0;
    #10; $display("%b %b | %b", a, b, y); 
    a=1;b=0;
    #10; $display("%b %b | %b", a, b, y);
    a=0;b=1;
    #10; $display("%b %b | %b", a, b, y);
    a=1;b=1;
    #10; $display("%b %b | %b", a, b, y);
    $finish();
end
endmodule
/*********************/
/**not gate**/
module not_gate_b(a,y);
input a;
output reg = y;
always @(a)  
y = ~a;
endmodule
/**test beanch **/
module not_gate_tb;
wire a;
reg y;
not_gate_s  uut(a,y);
initial begin
    a=0;
    #10; $display("%b %b | %b", a, b, y); 
    b=1;
    #10; $display("%b %b | %b", a, b, y); 
    $finish();
end
endmodule

/****************/
/**NAnd gate **/
module nand_gate_b(a,b,y);
input a,b;
output reg y ;
always @(a,b)
y = ~(a&b);
endmodule

/**tesh beanch**/
module nand_gate_tb;
reg a,b;
wire y;
nand_gate_s uut(a,b,y);
initial begin
    a=0;b=1; #10;$display("%b %b | %b", a, b, y); 
    a=0;b=0; #10;$display("%b %b | %b", a, b, y); 
    a=1;b=0; #10;$display("%b %b | %b", a, b, y); 
    a=1;b=1; #10;$display("%b %b | %b", a, b, y); 
    $finish();
end
endmodule
/*************/
/**nor gate **/
module nor_gate_b(a,b,y);
input a , b;
output reg y;
always @(a,b);
y= ~(a|b);
endmodule
/**tesh beanch**/
module nor_gate_tb;
reg a,b;
wire y;
nor_gate_s uut (a,b,y);
initial begin
    a=0;b=1; #10;$display("%b %b | %b", a, b, y); 
    a=0;b=0; #10;$display("%b %b | %b", a, b, y); 
    a=1;b=0; #10;$display("%b %b | %b", a, b, y); 
    a=1;b=1; #10;$display("%b %b | %b", a, b, y); 
    $finish();
end
endmodule

/************/
/**xnor gate**/
module xnor_gate_t(a,b,y);
input a,b;
output reg = y;



/**********************/
 
