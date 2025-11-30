module booth_url(
    input signed[3:0] multiplicand,    
    input signed[3:0] multiplier,
    putput reg signed[7:0] product    

);

//Inital register 
reg signed[4:0] A; // Accumlator
reg signed[4:0] M_ext; //sign-extended multiplicand 
reg [3:0] Q_reg; //multiplier register 
reg Q_1;         // Q(-1)bit 
integer  i;
reg[9:0] concat; // temporay register for shift 

always @(*) begin
    //intialization
    A = 5'b0;
    M_ext = {multiplicand[3],multiplicand};//sign extend
    Q_reg = multiplier;
    Q_1 = 1'b0;

    //performa 4  interation 
    for(i=0;i<4;i=i+1){
        
    }
end