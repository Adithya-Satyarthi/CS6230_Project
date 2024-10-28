

import cocotb
from cocotb_coverage.coverage import *


counter_coverage = coverage_section(
    CoverPoint('top.mac_fp_input_inp_1', vname='a', bins = [
    # 16-bit 0
    "0000000000000000",
    
    # 16-bit all 1
    "0111111111111111",
    
    # 16-bit alternating ones
    "0010101010101010",
    "0101010101010101",
    
    # 16-bit walking one
    "0000000000000001",
    "0000000000000010",
    "0000000000000100",
    "0000000000001000",
    "0000000000010000",
    "0000000000100000",
    "0000000001000000",
    "0000000010000000",
    "0000000100000000",
    "0000001000000000",
    "0000010000000000",
    "0000100000000000",
    "0001000000000000",
    "0010000000000000",
    "0100000000000000",
    
    
    # 16-bit walking zero
    "0111111111111110",
    "0111111111111101",
    "0111111111111011",
    "0111111111110111",
    "0111111111101111",
    "0111111111011111",
    "0111111110111111",
    "0111111101111111",
    "0111111011111111",
    "0111110111111111",
    "0111101111111111",
    "0111011111111111",
    "0110111111111111",
    "0101111111111111",
    "0011111111111111",
    "0111111111111111"
]),
    CoverPoint('top.mac_fp_input_inp_2', vname='b', bins = [
    # 16-bit 0
      "0000000000000000",
    
    # 16-bit all 1
    "0111111111111111",
    
    # 16-bit alternating ones
    "0010101010101010",
    "0101010101010101",
    
    # 16-bit walking one
    "0000000000000001",
    "0000000000000010",
    "0000000000000100",
    "0000000000001000",
    "0000000000010000",
    "0000000000100000",
    "0000000001000000",
    "0000000010000000",
    "0000000100000000",
    "0000001000000000",
    "0000010000000000",
    "0000100000000000",
    "0001000000000000",
    "0010000000000000",
    "0100000000000000",
    
    
    # 16-bit walking zero
    "0111111111111110",
    "0111111111111101",
    "0111111111111011",
    "0111111111110111",
    "0111111111101111",
    "0111111111011111",
    "0111111110111111",
    "0111111101111111",
    "0111111011111111",
    "0111110111111111",
    "0111101111111111",
    "0111011111111111",
    "0110111111111111",
    "0101111111111111",
    "0011111111111111",
    "0111111111111111"
]),
    CoverPoint('top.mac_fp_input_inp_3', vname='c', bins = [
    # 32-bit 0
    "00000000000000000000000000000000",
    
    # 32-bit all 1
    "01111111111111111111111111111111",
    
    # 32-bit alternating ones
    "00101010101010101010101010101010",
    "01010101010101010101010101010101",
    
    # 32-bit walking one
    "00000000000000000000000000000001",
    "00000000000000000000000000000010",
    "00000000000000000000000000000100",
    "00000000000000000000000000001000",
    "00000000000000000000000000010000",
    "00000000000000000000000000100000",
    "00000000000000000000000001000000",
    "00000000000000000000000010000000",
    "00000000000000000000000100000000",
    "00000000000000000000001000000000",
    "00000000000000000000010000000000",
    "00000000000000000000100000000000",
    "00000000000000000001000000000000",
    "00000000000000000010000000000000",
    "00000000000000000100000000000000",
    "00000000000000001000000000000000",
    "00000000000000010000000000000000",
    "00000000000000100000000000000000",
    "00000000000001000000000000000000",
    "00000000000010000000000000000000",
    "00000000000100000000000000000000",
    "00000000001000000000000000000000",
    "00000000010000000000000000000000",
    "00000000100000000000000000000000",
    "00000001000000000000000000000000",
    "00000010000000000000000000000000",
    "00000100000000000000000000000000",
    "00001000000000000000000000000000",
    "00010000000000000000000000000000",
    "00100000000000000000000000000000",
    "01000000000000000000000000000000",
    
    
    # 32-bit walking zero
    "01111111111111111111111111111110",
    "01111111111111111111111111111101",
    "01111111111111111111111111111011",
    "01111111111111111111111111110111",
    "01111111111111111111111111101111",
    "01111111111111111111111111011111",
    "01111111111111111111111110111111",
    "01111111111111111111111101111111",
    "01111111111111111111111011111111",
    "01111111111111111111110111111111",
    "01111111111111111111101111111111",
    "01111111111111111111011111111111",
    "01111111111111111110111111111111",
    "01111111111111111101111111111111",
    "01111111111111111011111111111111",
    "01111111111111110111111111111111",
    "01111111111111101111111111111111",
    "01111111111111011111111111111111",
    "01111111111110111111111111111111",
    "01111111111101111111111111111111",
    "01111111111011111111111111111111",
    "01111111110111111111111111111111",
    "01111111101111111111111111111111",
    "01111111011111111111111111111111",
    "01111110111111111111111111111111",
    "01111101111111111111111111111111",
    "01111011111111111111111111111111",
    "01110111111111111111111111111111",
    "01101111111111111111111111111111",
    "01011111111111111111111111111111",
    "00111111111111111111111111111111",
    "01111111111111111111111111111111"
]),
    CoverCross('top.cross_cover', items = ['top.mac_fp_input_inp_1', 'top.mac_fp_input_inp_2','top.mac_fp_input_inp_3'])
)











