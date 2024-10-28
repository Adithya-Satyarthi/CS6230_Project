package mac_fp32;

typedef struct {Bit#(1) sum;
		Bit#(1) cout;} Adder_output deriving(Bits, Eq); 
typedef struct {Bit#(16) out1;
		Bit#(16) out2;}  Wm_output deriving(Bits, Eq);

import FIFO :: *;
import DReg :: *;

interface Mac_int_ifc;
	method Action mac_fp_input(Bit#(16) inp_1, Bit#(16) inp_2, Bit#(32) inp_3);
	method Bit#(32) mac_fp_output();
endinterface : Mac_int_ifc

interface Csa_ifc;
	method Action csa_input(Bit#(32) csa_inp1, Bit#(32) csa_inp2, Bit#(32) csa_inp3);
	method Bit#(32) csa_output();
endinterface : Csa_ifc

interface Rca_ifc;
	method Action rca_input(Bit#(32) rca_inp1, Bit#(32) rca_inp2);
	method Bit#(32) rca_output();
endinterface : Rca_ifc

interface Wallace_multiplier_ifc;
	method Action wallace_input(Bit#(8) wm_inp1, Bit#(8) wm_inp2);
	method Bit#(16) wallace_output();
endinterface : Wallace_multiplier_ifc


module mk_wallace_multiplier(Wallace_multiplier_ifc);

	Csa_ifc csa_unit <- mk_carry_save_adder;
	
	//Debugging
	Reg#(Bit#(16)) treg <- mkReg(0);
	

	//Partial Product Registers
	Reg#(Bit#(8)) rg_p00 <- mkReg(8'b0);
	Reg#(Bit#(8)) rg_p01 <- mkReg(8'b0);
	Reg#(Bit#(8)) rg_p02 <- mkReg(8'b0);
	Reg#(Bit#(8)) rg_p03 <- mkReg(8'b0);
	Reg#(Bit#(8)) rg_p04 <- mkReg(8'b0);
	Reg#(Bit#(8)) rg_p05 <- mkReg(8'b0);
	Reg#(Bit#(8)) rg_p06 <- mkReg(8'b0);
	Reg#(Bit#(8)) rg_p07 <- mkReg(8'b0);
	Reg#(Bool) pp_ready <- mkDReg(False);

	//Level 1 Registers
	Reg#(Bit#(15)) rg_p10  <- mkReg(15'b0);
	Reg#(Bit#(13)) rg_p11  <- mkReg(13'b0);
	Reg#(Bit#(9)) rg_p12   <- mkReg(9'b0);
	Reg#(Bit#(7)) rg_p13   <- mkReg(7'b0);
	Reg#(Bit#(3)) rg_p14   <- mkReg(3'b0);
	Reg#(Bit#(1)) rg_p15   <- mkReg(1'b0);
	Reg#(Bool) lvl1_ready <- mkDReg(False);

	//Level 2 Registers
	Reg#(Bit#(16)) rg_p20  <- mkReg(16'b0);
	Reg#(Bit#(12)) rg_p21  <- mkReg(12'b0);
	Reg#(Bit#(7)) rg_p22   <- mkReg(7'b0);
	Reg#(Bit#(3)) rg_p23   <- mkReg(3'b0);
	Reg#(Bool) lvl2_ready <- mkDReg(False);

	//Level 3 Registers
	Reg#(Bit#(16)) rg_p30  <- mkReg(16'b0);
	Reg#(Bit#(12)) rg_p31  <- mkReg(12'b0);
	Reg#(Bit#(3)) rg_p32   <- mkReg(3'b0);
	Reg#(Bool) lvl3_ready <- mkDReg(False);

	//Level 4 Registers
	Reg#(Bit#(16)) rg_p40  <- mkReg(0);
	Reg#(Bit#(16)) rg_p41  <- mkReg(0);
	Reg#(Bit#(16)) result <- mkReg(unpack(0));
	Reg#(Bool) lvl4_ready <- mkDReg(False);
	Reg#(Bool) out_ready <- mkDReg(False);
	


	function Adder_output half_adder(Bit#(1) ha_inp1, Bit#(1) ha_inp2);
		Bit#(1) ha_sum  = ha_inp1 ^ ha_inp2;
		Bit#(1) ha_cout = ha_inp1 & ha_inp2;
		Adder_output ha_out = Adder_output{sum: ha_sum, cout: ha_cout};
		return ha_out;
	endfunction : half_adder
	
	function Adder_output full_adder(Bit#(1) f_inp1, Bit#(1) f_inp2, Bit#(1) f_cin);
		Bit#(1) f_sum  = f_inp1 ^ f_inp2 ^ f_cin;
		Bit#(1) f_cout = (f_inp1 & f_inp2) | (f_inp1 & f_cin) | (f_inp2 & f_cin);
		Adder_output f_out = Adder_output{sum: f_sum, cout: f_cout};
		return f_out;
	endfunction : full_adder
	

	rule level_1(pp_ready);
	
		Bit#(15) w10 = 0;
		Bit#(13) w11 = 0;
		Bit#(9) w12 = 0;
		Bit#(7) w13 = 0;
		Bit#(3) w14 = 0;
		Bit#(1) w15 = 0;
		
		w10[0] = rg_p00[0];
		let half_adder1 = half_adder(rg_p00[1], rg_p01[0]);
		w10[1] = half_adder1.sum;
		w10[2] = half_adder1.cout;
		let full_adder1 = full_adder(rg_p00[2], rg_p01[1], rg_p02[0]);
		w11[0] = full_adder1.sum;
		w10[3] = full_adder1.cout;
		let full_adder2 = full_adder(rg_p00[3], rg_p01[2], rg_p02[1]);
		w11[1] = full_adder2.sum;
		w10[4] = full_adder2.cout;
		w12[0] = rg_p03[0];
		let full_adder3 = full_adder(rg_p00[4], rg_p01[3], rg_p02[2]);
		w11[2] = full_adder3.sum;
		w10[5] = full_adder3.cout;
		let half_adder2 = half_adder(rg_p03[1], rg_p04[0]);
		w12[1] = half_adder2.sum;
		w11[3] = half_adder2.cout;
		let full_adder4 = full_adder(rg_p00[5], rg_p01[4], rg_p02[3]);
		w12[2] = full_adder4.sum;
		w10[6] = full_adder4.cout;
		let full_adder5 = full_adder(rg_p03[2], rg_p04[1], rg_p05[0]);
		w13[0] = full_adder5.sum;
		w11[4] = full_adder5.cout;
		let full_adder6 = full_adder(rg_p00[6], rg_p01[5], rg_p02[4]);
		w12[3] = full_adder6.sum;
		w10[7] = full_adder6.cout;
		let full_adder7 = full_adder(rg_p03[3], rg_p04[2], rg_p05[1]);
		w13[1] = full_adder7.sum;
		w11[5] = full_adder7.cout;
		w14[0] = rg_p06[0];
		let full_adder8 = full_adder(rg_p00[7], rg_p01[6], rg_p02[5]);
		w12[4] = full_adder8.sum;
		w10[8] = full_adder8.cout;
		let full_adder9 = full_adder(rg_p03[4], rg_p04[3], rg_p05[2]);
		w13[2] = full_adder9.sum;
		w11[6] = full_adder9.cout;
		let half_adder3 = half_adder(rg_p06[1], rg_p07[0]);
		w14[1] = half_adder3.sum;
		w12[5] = half_adder3.cout;		
		let full_adder10 = full_adder(rg_p01[7], rg_p02[6], rg_p03[5]);
		w13[3] = full_adder10.sum;
		w10[9] = full_adder10.cout;
		let full_adder11 = full_adder(rg_p04[4], rg_p05[3], rg_p06[2]);
		w14[2] = full_adder11.sum;
		w11[7] = full_adder11.cout;
		w15    = rg_p07[1];
		let full_adder12 = full_adder(rg_p02[7], rg_p03[6], rg_p04[5]);
		w12[6] = full_adder12.sum;
		w10[10] = full_adder12.cout;
		let full_adder13 = full_adder(rg_p05[4], rg_p06[3], rg_p07[2]);
		w13[4] = full_adder13.sum;
		w11[8] = full_adder13.cout;
		let full_adder14 = full_adder(rg_p03[7], rg_p04[6], rg_p05[5]);
		w12[7] = full_adder14.sum;
		w10[11] = full_adder14.cout;
		let half_adder4 = half_adder(rg_p06[4], rg_p07[3]);
		w13[5] = half_adder4.sum;
		w11[9] = half_adder4.cout;
		let full_adder15 = full_adder(rg_p04[7], rg_p05[6], rg_p06[5]);
		w12[8] = full_adder15.sum;
		w10[12] = full_adder15.cout;
		w13[6] = rg_p07[4];
		let full_adder16 = full_adder(rg_p05[7], rg_p06[6], rg_p07[5]);
		w11[10] = full_adder16.sum;
		w10[13] = full_adder16.cout;
		let half_adder5 = half_adder(rg_p06[7], rg_p07[6]);
		w11[11] = half_adder5.sum;
		w10[14] = half_adder5.cout;
		w11[12] = rg_p07[7];
		
		rg_p10 <= w10;
		rg_p11 <= w11;
		rg_p12 <= w12;
		rg_p13 <= w13;
		rg_p14 <= w14;
		rg_p15 <= w15;
		lvl1_ready <= True;

	endrule : level_1		

	rule level_2(lvl1_ready);
	
		Bit#(16) w20 = 0; 
		Bit#(12) w21 = 0; 
		Bit#(7) w22 = 0; 
		Bit#(3) w23 = 0;   
	
		w20[0] = rg_p10[0];
		w20[1] = rg_p10[1];
		let half_adder1 = half_adder(rg_p10[2], rg_p11[0]);
		w20[2] = half_adder1.sum;
		w20[3] = half_adder1.cout;
		let full_adder1 = full_adder(rg_p10[3], rg_p11[1], rg_p12[0]);
		w21[0] = full_adder1.sum;
		w20[4] = full_adder1.cout;
		let full_adder2 = full_adder(rg_p10[4], rg_p11[2], rg_p12[1]);
		w21[1] = full_adder2.sum;
		w20[5] = full_adder2.cout;
		let full_adder3 = full_adder(rg_p10[5], rg_p11[3], rg_p12[2]);
		w21[2] = full_adder3.sum;
		w20[6] = full_adder3.cout;
		w22[0] = rg_p13[0];
		let full_adder4 = full_adder(rg_p10[6], rg_p11[4], rg_p12[3]);
		w21[3] = full_adder4.sum;
		w20[7] = full_adder4.cout;
		let half_adder2 = half_adder(rg_p13[1], rg_p14[0]);
		w22[1] = half_adder2.sum;
		w21[4] = half_adder2.cout;
		let full_adder5 = full_adder(rg_p10[7], rg_p11[5], rg_p12[4]);
		w22[2] = full_adder5.sum;
		w20[8] = full_adder5.cout;
		let half_adder3 = half_adder(rg_p13[2], rg_p14[1]);
		w23[0] = half_adder3.sum;
		w21[5] = half_adder3.cout;
		let full_adder6 = full_adder(rg_p10[8], rg_p11[6], rg_p12[5]);
		w22[3] = full_adder6.sum;
		w20[9] = full_adder6.cout;
		let full_adder7 = full_adder(rg_p13[3], rg_p14[2], rg_p15);
		w23[1] = full_adder7.sum;
		w21[6] = full_adder7.cout;
		let full_adder8 = full_adder(rg_p10[9], rg_p11[7], rg_p12[6]);
		w22[4] = full_adder8.sum;
		w20[10] = full_adder8.cout;
		w23[2] = rg_p13[4];
		let full_adder9 = full_adder(rg_p10[10], rg_p11[8], rg_p12[7]);
		w21[7] = full_adder9.sum;
		w20[11] = full_adder9.cout;
		w22[5] = rg_p13[5];
		let full_adder10 = full_adder(rg_p10[11], rg_p11[9], rg_p12[8]);
		w21[8] = full_adder10.sum;
		w20[12] = full_adder10.cout;
		w22[6] = rg_p13[6];
		let half_adder4 = half_adder(rg_p10[12], rg_p11[10]);
		w21[9] = half_adder4.sum;
		w20[13] = half_adder4.cout;
		let half_adder5 = half_adder(rg_p10[13], rg_p11[11]);
		w21[10] = half_adder5.sum;
		w20[14] = half_adder5.cout;
		let half_adder6 = half_adder(rg_p10[14], rg_p11[12]);
		w21[11] = half_adder6.sum;
		w20[15] = half_adder6.cout;
		
		rg_p20 <= w20;
		rg_p21 <= w21;
		rg_p22 <= w22;
		rg_p23 <= w23;
		lvl2_ready <= True;
		
	endrule : level_2

	rule level_3(lvl2_ready);
	
		Bit#(16) w30 = 0;
		Bit#(12) w31 = 0;
		Bit#(3) w32 = 0;

		w30[0] = rg_p20[0];
		w30[1] = rg_p20[1];
		w30[2] = rg_p20[2];
		let half_adder1 = half_adder(rg_p20[3], rg_p21[0]);
		w30[3] = half_adder1.sum;
		w30[4] = half_adder1.cout;		
		let half_adder2 = half_adder(rg_p20[4], rg_p21[1]);
		w31[0] = half_adder2.sum;
		w30[5] = half_adder2.cout;
		let full_adder1 = full_adder(rg_p20[5], rg_p21[2], rg_p22[0]);
		w31[1] = full_adder1.sum;
		w30[6] = full_adder1.cout;
		let full_adder2 = full_adder(rg_p20[6], rg_p21[3], rg_p22[1]);
		w31[2] = full_adder2.sum;
		w30[7] = full_adder2.cout;
		let full_adder3 = full_adder(rg_p20[7], rg_p21[4], rg_p22[2]);
		w31[3] = full_adder3.sum;
		w30[8] = full_adder3.cout;
		w32[0] = rg_p23[0];
		let full_adder4 = full_adder(rg_p20[8], rg_p21[5], rg_p22[3]);
		w31[4] = full_adder4.sum;
		w30[9] = full_adder4.cout;
		w32[1] = rg_p23[1];
		let full_adder5 = full_adder(rg_p20[9], rg_p21[6], rg_p22[4]);
		w31[5] = full_adder5.sum;
		w30[10] = full_adder5.cout;
		w32[2] = rg_p23[2];
		let full_adder6 = full_adder(rg_p20[10], rg_p21[7], rg_p22[5]);
		w31[6] = full_adder6.sum;
		w30[11] = full_adder6.cout;
		let full_adder7 = full_adder(rg_p20[11], rg_p21[8], rg_p22[6]);
		w31[7] = full_adder7.sum;
		w30[12] = full_adder7.cout;
		let half_adder3 = half_adder(rg_p20[12], rg_p21[9]);
		w31[8] = half_adder3.sum;
		w30[13] = half_adder3.cout;
		let half_adder4 = half_adder(rg_p20[13], rg_p21[10]);
		w31[9] = half_adder4.sum;
		w30[14] = half_adder4.cout;
		let half_adder5 = half_adder(rg_p20[14], rg_p21[11]);
		w31[10] = half_adder5.sum;
		w30[15] = half_adder5.cout;
		w31[11] = rg_p20[15];
		
		rg_p30 <= w30;
		rg_p31 <= w31;
		rg_p32 <= w32;		
		lvl3_ready <= True;
	
	endrule : level_3

	rule level_4 (lvl3_ready);
	
		Bit#(16) w40 = 0;
		Bit#(16) w41 = 0;
	
		w40[0] = rg_p30[0];
		w40[1] = rg_p30[1];
		w40[2] = rg_p30[2];
		w40[3] = rg_p30[3];
		let half_adder1 = half_adder(rg_p30[4], rg_p31[0]);
		w40[4] = half_adder1.sum;
		w40[5] = half_adder1.cout;		
		let half_adder2 = half_adder(rg_p30[5], rg_p31[1]);
		w41[5] = half_adder2.sum;
		w40[6] = half_adder2.cout;
		let half_adder3 = half_adder(rg_p30[6], rg_p31[2]);
		w41[6] = half_adder3.sum;
		w40[7] = half_adder3.cout;
		let full_adder1 = full_adder(rg_p30[7], rg_p31[3], rg_p32[0]);
		w41[7] = full_adder1.sum;
		w40[8] = full_adder1.cout;
		let full_adder2 = full_adder(rg_p30[8], rg_p31[4], rg_p32[1]);
		w41[8] = full_adder2.sum;
		w40[9] = full_adder2.cout;
		let full_adder3 = full_adder(rg_p30[9], rg_p31[5], rg_p32[2]);
		w41[9] = full_adder3.sum;
		w40[10] = full_adder3.cout;
		let half_adder4 = half_adder(rg_p30[10], rg_p31[6]);
		w41[10] = half_adder4.sum;
		w40[11] = half_adder4.cout;
		let half_adder5 = half_adder(rg_p30[11], rg_p31[7]);
		w41[11] = half_adder5.sum;
		w40[12] = half_adder5.cout;
		let half_adder6 = half_adder(rg_p30[12], rg_p31[8]);
		w41[12] = half_adder6.sum;
		w40[13] = half_adder6.cout;
		let half_adder7 = half_adder(rg_p30[13], rg_p31[9]);
		w41[13] = half_adder7.sum;
		w40[14] = half_adder7.cout;
		let half_adder8 = half_adder(rg_p30[14], rg_p31[10]);
		w41[14] = half_adder8.sum;
		w40[15] = half_adder8.cout;
		let half_adder9 = half_adder(rg_p30[15], rg_p31[11]);
		w41[15] = half_adder9.sum;
		//rg_p41[16] <= half_adder(rg_p30[15], rg_p31[11]).cout;
		
		csa_unit.csa_input(signExtend(w40), signExtend(w41), signExtend(32'b0));
		rg_p40 <= w40;
		rg_p41 <= w41;
		lvl4_ready <= True;		

	endrule : level_4
	
	rule endresult(lvl4_ready);
	
		let temp = csa_unit.csa_output();
		result <= truncate(temp);
		out_ready <= True;
		
	endrule : endresult

	method Action wallace_input(Bit#(8) wm_inp1, Bit#(8) wm_inp2);
		
		rg_p00 <= (wm_inp1 & {wm_inp2[0], wm_inp2[0], wm_inp2[0], wm_inp2[0], wm_inp2[0], wm_inp2[0], wm_inp2[0], wm_inp2[0]});
		rg_p01 <= (wm_inp1 & {wm_inp2[1], wm_inp2[1], wm_inp2[1], wm_inp2[1], wm_inp2[1], wm_inp2[1], wm_inp2[1], wm_inp2[1]});
		rg_p02 <= (wm_inp1 & {wm_inp2[2], wm_inp2[2], wm_inp2[2], wm_inp2[2], wm_inp2[2], wm_inp2[2], wm_inp2[2], wm_inp2[2]});
		rg_p03 <= (wm_inp1 & {wm_inp2[3], wm_inp2[3], wm_inp2[3], wm_inp2[3], wm_inp2[3], wm_inp2[3], wm_inp2[3], wm_inp2[3]});
		rg_p04 <= (wm_inp1 & {wm_inp2[4], wm_inp2[4], wm_inp2[4], wm_inp2[4], wm_inp2[4], wm_inp2[4], wm_inp2[4], wm_inp2[4]});
		rg_p05 <= (wm_inp1 & {wm_inp2[5], wm_inp2[5], wm_inp2[5], wm_inp2[5], wm_inp2[5], wm_inp2[5], wm_inp2[5], wm_inp2[5]});
		rg_p06 <= (wm_inp1 & {wm_inp2[6], wm_inp2[6], wm_inp2[6], wm_inp2[6], wm_inp2[6], wm_inp2[6], wm_inp2[6], wm_inp2[6]});
		rg_p07 <= (wm_inp1 & {wm_inp2[7], wm_inp2[7], wm_inp2[7], wm_inp2[7], wm_inp2[7], wm_inp2[7], wm_inp2[7], wm_inp2[7]});
		pp_ready <= True;
	endmethod : wallace_input
	method Bit#(16) wallace_output() if(out_ready);
		return result;
	endmethod : wallace_output
endmodule : mk_wallace_multiplier



module mk_ripple_carry_adder(Rca_ifc);
	Reg#(Bit#(32)) rg_inp1 <- mkReg(0);
	Reg#(Bit#(32)) rg_inp2 <- mkReg(0);
	Reg#(Bit#(32)) rg_out  <- mkReg(0);
	Reg#(Bool)  input_ready <- mkDReg(False);
	Reg#(Bool)  output_ready <- mkDReg(False);

	rule addition(input_ready);
		Bit#(32) sum   = 0;
		Bit#(33) carry = 0;
		for(Integer i = 0; i < 32; i = i + 1)begin
			sum[i] = rg_inp1[i] ^ rg_inp2[i] ^ carry[i];
			carry[i+1] = (rg_inp1[i] & rg_inp2[i]) | (rg_inp1[i] & carry[i]) | (rg_inp2[i] & carry[i]);
		end
		rg_out <= sum;
		output_ready <= True;
	endrule : addition
	
	method Action rca_input(Bit#(32) rca_inp1, Bit#(32) rca_inp2);
		rg_inp1 <= rca_inp1;
		rg_inp2 <= rca_inp2;
		input_ready <= True;
	endmethod : rca_input
	method Bit#(32) rca_output() if(output_ready);
		return rg_out;
	endmethod : rca_output
endmodule : mk_ripple_carry_adder


module mk_carry_save_adder(Csa_ifc);
		
	Rca_ifc ripple_carry_adder <- mk_ripple_carry_adder;

	Reg#(Bit#(32)) rg_inp1 <- mkReg(0);
	Reg#(Bit#(32)) rg_inp2 <- mkReg(0);
	Reg#(Bit#(32)) rg_inp3 <- mkReg(0);
	Reg#(Bit#(32)) rg_out  <- mkReg(0);
	Reg#(Bool)  input_ready <- mkDReg(False);
	Reg#(Bool)  output_ready <- mkDReg(False);
	Reg#(Bool)  cal_ready <- mkDReg(False);
		
	rule calculation(input_ready);
		Bit#(32) sum = 0;
		Bit#(32) carry = 0;
		for(Integer i = 0; i < 32; i = i+1)begin
			sum[i] = (rg_inp1[i] ^ rg_inp2[i] ^ rg_inp3[i]);
			carry[i] = (rg_inp1[i] & rg_inp2[i]) | (rg_inp1[i] & rg_inp3[i]) | (rg_inp2[i] & rg_inp3[i]);
		end
		carry = carry << 1;
		ripple_carry_adder.rca_input(sum, carry);
		cal_ready <= True;
	endrule : calculation
	rule result(cal_ready);
		rg_out <= ripple_carry_adder.rca_output();
		output_ready <= True;
	endrule : result

	method Action csa_input(Bit#(32) csa_inp1, Bit#(32) csa_inp2, Bit#(32) csa_inp3);
		rg_inp1 <= csa_inp1;
		rg_inp2 <= csa_inp2;
		rg_inp3 <= csa_inp3;
		input_ready <= True;
	endmethod : csa_input
	method Bit#(32) csa_output() if(output_ready);
		return rg_out;
	endmethod : csa_output

endmodule : mk_carry_save_adder

(*synthesize*)
module mk_mac_fp(Mac_int_ifc);

	Wallace_multiplier_ifc wallace_multiplier_unit <- mk_wallace_multiplier;
	Csa_ifc carry_save_adder_unit_1 <- mk_carry_save_adder;
	Csa_ifc carry_save_adder_unit_2 <- mk_carry_save_adder;
	Csa_ifc carry_save_adder_unit_3 <- mk_carry_save_adder;
	Csa_ifc carry_save_adder_unit_4 <- mk_carry_save_adder;
	Csa_ifc carry_save_adder_unit_5 <- mk_carry_save_adder;
	Csa_ifc carry_save_adder_unit_6 <- mk_carry_save_adder;
	Csa_ifc carry_save_adder_unit_7 <- mk_carry_save_adder;
	Csa_ifc carry_save_adder_unit_8 <- mk_carry_save_adder;
	Csa_ifc carry_save_adder_unit_9 <- mk_carry_save_adder;
	Csa_ifc carry_save_adder_unit_10 <- mk_carry_save_adder;
	Csa_ifc carry_save_adder_unit_11 <- mk_carry_save_adder;
	Csa_ifc carry_save_adder_unit_12 <- mk_carry_save_adder;

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
	Reg#(Bool) condition_4 <- mkDReg(False);
	Reg#(Bool) condition_5 <- mkDReg(False);
	Reg#(Bool) condition_6 <- mkDReg(False);
	Reg#(Bool) condition_7 <- mkDReg(False);
	Reg#(Bool) condition_8 <- mkDReg(False);
	Reg#(Bool) condition_9 <- mkDReg(False);
	Reg#(Bool) condition_10 <- mkDReg(False);
	Reg#(Bool) condition_11 <- mkDReg(False);
	Reg#(Bool) condition_12 <- mkDReg(False);
	
	
	
	
	rule initialization(condition_1);
		Bit#(1) signbit_1 = rg_inp_1[15];
		Bit#(1) signbit_2 = rg_inp_2[15];
		Bit#(1) signbit_o = signbit_1 ^ signbit_2;
		sign_bit <=signbit_o;
		mantissa_a <= {1'b1,rg_inp_1[6:0]};
        	mantissa_b <= {1'b1,rg_inp_2[6:0]};
        	expo_a <=rg_inp_1[14:7];
        	expo_b <=rg_inp_2[14:7];
        	condition_2<=True;
        	
        endrule

	

	rule wallace_multiplication_mantissa_expo_addition(condition_2);
		
		Bit#(32) input_a = zeroExtend(expo_a);
		Bit#(32) input_b = zeroExtend(expo_b);
		wallace_multiplier_unit.wallace_input(mantissa_a, mantissa_b);
		Bit#(32) input_c=(expo_a==8'b0||expo_b==8'b0)?32'b0:32'b10000001;
		
		
		carry_save_adder_unit_1.csa_input(input_a,input_b,input_c);
		condition_3<= True;
	endrule  

	rule mantissa_output_expo_addition_output(condition_3);
		
		Bit#(16) mantissa_output = (expo_a==8'b0||expo_b==8'b0)?16'b0 : wallace_multiplier_unit.wallace_output();
		
		//carry_save_adder_unit.csa_input(input_1, input_2, 0);
		mantissa_o <=mantissa_output;
		expo_o <= carry_save_adder_unit_1.csa_output()[7:0];
		condition_4<=True;
	endrule  

	rule expo_increment(condition_4);
		Bit#(32) input_a = zeroExtend(expo_o);
		
	
	
		//mantissa_o <= carry_save_adder_unit.csa_output()[15:0];//only last 16 bits
		if (mantissa_o[15] == 1) begin
		carry_save_adder_unit_2.csa_input(input_a,32'b1,0);
		Bit#(23) x={mantissa_o[14:0],8'b0};
		//need to add one here
		
		mantissa_o_1 <=x;
                //expo_output_initial = expo_output_initial + 1;
        	end else begin
        	Bit#(23) x={mantissa_o[13:0],9'b0};
		mantissa_o_1 <=x;
		carry_save_adder_unit_2.csa_input(input_a,32'b0,0);
		end
        	
        	
		condition_5 <=True;
		
	endrule 
	
	rule final_output_after_multiplication(condition_5);
		
		Bit#(8) x=carry_save_adder_unit_2.csa_output()[7:0];
		
		expo_o_1 <=x;
                //expo_output_initial = expo_output_initial + 1;
        	
        	
        	
        	
        	let mantissa_bfloat=mantissa_o_1[22:16];
        	
        	
        	Bit#(32) input_a = zeroExtend(mantissa_bfloat);
		Bit#(32) input_b ;
		if (mantissa_o_1[15:0]>=16'b1000000000000000 )begin
			if (mantissa_o_1[15:0]>16'b1000000000000000) input_b=32'b1;
			else begin
				if (mantissa_o_1[16]==1) input_b=32'b1;
				else input_b=32'b0;
			end
			
		end else begin
			input_b =0;
		
		end
		//if (mantissa_o[15]==1)begin
        	carry_save_adder_unit_9.csa_input(input_a,input_b,32'b0);
        	//end else begin
        	//carry_save_adder_unit_9.csa_input(input_a,0,32'b0);
        	//end
        	condition_6<=True;
        	
        endrule
        rule rounding_1(condition_6);
        	Bit#(32) y=carry_save_adder_unit_9.csa_output();
        	//Bit#(32) y=(mantissa_o[15]==1) ? carry_save_adder_unit_9.csa_output(): {25'b0,mantissa_o_1[22:16]};
        	Bit#(32) input_a = zeroExtend(expo_o_1);
        	if (y[7]==1) begin
        	
        	carry_save_adder_unit_10.csa_input(input_a,32'b1,32'b0);
        	mantissa_o_2<={0,y[6:1]};
        	end else begin
        	carry_save_adder_unit_10.csa_input(input_a,32'b0,32'b0);
        	mantissa_o_2<=y[6:0];
        	end
        	
        	condition_7<=True;
        endrule
        
        rule after_round(condition_7);
        	
        	
        	
        	
		let z=carry_save_adder_unit_10.csa_output()[7:0];
        	
        	
        
    
    
        	sign_1      <= sign_bit;
        	expo_1      <= z;
        	mantissa_1  <= {1'b1, mantissa_o_2,16'b0};
        	
        	sign_2        <= rg_inp_3[31];
        	expo_2    <= rg_inp_3[30:23];
        	mantissa_2  <= {1'b1,rg_inp_3[22:0]}; 
        	
        	Bit#(32) input_a = zeroExtend(expo_1);
		Bit#(32) input_b = zeroExtend(expo_2);
		carry_save_adder_unit_3.csa_input(input_a,negate(input_b),0);
		carry_save_adder_unit_4.csa_input(negate(input_a),input_b,0);
        	
        	
        	
        	condition_8<=True;
        	
        	
        	 
        endrule
        
        
        rule difference_calc(condition_8);
        	Bit#(8) expo_dif=0;
        	if (expo_1==expo_2) begin
        	expo_diff<=8'b0;
        	expo_dif =8'b0;
        	end else begin
        	expo_diff <= (expo_1 > expo_2) ? (carry_save_adder_unit_3.csa_output()[7:0]) : (carry_save_adder_unit_4.csa_output()[7:0] );
        	expo_dif = (expo_1 > expo_2) ? (carry_save_adder_unit_3.csa_output()[7:0]) : (carry_save_adder_unit_4.csa_output()[7:0] );
        	end
        	
        	
        	
        	Bit#(24) mantissa_align=(expo_1>expo_2) ? mantissa_2 :mantissa_1 ;
        	Bit#(24) mantissa_n_align=(expo_1>expo_2) ? mantissa_1 :mantissa_2 ;
        	Bit#(24) n=0;
        	n[expo_dif-1]=1;
        	Bit#(1) k=0 ;
		if (expo_dif>24  || expo_dif==0)begin
		k=0;
		end else begin
			if (mantissa_align[expo_dif-1:0]>=n) begin
				if (mantissa_align[expo_dif-1:0]==n) begin
					if (mantissa_align[expo_dif]==1) k=1;
					else begin
						if (mantissa_n_align[0]==1) k=1;
						else k=0 ;
					end
				end else begin
				k=1;
				end
			end else begin
			k=0;
			end
			
					
		end
        	j<=k;
        	
		aligned_mantissa1_i <= (expo_1 >= expo_2) ? mantissa_1 : (mantissa_1 >> expo_diff);
		aligned_mantissa2_i <= (expo_2 >= expo_1) ? mantissa_2 : (mantissa_2 >> expo_diff);
		
		Bit#(32) input_a = zeroExtend(aligned_mantissa1_i);
		Bit#(32) input_b = zeroExtend(aligned_mantissa2_i);
		if (expo_1>expo_2) begin
		carry_save_adder_unit_11.csa_input(input_b,{31'b0,k},0);
		end else begin
		carry_save_adder_unit_11.csa_input(input_a,{31'b0,k},0);
		end
		
		condition_9<=True;
	endrule
	
	rule after_aligning(condition_9);
		Bit#(24) aligned_mantissa1 = (expo_1 >= expo_2) ? aligned_mantissa1_i: carry_save_adder_unit_11.csa_output()[23:0];
		Bit#(24) aligned_mantissa2 = (expo_2 >= expo_1) ? aligned_mantissa2_i: carry_save_adder_unit_11.csa_output()[23:0];
		
		
		
		Bit#(8) temp_result_exponent = (expo_1 >= expo_2) ? expo_1 : expo_2;
		
		
		
		Bit#(32) input_a = zeroExtend(aligned_mantissa1);
		Bit#(32) input_b = zeroExtend(aligned_mantissa2);
		
		
		carry_save_adder_unit_5.csa_input(input_a,input_b,0);
		carry_save_adder_unit_6.csa_input(input_a,negate(input_b),0);
		carry_save_adder_unit_7.csa_input(negate(input_a),input_b,0);
		aligned_mantissa_1<=aligned_mantissa1;
		aligned_mantissa_2<=aligned_mantissa2;
		
		result_sign<=(aligned_mantissa_1 > aligned_mantissa_2) ? sign_1 : sign_2;
		temp_expo <=temp_result_exponent;
		condition_10 <=True;
	
	
	
        endrule
        rule mantissa_addition(condition_10);
		Bit#(25) mantissa_sum=25'b0;
		if (sign_1 == sign_2) begin
		    mantissa_sum = carry_save_adder_unit_5.csa_output()[24:0];
		end else begin
		    mantissa_sum = (aligned_mantissa_1 > aligned_mantissa_2) ? 
		                   (carry_save_adder_unit_6.csa_output()[24:0]) : 
		                   (carry_save_adder_unit_7.csa_output()[24:0]);
		                   
		                   
		 
        	end
        	h<=mantissa_sum;
        	Bit#(32) input_a = zeroExtend(temp_expo);
        	if (mantissa_sum[24] == 1) begin
        	
        	Bit#(24) ans={23'b0, (mantissa_sum[0]&mantissa_sum[1])};
            	//result_mantissa <= mantissa_sum[24:1]+ans;
            	Bit#(32) input_b = zeroExtend(ans);
            	Bit#(32) input_c = zeroExtend(mantissa_sum[24:1]);
            	
            	carry_save_adder_unit_8.csa_input(input_a,32'b1,0);
            	carry_save_adder_unit_12.csa_input(input_b,input_c,0);
            	//result_exponent = temp_result_exponent + 1;
        	end else begin
            	//result_mantissa <= mantissa_sum[23:0];
            	Bit#(32) input_c = zeroExtend(mantissa_sum[23:0]);
            	
            	carry_save_adder_unit_8.csa_input(input_a,32'b0,0);
            	carry_save_adder_unit_12.csa_input(0,input_c,0);
            	//result_exponent = temp_result_exponent;
        	end
        	
        	condition_11<=True;
        endrule
        
        
        rule final_output(condition_11);
        	result_expo<=carry_save_adder_unit_8.csa_output()[7:0];
        	Bit#(24) result_mantissa=carry_save_adder_unit_12.csa_output()[23:0];
        	if (rg_inp_3[30:0] !=31'b0) begin
        	rg_out<=(expo_a==8'b0||expo_b==8'b0)? rg_inp_3:{result_sign, result_expo, result_mantissa[22:0]};
        	end else begin
        	rg_out<=(expo_a==8'b0||expo_b==8'b0)?rg_inp_3:{sign_1,expo_1,mantissa_1[22:0]};
        	end
        	//rg_out<={h,7'b0};
        	
        	//rg_out<={sign_bit, expo_o, mantissa_o_1};
        	//rg_out<={sign_1, expo_1, mantissa_o_2,16'b0};
        	//rg_out<={32'b1};
        	//rg_out<={mantissa_a, mantissa_b, mantissa_o};
        	//rg_out<={rg_inp_1,16'b11111};
        	//rg_out<={j,31'b0};
        	//rg_out<={25'b0 , mantissa_o_2};
        	
        	condition_12 <= True;
        endrule
        	
        	
        	
        	
        

        	
         
        
		
	
	
	
		
	
	
	
	
	
	method Action mac_fp_input(Bit#(16) inp_1, Bit#(16) inp_2, Bit#(32) inp_3);
		rg_inp_1 <= inp_1;
		rg_inp_2 <= inp_2;
		rg_inp_3 <= inp_3;
		condition_1 <= True;
	endmethod  

	method Bit#(32) mac_fp_output() if(condition_12);
		return rg_out;
		//return 32'b1 ;
	endmethod  
endmodule : mk_mac_fp
endpackage : mac_fp32









        
        
        
      
