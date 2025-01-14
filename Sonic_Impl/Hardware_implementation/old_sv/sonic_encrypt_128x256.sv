/////////////////////////////////////////////////////////////////////////////////
//
// Engineer: Santosh Ghosh, PhD
// 
// Create Date:    2:13:52 05/09/2023
// Design Name: 
// Module Name:    sonic_encrypt 
// Project Name:   low_latency_blockcipher 
//////////////////////////////////////////////////////////////////////////////////
module sonic_encrypt_128x256(clk, resetn, in, key, input_valid, out, output_valid);
input          clk    ;
input          resetn ;
input  [127:0] in     ; //128 bit data in
input  [255:0] key    ; //256 bit secret key; 
input          input_valid;

output         output_valid;
output [127:0] out     ; //128 bit data out 


logic [127:0] sr1;
logic [127:0] sr2;
logic [255:0] kr1;

logic  valid1;
logic  valid2;

logic [127:0] rout1, rout2, rout3, rout4, rout5, rout6, rout7, rout8, rout9, rout10;
logic [127:0] rout11, rout12, rout13, rout14, rout15, rout16, rout17, rout18, rout19, rout20;
logic [127:0] rout21;

logic [255:0] kout1, kout2, kout3, kout4, kout5, kout6, kout7, kout8, kout9, kout10;
logic [255:0] kout11, kout12, kout13, kout14, kout15, kout16, kout17, kout18, kout19, kout20;
logic [255:0] kout21;


assign output_valid = valid2;
assign out = sr2;

always_ff @(posedge clk) begin
if(~resetn) begin
 valid1 <= 1'b0 ;
 valid2 <= 1'b0 ;
 sr1    <= 128'd0;
 sr2    <= 128'd0;
 kr1    <= 256'd0;
 end
else begin 
 valid1 <= input_valid ;
 valid2 <= valid1 ;
 sr1    <= in;
 sr2    <= rout21;
 kr1    <= key;
 end 
end

/*
sonic_round_128x256  i_sr0 (.in(  sr1 ), .rk(  kr1 [255:192]),   .out(rout1 ));
sonic_round_128x256  i_sr1 (.in(rout1 ), .rk(kout1 [255:192]),   .out(rout2 ));
sonic_round_128x256  i_sr2 (.in(rout2 ), .rk(kout2 [255:192]),   .out(rout3 ));
sonic_round_128x256  i_sr3 (.in(rout3 ), .rk(kout3 [255:192]),   .out(rout4 ));
sonic_round_128x256  i_sr4 (.in(rout4 ), .rk(kout4 [255:192]),   .out(rout5 ));
sonic_round_128x256  i_sr5 (.in(rout5 ), .rk(kout5 [255:192]),   .out(rout6 ));
sonic_round_128x256  i_sr6 (.in(rout6 ), .rk(kout6 [255:192]),   .out(rout7 ));
sonic_round_128x256  i_sr7 (.in(rout7 ), .rk(kout7 [255:192]),   .out(rout8 ));
sonic_round_128x256  i_sr8 (.in(rout8 ), .rk(kout8 [255:192]),   .out(rout9 ));
sonic_round_128x256  i_sr9 (.in(rout9 ), .rk(kout9 [255:192]),   .out(rout10));
sonic_round_128x256  i_sr10(.in(rout10), .rk(kout10[255:192]),   .out(rout11));
sonic_round_128x256  i_sr11(.in(rout11), .rk(kout11[255:192]),   .out(rout12));
sonic_round_128x256  i_sr12(.in(rout12), .rk(kout12[255:192]),   .out(rout13));
sonic_round_128x256  i_sr13(.in(rout13), .rk(kout13[255:192]),   .out(rout14));
sonic_round_128x256  i_sr14(.in(rout14), .rk(kout14[255:192]),   .out(rout15));
sonic_round_128x256  i_sr15(.in(rout15), .rk(kout15[255:192]),   .out(rout16));
sonic_round_128x256  i_sr16(.in(rout16), .rk(kout16[255:192]),   .out(rout17));
sonic_round_128x256  i_sr17(.in(rout17), .rk(kout17[255:192]),   .out(rout18));
sonic_round_128x256  i_sr18(.in(rout18), .rk(kout18[255:192]),   .out(rout19));
sonic_round_128x256  i_sr19(.in(rout19), .rk(kout19[255:192]),   .out(rout20));
sonic_round_128x256  i_sr20(.in(rout20), .rk(kout20[255:192]),   .out(rout21));

*/

