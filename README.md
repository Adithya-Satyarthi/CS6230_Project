# CS6230 Project: MAC Unit Design

This project is part of the CS6230: CAD for VLSI course. The objective is to design a Multiply-Accumulate (MAC) unit that supports the following operations:
- **Integer Mode**: (A: int8, B: int8, C: int32) → (MAC: int32)
- **Floating-Point Mode**: (A: bf16, B: bf16, C: fp32) → (MAC: fp32)

The design includes two MAC modules, each dedicated to performing one of the operations above.

## Design Overview

### 1. MAC_int Module (Integer Mode)
The `MAC_int` module consists of two stages:
1. **Multiplication**: Implemented using a Wallace Multiplier with a Carry-Save Adder (CSA).
2. **Accumulation**: Performed using a Ripple Carry Adder (RCA).

**Wallace Multiplier**: The Wallace Multiplier is a hardware-efficient implementation designed to speed up binary multiplication. A naive approach to adding partial products results in a time complexity of $O(log^2(n))$, while the Wallace Multiplier reduces this to $O(log(n))$. Our implementation[^1] further optimizes the delay compared to the standard design.

<div align="center">
<img src="https://github.com/user-attachments/assets/2d3949b0-f814-47b8-9a4a-4962c795f96e" alt="Wallace Multiplier" width="500" height="400"/>
</div>

The final partial sums are combined using a Carry-Save Adder (CSA) to reduce propagation delay due to carry.

 **Accumulation**: The accumulation phase uses a standard Ripple Carry Adder (RCA) to sum the result of the multiplication with the input accumulator value (C).

### 2. MAC_fp Module (Floating-Point Mode)
The `MAC_fp` module performs multiplication and accumulation in floating-point format, supporting the bf16 (bfloat16) and fp32 (single-precision) data types. 

References:
[^1]: M. Sai Kumar, D. A. Kumar and P. Samundiswary, "Design and performance analysis of Multiply-Accumulate (MAC) unit," 2014 International Conference on Circuits, Power and Computing Technologies [ICCPCT-2014], Nagercoil, India, 2014, pp. 1084-1089, doi: 10.1109/ICCPCT.2014.7054782. keywords: {Adders;Arrays;Computational modeling;Integrated circuit modeling;Simulation;Computers;Carry Save Adder (CSA);Booth Multiplier;Array Multiplier;Ripple Carry Array Multiplier with Row Bypass;Wallace Tree Multipiler;DADDA Mulitplier and Multiply-Accumulate (MAC) unit},


