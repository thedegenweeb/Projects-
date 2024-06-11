`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/04/2024 05:26:13 PM
// Design Name: 
// Module Name: ALUControl
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


module ALUControl (
    input [1:0] ALUOp,
    input [5:0] Funct,
    output reg [3:0] ALUControl
);

    always @(*) begin
        case (ALUOp)
            2'b00: ALUControl = 4'b0010; // lw/sw - add
            2'b01: ALUControl = 4'b0110; // beq - sub
            2'b10: begin
                case (Funct)
                    6'b100000: ALUControl = 4'b0010; // add
                    6'b100010: ALUControl = 4'b0110; // sub
                    6'b100100: ALUControl = 4'b0000; // and
                    6'b100101: ALUControl = 4'b0001; // or
                    6'b101010: ALUControl = 4'b0111; // slt
                    default: ALUControl = 4'b0000;   // default
                endcase
            end
            default: ALUControl = 4'b0000; // default
        endcase
    end
endmodule
