package mac_fp32;

import wallace_multiplier ::*;
import DReg :: *;

interface Mac_int_ifc;
	method Action mac_fp_input(Bit#(16) inp_1, Bit#(16) inp_2, Bit#(32) inp_3);
	method Bit#(32) mac_fp_output();
endinterface : Mac_int_ifc

interface Csa_ifc_1;
	method Bit#(32) csa_input(Bit#(32) csa_inp1, Bit#(32) csa_inp2, Bit#(32) csa_inp3);
endinterface : Csa_ifc_1

interface Rca_ifc_1;
	method Bit#(32) rca_input(Bit#(32) rca_inp1, Bit#(32) rca_inp2);
endinterface : Rca_ifc_1

interface Rca_ifc_2;
	method Bit#(49) rca_input(Bit#(49) rca_inp1, Bit#(49) rca_inp2);
endinterface : Rca_ifc_2

module mk_ripple_carry_adder_1(Rca_ifc_1);
	method Bit#(32) rca_input(Bit#(32) rca_inp1, Bit#(32) rca_inp2);
		Bit#(32) sum   = 0;
		Bit#(33) carry = 0;
		for(Integer i = 0; i < 32; i = i + 1)begin
			sum[i] = rca_inp1[i] ^ rca_inp2[i] ^ carry[i];
			carry[i+1] = (rca_inp1[i] & rca_inp2[i]) | (rca_inp1[i] & carry[i]) | (rca_inp2[i] & carry[i]);
		end
		return sum;
	endmethod : rca_input
endmodule : mk_ripple_carry_adder_1

module mk_ripple_carry_adder_2(Rca_ifc_2);
	method Bit#(49) rca_input(Bit#(49) rca_inp1, Bit#(49) rca_inp2);
		Bit#(49) sum   = 0;
		Bit#(49) carry = 0;
		for(Integer i = 0; i < 49; i = i + 1)begin
			sum[i] = rca_inp1[i] ^ rca_inp2[i] ^ carry[i];
			carry[i+1] = (rca_inp1[i] & rca_inp2[i]) | (rca_inp1[i] & carry[i]) | (rca_inp2[i] & carry[i]);
		end
		return sum;
	endmethod : rca_input
endmodule : mk_ripple_carry_adder_2

module mk_carry_save_adder_1(Csa_ifc_1);

	Rca_ifc_1 ripple_carry_adder <- mk_ripple_carry_adder_1;

	method Bit#(32) csa_input(Bit#(32) csa_inp1, Bit#(32) csa_inp2, Bit#(32) csa_inp3);
		Bit#(32) sum = 0;
		Bit#(32) carry = 0;
		for(Integer i = 0; i < 32; i = i+1)begin
			sum[i] = (csa_inp1[i] ^ csa_inp2[i] ^ csa_inp3[i]);
			carry[i] = (csa_inp1[i] & csa_inp2[i]) | (csa_inp1[i] & csa_inp3[i]) | (csa_inp2[i] & csa_inp3[i]);
		end
		carry = carry << 1;
		Bit#(32) result = ripple_carry_adder.rca_input(sum, carry);

		return result;
	endmethod : csa_input

endmodule : mk_carry_save_adder_1



(*synthesize*)
module mk_mac_fp(Mac_int_ifc);

	Wallace_multiplier_ifc wallace_multiplier_unit <- mk_wallace_multiplier;
	Csa_ifc_1 carry_save_adder_unit <- mk_carry_save_adder_1;
	Rca_ifc_2 ripple_carry_adder_unit <- mk_ripple_carry_adder_2;
	

	//Registers
	Reg#(Bit#(16)) rg_inp_1  <- mkReg(0); // Need to later make this FIFO depth 2
	Reg#(Bit#(16)) rg_inp_2  <- mkReg(0);
	Reg#(Bit#(32)) rg_inp_3 <- mkReg(0);
	Reg#(Bit#(32)) rg_out   <- mkReg(32'b1111);
	Reg#(Bit#(1)) sign_bit   <- mkReg(0);
	Reg#(Bit#(8)) mantissa_a   <- mkReg(0);
	Reg#(Bit#(8)) mantissa_b   <- mkReg(0);
	Reg#(Bit#(8)) expo_a   <- mkReg(0);
	Reg#(Bit#(8)) expo_b   <- mkReg(0);
	Reg#(Bit#(16)) mantissa_o   <- mkReg(0);
	Reg#(Bit#(23)) mantissa_o_1   <- mkReg(0);
	Reg#(Bit#(8)) expo_o  <- mkReg(0);
	Reg#(Bit#(8)) expo_o_1  <- mkReg(0);
	
	
	Reg#(Bit#(8)) expo_after_multiplication  <- mkReg(0);
	Reg#(Bit#(23)) mantissa_after_multiplication  <- mkReg(0);
	Reg#(Bit#(8)) expo_after_multiplication_1 <- mkReg(0);
	
	Reg#(Bit#(7)) mantissa_bfloat_1 <- mkReg(0);
	
	Reg#(Bit#(49)) aligned_mantissa1 <- mkReg(0);
	Reg#(Bit#(49)) aligned_mantissa2 <- mkReg(0);
	Reg#(Bit#(8)) expo_temp <- mkReg(0);
	Reg#(Bit#(49)) mantissa_sum  <- mkReg(0);
	Reg#(Bit#(8)) expo_temp_1  <- mkReg(0);
	Reg#(Bit#(1)) sign_out <- mkReg(0);
	Reg#(Bit#(48)) mantissa_before_rounding <- mkReg(0);
	Reg#(Bit#(8)) expo_final <- mkReg(0);
	Reg#(Bit#(23)) mantissa_final <- mkReg(0);
	
	
	
	
	Reg#(Bit#(7)) mantissa_o_2  <- mkReg(0);
	
	Reg#(Bit#(1)) sign_1  <- mkReg(0);
	Reg#(Bit#(8)) expo_1  <- mkReg(0);
	Reg#(Bit#(24)) mantissa_1  <- mkReg(0);
	
	Reg#(Bit#(1)) sign_2 <- mkReg(0);
	Reg#(Bit#(8)) expo_2  <- mkReg(0);
	Reg#(Bit#(24)) mantissa_2  <- mkReg(0);
	
	Reg#(Bit#(24)) aligned_mantissa1_i  <- mkReg(0);
	Reg#(Bit#(24)) aligned_mantissa2_i  <- mkReg(0);
	
	Reg#(Bit#(24)) aligned_mantissa_1  <- mkReg(0);
	Reg#(Bit#(24)) aligned_mantissa_2  <- mkReg(0);
	Reg#(Bit#(8)) expo_diff  <- mkReg(0);
	Reg#(Bit#(8)) temp_expo  <- mkReg(0);
	
	Reg#(Bit#(25)) h <- mkReg(0);
	
	Reg#(Bit#(8)) result_expo  <- mkReg(0);
	Reg#(Bit#(24)) result_mantissa  <- mkReg(0);
	Reg#(Bit#(1)) result_sign  <- mkReg(0);
	
	Reg#(Bit#(1)) j  <- mkReg(0);
	
	Reg#(Bool) condition_1 <- mkDReg(False);
	Reg#(Bool) condition_2 <- mkDReg(False);
	Reg#(Bool) condition_3 <- mkDReg(False);
	
	
	
	function Bit#(8) findFirstOne(Bit#(49) num, Bit#(8) index );
   		if (index == 0) begin
      			return num[0] == 1 ? 0 : 49;
   		end
   		else begin
      			return num[index] == 1 ? index : findFirstOne(num, index - 1);
   		end
	endfunction

	
	
	rule output_after_multiplication(condition_1);
		
		Bit#(16) multiplier_output = wallace_multiplier_unit.wallace_output();
		
		
		//incrementing the exponent if 16th bit is 1  and normalising the mantissa
		if (multiplier_output[15] == 1) begin
		Bit#(32) input_a = zeroExtend(expo_o);
		expo_after_multiplication <=carry_save_adder_unit.csa_input(input_a,32'b1,0)[7:0];
		mantissa_after_multiplication <={multiplier_output[14:0],8'b0};
                
        	end else begin
		mantissa_after_multiplication <={multiplier_output[13:0],9'b0};
		expo_after_multiplication<=expo_o;
		end
		
		
		//converting the mantissa into bfloat format i.e 7 bit mantissa
		let mantissa_bfloat=mantissa_after_multiplication[22:16];
       
        	Bit#(32) input_a1 = zeroExtend(mantissa_bfloat);
		Bit#(32) input_b1;
		if (mantissa_after_multiplication[15:0]>=16'b1000000000000000 )begin
			if (mantissa_after_multiplication[15:0]>16'b1000000000000000) input_b1=32'b1;
			else begin
				if (mantissa_after_multiplication[16]==1) input_b1=32'b1;
				else input_b1=32'b0;
			end	
		end else begin
			input_b1 =0;
		end
		Bit#(32) y=carry_save_adder_unit.csa_input(input_a1,input_b1,0);
		
		
		
		// incrementing the exponent if rounding creates an overflow 
		Bit#(32) input_a2 = zeroExtend(expo_after_multiplication);
        	if (y[7]==1) begin
        	
        	expo_after_multiplication_1<=carry_save_adder_unit.csa_input(input_a2,32'b1,32'b0)[7:0];
        	mantissa_bfloat_1<={0,y[6:1]};
        	end else begin
        	expo_after_multiplication_1<=carry_save_adder_unit.csa_input(input_a2,32'b0,32'b0)[7:0];
        	mantissa_bfloat_1<=y[6:0];
        	end
		
		condition_2<=True;
	endrule  

        
        rule accumulation(condition_2);
        	
        	sign_1      <= sign_bit;
        	expo_1      <= expo_after_multiplication_1;
        	mantissa_1  <= {1'b1, mantissa_bfloat_1,16'b0};
        	
        	sign_2        <= rg_inp_3[31];
        	expo_2    <= rg_inp_3[30:23];
        	mantissa_2 <=(expo_2==8'b0)? {1'b0,rg_inp_3[22:0]}:{1'b1,rg_inp_3[22:0]};
        	//mantissa_2  <= {1'b1,rg_inp_3[22:0]}; 
        	
        	
        	Bit#(32) input_a = zeroExtend(expo_1);
		Bit#(32) input_b = zeroExtend(expo_2);
        	
        	if (expo_1==expo_2) begin
        	expo_diff<=8'b0;
        	
        	end else begin
        	expo_diff <= (expo_1 > expo_2) ? (carry_save_adder_unit.csa_input(input_a,negate(input_b),0)[7:0]) : (carry_save_adder_unit.csa_input(negate(input_a),input_b,0)[7:0] );
        	
        	end
        	Bit#(49) m_1={0,mantissa_1,24'b0};
        	Bit#(49) m_2={0,mantissa_2,24'b0};
        	
        	aligned_mantissa1 <= (expo_1 >= expo_2) ? m_1 : (m_1 >> expo_diff);
		aligned_mantissa2 <= (expo_2 >= expo_1) ? m_2 : (m_2 >> expo_diff);
		expo_temp<=(expo_1>=expo_2)?expo_1:expo_2;
		
		if (sign_1==sign_2) begin
			mantissa_sum<=ripple_carry_adder_unit.rca_input(aligned_mantissa1,aligned_mantissa2);
			sign_out<=sign_1;
			Bit#(8) x=findFirstOne(mantissa_sum, 48);
			if (x==48) begin 
			expo_temp_1<=carry_save_adder_unit.csa_input(zeroExtend(expo_temp),32'b1,0)[7:0];
			mantissa_before_rounding<=mantissa_sum[48:1];
			 
			
			end
			else begin 
			expo_temp_1<=expo_temp;
			mantissa_before_rounding<=mantissa_sum[47:0];
			
			
			end
        	end else begin
        		mantissa_sum<= aligned_mantissa1>aligned_mantissa2 ?ripple_carry_adder_unit.rca_input(aligned_mantissa1,negate(aligned_mantissa2)):ripple_carry_adder_unit.rca_input(aligned_mantissa2,negate(aligned_mantissa1));
        		if (aligned_mantissa1==aligned_mantissa2) sign_out<=sign_1 & sign_2;
        		else sign_out<=aligned_mantissa1>aligned_mantissa2 ? sign_1:sign_2;
        		Bit#(8) x=findFirstOne(mantissa_sum,48);
        		Bit#(32) input_c=zeroExtend(expo_temp);
        		if (x==48) begin 
        		expo_temp_1<=carry_save_adder_unit.csa_input(input_c,32'b1,0)[7:0];
        		mantissa_before_rounding<=mantissa_sum[48:1];
        		end
        		else if (x==47) begin 
        		expo_temp_1<=expo_temp;
        		mantissa_before_rounding<=mantissa_sum[47:0];
        		end
        		else begin 
        		Bit#(32) input_d=zeroExtend(47-x);
        		
        		
        		expo_temp_1<=(input_c>input_d) ? carry_save_adder_unit.csa_input(input_c,negate(input_d),0)[7:0]: 8'b0;
        		Bit#(200) n={mantissa_sum[x:0], 48'b0};
        		mantissa_before_rounding<=n[48+x:x+1];
        		
        		end
        		
        		
        	end
        	Bit#(32) input_a1 = zeroExtend(mantissa_before_rounding[47:24]);
		Bit#(32) input_b1;
		if (mantissa_before_rounding[23:0]>=24'b100000000000000000000000 )begin
			if (mantissa_before_rounding[23:0]>=24'b100000000000000000000000) input_b1=32'b1;
			else begin
				if (mantissa_before_rounding[24]==1) input_b1=32'b1;
				else input_b1=32'b0;
			end	
		end else begin
			input_b1 =0;
		end
        	
        	Bit#(32) y=carry_save_adder_unit.csa_input(input_a1,input_b1,0);
        	Bit#(32) input_a2 = zeroExtend(expo_temp_1);
        	if (y[24]==1) begin
        	
        	expo_final<=carry_save_adder_unit.csa_input(input_a2,32'b1,32'b0)[7:0];
        	mantissa_final<={y[23:1]};
        	end else begin
        	expo_final<=carry_save_adder_unit.csa_input(input_a2,32'b0,32'b0)[7:0];
        	mantissa_final<=y[22:0];
        	end
        	rg_out<={sign_out,expo_final,mantissa_final};
        		
        	
        	
        	condition_3<=True;	 
        endrule
        	
	
	method Action mac_fp_input(Bit#(16) inp_1, Bit#(16) inp_2, Bit#(32) inp_3);
		
		//saving inputs a,b,c into registers
		rg_inp_1 <= inp_1;
		rg_inp_2 <= inp_2;
		rg_inp_3 <= inp_3;
		
		//extracting mantissas , exponents and sign bits
		Bit#(1) signbit_1 = inp_1[15];
		Bit#(1) signbit_2 = inp_2[15];
		expo_a <=inp_1[14:7];
        	expo_b <=inp_2[14:7];
        	
		mantissa_a <=(expo_a==8'b0)? {1'b0,inp_1[6:0]}:{1'b1,inp_1[6:0]};
		mantissa_b <=(expo_b==8'b0)? {1'b0,inp_2[6:0]}:{1'b1,inp_2[6:0]};
        	
        	
        	// signbit after multiplication
        	Bit#(1) signbit_o = signbit_1 ^ signbit_2;
		sign_bit <=signbit_o;
		
        	//giving inputs to the wallace multiplier
        	wallace_multiplier_unit.wallace_input(mantissa_a,mantissa_b);
        	
        	//adding the exponents
        	Bit#(32) input_a = zeroExtend(inp_1[14:7]);
		Bit#(32) input_b = zeroExtend(inp_2[14:7]);
		//Bit#(32) input_c=(carry_save_adder_unit.csa_input(input_a,input_b,0)>=127)?32'b10000001:32'b0;
        	expo_o <=(carry_save_adder_unit.csa_input(input_a,input_b,0)<127)?8'b0 :carry_save_adder_unit.csa_input(input_a,input_b,32'b10000001)[7:0];
        	
		condition_1 <= True;
	endmethod  

	method Bit#(32) mac_fp_output() if(condition_3);
		Bit#(32) a=zeroExtend(expo_a);
		Bit#(32) b=zeroExtend(expo_b);
		
		if (carry_save_adder_unit.csa_input(a,b,0)<=127) begin
		return rg_inp_3;
		end else if (expo_a==8'b0 || expo_b==8'b0) begin
		return rg_inp_3;
		end else  if (rg_inp_1==16'b0 || rg_inp_2==16'b0)begin
		return rg_inp_3;
		end else begin
		return rg_out;
		end
		//return {expo_o,24'b0};
		
		//return 32'b1 ;
	endmethod  
endmodule : mk_mac_fp
endpackage : mac_fp32









        
        
        
      
