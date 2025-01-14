/////////////////////////////////////////////////////////////////////////////////
//
// Engineer: Santosh Ghosh, PhD
// 
// Create Date:    2:13:52 05/09/2023
// Design Name: 
// Module Name:    sonic_round
// Project Name:   low_latency_blockcipher 
//////////////////////////////////////////////////////////////////////////////////
module sonic_round_64x128(in, rk, out);
input [63 :0] in            ; //128 bit state in
input [31 :0] rk            ; //round key; 
output logic [63:0] out     ; //128 bit state out 

logic [31:0] t, x, y;

always_comb begin
 y = ({in[30:0],in[31]} ^ {in[23:0],in[31:24]}) ^ ({in[21:0],in[31:22]} ^ rk);
 t = in[63:32] ^ ({in[19:0],in[31:20]} & in[31:0]) ^ {in[30:0],in[31]};

 for (int i = 0;  i<32; i=i+1)
   x[i] = t[(15*i)%32];
 
 out = {y,x}; 
end


endmodule