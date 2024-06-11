`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/07/2024 10:43:22 AM
// Design Name: 
// Module Name: testbench
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


module testbench();
    reg clk=0, rst;
    wire [31:0] program_counter, code, data_read_1, data_read_2, result_alu, memory_read, data_write;
    wire [31:0] next_pc, immediate; 
    wire [4:0] reg_write;
    wire [6:0]op_code;
    wire [2:0]alu_cunt;
    // wire Zero;
    wire PCSrc, Branch, write_memory, ALUSrc, write_register;

Pipeline_top pipeline (.clk(clk), .rst(rst));

    assign program_counter = pipeline.PCD; 
    assign next_pc = pipeline.PCPlus4D; 
    assign code = pipeline.instructions; 
    assign data_read_1 = pipeline.RS1_E;
    assign data_read_2 = pipeline.RS2_E; 
    assign result_alu = pipeline.ALU_ResultM;
    assign memory_read = pipeline.ReadDataW;
    assign data_write = pipeline.WriteDataM; 
    assign immediate = pipeline.Decode.Imm_Ext_D;
    assign reg_write = pipeline.RDW;
    // assign Zero = pipeline.Execute.ZeroE;
    assign alu_cunt = pipeline.ALUControlE;
    assign op_code = pipeline.Decode.control.Op;
    assign PCSrc = pipeline.PCSrcE; 
    assign Branch = pipeline.BranchE;
    assign write_memory = pipeline.MemWriteE; 
    assign ALUSrc = pipeline.ALUSrcE;
    assign write_register = pipeline.RegWriteE;
    always begin
        clk = ~clk;
        #50;
    end

    initial begin
        rst <= 1'b0;
        #200;
        rst <= 1'b1;
        #1500;
        // $finish;    
    end

endmodule