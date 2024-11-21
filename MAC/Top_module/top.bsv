package top;
import mac_fp32 ::*;
import mac_int32 ::*;
import DReg ::*;

//import FIFO :: *;

interface Mac_ifc;
		method Action get_A(Bit#(16) a);
		method Action get_B(Bit#(16) b);
		method Action get_C(Bit#(32) c);
		method Action sel_line(Bit#(1) sel);
		method Bit#(32) mac_output();
endinterface : Mac_ifc
(*synthesize*)
module mk_mac_unit(Mac_ifc );
	Mac_int_ifc mac_int_unit <- mk_mac_int;
	Mac_fp_ifc mac_float_unit <- mk_mac_fp;
		
	Reg#(Bit#(1)) rg_sel_bit <- mkReg(0);
	Reg#(Bit#(16)) rg_inp1   <- mkReg(0);
	Reg#(Bit#(16)) rg_inp2   <- mkReg(0);
	Reg#(Bit#(32)) rg_inp3   <- mkReg(0);
	Reg#(Bit#(32)) rg_out    <- mkReg(0);
	Reg#(Bool) inp1_ready <- mkReg(False);
	Reg#(Bool) inp2_ready <- mkReg(False);
	Reg#(Bool) inp3_ready <- mkReg(False);
	Reg#(Bool) sel_ready <- mkReg(False);
	Reg#(Bool) int_input <- mkReg(False);
	Reg#(Bool) int_output <- mkReg(False);
	Reg#(Bool) float_input <- mkReg(False);
	Reg#(Bool) float_output <- mkReg(False);

	rule int_selection(inp1_ready && inp2_ready && inp3_ready && sel_ready && rg_sel_bit == 1'b0);
	
		Bit#(8) inp1 = rg_inp1[7:0];
		Bit#(8) inp2 = rg_inp2[7:0];
		mac_int_unit.mac_int_input(inp1, inp2, rg_inp3);
		int_input <=True;
		
	endrule : int_selection
	
	rule float_selection(inp1_ready && inp2_ready && inp3_ready && sel_ready && rg_sel_bit == 1'b1);
	
		mac_float_unit.mac_fp_input(rg_inp1, rg_inp2, rg_inp3);
		float_input <=True;
		
	endrule : float_selection
	
	rule int_result(rg_sel_bit == 1'b0 && int_input);
	
		rg_out <= mac_int_unit.mac_int_output();
		int_output <= True;
		
	endrule
	
	rule float_result(rg_sel_bit == 1'b1 && float_input);
	
		rg_out <= mac_float_unit.mac_fp_output();
		float_output <= True;
		
	endrule

	method Action get_A(Bit#(16) a) if(!inp1_ready);
		rg_inp1 <= a;
		inp1_ready <= True;
	endmethod : get_A
	method Action get_B(Bit#(16) b) if(!inp2_ready);
		rg_inp2 <= b;
		inp2_ready <= True;
	endmethod : get_B
	method Action get_C(Bit#(32) c) if(!inp3_ready);
		rg_inp3 <= c;
		inp3_ready <= True;
	endmethod : get_C
	method Action sel_line(Bit#(1) sel) if(!sel_ready);
		rg_sel_bit <= sel;
		sel_ready <= True;
	endmethod : sel_line
	method Bit#(32) mac_output() if (int_output || float_output);
		return rg_out;
	endmethod : mac_output
	
endmodule : mk_mac_unit
endpackage : top
