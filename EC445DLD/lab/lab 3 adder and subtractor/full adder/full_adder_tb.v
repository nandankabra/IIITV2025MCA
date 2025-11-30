// Testbench for Full Adder
module full_adder_tb;

  reg a, b, cin;       // inputs
  wire sum, cout;      // outputs

  // Instantiate the DUT (Design Under Test)
  full_adder uut (.a(a), .b(b), .cin(cin), .sum(sum), .cout(cout));

  initial begin
    // Dump waveform data
    $dumpfile("full_adder.vcd");
    $dumpvars(0, full_adder_tb);

    // Print truth table header
    $display("A B Cin | SUM Cout");
    $display("------------------");

    // Test cases (all 8 possibilities)
    a = 0; b = 0; cin = 0; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 0; b = 0; cin = 1; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 0; b = 1; cin = 0; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 0; b = 1; cin = 1; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 1; b = 0; cin = 0; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 1; b = 0; cin = 1; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 1; b = 1; cin = 0; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);
    a = 1; b = 1; cin = 1; #10; $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);

    $finish;   // End simulation
  end

endmodule
