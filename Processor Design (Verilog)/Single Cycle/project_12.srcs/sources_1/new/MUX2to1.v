`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/04/2024 05:25:01 PM
// Design Name: 
// Module Name: MUX2to1
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


module MUX2to1 (
    input [31:0] In0,
    input [31:0] In1,
    input Sel,
    output [31:0] Out
);
    assign Out = (Sel) ? In1 : In0;
endmodule