def round_to_8_msb(binary_string):
    
    msb_8 = binary_string[:8]
    if len(binary_string) > 8:
        remaining_bits = binary_string[8:]
        half_threshold = (2 ** len(remaining_bits)) // 2
        remaining_value = int(remaining_bits, 2)
        
        
        if  (remaining_value > half_threshold):
            
            rounded_int = int(msb_8, 2) + 1
            msb_8 = bin(rounded_int)[2:]  
            
        elif (binary_string[7] == '1') and (remaining_value >= half_threshold) :
            rounded_int = int(msb_8, 2) + 1
            msb_8 = bin(rounded_int)[2:] 
           
        else:
            msb_8=msb_8
        
    
    
            
            
        if len(msb_8) > 8:
                
            msb_8 = msb_8[:8]
            return msb_8, True  
        else:
            return msb_8, False  
    return msb_8, False  

def round_to_24_msb(binary_string):
    
    msb_24 = binary_string[:24]
    if len(binary_string) > 24:
        remaining_bits = binary_string[24:]
        half_threshold = (2 ** len(remaining_bits)) // 2
        remaining_value = int(remaining_bits, 2)

       
        if  (remaining_value > half_threshold):
            
            rounded_int = int(msb_24, 2) + 1
            msb_24 = bin(rounded_int)[2:]  
        elif (binary_string[23] == '1') and (remaining_value >= half_threshold) :
            rounded_int = int(msb_24, 2) + 1
            msb_24 = bin(rounded_int)[2:] 

            
        if len(msb_24) > 24:
                
            msb_24 = msb_24[:24]
            return msb_24, True  
        else:
            return msb_24, False  
    return msb_24, False  

