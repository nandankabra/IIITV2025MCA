
module tb_and_gate_b;
  reg a, b;
  wire y;

  // Instantiate the AND gate
  and_gate_b uut (
    .a(a),
    .b(b),
    .y(y)
  );

  initial begin
    // Display header
    $display("A B | Y");
    $display("------");

    // Test all combinations
    a = 0; b = 0; #10 $display("%b %b | %b", a, b, y);
    a = 0; b = 1; #10 $display("%b %b | %b", a, b, y);
    a = 1; b = 0; #10 $display("%b %b | %b", a, b, y);
    a = 1; b = 1; #10 $display("%b %b | %b", a, b, y);

    $finish;
  end
endmodule
