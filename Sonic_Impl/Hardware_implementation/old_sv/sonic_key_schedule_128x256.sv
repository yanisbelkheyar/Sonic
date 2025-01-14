/////////////////////////////////////////////////////////////////////////////////
//
// Engineer: Santosh Ghosh, PhD
// 
// Create Date:    2:13:52 05/09/2023
// Design Name: 
// Module Name:    sonic_round
// Project Name:   low_latency_blockcipher 
//////////////////////////////////////////////////////////////////////////////////
module sonic_key_schedule_128x256(in, out);
input [255 :0] in            ; //256 bit key in
output logic [255:0] out     ; //256 bit key out 

logic [127:0] t, x, y;

always_comb begin
 y = {in[126:0],in[127]} ^ {in[119:0],in[127:120]} ^ {in[117:0],in[127:118]};
 t = in[255:128] ^ ({in[115:0],in[127:116]} & in[127:0]) ^ {in[126:0],in[127]};

 for (int i = 0;  i<128; i=i+1)
   x[i] = t[(15*i)%128];
 
 out = {y,x}; 
end


endmodule