def output(a, b, c):
    
    sign_a = a[0]
    exponent_a = a[1:9]
    mantissa_a = '1' + a[9:16]  

  
    sign_b = b[0]
    exponent_b = b[1:9]
    mantissa_b = '1' + b[9:16] 
    if exponent_a=='00000000' or exponent_b=='00000000' :
    	return c

   
    exponent_a_int = int(exponent_a, 2)
    exponent_b_int = int(exponent_b, 2)
    combined_exponent = (exponent_a_int + exponent_b_int) - 127
    combined_exponent_bin = bin(combined_exponent & 0xFF)[2:].zfill(8)

    
    mantissa_a_int = int(mantissa_a, 2)
    mantissa_b_int = int(mantissa_b, 2)
    multiplied_mantissa = mantissa_a_int * mantissa_b_int
    multiplied_mantissa_bin = bin(multiplied_mantissa & 0xFFFF)[2:].zfill(16)

    
    if multiplied_mantissa_bin[0] == '1':
        
        combined_exponent += 1
        combined_exponent_bin = bin(combined_exponent & 0xFF)[2:].zfill(8)
    else:
        
        multiplied_mantissa_bin = multiplied_mantissa_bin[1:] + '0'
   
    rounded_mantissa_8, overflow_8 = round_to_8_msb(multiplied_mantissa_bin)
    
    if overflow_8:
        combined_exponent += 1
        combined_exponent_bin = bin(combined_exponent & 0xFF)[2:].zfill(8)

    
    sign_bit = str(int(sign_a) ^ int(sign_b))

    
    padded_mantissa_8 = rounded_mantissa_8.ljust(24, '0')  
    if c[1:32]=='0000000000000000000000000000000':
    	return sign_bit+combined_exponent_bin[:8]+padded_mantissa_8[1:]
    
    sign_c = c[0]
    exponent_c = c[1:9]
    mantissa_c = '1' + c[9:32]  
    mantissa_c = mantissa_c[:24]  

    
    combined_exponent_int = int(combined_exponent_bin, 2)
    exponent_c_int = int(exponent_c, 2)

    
    if combined_exponent_int > exponent_c_int:
        higher_exponent = combined_exponent_int
        lower_mantissa = mantissa_c
        higher_mantissa = padded_mantissa_8
        expo_difference = combined_exponent_int - exponent_c_int
    else:
        higher_exponent = exponent_c_int
        higher_mantissa = mantissa_c
        lower_mantissa = padded_mantissa_8
        expo_difference = exponent_c_int - combined_exponent_int

    
    if expo_difference > 0:
        
        lower_mantissa_shifted = '0' * expo_difference + lower_mantissa
    else:
        lower_mantissa_shifted = lower_mantissa  

   
    higher_mantissa_padded = higher_mantissa.ljust(len(lower_mantissa_shifted), '0')

    
    result_expo_bin = bin(higher_exponent & 0xFF)[2:].zfill(8)

    
    if sign_bit == sign_c:
        
        final_mantissa_int = int(higher_mantissa_padded, 2) + int(lower_mantissa_shifted, 2)
        final_sign_bit = sign_bit  

        
        if final_mantissa_int >= (1 << len(higher_mantissa_padded)):  
            a=int(str(bin(final_mantissa_int))[-1])&int(str(bin(final_mantissa_int))[-2])
            final_mantissa_int >>= 1  
            
            final_mantissa_int+=a
            higher_exponent += 1  
            
            
    else:
        
        higher_mantissa_value = int(higher_mantissa_padded, 2)
        lower_mantissa_value = int(lower_mantissa_shifted, 2)

        if higher_mantissa_value >= lower_mantissa_value:
            final_mantissa_int = higher_mantissa_value - lower_mantissa_value
            final_sign_bit = sign_bit if higher_exponent == exponent_a_int else sign_b 
        else:
            final_mantissa_int = lower_mantissa_value - higher_mantissa_value
            final_sign_bit = sign_c if higher_exponent == exponent_b_int else sign_a 

    
    final_mantissa_bin = bin(final_mantissa_int)[2:]  
    rounded_final_mantissa, overflow_final = round_to_24_msb(final_mantissa_bin)

    
    if overflow_final:
        higher_exponent += 1
    result_expo_bin = bin(higher_exponent & 0xFF)[2:].zfill(8)

    
    
    
    
   
    return final_sign_bit+result_expo_bin+rounded_final_mantissa[1:]

@counter_coverage
def model_macfp32(a,b,c) -> int:
    return output(a,b,c)