sonic_round_128x256  i_sr0 (.in(  sr1 ), .rk(  kr1 [255:192]),   .out(rout1 ));
sonic_round_128x256  i_sr1 (.in(rout1 ), .rk(kout1 [255:192]),   .out(rout2 ));
sonic_round_128x256  i_sr2 (.in(rout2 ), .rk(kout1 [191:128]),   .out(rout3 ));
sonic_round_128x256  i_sr3 (.in(rout3 ), .rk(kout2 [255:192]),   .out(rout4 ));
sonic_round_128x256  i_sr4 (.in(rout4 ), .rk(kout2 [191:128]),   .out(rout5 ));
sonic_round_128x256  i_sr5 (.in(rout5 ), .rk(kout3 [255:192]),   .out(rout6 ));
sonic_round_128x256  i_sr6 (.in(rout6 ), .rk(kout3 [191:128]),   .out(rout7 ));
sonic_round_128x256  i_sr7 (.in(rout7 ), .rk(kout4 [255:192]),   .out(rout8 ));
sonic_round_128x256  i_sr8 (.in(rout8 ), .rk(kout4 [191:128]),   .out(rout9 ));
sonic_round_128x256  i_sr9 (.in(rout9 ), .rk(kout5 [255:192]),   .out(rout10));
sonic_round_128x256  i_sr10(.in(rout10), .rk(kout5 [191:128]),   .out(rout11));
sonic_round_128x256  i_sr11(.in(rout11), .rk(kout6 [255:192]),   .out(rout12));
sonic_round_128x256  i_sr12(.in(rout12), .rk(kout6 [191:128]),   .out(rout13));
sonic_round_128x256  i_sr13(.in(rout13), .rk(kout7 [255:192]),   .out(rout14));
sonic_round_128x256  i_sr14(.in(rout14), .rk(kout7 [191:128]),   .out(rout15));
sonic_round_128x256  i_sr15(.in(rout15), .rk(kout8 [255:192]),   .out(rout16));
sonic_round_128x256  i_sr16(.in(rout16), .rk(kout8 [191:128]),   .out(rout17));
sonic_round_128x256  i_sr17(.in(rout17), .rk(kout9 [255:192]),   .out(rout18));
sonic_round_128x256  i_sr18(.in(rout18), .rk(kout9 [191:128]),   .out(rout19));
sonic_round_128x256  i_sr19(.in(rout19), .rk(kout10[255:192]),   .out(rout20));
sonic_round_128x256  i_sr20(.in(rout20), .rk(kout10[191:128]),   .out(rout21));

sonic_key_schedule_128x256  i_kr0 (.in(  kr1 ),  .out(kout1 ));
sonic_key_schedule_128x256  i_kr1 (.in(kout1 ),  .out(kout2 ));
sonic_key_schedule_128x256  i_kr2 (.in(kout2 ),  .out(kout3 ));
sonic_key_schedule_128x256  i_kr3 (.in(kout3 ),  .out(kout4 ));
sonic_key_schedule_128x256  i_kr4 (.in(kout4 ),  .out(kout5 ));
sonic_key_schedule_128x256  i_kr5 (.in(kout5 ),  .out(kout6 ));
sonic_key_schedule_128x256  i_kr6 (.in(kout6 ),  .out(kout7 ));
sonic_key_schedule_128x256  i_kr7 (.in(kout7 ),  .out(kout8 ));
sonic_key_schedule_128x256  i_kr8 (.in(kout8 ),  .out(kout9 ));
sonic_key_schedule_128x256  i_kr9 (.in(kout9 ),  .out(kout10));
sonic_key_schedule_128x256  i_kr10(.in(kout10),  .out(kout11));
sonic_key_schedule_128x256  i_kr11(.in(kout11),  .out(kout12));
sonic_key_schedule_128x256  i_kr12(.in(kout12),  .out(kout13));
sonic_key_schedule_128x256  i_kr13(.in(kout13),  .out(kout14));
sonic_key_schedule_128x256  i_kr14(.in(kout14),  .out(kout15));
sonic_key_schedule_128x256  i_kr15(.in(kout15),  .out(kout16));
sonic_key_schedule_128x256  i_kr16(.in(kout16),  .out(kout17));
sonic_key_schedule_128x256  i_kr17(.in(kout17),  .out(kout18));
sonic_key_schedule_128x256  i_kr18(.in(kout18),  .out(kout19));
sonic_key_schedule_128x256  i_kr19(.in(kout19),  .out(kout20));


endmodule