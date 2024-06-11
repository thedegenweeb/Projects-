`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/07/2024 10:43:22 AM
// Design Name: 
// Module Name: PC_Module
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


module PC_Module(clk,rst,PC,PC_Next);
//declaring I/O
    input clk,rst;
    input [31:0]PC_Next;
    output [31:0]PC;
    reg [31:0]PC;

    always @(posedge clk)
    begin
        if(rst == 1'b0)
            PC <= {32{1'b0}};           //resetting PC
        else
            PC <= PC_Next;              //incrementing PC
    end
endmodule