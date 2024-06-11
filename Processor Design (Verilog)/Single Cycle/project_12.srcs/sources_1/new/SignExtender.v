`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/04/2024 05:24:22 PM
// Design Name: 
// Module Name: SignExtender
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module SignExtender (
    input [15:0] Inst,
    output [31:0] SignImm
);
    assign SignImm = {{16{Inst[15]}}, Inst};
endmodule
