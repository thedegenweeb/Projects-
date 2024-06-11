`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/07/2024 03:02:21 PM
// Design Name: 
// Module Name: two_bit_predictor
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

module two_bit_predictor (
    input wire clk,
    input wire reset,
    input wire branch,    // Branch instruction signal (1 if a branch instruction is present, 0 otherwise)
    input wire taken,     // Actual outcome of the branch (1 if taken, 0 if not taken)
    output reg predict    // Prediction output (1 if predicted taken, 0 if predicted not taken)
);

    // State encoding for the 2-bit predictor
    parameter STRONGLY_NOT_TAKEN = 2'b00;
    parameter WEAKLY_NOT_TAKEN   = 2'b01;
    parameter WEAKLY_TAKEN       = 2'b10;
    parameter STRONGLY_TAKEN     = 2'b11;

    reg [1:0] state, next_state;

    // State transition and output logic
    always @(*) begin
        case (state)
            STRONGLY_NOT_TAKEN: begin
                predict = 1'b0;
                if (branch) begin
                    if (taken)
                        next_state = WEAKLY_NOT_TAKEN;
                    else
                        next_state = STRONGLY_NOT_TAKEN;
                end else begin
                    next_state = STRONGLY_NOT_TAKEN;
                end
            end
            WEAKLY_NOT_TAKEN: begin
                predict = 1'b0;
                if (branch) begin
                    if (taken)
                        next_state = WEAKLY_TAKEN;
                    else
                        next_state = STRONGLY_NOT_TAKEN;
                end else begin
                    next_state = WEAKLY_NOT_TAKEN;
                end
            end
            WEAKLY_TAKEN: begin
                predict = 1'b1;
                if (branch) begin
                    if (taken)
                        next_state = STRONGLY_TAKEN;
                    else
                        next_state = WEAKLY_NOT_TAKEN;
                end else begin
                    next_state = WEAKLY_TAKEN;
                end
            end
            STRONGLY_TAKEN: begin
                predict = 1'b1;
                if (branch) begin
                    if (taken)
                        next_state = STRONGLY_TAKEN;
                    else
                        next_state = WEAKLY_TAKEN;
                end else begin
                    next_state = STRONGLY_TAKEN;
                end
            end
            default: begin
                predict = 1'b0;
                next_state = STRONGLY_NOT_TAKEN;
            end
        endcase
    end

    // State register
    always @(posedge clk or posedge reset) begin
        if (reset)
            state <= STRONGLY_NOT_TAKEN;
        else
            state <= next_state;
    end

endmodule
