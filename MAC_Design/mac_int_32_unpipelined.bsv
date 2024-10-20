package mac_int_32;

typedef struct {Bit#(1) sum;
		Bit#(1) cout;} Adder_output deriving(Bits, Eq); 

interface Mac_int_ifc;
	method Bit#(32) mac_int_input(Bit#(8) inp_1, Bit#(8) inp_2, Bit#(32) inp_3);
endinterface : Mac_int_ifc

interface Csa_ifc;
	method Bit#(32) csa_input(Bit#(32) csa_inp1, Bit#(32) csa_inp2, Bit#(32) csa_inp3);
endinterface : Csa_ifc

interface Rca_ifc;
	method Bit#(32) rca_input(Bit#(32) rca_inp1, Bit#(32) rca_inp2);
endinterface : Rca_ifc

interface Wallace_multiplier_ifc;
	method Bit#(16) wallace_input(Bit#(8) wm_inp1, Bit#(8) wm_inp2);
endinterface : Wallace_multiplier_ifc

module mk_wallace_multiplier(Wallace_multiplier_ifc);

	Csa_ifc csa_unit <- mk_carry_save_adder;

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

	method Bit#(32) wallace_input(Bit#(8) wm_inp1, Bit#(8) wm_inp2);
		
		Bit#(8) pp0 = (wm_inp1 & {wm_inp2[0], wm_inp2[0], wm_inp2[0], wm_inp2[0], wm_inp2[0], wm_inp2[0], wm_inp2[0], wm_inp2[0]});
		pp0[7] = ~pp0[7];
		Bit#(8) pp1 = (wm_inp1 & {wm_inp2[1], wm_inp2[1], wm_inp2[1], wm_inp2[1], wm_inp2[1], wm_inp2[1], wm_inp2[1], wm_inp2[1]});
		pp1[7] = ~pp1[7];
		Bit#(8) pp2 = (wm_inp1 & {wm_inp2[2], wm_inp2[2], wm_inp2[2], wm_inp2[2], wm_inp2[2], wm_inp2[2], wm_inp2[2], wm_inp2[2]});
		pp2[7] = ~pp2[7];
		Bit#(8) pp3 = (wm_inp1 & {wm_inp2[3], wm_inp2[3], wm_inp2[3], wm_inp2[3], wm_inp2[3], wm_inp2[3], wm_inp2[3], wm_inp2[3]});
		pp3[7] = ~pp3[7];
		Bit#(8) pp4 = (wm_inp1 & {wm_inp2[4], wm_inp2[4], wm_inp2[4], wm_inp2[4], wm_inp2[4], wm_inp2[4], wm_inp2[4], wm_inp2[4]});
		pp4[7] = ~pp4[7];
		Bit#(8) pp5 = (wm_inp1 & {wm_inp2[5], wm_inp2[5], wm_inp2[5], wm_inp2[5], wm_inp2[5], wm_inp2[5], wm_inp2[5], wm_inp2[5]});
		pp5[7] = ~pp5[7];
		Bit#(8) pp6 = (wm_inp1 & {wm_inp2[6], wm_inp2[6], wm_inp2[6], wm_inp2[6], wm_inp2[6], wm_inp2[6], wm_inp2[6], wm_inp2[6]});
		pp6[7] = ~pp6[7];
		Bit#(8) pp7 = (wm_inp1 & {wm_inp2[7], wm_inp2[7], wm_inp2[7], wm_inp2[7], wm_inp2[7], wm_inp2[7], wm_inp2[7], wm_inp2[7]});
		pp7 = ~pp7;
		pp7[7] = ~pp7[7];

		//Stage 1
		Bit#(15) w10 = 0;
		Bit#(13) w11 = 0;
		Bit#(9) w12 = 0;
		Bit#(7) w13 = 0;
		Bit#(3) w14 = 0;
		Bit#(1) w15 = 0;
		
		w10[0] = pp0[0];
		let half_adder1 = half_adder(pp0[1], pp1[0]);
		w10[1] = half_adder1.sum;
		w10[2] = half_adder1.cout;
		let full_adder1 = full_adder(pp0[2], pp1[1], pp2[0]);
		w11[0] = full_adder1.sum;
		w10[3] = full_adder1.cout;
		let full_adder2 = full_adder(pp0[3], pp1[2], pp2[1]);
		w11[1] = full_adder2.sum;
		w10[4] = full_adder2.cout;
		w12[0] = pp3[0];
		let full_adder3 = full_adder(pp0[4], pp1[3], pp2[2]);
		w11[2] = full_adder3.sum;
		w10[5] = full_adder3.cout;
		let half_adder2 = half_adder(pp3[1], pp4[0]);
		w12[1] = half_adder2.sum;
		w11[3] = half_adder2.cout;
		let full_adder4 = full_adder(pp0[5], pp1[4], pp2[3]);
		w12[2] = full_adder4.sum;
		w10[6] = full_adder4.cout;
		let full_adder5 = full_adder(pp3[2], pp4[1], pp5[0]);
		w13[0] = full_adder5.sum;
		w11[4] = full_adder5.cout;
		let full_adder6 = full_adder(pp0[6], pp1[5], pp2[4]);
		w12[3] = full_adder6.sum;
		w10[7] = full_adder6.cout;
		let full_adder7 = full_adder(pp3[3], pp4[2], pp5[1]);
		w13[1] = full_adder7.sum;
		w11[5] = full_adder7.cout;
		w14[0] = pp6[0];
		let full_adder8 = full_adder(pp0[7], pp1[6], pp2[5]);
		w12[4] = full_adder8.sum;
		w10[8] = full_adder8.cout;
		let full_adder9 = full_adder(pp3[4], pp4[3], pp5[2]);
		w13[2] = full_adder9.sum;
		w11[6] = full_adder9.cout;
		let half_adder3 = half_adder(pp6[1], pp7[0]);
		w14[1] = half_adder3.sum;
		w12[5] = half_adder3.cout;		
		let full_adder10 = full_adder(pp1[7], pp2[6], pp3[5]);
		w13[3] = full_adder10.sum;
		w10[9] = full_adder10.cout;
		let full_adder11 = full_adder(pp4[4], pp5[3], pp6[2]);
		w14[2] = full_adder11.sum;
		w11[7] = full_adder11.cout;
		w15    = pp7[1];
		let full_adder12 = full_adder(pp2[7], pp3[6], pp4[5]);
		w12[6] = full_adder12.sum;
		w10[10] = full_adder12.cout;
		let full_adder13 = full_adder(pp5[4], pp6[3], pp7[2]);
		w13[4] = full_adder13.sum;
		w11[8] = full_adder13.cout;
		let full_adder14 = full_adder(pp3[7], pp4[6], pp5[5]);
		w12[7] = full_adder14.sum;
		w10[11] = full_adder14.cout;
		let half_adder4 = half_adder(pp6[4], pp7[3]);
		w13[5] = half_adder4.sum;
		w11[9] = half_adder4.cout;
		let full_adder15 = full_adder(pp4[7], pp5[6], pp6[5]);
		w12[8] = full_adder15.sum;
		w10[12] = full_adder15.cout;
		w13[6] = pp7[4];
		let full_adder16 = full_adder(pp5[7], pp6[6], pp7[5]);
		w11[10] = full_adder16.sum;
		w10[13] = full_adder16.cout;
		let half_adder5 = half_adder(pp6[7], pp7[6]);
		w11[11] = half_adder5.sum;
		w10[14] = half_adder5.cout;
		w11[12] = pp7[7];
		
		//Stage 2
		Bit#(16) w20 = 0; 
		Bit#(12) w21 = 0; 
		Bit#(7) w22 = 0; 
		Bit#(3) w23 = 0; 

		w20[0] = w10[0];
		w20[1] = w10[1];
		let half_adder1 = half_adder(w10[2], w11[0]);
		w20[2] = half_adder1.sum;
		w20[3] = half_adder1.cout;
		let full_adder1 = full_adder(w10[3], w11[1], w12[0]);
		w21[0] = full_adder1.sum;
		w20[4] = full_adder1.cout;
		let full_adder2 = full_adder(w10[4], w11[2], w12[1]);
		w21[1] = full_adder2.sum;
		w20[5] = full_adder2.cout;
		let full_adder3 = full_adder(w10[5], w11[3], w12[2]);
		w21[2] = full_adder3.sum;
		w20[6] = full_adder3.cout;
		w22[0] = w13[0];
		let full_adder4 = full_adder(w10[6], w11[4], w12[3]);
		w21[3] = full_adder4.sum;
		w20[7] = full_adder4.cout;
		let half_adder2 = half_adder(w13[1], w14[0]);
		w22[1] = half_adder2.sum;
		w21[4] = half_adder2.cout;
		let full_adder5 = full_adder(w10[7], w11[5], w12[4]);
		w22[2] = full_adder5.sum;
		w20[8] = full_adder5.cout;
		let half_adder3 = half_adder(w13[2], w14[1]);
		w23[0] = half_adder3.sum;
		w21[5] = half_adder3.cout;
		let full_adder6 = full_adder(w10[8], w11[6], w12[5]);
		w22[3] = full_adder6.sum;
		w20[9] = full_adder6.cout;
		let full_adder7 = full_adder(w13[3], w14[2], w15);
		w23[1] = full_adder7.sum;
		w21[6] = full_adder7.cout;
		let full_adder8 = full_adder(w10[9], w11[7], w12[6]);
		w22[4] = full_adder8.sum;
		w20[10] = full_adder8.cout;
		w23[2] = w13[4];
		let full_adder9 = full_adder(w10[10], w11[8], w12[7]);
		w21[7] = full_adder9.sum;
		w20[11] = full_adder9.cout;
		w22[5] = w13[5];
		let full_adder10 = full_adder(w10[11], w11[9], w12[8]);
		w21[8] = full_adder10.sum;
		w20[12] = full_adder10.cout;
		w22[6] = w13[6];
		let half_adder4 = half_adder(w10[12], w11[10]);
		w21[9] = half_adder4.sum;
		w20[13] = half_adder4.cout;
		let half_adder5 = half_adder(w10[13], w11[11]);
		w21[10] = half_adder5.sum;
		w20[14] = half_adder5.cout;
		let half_adder6 = half_adder(w10[14], w11[12]);
		w21[11] = half_adder6.sum;
		w20[15] = half_adder6.cout;

		//Stage 3
		Bit#(16) w30 = 0;
		Bit#(12) w31 = 0;
		Bit#(3) w32 = 0;

		w30[0] = w20[0];
		w30[1] = w20[1];
		w30[2] = w20[2];
		let half_adder1 = half_adder(w20[3], w21[0]);
		w30[3] = half_adder1.sum;
		w30[4] = half_adder1.cout;		
		let half_adder2 = half_adder(w20[4], w21[1]);
		w31[0] = half_adder2.sum;
		w30[5] = half_adder2.cout;
		let full_adder1 = full_adder(w20[5], w21[2], w22[0]);
		w31[1] = full_adder1.sum;
		w30[6] = full_adder1.cout;
		let full_adder2 = full_adder(w20[6], w21[3], w22[1]);
		w31[2] = full_adder2.sum;
		w30[7] = full_adder2.cout;
		let full_adder3 = full_adder(w20[7], w21[4], w22[2]);
		w31[3] = full_adder3.sum;
		w30[8] = full_adder3.cout;
		w32[0] = w23[0];
		let full_adder4 = full_adder(w20[8], w21[5], w22[3]);
		w31[4] = full_adder4.sum;
		w30[9] = full_adder4.cout;
		w32[1] = w23[1];
		let full_adder5 = full_adder(w20[9], w21[6], w22[4]);
		w31[5] = full_adder5.sum;
		w30[10] = full_adder5.cout;
		w32[2] = w23[2];
		let full_adder6 = full_adder(w20[10], w21[7], w22[5]);
		w31[6] = full_adder6.sum;
		w30[11] = full_adder6.cout;
		let full_adder7 = full_adder(w20[11], w21[8], w22[6]);
		w31[7] = full_adder7.sum;
		w30[12] = full_adder7.cout;
		let half_adder3 = half_adder(w20[12], w21[9]);
		w31[8] = half_adder3.sum;
		w30[13] = half_adder3.cout;
		let half_adder4 = half_adder(w20[13], w21[10]);
		w31[9] = half_adder4.sum;
		w30[14] = half_adder4.cout;
		let half_adder5 = half_adder(w20[14], w21[11]);
		w31[10] = half_adder5.sum;
		w30[15] = half_adder5.cout;
		w31[11] = w20[15];

		//Stage 4
		Bit#(16) w40 = 0;
		Bit#(16) w41 = 0;

		w40[0] = w30[0];
		w40[1] = w30[1];
		w40[2] = w30[2];
		w40[3] = w30[3];
		let half_adder1 = half_adder(w30[4], w31[0]);
		w40[4] = half_adder1.sum;
		w40[5] = half_adder1.cout;		
		let half_adder2 = half_adder(w30[5], w31[1]);
		w41[5] = half_adder2.sum;
		w40[6] = half_adder2.cout;
		let half_adder3 = half_adder(w30[6], w31[2]);
		w41[6] = half_adder3.sum;
		w40[7] = half_adder3.cout;
		let full_adder1 = full_adder(w30[7], w31[3], w32[0]);
		w41[7] = full_adder1.sum;
		w40[8] = full_adder1.cout;
		let full_adder2 = full_adder(w30[8], w31[4], w32[1]);
		w41[8] = full_adder2.sum;
		w40[9] = full_adder2.cout;
		let full_adder3 = full_adder(w30[9], w31[5], w32[2]);
		w41[9] = full_adder3.sum;
		w40[10] = full_adder3.cout;
		let half_adder4 = half_adder(w30[10], w31[6]);
		w41[10] = half_adder4.sum;
		w40[11] = half_adder4.cout;
		let half_adder5 = half_adder(w30[11], w31[7]);
		w41[11] = half_adder5.sum;
		w40[12] = half_adder5.cout;
		let half_adder6 = half_adder(w30[12], w31[8]);
		w41[12] = half_adder6.sum;
		w40[13] = half_adder6.cout;
		let half_adder7 = half_adder(w30[13], w31[9]);
		w41[13] = half_adder7.sum;
		w40[14] = half_adder7.cout;
		let half_adder8 = half_adder(w30[14], w31[10]);
		w41[14] = half_adder8.sum;
		w40[15] = half_adder8.cout;
		let half_adder9 = half_adder(w30[15], w31[11]);
		w41[15] = half_adder9.sum;
		//w41[16] <= half_adder(w30[15], w31[11]).cout;

		Bit#(16) result = truncate(csa_unit.csa_input(signExtend(w40), signExtend(w41), signExtend(16'b1000000100000000)));

		return result;

	endmethod : wallace_input

endmodule : mk_wallace_multiplier

module mk_ripple_carry_adder(Rca_ifc);
	method Bit#(32) rca_input(Bit#(32) rca_inp1, Bit#(32) rca_inp2);
		Bit#(32) sum   = 0;
		Bit#(33) carry = 0;
		for(Integer i = 0; i < 32; i = i + 1)begin
			sum[i] = rca_inp1[i] ^ rca_inp2[i] ^ carry[i];
			carry[i+1] = (rca_inp1[i] & rca_inp2[i]) | (rca_inp1[i] & carry[i]) | (rca_inp2[i] & carry[i]);
		end
		return sum;
	endmethod : rca_input
endmodule : mk_ripple_carry_adder

module mk_carry_save_adder(Csa_ifc);

	Rca_ifc ripple_carry_adder <- mk_ripple_carry_adder;

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

endmodule : mk_carry_save_adder

module mk_mac_int(Mac_int_ifc);

	Wallace_multiplier_ifc wallace_multiplier_unit <- mk_wallace_multiplier;
	Rca_ifc ripple_carry_adder <- mk_ripple_carry_adder;

	method Bit#(32) mac_int_input(Bit#(8) inp_1, Bit#(8) inp_2, Bit#(32) inp_3);
		
		Bit#(32) multiplication_result = signExtend(wallace_multiplier_unit.wallace_input(inp_1, inp_2));
		Bit#(32) accumulation = ripple_carry_adder.rca_input(multiplication_result, inp_3);
		return accumulation;
		
	endmethod : mac_int_input

endmodule : mk_mac_int

endpackage : mac_int_32