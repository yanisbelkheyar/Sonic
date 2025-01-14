/////////////////////////////////////////////////////////////////////////////////
//
// Engineer: Santosh Ghosh, PhD
// 
// Create Date:    2:13:52 05/09/2023
// Design Name: 
// Module Name:    sonic_round
// Project Name:   low_latency_blockcipher 
//////////////////////////////////////////////////////////////////////////////////
module sonic_round_128x256(in, rk, out);
input [127 :0] in            ; //128 bit state in
input [ 63 :0] rk            ; //round key; 
output logic [127:0] out     ; //128 bit state out 

logic [63:0] t, x, y;

always_comb begin
 y = ({in[62:0],in[63]} ^ {in[55:0],in[63:56]}) ^ ({in[53:0],in[63:54]} ^ rk);
 t = in[127:64] ^ ({in[51:0],in[63:52]} & in[63:0]) ^ {in[62:0],in[63]};

 for (int i = 0;  i<64; i=i+1)
   x[i] = t[(15*i)%64];
 
 out = {y,x}; 
end


endmodule