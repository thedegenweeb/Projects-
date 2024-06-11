`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/04/2024 05:20:22 PM
// Design Name: 
// Module Name: RegisterFile
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


module RegisterFile (
    input clk,
    input RegWrite,
    input [4:0] ReadRegister1,
    input [4:0] ReadRegister2,
    input [4:0] WriteRegister,
    input [31:0] WriteData,
    output [31:0] ReadData1,
    output [31:0] ReadData2
);

    reg [31:0] registers [31:0];
    initial begin
    registers[0] = 32'd0;
    registers[1] = 32'd1;
    registers[2] = 32'd2;
    registers[3] = 32'd3;
    registers[4] = 32'd4;
    registers[5] = 32'd5;
    registers[6] = 32'd6;
    registers[7] = 32'd7;
    registers[8] = 32'd8;
    registers[9] = 32'd9;
    registers[10] = 32'd8;
    registers[11] = 32'd7;
    registers[12] = 32'd6;
    registers[13] = 32'd5;
    registers[14] = 32'd4;
    registers[15] = 32'd3;
    registers[16] = 32'd2;
    registers[17] = 32'd1;
    registers[18] = 32'd2;
    registers[19] = 32'd3;
    registers[20] = 32'd4;
    registers[21] = 32'd5;
    registers[22] = 32'd6;
    registers[23] = 32'd7;
    registers[24] = 32'd8;
    registers[25] = 32'd9;
    registers[26] = 32'd8;
    registers[27] = 32'd7;
    registers[28] = 32'd6;
    registers[29] = 32'd5;
    registers[30] = 32'd4;
    registers[31] = 32'd3;
    end

    assign ReadData1 = registers[ReadRegister1];
    assign ReadData2 = registers[ReadRegister2];

    always @(posedge clk) begin
        if (RegWrite) begin
            registers[WriteRegister] <= WriteData;
        end
    end
endmodule
