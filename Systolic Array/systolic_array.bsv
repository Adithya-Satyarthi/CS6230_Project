package systolic_array;

typedef struct{
	Bit#(16) b0;
	Bit#(16) b1;
	Bit#(16) b2;
	Bit#(16) b3;
} B_out deriving(Bits, Eq);

typedef struct{
	Bit#(16) mac0;
	Bit#(16) mac1;
	Bit#(16) mac2;
	Bit#(16) mac3;
} Matrix_out deriving(Bits, Eq);

import FIFOF :: *;
import SpecialFIFOs :: *;
import DReg :: *;
import top :: *;

interface Ifc_SysArray;

	method Action get_B(Bit#(16) b0, Bit#(16) b1, Bit#(16) b2, Bit#(16) b3, Bit#(1) s0, Bit#(1) s1, Bit#(1) s2, Bit#(1) s3);
	method Action get_A(Bit#(16) a0, Bit#(16) a1, Bit#(16) a2, Bit#(16) a3);
	
	method ActionValue#(B_out) put_B();
	method ActionValue#(Bit#(32)) put_index0();
	method ActionValue#(Bit#(32)) put_index1();
	method ActionValue#(Bit#(32)) put_index2();
	method ActionValue#(Bit#(32)) put_index3();
	

endinterface : Ifc_SysArray

interface Ifc_matrix;

	method Action get_a(Bit#(16) a);
	method Action get_b(Bit#(16) b);
	method Action get_c(Bit#(32) c);
	method Action get_s(Bit#(1) s);
	method ActionValue#(Bit#(16)) put_a();
	method ActionValue#(Bit#(16)) put_b();
	method ActionValue#(Bit#(32)) put_c();
	method ActionValue#(Bit#(1)) put_s();
	method ActionValue#(Bit#(32)) put_mac();

endinterface : Ifc_matrix

module mk_matrix(Ifc_matrix);

	Mac_ifc mac_unit <- mk_mac_unit;

	FIFOF#(Bit#(16)) ff_a <- mkPipelineFIFOF();
	FIFOF#(Bit#(16)) ff_b <- mkPipelineFIFOF();
	FIFOF#(Bit#(32)) ff_c <- mkPipelineFIFOF();
	FIFOF#(Bit#(1)) ff_s <- mkPipelineFIFOF();
	
	
	rule rl_calculation;
	
		$display("rule : rl_calculation fired");
	
		Bit#(16) inp1 = ff_a.first;
		Bit#(16) inp2 = ff_b.first;
		Bit#(32) inp3 = ff_c.first;
		Bit#(1) sel = ff_s.first;
		mac_unit.get_A(inp1);
		mac_unit.get_B(inp2);
		mac_unit.get_C(inp3);
		mac_unit.sel_line(sel);
		
	endrule : rl_calculation
	
	method Action get_a(Bit#(16) a);
		
		ff_a.enq(a);
		
	endmethod : get_a
	
	method Action get_b(Bit#(16) b);
		
		ff_b.enq(b);
		
	endmethod : get_b
	
	method Action get_c(Bit#(32) c);
		
		ff_c.enq(c);
		
	endmethod : get_c
	
	method Action get_s(Bit#(1) s);
		
		ff_s.enq(s);
		
	endmethod : get_s
	
	method ActionValue#(Bit#(16)) put_a();
		
		Bit#(16) a = ff_a.first;
		ff_a.deq;
		return a;
		
	endmethod : put_a
	
	method ActionValue#(Bit#(16)) put_b();
		
		Bit#(16) b = ff_b.first;
		ff_b.deq;
		return b;
		
	endmethod : put_b
	
	method ActionValue#(Bit#(32)) put_c();
		
		Bit#(32) c = ff_c.first;
		ff_c.deq;
		return c;
		
	endmethod : put_c
	
	method ActionValue#(Bit#(1)) put_s();
		
		Bit#(1) s = ff_s.first;
		ff_s.deq;
		return s;
		
	endmethod : put_s
	
	method ActionValue#(Bit#(32)) put_mac();
	
		Bit#(32) mac = mac_unit.mac_output();
		return mac;
	
	endmethod : put_mac

endmodule : mk_matrix

(*synthesize*)

module mk_sys_array(Ifc_SysArray);

	Ifc_matrix el00 <- mk_matrix;
	Ifc_matrix el01 <- mk_matrix;
	Ifc_matrix el02 <- mk_matrix;
	Ifc_matrix el03 <- mk_matrix;
	Ifc_matrix el10 <- mk_matrix;
	Ifc_matrix el11 <- mk_matrix;
	Ifc_matrix el12 <- mk_matrix;
	Ifc_matrix el13 <- mk_matrix;
	Ifc_matrix el20 <- mk_matrix;
	Ifc_matrix el21 <- mk_matrix;
	Ifc_matrix el22 <- mk_matrix;
	Ifc_matrix el23 <- mk_matrix;
	Ifc_matrix el30 <- mk_matrix;
	Ifc_matrix el31 <- mk_matrix;
	Ifc_matrix el32 <- mk_matrix;
	Ifc_matrix el33 <- mk_matrix;
	
	
	
	FIFOF#(Bit#(32)) ff_mac0 <- mkPipelineFIFOF();
	FIFOF#(Bit#(32)) ff_mac1 <- mkPipelineFIFOF();
	FIFOF#(Bit#(32)) ff_mac2 <- mkPipelineFIFOF();
	FIFOF#(Bit#(32)) ff_mac3 <- mkPipelineFIFOF();
	
	(*descending_urgency = "stage1_b, stage2_b, stage3_b"*)
	(*descending_urgency = "stage1_a, stage2_a, stage3_a"*)
	(*descending_urgency = "stage1_c, stage2_c, stage3_c, stage4_c, stage5_c, stage6_c, stage7_c"*)
	
	rule stage1_b;
		
		Bit#(16) b0 <- el00.put_b();
		Bit#(1) s0 <- el00.put_s();
		el10.get_b(b0);
		el10.get_s(s0);
		Bit#(16) b1 <- el01.put_b();
		Bit#(1) s1 <- el01.put_s();
		el11.get_b(b1);
		el11.get_s(s1);
		Bit#(16) b2 <- el02.put_b();
		Bit#(1) s2 <- el02.put_s();
		el12.get_b(b2);
		el12.get_s(s2);
		Bit#(16) b3 <- el03.put_b();
		Bit#(1) s3 <- el03.put_s();
		el13.get_b(b3);
		el13.get_s(s3);
		
	endrule : stage1_b
	
	rule stage2_b;
		
		Bit#(16) b0 <- el10.put_b();
		Bit#(1) s0 <- el10.put_s();
		el20.get_b(b0);
		el20.get_s(s0);
		Bit#(16) b1 <- el11.put_b();
		Bit#(1) s1 <- el11.put_s();
		el21.get_b(b1);
		el21.get_s(s1);
		Bit#(16) b2 <- el12.put_b();
		Bit#(1) s2 <- el12.put_s();
		el22.get_b(b2);
		el22.get_s(s2);
		Bit#(16) b3 <- el13.put_b();
		Bit#(1) s3 <- el13.put_s();
		el23.get_b(b3);
		el23.get_s(s3);
		
	endrule : stage2_b
	
	rule stage3_b;
		
		Bit#(16) b0 <- el20.put_b();
		Bit#(1) s0 <- el20.put_s();
		el30.get_b(b0);
		el30.get_s(s0);
		Bit#(16) b1 <- el21.put_b();
		Bit#(1) s1 <- el21.put_s();
		el31.get_b(b1);
		el31.get_s(s1);
		Bit#(16) b2 <- el22.put_b();
		Bit#(1) s2 <- el22.put_s();
		el32.get_b(b2);
		el32.get_s(s2);
		Bit#(16) b3 <- el23.put_b();
		Bit#(1) s3 <- el23.put_s();
		el33.get_b(b3);
		el33.get_s(s3);
		
	endrule : stage3_b
	
	rule stage1_a;
	
		Bit#(16) a0 <- el00.put_a();
		el01.get_a(a0);
		Bit#(16) a1 <- el10.put_a();
		el11.get_a(a1);
		Bit#(16) a2 <- el20.put_a();
		el21.get_a(a2);
		Bit#(16) a3 <- el30.put_a();
		el31.get_a(a3);
		
	
	endrule : stage1_a
	
	rule stage2_a;
	
		Bit#(16) a0 <- el01.put_a();
		el02.get_a(a0);
		Bit#(16) a1 <- el11.put_a();
		el12.get_a(a1);
		Bit#(16) a2 <- el21.put_a();
		el22.get_a(a2);
		Bit#(16) a3 <- el31.put_a();
		el32.get_a(a3);
	
	endrule : stage2_a
	
	rule stage3_a;
	
		Bit#(16) a0 <- el02.put_a();
		el03.get_a(a0);
		Bit#(16) a1 <- el12.put_a();
		el13.get_a(a1);
		Bit#(16) a2 <- el22.put_a();
		el23.get_a(a2);
		Bit#(16) a3 <- el32.put_a();
		el33.get_a(a3);
	
	endrule : stage3_a
	
	rule stage1_c;
	
		Bit#(32) c0 <- el00.put_mac();
		el10.get_c(c0);
	
	endrule : stage1_c
	
	rule stage2_c;
	
		Bit#(32) c0 <- el10.put_mac();
		el20.get_c(c0);
		Bit#(32) c1 <- el01.put_mac();
		el11.get_c(c1);
	
	endrule : stage2_c
	
	rule stage3_c;
	
		Bit#(32) c0 <- el20.put_mac();
		el30.get_c(c0);
		Bit#(32) c1 <- el11.put_mac();
		el21.get_c(c1);
		Bit#(32) c2 <- el02.put_mac();
		el12.get_c(c2);
	
	endrule : stage3_c
	
	rule stage4_c;
	
		Bit#(32) mac0 <- el30.put_mac();
		ff_mac0.enq(mac0);
		Bit#(32) c1 <- el21.put_mac();
		el31.get_c(c1);
		Bit#(32) c2 <- el12.put_mac();
		el22.get_c(c2);
		Bit#(32) c3 <- el03.put_mac();
		el13.get_c(c3);
	
	endrule : stage4_c
	
	rule stage5_c;
	
		Bit#(32) c3 <- el13.put_mac();
		el23.get_c(c3);
		Bit#(32) c2 <- el22.put_mac();
		el32.get_c(c2);
		Bit#(32) mac1 <- el31.put_mac();
		ff_mac1.enq(mac1);
		
	endrule : stage5_c
	
	rule stage6_c;
	
		Bit#(32) c3 <- el23.put_mac();
		el33.get_c(c3);
		Bit#(32) mac2 <- el32.put_mac();
		ff_mac2.enq(mac2);
	
	endrule : stage6_c
	
	rule stage7_c;
	
		Bit#(32) mac3 <- el33.put_mac();
		ff_mac3.enq(mac3);
	
	endrule : stage7_c
	
	method Action get_A(Bit#(16) a0, Bit#(16) a1, Bit#(16) a2, Bit#(16) a3);
	
		el00.get_a(a0);
		el00.get_c(0);
		el10.get_a(a1);
		el01.get_c(0);
		el20.get_a(a2);
		el02.get_c(0);
		el30.get_a(a3);
		el03.get_c(0);
	
	endmethod : get_A
	
	method Action get_B(Bit#(16) b0, Bit#(16) b1, Bit#(16) b2, Bit#(16) b3, Bit#(1) s0, Bit#(1) s1, Bit#(1) s2, Bit#(1) s3);
	
		el00.get_b(b0);
		el00.get_s(s0);
		el01.get_b(b1);
		el01.get_s(s1);
		el02.get_b(b2);
		el02.get_s(s2);
		el03.get_b(b3);
		el03.get_s(s3);
	
	endmethod : get_B
	
	method ActionValue#(B_out) put_B();
		
		Bit#(16) b0 <- el30.put_b();
		Bit#(1) s0 <- el30.put_s();
		Bit#(16) b1 <- el31.put_b();
		Bit#(1) s1 <- el31.put_s();
		Bit#(16) b2 <- el32.put_b();
		Bit#(1) s2 <- el32.put_s();
		Bit#(16) b3 <- el33.put_b();
		Bit#(1) s3 <- el33.put_s();
		return B_out{b0:b0, b1:b1, b2:b2, b3:b3};
		
	endmethod : put_B
	
	method ActionValue#(Bit#(32)) put_index0();
		
		Bit#(32) result = ff_mac0.first;
		ff_mac0.deq;
		return result;
	
	endmethod : put_index0
	
	method ActionValue#(Bit#(32)) put_index1();
		
		Bit#(32) result = ff_mac1.first;
		ff_mac1.deq;
		return result;
	
	endmethod : put_index1
	
	method ActionValue#(Bit#(32)) put_index2();
		
		Bit#(32) result = ff_mac2.first;
		ff_mac2.deq;
		return result;
	
	endmethod : put_index2
	
	method ActionValue#(Bit#(32)) put_index3();
		
		Bit#(32) result = ff_mac3.first;
		ff_mac3.deq;
		return result;
	
	endmethod : put_index3

endmodule : mk_sys_array

endpackage : systolic_array
