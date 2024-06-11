`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/04/2024 05:28:29 PM
// Design Name: 
// Module Name: TopModule
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


module TopModule (
    input clk,
    input reset
);
    wire [31:0] PC, NextPC, Instruction, ReadData1, ReadData2, ALUResult, MemReadData, WriteData;
    wire [4:0] WriteRegister;
    wire [3:0] ALUControl;
    wire [1:0] ALUOp;
    wire [31:0] SignImm, ALUInput2;
    wire Zero, PCSrc, Branch, MemRead, MemWrite, RegDst, ALUSrc, MemtoReg, RegWrite;
    wire [31:0] BranchTarget, PCPlus4, PCBranch;
    ProgramCounter pc_module(clk, reset, NextPC, PC);
    InstructionMemory imem(PC, Instruction);
    ControlUnit cu(Instruction[31:26], RegDst, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch, ALUOp);
    ALUControl alu_control(ALUOp, Instruction[5:0], ALUControl);
    MUX2to1 reg_dst_mux(Instruction[20:16], Instruction[15:11], RegDst, WriteRegister);
    RegisterFile rf(clk, RegWrite, Instruction[25:21], Instruction[20:16], WriteRegister, WriteData, ReadData1, ReadData2);
    MUX2to1 alu_src_mux(ReadData2, SignImm, ALUSrc, ALUInput2);
    ALU alu(ReadData1, ALUInput2, ALUControl, ALUResult, Zero);
    DataMemory dmem(clk, MemRead, MemWrite, ALUResult, ReadData2, MemReadData);
    SignExtender se(Instruction[15:0], SignImm);
    PCAdder pc_adder(PC, PCPlus4);
    MUX2to1 mem_to_reg_mux(ALUResult, MemReadData, MemtoReg, WriteData);
    assign BranchTarget = SignImm << 2;
    assign PCBranch = PCPlus4 + BranchTarget;
    assign PCSrc = Branch & Zero;
    MUX2to1 pc_mux(PCPlus4, PCBranch, PCSrc, NextPC);
endmodule