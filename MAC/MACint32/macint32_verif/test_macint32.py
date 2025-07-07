# This file is public domain, it can be freely copied without restrictions.
# SPDX-License-Identifier: CC0-1.0

import os
import random
from pathlib import Path

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
from model_macint32 import *

'''
with open('A_binary.txt', 'r') as file:

    # Read all lines into a list
    lines_A = file.readlines()
with open('B_binary.txt', 'r') as file:
    # Read all lines into a list
    lines_B = file.readlines()
with open('C_binary.txt', 'r') as file:
    # Read all lines into a list
    lines_C = file.readlines()'''

with open('a.txt', 'r') as file:

    # Read all lines into a list
    lines_A = file.readlines()
with open('b.txt', 'r') as file:
    # Read all lines into a list
    lines_B = file.readlines()
with open('c.txt', 'r') as file:
    # Read all lines into a list
    lines_C = file.readlines()

# Print the list of lines



@cocotb.test()
async def test_macint32(dut):
    """Test to check counter"""

   
    
    #dut.EN_mac_int_input.value=1

    clock = Clock(dut.CLK, 10, units="ns")  # Create a 10us period clock on port clk
    # Start the clock. Start it low to avoid issues on the first RisingEdge
    cocotb.start_soon(clock.start(start_high=False))
    dut.RST_N.value = 0
    await RisingEdge(dut.CLK)
    dut.RST_N.value = 1
   
    
    
    

    dut.EN_mac_int_input.value=1
    #dut.EN_mac_int_output.value=1
    count=0
    for k in range(10):
        	

        	await RisingEdge(dut.CLK)

    for i in range(0, 23040):
    	
        #en =int(dut.EN_increment.value)
        
        #value = int(dut.increment_di.value)
        #value=i+1
        #dut.increment_di.value=i
        #ini = int(dut.read.value)
        #dut.increment_di.value = i
        dut.mac_int_input_inp_1.value=int(lines_A[i],2)
        dut.mac_int_input_inp_2.value=int(lines_B[i],2)
        dut.mac_int_input_inp_3.value=int(lines_C[i],2)
        a=lines_A[i][:8]
        b=lines_B[i][:8]
        c=lines_C[i][:32]
        
        for k in range(20):
        	

        	await RisingEdge(dut.CLK)
        macint32_out = int(model_macint32(a,b,c))
        #macint32_out=dut.mac_int_output.value
        #a=type(macint32_out)
        dut._log.info(f'output {a,b,c,dut.mac_int_input_inp_1.value,dut.mac_int_input_inp_2.value,dut.mac_int_input_inp_3.value,dut.mac_int_output.value,str(macint32_out).zfill(32) }')
        
        
       
        assert str(macint32_out).zfill(32) == str(dut.mac_int_output.value), f'Counter Output Mismatch, Expected = {str(macint32_out).zfill(32)} DUT = {dut.mac_int_output.value}'
    
    coverage_db.export_to_yaml(filename="coverage_macint32.yml")

