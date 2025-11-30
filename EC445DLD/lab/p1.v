module p1 (a,b,y);
input a,b;
output reg y;
always @(a,b);
begin
    y = ~(~(a(a&b))&~(b(a&b)));
end

endmodule