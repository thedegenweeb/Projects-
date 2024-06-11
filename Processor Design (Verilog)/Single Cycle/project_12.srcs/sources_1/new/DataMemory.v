`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/04/2024 05:22:33 PM
// Design Name: 
// Module Name: DataMemory
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


module DataMemory (
    input clk,
    input MemRead,
    input MemWrite,
    input [31:0] Address,
    input [31:0] WriteData,
    output [31:0] ReadData
);

    reg [31:0] memory [0:255];

    assign ReadData = (MemRead) ? memory[Address[31:2]] : 32'b0;

    always @(posedge clk) begin
        if (MemWrite) begin
            memory[Address[31:2]] <= WriteData;
        end
    end
endmodule
