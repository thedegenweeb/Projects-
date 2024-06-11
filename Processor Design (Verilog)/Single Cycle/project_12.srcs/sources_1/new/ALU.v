`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/04/2024 05:19:45 PM
// Design Name: 
// Module Name: ALU
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


module ALU (
    input [31:0] A,
    input [31:0] B,
    input [3:0] ALUControl,
    output reg [31:0] ALUResult,
    output Zero
);

    assign Zero = (ALUResult == 0);

    always @(*) begin
        case (ALUControl)
            4'b0010: ALUResult = A + B;   // ADD
            4'b0110: ALUResult = A - B;   // SUB
            4'b0000: ALUResult = A & B;   // AND
            4'b0001: ALUResult = A | B;   // OR
            4'b0111: ALUResult = (A < B) ? 1 : 0; // SLT
            default: ALUResult = 0;
        endcase
    end
endmodule
