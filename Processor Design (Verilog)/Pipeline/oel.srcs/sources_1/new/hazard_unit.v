`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/07/2024 10:43:22 AM
// Design Name: 
// Module Name: hazard_unit
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


module hazard_unit(rst, RegWriteM, RegWriteW, RD_M, RD_W, Rs1_E, Rs2_E, ForwardAE, ForwardBE);

    // Declaration of I/Os
    input rst, RegWriteM, RegWriteW;
    input [4:0] RD_M, RD_W, Rs1_E, Rs2_E;
    output [1:0] ForwardAE, ForwardBE;

//assigning values according to control signals
    assign ForwardAE = (rst == 1'b0) ? 2'b00 : 
                       ((RegWriteM == 1'b1) & (RD_M != 5'h00) & (RD_M == Rs1_E)) ? 2'b10 :
                       ((RegWriteW == 1'b1) & (RD_W != 5'h00) & (RD_W == Rs1_E)) ? 2'b01 : 2'b00;
                       
    assign ForwardBE = (rst == 1'b0) ? 2'b00 : 
                       ((RegWriteM == 1'b1) & (RD_M != 5'h00) & (RD_M == Rs2_E)) ? 2'b10 :
                       ((RegWriteW == 1'b1) & (RD_W != 5'h00) & (RD_W == Rs2_E)) ? 2'b01 : 2'b00;

endmodule
