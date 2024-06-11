`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/04/2024 05:21:45 PM
// Design Name: 
// Module Name: InstructionMemory
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


module InstructionMemory (
    input [31:0] Address,
    output [31:0] Instruction
);

    reg [31:0] memory [0:255];

    initial begin
        
        memory[0] = 32'h00221820;
        memory[4] = 32'h00161710;
        memory[8] = 32'h00223820;
        memory[12] = 32'h00241820;
        memory[16] = 32'h00161710;
        memory[20] = 32'h00821820;
        memory[24] = 32'h00721820;
        memory[28] = 32'h00621820;
        memory[32] = 32'h00521820;
        memory[36] = 32'h00421820;
        memory[40] = 32'h00321820;
        
    end

    assign Instruction = memory[Address[31:2]];
endmodule
