`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/04/2024 05:29:23 PM
// Design Name: 
// Module Name: TopModuleTB
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


module TopModuleTB;
    reg clk;reg reset;
    wire [31:0] PC, Instruction, ReadData1, ReadData2, ALUResult, MemReadData, WriteData;
    wire [31:0] NextPC, SignImm, ALUInput2; wire [4:0] WriteRegister; wire [3:0] ALUControl;
    wire [1:0] ALUOp; wire Zero, PCSrc, Branch, MemRead, MemWrite, RegDst, ALUSrc, MemtoReg, RegWrite;
    TopModule topModule (.clk(clk), .reset(reset));
    assign PC = topModule.pc_module.PC; assign NextPC = topModule.NextPC; 
    assign Instruction = topModule.imem.Instruction; assign ReadData1 = topModule.rf.ReadData1;
    assign ReadData2 = topModule.rf.ReadData2; assign ALUResult = topModule.alu.ALUResult;
    assign MemReadData = topModule.dmem.ReadData;
    assign WriteData = topModule.WriteData; 
    assign SignImm = topModule.se.SignImm;
    assign ALUInput2 = topModule.ALUInput2; assign WriteRegister = topModule.WriteRegister;
    assign ALUControl = topModule.alu_control.ALUControl;
    assign ALUOp = topModule.cu.ALUOp; assign Zero = topModule.alu.Zero;
    assign PCSrc = topModule.PCSrc; assign Branch = topModule.cu.Branch;
    assign MemRead = topModule.cu.MemRead; assign MemWrite = topModule.cu.MemWrite;
    assign RegDst = topModule.cu.RegDst; assign ALUSrc = topModule.cu.ALUSrc;
    assign MemtoReg = topModule.cu.MemtoReg; assign RegWrite = topModule.cu.RegWrite;
    initial begin
        clk = 0; forever #5 clk = ~clk;
    end
    initial begin
        reset = 1; #10;
        reset = 0; #100;
        $finish;
    end
endmodule

