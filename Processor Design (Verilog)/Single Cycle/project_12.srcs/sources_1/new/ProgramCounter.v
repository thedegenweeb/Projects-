`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/04/2024 05:27:16 PM
// Design Name: 
// Module Name: ProgramCounter
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


module ProgramCounter (
    input clk,
    input reset,
    input [31:0] NextPC,
    output reg [31:0] PC
);

    always @(posedge clk or posedge reset) begin
        if (reset)
            PC <= 32'b0;
        else
            PC <= NextPC;
    end
endmodule
