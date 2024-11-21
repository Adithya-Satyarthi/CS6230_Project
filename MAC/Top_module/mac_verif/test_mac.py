# This file is public domain, it can be freely copied without restrictions.
# SPDX-License-Identifier: CC0-1.0

import os
import random
from pathlib import Path

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
from model_macint32 import *
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
    lines_C = file.readlines()'''

with open('s.txt', 'r') as file:
    # Read all lines into a list
    lines_S = file.readlines()

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
async def test_mac(dut):
    """Test to check counter"""

   
    
    #dut.EN_mac_int_input.value=1

    clock = Clock(dut.CLK, 10, units="ns")  # Create a 10us period clock on port clk
    # Start the clock. Start it low to avoid issues on the first RisingEdge
    cocotb.start_soon(clock.start(start_high=False))
    dut.RST_N.value = 0
    await RisingEdge(dut.CLK)
    dut.RST_N.value = 1
   
    
    
    

    dut.EN_get_A.value=1
    dut.EN_get_B.value=1
    dut.EN_get_C.value=1
    dut.EN_sel_line.value=1
    #dut.EN_mac_int_output.value=1
    count=0
    for k in range(50):
        	

        	await RisingEdge(dut.CLK)

    for i in range(0, 1000):
    	
        #en =int(dut.EN_increment.value)
        
        #value = int(dut.increment_di.value)
        #value=i+1
        #dut.increment_di.value=i
        #ini = int(dut.read.value)
        #dut.increment_di.value = i
        dut.sel_line_sel.value=int(lines_S[i],2)
        dut.get_A_a.value=int(lines_A[i],2)
        dut.get_B_b.value=int(lines_B[i],2)
        dut.get_C_c.value=int(lines_C[i],2)
        s=lines_A[i][0]
        a=lines_A[i][:16]
        b=lines_B[i][:16]
        c=lines_C[i][:32]
        
        for k in range(50):
        	

        	await RisingEdge(dut.CLK)
        if int(s)==0:
        
        	mac_out = int(model_macint32(a,b,c))
        else:
        	mac_out=int(model_macfp32(a,b,c))
        #macint32_out=dut.mac_int_output.value
        #a=type(macint32_out)
        dut._log.info(f'output {i,s,dut.get_A_a.value,dut.get_B_b.value,dut.get_C_c.value,dut.mac_output.value,str(mac_out).zfill(32) }')
        
        
       
        assert str(mac_out).zfill(32) == str(dut.mac_output.value), f'Counter Output Mismatch, Expected = {str(mac_out).zfill(32)} DUT = {dut.mac_output.value}'
    
    coverage_db.export_to_yaml(filename="coverage_mac.yml")

