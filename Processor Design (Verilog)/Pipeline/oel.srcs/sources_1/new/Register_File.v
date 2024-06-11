`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/07/2024 10:43:22 AM
// Design Name: 
// Module Name: Register_File
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


module Register_File(clk,rst,WE3,WD3,A1,A2,A3,RD1,RD2);
//declaring I/O
    input clk,rst,WE3;
    input [4:0]A1,A2,A3;
    input [31:0]WD3;
    output [31:0]RD1,RD2;

    reg [31:0] Register [31:0];         //register file

    always @ (posedge clk)
    begin
        if(WE3 & (A3 != 5'h00))
            Register[A3] <= WD3;
    end
//assigning values 
    assign RD1 = (rst==1'b0) ? 32'd0 : Register[A1];
    assign RD2 = (rst==1'b0) ? 32'd0 : Register[A2];

    initial begin
        Register[0] = 32'h00000000;
    end

endmodule