# This file is public domain, it can be freely copied without restrictions.
# SPDX-License-Identifier: CC0-1.0

import os
import random
from pathlib import Path

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
from model_macfp32 import *

'''
with open('A_binary.txt', 'r') as file:

    # Read all lines into a list
    lines_A = file.readlines()
with open('B_binary.txt', 'r') as file:
    # Read all lines into a list
    lines_B = file.readlines()
with open('C_binary.txt', 'r') as file:
    # Read all lines into a list
    lines_C = file.readlines()

# Print the list of lines

'''
with open('a.txt', 'r') as file:

    # Read all lines into a list
    lines_A = file.readlines()
with open('b.txt', 'r') as file:
    # Read all lines into a list
    lines_B = file.readlines()
with open('c.txt', 'r') as file:
    # Read all lines into a list
    lines_C = file.readlines()


@cocotb.test()
async def test_macfp32(dut):
    """Test to check counter"""

   
    
    dut.EN_mac_fp_input.value=1

    clock = Clock(dut.CLK, 1, units="ns")  # Create a 10us period clock on port clk
    # Start the clock. Start it low to avoid issues on the first RisingEdge
    cocotb.start_soon(clock.start(start_high=False))
    dut.RST_N.value = 0
    await RisingEdge(dut.CLK)
    dut.RST_N.value = 1
   
    
    
    

    dut.EN_mac_fp_input.value=1
    #dut.EN_mac_int_output.value=1
    count=0
    for k in range(100):
        	

        	await RisingEdge(dut.CLK)

    for i in range(0, 77297):
    	
        #en =int(dut.EN_increment.value)
        
        #value = int(dut.increment_di.value)
        #value=i+1
        #dut.increment_di.value=i
        #ini = int(dut.read.value)
        #dut.increment_di.value = i
        dut.mac_fp_input_inp_1.value=int(lines_A[i],2)
        dut.mac_fp_input_inp_2.value=int(lines_B[i],2)
        dut.mac_fp_input_inp_3.value=int(lines_C[i],2)
        a=lines_A[i][:16]
        b=lines_B[i][:16]
        c=lines_C[i][:32]
        
        for k in range(20):
        	

        	await RisingEdge(dut.CLK)
        macfp32_out = int(model_macfp32(a,b,c))
        #macint32_out=dut.mac_int_output.value
        #a=type(macint32_out)
        dut._log.info(f'output {i,dut.mac_fp_input_inp_1.value,dut.mac_fp_input_inp_2.value,dut.mac_fp_input_inp_3.value,dut.mac_fp_output.value,str(macfp32_out).zfill(32) }')
        
        #if i in [20969,]:
       		#continue
       		
        
        assert str(macfp32_out).zfill(32)[:30] == str(dut.mac_fp_output.value)[:30], f'Counter Output Mismatch, Expected = {str(macfp32_out).zfill(32)} DUT = {dut.mac_fp_output.value}'
    
    coverage_db.export_to_yaml(filename="coverage_macfp32.yml")

