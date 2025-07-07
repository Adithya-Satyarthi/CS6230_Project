// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/shakti/Desktop/macint32/verilog/mk_mac_int.v", 36, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/shakti/Desktop/macint32/verilog/mk_mac_int.v", 36, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mk_mac_int__DOT__CLK = vlTOPp->CLK;
    vlTOPp->mk_mac_int__DOT__RST_N = vlTOPp->RST_N;
    vlTOPp->mk_mac_int__DOT__mac_int_input_inp_1 = vlTOPp->mac_int_input_inp_1;
    vlTOPp->mk_mac_int__DOT__mac_int_input_inp_2 = vlTOPp->mac_int_input_inp_2;
    vlTOPp->mk_mac_int__DOT__mac_int_input_inp_3 = vlTOPp->mac_int_input_inp_3;
    vlTOPp->mk_mac_int__DOT__EN_mac_int_input = vlTOPp->EN_mac_int_input;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_mac_int_input 
        = vlTOPp->EN_mac_int_input;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_treg_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_treg 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_treg_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_treg = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p40_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p40 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p40_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p40 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p41_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p41 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p41_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p41 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_result_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_result 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_result_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_result = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_out_EN) {
            vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_out 
                = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_out_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_out = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__rg_inp_3_EN) {
            vlTOPp->mk_mac_int__DOT__rg_inp_3 = vlTOPp->mk_mac_int__DOT__rg_inp_3_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__rg_inp_3 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_out_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_out 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_out_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_out = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_out_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_out 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_out_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_out = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_out_EN) {
            vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_out 
                = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_out_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_out = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__output_ready_EN) {
            vlTOPp->mk_mac_int__DOT__output_ready = vlTOPp->mk_mac_int__DOT__output_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__output_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__rg_out_EN) {
            vlTOPp->mk_mac_int__DOT__rg_out = vlTOPp->mk_mac_int__DOT__rg_out_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__rg_out = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_input_ready_EN) {
            vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_input_ready 
                = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_input_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_input_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_input_ready_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_input_ready 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_input_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_input_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p23_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p23 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p23_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p23 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl2_ready_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl2_ready 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl2_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl2_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_input_ready_EN) {
            vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_input_ready 
                = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_input_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_input_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_input_ready_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_input_ready 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_input_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_input_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl1_ready_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl1_ready 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl1_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl1_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl4_ready_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl4_ready 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl4_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl4_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_output_ready_EN) {
            vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_output_ready 
                = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_output_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_output_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__accumulation_ready_EN) {
            vlTOPp->mk_mac_int__DOT__accumulation_ready 
                = vlTOPp->mk_mac_int__DOT__accumulation_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__accumulation_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_cal_ready_EN) {
            vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_cal_ready 
                = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_cal_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_cal_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_output_ready_EN) {
            vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_output_ready 
                = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_output_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_output_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_cal_ready_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_cal_ready 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_cal_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_cal_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_output_ready_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_output_ready 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_output_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_output_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_output_ready_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_output_ready 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_output_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_output_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__input_ready_EN) {
            vlTOPp->mk_mac_int__DOT__input_ready = vlTOPp->mk_mac_int__DOT__input_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__input_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_out_ready_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_out_ready 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_out_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_out_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__multi_ready_EN) {
            vlTOPp->mk_mac_int__DOT__multi_ready = vlTOPp->mk_mac_int__DOT__multi_ready_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__multi_ready = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__rg_inp_1_EN) {
            vlTOPp->mk_mac_int__DOT__rg_inp_1 = vlTOPp->mk_mac_int__DOT__rg_inp_1_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__rg_inp_1 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__rg_inp_2_EN) {
            vlTOPp->mk_mac_int__DOT__rg_inp_2 = vlTOPp->mk_mac_int__DOT__rg_inp_2_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__rg_inp_2 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p15_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p15 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p15_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p15 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p14_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p14 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p14_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p14 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3_EN) {
            vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3 
                = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2_EN) {
            vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_EN) {
            vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2_EN) {
            vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1_EN) {
            vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 = 0U;
    }
    if (vlTOPp->RST_N) {
        if (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1_EN) {
            vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1_D_IN;
        }
    } else {
        vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 = 0U;
    }
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_D_IN 
        = ((0xffff0000U & ((- (IData)((1U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_result) 
                                             >> 0xfU)))) 
                           << 0x10U)) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_result));
    vlTOPp->mk_mac_int__DOT__rg_out_D_IN = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_out;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3_D_IN 
        = vlTOPp->mk_mac_int__DOT__rg_inp_3;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_result_D_IN 
        = (0xffffU & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_out);
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_out_D_IN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_out;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_out_D_IN 
        = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_out;
    vlTOPp->mk_mac_int__DOT__RDY_mac_int_output = vlTOPp->mk_mac_int__DOT__output_ready;
    vlTOPp->mk_mac_int__DOT__mac_int_output = vlTOPp->mk_mac_int__DOT__rg_out;
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_carry_save_adder_unit_ripple_carry_adder_addition 
        = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_input_ready;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_carry_save_adder_unit_ripple_carry_adder_addition 
        = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_input_ready;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_output_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_input_ready;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_out_EN 
        = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_input_ready;
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_csa_unit_ripple_carry_adder_addition 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_input_ready;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_wallace_multiplier_unit_csa_unit_ripple_carry_adder_addition 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_output_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_out_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_input_ready;
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p23_BIT_0_THEN_1_ETC___05Fq23 
        = ((1U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p23))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_level_3 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl2_ready;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_wallace_multiplier_unit_level_3 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl2_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl2_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl2_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl2_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl2_ready;
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_carry_save_adder_unit_calculation 
        = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_input_ready;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_carry_save_adder_unit_calculation 
        = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_input_ready;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_cal_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_input_ready;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_input_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_input_ready;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1_EN 
        = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_input_ready;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2_EN 
        = vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_input_ready;
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_csa_unit_calculation 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_input_ready;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_wallace_multiplier_unit_csa_unit_calculation 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_cal_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_input_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_input_ready;
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_level_2 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl1_ready;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_wallace_multiplier_unit_level_2 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl1_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl2_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl1_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl1_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl1_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl1_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p23_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl1_ready;
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_carry_save_adder_unit_result 
        = ((IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_output_ready) 
           & (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_cal_ready));
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_result = ((IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_output_ready) 
                                                   & (IData)(vlTOPp->mk_mac_int__DOT__accumulation_ready));
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_endresult 
        = ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_output_ready) 
           & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl4_ready));
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_csa_unit_result 
        = ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_output_ready) 
           & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_cal_ready));
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_level_1 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_wallace_multiplier_unit_level_1 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl1_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p14_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p15_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready;
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_level_4 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_wallace_multiplier_unit_level_4 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_input_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl4_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p40_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p41_EN 
        = vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_lvl3_ready;
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_multiplication 
        = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_multiplication 
        = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__multi_ready_D_IN = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_pp_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_EN 
        = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01_EN 
        = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02_EN 
        = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03_EN 
        = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04_EN 
        = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05_EN 
        = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06_EN 
        = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07_EN 
        = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_treg_EN 
        = vlTOPp->mk_mac_int__DOT__input_ready;
    vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_accumulation 
        = ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_out_ready) 
           & (IData)(vlTOPp->mk_mac_int__DOT__multi_ready));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_treg_D_IN 
        = vlTOPp->mk_mac_int__DOT__rg_inp_2;
    vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_0_986_CONCAT_ETC___05F_d1990 
        = ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1) 
           & (- (IData)((1U & (IData)(vlTOPp->mk_mac_int__DOT__rg_inp_2)))));
    vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_1_995_CONCAT_ETC___05F_d1999 
        = ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1) 
           & (- (IData)((1U & ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_2) 
                               >> 1U)))));
    vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_2_004_CONCAT_ETC___05F_d2008 
        = ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1) 
           & (- (IData)((1U & ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_2) 
                               >> 2U)))));
    vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_3_013_CONCAT_ETC___05F_d2017 
        = ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1) 
           & (- (IData)((1U & ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_2) 
                               >> 3U)))));
    vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_4_022_CONCAT_ETC___05F_d2026 
        = ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1) 
           & (- (IData)((1U & ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_2) 
                               >> 4U)))));
    vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_5_031_CONCAT_ETC___05F_d2035 
        = ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1) 
           & (- (IData)((1U & ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_2) 
                               >> 5U)))));
    vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_6_040_CONCAT_ETC___05F_d2044 
        = ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1) 
           & (- (IData)((1U & ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_2) 
                               >> 6U)))));
    vlTOPp->mk_mac_int__DOT__pp7___05Fh59549 = ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1) 
                                                & (- (IData)(
                                                             (1U 
                                                              & ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_2) 
                                                                 >> 7U)))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p15_D_IN 
        = (1U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                 >> 1U));
    vlTOPp->mk_mac_int__DOT__y___05Fh30930 = (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p14) 
                                               >> 2U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p15));
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p13_BIT_2_XOR_wa_ETC___05Fq22 
        = ((1U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13) 
                   >> 2U) ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p14) 
                             >> 1U))) ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh31672 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13) 
                                                >> 3U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p14) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p13_BIT_0_THEN_1_ETC___05Fq16 
        = ((1U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh30931 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13) 
                                                >> 3U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p14) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh30932 = (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13) 
                                               >> 3U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p15));
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p06_BIT_0_THEN_1_ETC___05Fq21 
        = ((1U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__y___05Fh26351 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh27357 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                >> 3U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh27544 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                >> 7U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh28443 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                >> 4U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh26352 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh26353 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh27241 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                >> 3U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh26234 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh27358 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh27359 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh35056 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                >> 5U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh34827 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                >> 3U) 
                                               & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32)));
    vlTOPp->mk_mac_int__DOT__y___05Fh34942 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh28700 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                >> 4U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh28144 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                >> 7U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh26117 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh27242 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh27243 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh27009 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                >> 2U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh27125 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                >> 3U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh26235 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh26236 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh26893 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                >> 1U) 
                                               & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05)));
    vlTOPp->mk_mac_int__DOT__x___05Fh28102 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 7U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh28317 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 3U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh28359 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 4U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh26118 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh26119 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh26000 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p03_BIT_0_THEN_1_ETC___05Fq12 
        = ((1U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh28279 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 2U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh27010 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 3U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh27126 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh27011 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 3U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh27127 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh26894 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 2U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh26895 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                >> 2U) 
                                               & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05)));
    vlTOPp->mk_mac_int__DOT__x___05Fh35774 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                                >> 8U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh35816 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                                >> 9U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh35057 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                                >> 9U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh35058 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                                >> 9U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p30_BIT_0_THEN_1_ETC___05Fq4 
        = ((1U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p30_BIT_5_XOR_wa_ETC___05Fq3 
        = ((1U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                   >> 5U) ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                             >> 1U))) ? 0x20U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh35732 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                                >> 7U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh34828 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh34943 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                                >> 8U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh34829 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                                >> 7U) 
                                               & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32)));
    vlTOPp->mk_mac_int__DOT__y___05Fh34944 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                                >> 8U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32995 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                >> 8U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32767 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32881 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32539 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32653 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                >> 5U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32310 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                >> 2U) 
                                               & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32425 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                >> 3U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh33705 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 0xaU) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 7U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh33747 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 0xbU) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 8U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh32996 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 0xbU) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 8U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32997 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 0xbU) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh33537 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 6U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh33579 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 7U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh33621 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 8U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh33663 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 9U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh32768 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 9U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh32882 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 0xaU) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 7U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32769 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 9U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32883 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 0xaU) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p20_BIT_4_XOR_wa_ETC___05Fq18 
        = ((1U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                   >> 4U) ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                             >> 1U))) ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh33495 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 5U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh32540 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh32654 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 8U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32541 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32655 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 8U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p20_BIT_0_THEN_1_ETC___05Fq17 
        = ((1U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh32311 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 5U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh32426 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32312 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 5U) 
                                               & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22)));
    vlTOPp->mk_mac_int__DOT__y___05Fh32427 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh28060 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                >> 7U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25883 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh26001 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh26002 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh30129 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                >> 9U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 8U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29901 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh30015 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                >> 8U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 7U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29673 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                >> 5U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29787 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29445 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                >> 3U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29559 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29216 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                >> 1U) 
                                               & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29331 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                >> 2U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh28401 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                >> 7U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh25884 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25885 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25651 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                >> 5U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25767 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25419 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                >> 3U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25535 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25186 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                >> 1U) 
                                               & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25303 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                >> 2U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh31445 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 9U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 7U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh31059 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 0xbU) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 9U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh31361 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 7U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh31403 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 8U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh30130 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 0xbU) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 9U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh30131 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 0xbU) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 8U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh31017 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 0xaU) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 8U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh29902 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 9U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 7U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh30016 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 0xaU) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 8U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29903 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 9U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh30017 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 0xaU) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 7U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh30683 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 5U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh30725 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 6U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh29674 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh29788 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 8U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29675 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29789 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 8U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh30641 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 4U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh29446 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 5U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh29560 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh30603 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 3U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29447 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 5U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29561 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p10_BIT_0_THEN_1_ETC___05Fq14 
        = ((1U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh29217 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 3U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh29332 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29218 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 3U) 
                                               & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12)));
    vlTOPp->mk_mac_int__DOT__y___05Fh29333 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh27897 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 6U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh27939 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 7U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh27855 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 5U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh26722 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 3U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh26764 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 4U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh25652 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh25768 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                  >> 6U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25653 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 6U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25769 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 7U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                  >> 5U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh26684 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 2U) 
                                               ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh25420 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh25536 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 5U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                  >> 4U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25421 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 4U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25537 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 5U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                  >> 3U)));
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p00_BIT_0_THEN_1_ETC___05Fq10 
        = ((1U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh25187 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 2U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__x___05Fh25304 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 3U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                  >> 2U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25188 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 2U) 
                                               & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02)));
    vlTOPp->mk_mac_int__DOT__y___05Fh25305 = (1U & 
                                              (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                                >> 3U) 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                  >> 1U)));
    vlTOPp->mk_mac_int__DOT__y___05Fh58243 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x1eU));
    vlTOPp->mk_mac_int__DOT__y___05Fh57877 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x1cU));
    vlTOPp->mk_mac_int__DOT__y___05Fh58060 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x1dU));
    vlTOPp->mk_mac_int__DOT__y___05Fh57511 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x1aU));
    vlTOPp->mk_mac_int__DOT__y___05Fh57694 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x1bU));
    vlTOPp->mk_mac_int__DOT__y___05Fh57145 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x18U));
    vlTOPp->mk_mac_int__DOT__y___05Fh57328 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x19U));
    vlTOPp->mk_mac_int__DOT__y___05Fh56779 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x16U));
    vlTOPp->mk_mac_int__DOT__y___05Fh56962 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x17U));
    vlTOPp->mk_mac_int__DOT__y___05Fh56413 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x14U));
    vlTOPp->mk_mac_int__DOT__y___05Fh56596 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x15U));
    vlTOPp->mk_mac_int__DOT__y___05Fh56047 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x12U));
    vlTOPp->mk_mac_int__DOT__y___05Fh56230 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x13U));
    vlTOPp->mk_mac_int__DOT__y___05Fh55681 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x10U));
    vlTOPp->mk_mac_int__DOT__y___05Fh55864 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x11U));
    vlTOPp->mk_mac_int__DOT__y___05Fh55315 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0xeU));
    vlTOPp->mk_mac_int__DOT__y___05Fh55498 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0xfU));
    vlTOPp->mk_mac_int__DOT__y___05Fh54949 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0xcU));
    vlTOPp->mk_mac_int__DOT__y___05Fh55132 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0xdU));
    vlTOPp->mk_mac_int__DOT__y___05Fh54583 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0xaU));
    vlTOPp->mk_mac_int__DOT__y___05Fh54766 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0xbU));
    vlTOPp->mk_mac_int__DOT__y___05Fh54217 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 8U));
    vlTOPp->mk_mac_int__DOT__y___05Fh54400 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 9U));
    vlTOPp->mk_mac_int__DOT__y___05Fh53851 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 6U));
    vlTOPp->mk_mac_int__DOT__y___05Fh54034 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 7U));
    vlTOPp->mk_mac_int__DOT__y___05Fh53485 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 4U));
    vlTOPp->mk_mac_int__DOT__y___05Fh53668 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 5U));
    vlTOPp->mk_mac_int__DOT__y___05Fh53119 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 2U));
    vlTOPp->mk_mac_int__DOT__y___05Fh53302 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 3U));
    vlTOPp->mk_mac_int__DOT__y___05Fh52936 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 1U));
    vlTOPp->mk_mac_int__DOT__y___05Fh52757 = (1U & 
                                              (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2 
                                               & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3));
    vlTOPp->mk_mac_int__DOT__y___05Fh22488 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x1eU));
    vlTOPp->mk_mac_int__DOT__y___05Fh22122 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x1cU));
    vlTOPp->mk_mac_int__DOT__y___05Fh22305 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x1dU));
    vlTOPp->mk_mac_int__DOT__y___05Fh21756 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x1aU));
    vlTOPp->mk_mac_int__DOT__y___05Fh21939 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x1bU));
    vlTOPp->mk_mac_int__DOT__y___05Fh21390 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x18U));
    vlTOPp->mk_mac_int__DOT__y___05Fh21573 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x19U));
    vlTOPp->mk_mac_int__DOT__y___05Fh21024 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x16U));
    vlTOPp->mk_mac_int__DOT__y___05Fh21207 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x17U));
    vlTOPp->mk_mac_int__DOT__y___05Fh20658 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x14U));
    vlTOPp->mk_mac_int__DOT__y___05Fh20841 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x15U));
    vlTOPp->mk_mac_int__DOT__y___05Fh20292 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x12U));
    vlTOPp->mk_mac_int__DOT__y___05Fh20475 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x13U));
    vlTOPp->mk_mac_int__DOT__y___05Fh19926 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x10U));
    vlTOPp->mk_mac_int__DOT__y___05Fh20109 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x11U));
    vlTOPp->mk_mac_int__DOT__y___05Fh19560 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0xeU));
    vlTOPp->mk_mac_int__DOT__y___05Fh19743 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0xfU));
    vlTOPp->mk_mac_int__DOT__y___05Fh19194 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0xcU));
    vlTOPp->mk_mac_int__DOT__y___05Fh19377 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0xdU));
    vlTOPp->mk_mac_int__DOT__y___05Fh18828 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0xaU));
    vlTOPp->mk_mac_int__DOT__y___05Fh19011 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0xbU));
    vlTOPp->mk_mac_int__DOT__y___05Fh18462 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 8U));
    vlTOPp->mk_mac_int__DOT__y___05Fh18645 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 9U));
    vlTOPp->mk_mac_int__DOT__y___05Fh18096 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 6U));
    vlTOPp->mk_mac_int__DOT__y___05Fh18279 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 7U));
    vlTOPp->mk_mac_int__DOT__y___05Fh17730 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 4U));
    vlTOPp->mk_mac_int__DOT__y___05Fh17913 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 5U));
    vlTOPp->mk_mac_int__DOT__y___05Fh17364 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 2U));
    vlTOPp->mk_mac_int__DOT__y___05Fh17547 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 3U));
    vlTOPp->mk_mac_int__DOT__y___05Fh17181 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 1U));
    vlTOPp->mk_mac_int__DOT__y___05Fh17002 = (1U & 
                                              (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2 
                                               & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3));
    vlTOPp->mk_mac_int__DOT__x___05Fh52118 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x1eU));
    vlTOPp->mk_mac_int__DOT__x___05Fh52229 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x1fU));
    vlTOPp->mk_mac_int__DOT__x___05Fh58244 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x1eU));
    vlTOPp->mk_mac_int__DOT__y___05Fh58245 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x1eU));
    vlTOPp->mk_mac_int__DOT__x___05Fh51674 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x1aU));
    vlTOPp->mk_mac_int__DOT__x___05Fh51785 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x1bU));
    vlTOPp->mk_mac_int__DOT__x___05Fh51896 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x1cU));
    vlTOPp->mk_mac_int__DOT__x___05Fh52007 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x1dU));
    vlTOPp->mk_mac_int__DOT__x___05Fh57878 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x1cU));
    vlTOPp->mk_mac_int__DOT__x___05Fh58061 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x1dU));
    vlTOPp->mk_mac_int__DOT__y___05Fh57879 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x1cU));
    vlTOPp->mk_mac_int__DOT__y___05Fh58062 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x1dU));
    vlTOPp->mk_mac_int__DOT__x___05Fh51230 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x16U));
    vlTOPp->mk_mac_int__DOT__x___05Fh51341 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x17U));
    vlTOPp->mk_mac_int__DOT__x___05Fh51452 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x18U));
    vlTOPp->mk_mac_int__DOT__x___05Fh51563 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x19U));
    vlTOPp->mk_mac_int__DOT__x___05Fh57512 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x1aU));
    vlTOPp->mk_mac_int__DOT__x___05Fh57695 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x1bU));
    vlTOPp->mk_mac_int__DOT__y___05Fh57513 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x1aU));
    vlTOPp->mk_mac_int__DOT__y___05Fh57696 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x1bU));
    vlTOPp->mk_mac_int__DOT__x___05Fh50786 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x12U));
    vlTOPp->mk_mac_int__DOT__x___05Fh50897 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x13U));
    vlTOPp->mk_mac_int__DOT__x___05Fh51008 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x14U));
    vlTOPp->mk_mac_int__DOT__x___05Fh51119 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x15U));
    vlTOPp->mk_mac_int__DOT__x___05Fh57146 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x18U));
    vlTOPp->mk_mac_int__DOT__x___05Fh57329 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x19U));
    vlTOPp->mk_mac_int__DOT__y___05Fh57147 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x18U));
    vlTOPp->mk_mac_int__DOT__y___05Fh57330 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x19U));
    vlTOPp->mk_mac_int__DOT__x___05Fh50342 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0xeU));
    vlTOPp->mk_mac_int__DOT__x___05Fh50453 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0xfU));
    vlTOPp->mk_mac_int__DOT__x___05Fh50564 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x10U));
    vlTOPp->mk_mac_int__DOT__x___05Fh50675 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x11U));
    vlTOPp->mk_mac_int__DOT__x___05Fh56780 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x16U));
    vlTOPp->mk_mac_int__DOT__x___05Fh56963 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x17U));
    vlTOPp->mk_mac_int__DOT__y___05Fh56781 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x16U));
    vlTOPp->mk_mac_int__DOT__y___05Fh56964 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x17U));
    vlTOPp->mk_mac_int__DOT__x___05Fh49898 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0xaU));
    vlTOPp->mk_mac_int__DOT__x___05Fh50009 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0xbU));
    vlTOPp->mk_mac_int__DOT__x___05Fh50120 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0xcU));
    vlTOPp->mk_mac_int__DOT__x___05Fh50231 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0xdU));
    vlTOPp->mk_mac_int__DOT__x___05Fh56414 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x14U));
    vlTOPp->mk_mac_int__DOT__x___05Fh56597 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x15U));
    vlTOPp->mk_mac_int__DOT__y___05Fh56415 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x14U));
    vlTOPp->mk_mac_int__DOT__y___05Fh56598 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x15U));
    vlTOPp->mk_mac_int__DOT__x___05Fh49454 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 6U));
    vlTOPp->mk_mac_int__DOT__x___05Fh49565 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 7U));
    vlTOPp->mk_mac_int__DOT__x___05Fh49676 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 8U));
    vlTOPp->mk_mac_int__DOT__x___05Fh49787 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 9U));
    vlTOPp->mk_mac_int__DOT__x___05Fh56048 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x12U));
    vlTOPp->mk_mac_int__DOT__x___05Fh56231 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x13U));
    vlTOPp->mk_mac_int__DOT__y___05Fh56049 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x12U));
    vlTOPp->mk_mac_int__DOT__y___05Fh56232 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x13U));
    vlTOPp->mk_mac_int__DOT__x___05Fh49010 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 2U));
    vlTOPp->mk_mac_int__DOT__x___05Fh49121 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 3U));
    vlTOPp->mk_mac_int__DOT__x___05Fh49232 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 4U));
    vlTOPp->mk_mac_int__DOT__x___05Fh49343 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 5U));
    vlTOPp->mk_mac_int__DOT__x___05Fh55682 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x10U));
    vlTOPp->mk_mac_int__DOT__x___05Fh55865 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0x11U));
    vlTOPp->mk_mac_int__DOT__y___05Fh55683 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x10U));
    vlTOPp->mk_mac_int__DOT__y___05Fh55866 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0x11U));
    vlTOPp->mk_mac_int__DOT__x___05Fh48899 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 1U));
    vlTOPp->mk_mac_int__DOT__x___05Fh55316 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0xeU));
    vlTOPp->mk_mac_int__DOT__x___05Fh55499 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0xfU));
    vlTOPp->mk_mac_int__DOT__y___05Fh55317 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0xeU));
    vlTOPp->mk_mac_int__DOT__y___05Fh55500 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0xfU));
    vlTOPp->mk_mac_int__DOT__x___05Fh48789 = (1U & 
                                              (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                               ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2));
    vlTOPp->mk_mac_int__DOT__x___05Fh54950 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0xcU));
    vlTOPp->mk_mac_int__DOT__x___05Fh55133 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0xdU));
    vlTOPp->mk_mac_int__DOT__y___05Fh54951 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0xcU));
    vlTOPp->mk_mac_int__DOT__y___05Fh55134 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0xdU));
    vlTOPp->mk_mac_int__DOT__x___05Fh54584 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0xaU));
    vlTOPp->mk_mac_int__DOT__x___05Fh54767 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 0xbU));
    vlTOPp->mk_mac_int__DOT__y___05Fh54585 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0xaU));
    vlTOPp->mk_mac_int__DOT__y___05Fh54768 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 0xbU));
    vlTOPp->mk_mac_int__DOT__x___05Fh54218 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 8U));
    vlTOPp->mk_mac_int__DOT__x___05Fh54401 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 9U));
    vlTOPp->mk_mac_int__DOT__y___05Fh54219 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 8U));
    vlTOPp->mk_mac_int__DOT__y___05Fh54402 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 9U));
    vlTOPp->mk_mac_int__DOT__x___05Fh53852 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 6U));
    vlTOPp->mk_mac_int__DOT__x___05Fh54035 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 7U));
    vlTOPp->mk_mac_int__DOT__y___05Fh53853 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 6U));
    vlTOPp->mk_mac_int__DOT__y___05Fh54036 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 7U));
    vlTOPp->mk_mac_int__DOT__x___05Fh53486 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 4U));
    vlTOPp->mk_mac_int__DOT__x___05Fh53669 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 5U));
    vlTOPp->mk_mac_int__DOT__y___05Fh53487 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 4U));
    vlTOPp->mk_mac_int__DOT__y___05Fh53670 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 5U));
    vlTOPp->mk_mac_int__DOT__x___05Fh53120 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 2U));
    vlTOPp->mk_mac_int__DOT__x___05Fh53303 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 3U));
    vlTOPp->mk_mac_int__DOT__y___05Fh53121 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 2U));
    vlTOPp->mk_mac_int__DOT__y___05Fh53304 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 3U));
    vlTOPp->mk_mac_int__DOT__x___05Fh52937 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2) 
                                               >> 1U));
    vlTOPp->mk_mac_int__DOT__y___05Fh52938 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3) 
                                               >> 1U));
    vlTOPp->mk_mac_int__DOT__x___05Fh52758 = (1U & 
                                              (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                               & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2));
    vlTOPp->mk_mac_int__DOT__y___05Fh52759 = (1U & 
                                              (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1 
                                               & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3));
    vlTOPp->mk_mac_int__DOT__x___05Fh16326 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x1eU));
    vlTOPp->mk_mac_int__DOT__x___05Fh16437 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x1fU));
    vlTOPp->mk_mac_int__DOT__x___05Fh22489 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x1eU));
    vlTOPp->mk_mac_int__DOT__y___05Fh22490 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x1eU));
    vlTOPp->mk_mac_int__DOT__x___05Fh15882 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x1aU));
    vlTOPp->mk_mac_int__DOT__x___05Fh15993 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x1bU));
    vlTOPp->mk_mac_int__DOT__x___05Fh16104 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x1cU));
    vlTOPp->mk_mac_int__DOT__x___05Fh16215 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x1dU));
    vlTOPp->mk_mac_int__DOT__x___05Fh22123 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x1cU));
    vlTOPp->mk_mac_int__DOT__x___05Fh22306 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x1dU));
    vlTOPp->mk_mac_int__DOT__y___05Fh22124 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x1cU));
    vlTOPp->mk_mac_int__DOT__y___05Fh22307 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x1dU));
    vlTOPp->mk_mac_int__DOT__x___05Fh15438 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x16U));
    vlTOPp->mk_mac_int__DOT__x___05Fh15549 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x17U));
    vlTOPp->mk_mac_int__DOT__x___05Fh15660 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x18U));
    vlTOPp->mk_mac_int__DOT__x___05Fh15771 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x19U));
    vlTOPp->mk_mac_int__DOT__x___05Fh21757 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x1aU));
    vlTOPp->mk_mac_int__DOT__x___05Fh21940 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x1bU));
    vlTOPp->mk_mac_int__DOT__y___05Fh21758 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x1aU));
    vlTOPp->mk_mac_int__DOT__y___05Fh21941 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x1bU));
    vlTOPp->mk_mac_int__DOT__x___05Fh14994 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x12U));
    vlTOPp->mk_mac_int__DOT__x___05Fh15105 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x13U));
    vlTOPp->mk_mac_int__DOT__x___05Fh15216 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x14U));
    vlTOPp->mk_mac_int__DOT__x___05Fh15327 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x15U));
    vlTOPp->mk_mac_int__DOT__x___05Fh21391 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x18U));
    vlTOPp->mk_mac_int__DOT__x___05Fh21574 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x19U));
    vlTOPp->mk_mac_int__DOT__y___05Fh21392 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x18U));
    vlTOPp->mk_mac_int__DOT__y___05Fh21575 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x19U));
    vlTOPp->mk_mac_int__DOT__x___05Fh14550 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0xeU));
    vlTOPp->mk_mac_int__DOT__x___05Fh14661 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0xfU));
    vlTOPp->mk_mac_int__DOT__x___05Fh14772 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x10U));
    vlTOPp->mk_mac_int__DOT__x___05Fh14883 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x11U));
    vlTOPp->mk_mac_int__DOT__x___05Fh21025 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x16U));
    vlTOPp->mk_mac_int__DOT__x___05Fh21208 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x17U));
    vlTOPp->mk_mac_int__DOT__y___05Fh21026 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x16U));
    vlTOPp->mk_mac_int__DOT__y___05Fh21209 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x17U));
    vlTOPp->mk_mac_int__DOT__x___05Fh14106 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0xaU));
    vlTOPp->mk_mac_int__DOT__x___05Fh14217 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0xbU));
    vlTOPp->mk_mac_int__DOT__x___05Fh14328 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0xcU));
    vlTOPp->mk_mac_int__DOT__x___05Fh14439 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0xdU));
    vlTOPp->mk_mac_int__DOT__x___05Fh20659 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x14U));
    vlTOPp->mk_mac_int__DOT__x___05Fh20842 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x15U));
    vlTOPp->mk_mac_int__DOT__y___05Fh20660 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x14U));
    vlTOPp->mk_mac_int__DOT__y___05Fh20843 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x15U));
    vlTOPp->mk_mac_int__DOT__x___05Fh13662 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 6U));
    vlTOPp->mk_mac_int__DOT__x___05Fh13773 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 7U));
    vlTOPp->mk_mac_int__DOT__x___05Fh13884 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 8U));
    vlTOPp->mk_mac_int__DOT__x___05Fh13995 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 9U));
    vlTOPp->mk_mac_int__DOT__x___05Fh20293 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x12U));
    vlTOPp->mk_mac_int__DOT__x___05Fh20476 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x13U));
    vlTOPp->mk_mac_int__DOT__y___05Fh20294 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x12U));
    vlTOPp->mk_mac_int__DOT__y___05Fh20477 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x13U));
    vlTOPp->mk_mac_int__DOT__x___05Fh13218 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 2U));
    vlTOPp->mk_mac_int__DOT__x___05Fh13329 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 3U));
    vlTOPp->mk_mac_int__DOT__x___05Fh13440 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 4U));
    vlTOPp->mk_mac_int__DOT__x___05Fh13551 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 5U));
    vlTOPp->mk_mac_int__DOT__x___05Fh19927 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x10U));
    vlTOPp->mk_mac_int__DOT__x___05Fh20110 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0x11U));
    vlTOPp->mk_mac_int__DOT__y___05Fh19928 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x10U));
    vlTOPp->mk_mac_int__DOT__y___05Fh20111 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0x11U));
    vlTOPp->mk_mac_int__DOT__x___05Fh13107 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 1U));
    vlTOPp->mk_mac_int__DOT__x___05Fh19561 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0xeU));
    vlTOPp->mk_mac_int__DOT__x___05Fh19744 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0xfU));
    vlTOPp->mk_mac_int__DOT__y___05Fh19562 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0xeU));
    vlTOPp->mk_mac_int__DOT__y___05Fh19745 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0xfU));
    vlTOPp->mk_mac_int__DOT__x___05Fh12997 = (1U & 
                                              (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                               ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2));
    vlTOPp->mk_mac_int__DOT__x___05Fh19195 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0xcU));
    vlTOPp->mk_mac_int__DOT__x___05Fh19378 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0xdU));
    vlTOPp->mk_mac_int__DOT__y___05Fh19196 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0xcU));
    vlTOPp->mk_mac_int__DOT__y___05Fh19379 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0xdU));
    vlTOPp->mk_mac_int__DOT__x___05Fh18829 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0xaU));
    vlTOPp->mk_mac_int__DOT__x___05Fh19012 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 0xbU));
    vlTOPp->mk_mac_int__DOT__y___05Fh18830 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0xaU));
    vlTOPp->mk_mac_int__DOT__y___05Fh19013 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 0xbU));
    vlTOPp->mk_mac_int__DOT__x___05Fh18463 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 8U));
    vlTOPp->mk_mac_int__DOT__x___05Fh18646 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 9U));
    vlTOPp->mk_mac_int__DOT__y___05Fh18464 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 8U));
    vlTOPp->mk_mac_int__DOT__y___05Fh18647 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 9U));
    vlTOPp->mk_mac_int__DOT__x___05Fh18097 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 6U));
    vlTOPp->mk_mac_int__DOT__x___05Fh18280 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 7U));
    vlTOPp->mk_mac_int__DOT__y___05Fh18098 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 6U));
    vlTOPp->mk_mac_int__DOT__y___05Fh18281 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 7U));
    vlTOPp->mk_mac_int__DOT__x___05Fh17731 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 4U));
    vlTOPp->mk_mac_int__DOT__x___05Fh17914 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 5U));
    vlTOPp->mk_mac_int__DOT__y___05Fh17732 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 4U));
    vlTOPp->mk_mac_int__DOT__y___05Fh17915 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 5U));
    vlTOPp->mk_mac_int__DOT__x___05Fh17365 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 2U));
    vlTOPp->mk_mac_int__DOT__x___05Fh17548 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 3U));
    vlTOPp->mk_mac_int__DOT__y___05Fh17366 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 2U));
    vlTOPp->mk_mac_int__DOT__y___05Fh17549 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 3U));
    vlTOPp->mk_mac_int__DOT__x___05Fh17182 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2) 
                                               >> 1U));
    vlTOPp->mk_mac_int__DOT__y___05Fh17183 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3) 
                                               >> 1U));
    vlTOPp->mk_mac_int__DOT__x___05Fh17003 = (1U & 
                                              (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                               & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2));
    vlTOPp->mk_mac_int__DOT__y___05Fh17004 = (1U & 
                                              (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1 
                                               & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3));
    vlTOPp->mk_mac_int__DOT__x___05Fh10772 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1eU));
    vlTOPp->mk_mac_int__DOT__x___05Fh11083 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1fU));
    vlTOPp->mk_mac_int__DOT__x___05Fh10150 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1cU));
    vlTOPp->mk_mac_int__DOT__x___05Fh10461 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1dU));
    vlTOPp->mk_mac_int__DOT__x___05Fh11186 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1eU));
    vlTOPp->mk_mac_int__DOT__x___05Fh9528 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x1aU));
    vlTOPp->mk_mac_int__DOT__x___05Fh9839 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x1bU));
    vlTOPp->mk_mac_int__DOT__x___05Fh8906 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x18U));
    vlTOPp->mk_mac_int__DOT__x___05Fh9217 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x19U));
    vlTOPp->mk_mac_int__DOT__x___05Fh8284 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x16U));
    vlTOPp->mk_mac_int__DOT__x___05Fh8595 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x17U));
    vlTOPp->mk_mac_int__DOT__x___05Fh7662 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x14U));
    vlTOPp->mk_mac_int__DOT__x___05Fh7973 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x15U));
    vlTOPp->mk_mac_int__DOT__x___05Fh10875 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1dU));
    vlTOPp->mk_mac_int__DOT__x___05Fh7040 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x12U));
    vlTOPp->mk_mac_int__DOT__x___05Fh7351 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x13U));
    vlTOPp->mk_mac_int__DOT__x___05Fh6418 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x10U));
    vlTOPp->mk_mac_int__DOT__x___05Fh6729 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x11U));
    vlTOPp->mk_mac_int__DOT__x___05Fh5796 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0xeU));
    vlTOPp->mk_mac_int__DOT__x___05Fh6107 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0xfU));
    vlTOPp->mk_mac_int__DOT__x___05Fh10564 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1cU));
    vlTOPp->mk_mac_int__DOT__x___05Fh5174 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0xcU));
    vlTOPp->mk_mac_int__DOT__x___05Fh5485 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0xdU));
    vlTOPp->mk_mac_int__DOT__x___05Fh4552 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0xaU));
    vlTOPp->mk_mac_int__DOT__x___05Fh4863 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0xbU));
    vlTOPp->mk_mac_int__DOT__x___05Fh3930 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 8U));
    vlTOPp->mk_mac_int__DOT__x___05Fh4241 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 9U));
    vlTOPp->mk_mac_int__DOT__x___05Fh3308 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 6U));
    vlTOPp->mk_mac_int__DOT__x___05Fh3619 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 7U));
    vlTOPp->mk_mac_int__DOT__x___05Fh10253 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1bU));
    vlTOPp->mk_mac_int__DOT__x___05Fh2686 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 4U));
    vlTOPp->mk_mac_int__DOT__x___05Fh2997 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 5U));
    vlTOPp->mk_mac_int__DOT__x___05Fh2062 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 2U));
    vlTOPp->mk_mac_int__DOT__x___05Fh2375 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 3U));
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_csa_unit_ripple_car_ETC___05Fq5 
        = ((1U & (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                  ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh1754 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 1U));
    vlTOPp->mk_mac_int__DOT__x___05Fh9942 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x1aU));
    vlTOPp->mk_mac_int__DOT__x___05Fh9631 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x19U));
    vlTOPp->mk_mac_int__DOT__x___05Fh9320 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x18U));
    vlTOPp->mk_mac_int__DOT__x___05Fh9009 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x17U));
    vlTOPp->mk_mac_int__DOT__x___05Fh8698 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x16U));
    vlTOPp->mk_mac_int__DOT__x___05Fh8387 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x15U));
    vlTOPp->mk_mac_int__DOT__x___05Fh8076 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x14U));
    vlTOPp->mk_mac_int__DOT__x___05Fh7765 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x13U));
    vlTOPp->mk_mac_int__DOT__x___05Fh7454 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x12U));
    vlTOPp->mk_mac_int__DOT__x___05Fh7143 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x11U));
    vlTOPp->mk_mac_int__DOT__x___05Fh6832 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0x10U));
    vlTOPp->mk_mac_int__DOT__x___05Fh6521 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0xfU));
    vlTOPp->mk_mac_int__DOT__x___05Fh6210 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0xeU));
    vlTOPp->mk_mac_int__DOT__x___05Fh5899 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0xdU));
    vlTOPp->mk_mac_int__DOT__x___05Fh5588 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0xcU));
    vlTOPp->mk_mac_int__DOT__x___05Fh5277 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0xbU));
    vlTOPp->mk_mac_int__DOT__x___05Fh4966 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 0xaU));
    vlTOPp->mk_mac_int__DOT__x___05Fh4655 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 9U));
    vlTOPp->mk_mac_int__DOT__x___05Fh4344 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 8U));
    vlTOPp->mk_mac_int__DOT__x___05Fh4033 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 7U));
    vlTOPp->mk_mac_int__DOT__x___05Fh3722 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 6U));
    vlTOPp->mk_mac_int__DOT__x___05Fh3411 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 5U));
    vlTOPp->mk_mac_int__DOT__x___05Fh3100 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 4U));
    vlTOPp->mk_mac_int__DOT__x___05Fh2789 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 3U));
    vlTOPp->mk_mac_int__DOT__x___05Fh2478 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 2U));
    vlTOPp->mk_mac_int__DOT__x___05Fh2165 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2) 
                                                   >> 1U));
    vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_csa_unit_ripple_car_ETC___05Fq1 
        = ((1U & (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                  & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2))
            ? 2ULL : 0ULL);
    vlTOPp->mk_mac_int__DOT__x___05Fh46701 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1eU));
    vlTOPp->mk_mac_int__DOT__x___05Fh47010 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1fU));
    vlTOPp->mk_mac_int__DOT__x___05Fh46083 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1cU));
    vlTOPp->mk_mac_int__DOT__x___05Fh46392 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1dU));
    vlTOPp->mk_mac_int__DOT__x___05Fh47111 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1eU));
    vlTOPp->mk_mac_int__DOT__x___05Fh45465 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1aU));
    vlTOPp->mk_mac_int__DOT__x___05Fh45774 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1bU));
    vlTOPp->mk_mac_int__DOT__x___05Fh44847 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x18U));
    vlTOPp->mk_mac_int__DOT__x___05Fh45156 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x19U));
    vlTOPp->mk_mac_int__DOT__x___05Fh44229 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x16U));
    vlTOPp->mk_mac_int__DOT__x___05Fh44538 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x17U));
    vlTOPp->mk_mac_int__DOT__x___05Fh43611 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x14U));
    vlTOPp->mk_mac_int__DOT__x___05Fh43920 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x15U));
    vlTOPp->mk_mac_int__DOT__x___05Fh46802 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1dU));
    vlTOPp->mk_mac_int__DOT__x___05Fh42993 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x12U));
    vlTOPp->mk_mac_int__DOT__x___05Fh43302 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x13U));
    vlTOPp->mk_mac_int__DOT__x___05Fh42375 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x10U));
    vlTOPp->mk_mac_int__DOT__x___05Fh42684 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x11U));
    vlTOPp->mk_mac_int__DOT__x___05Fh41757 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0xeU));
    vlTOPp->mk_mac_int__DOT__x___05Fh42066 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0xfU));
    vlTOPp->mk_mac_int__DOT__x___05Fh46493 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1cU));
    vlTOPp->mk_mac_int__DOT__x___05Fh41139 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0xcU));
    vlTOPp->mk_mac_int__DOT__x___05Fh41448 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0xdU));
    vlTOPp->mk_mac_int__DOT__x___05Fh40521 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0xaU));
    vlTOPp->mk_mac_int__DOT__x___05Fh40830 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0xbU));
    vlTOPp->mk_mac_int__DOT__x___05Fh39903 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 8U));
    vlTOPp->mk_mac_int__DOT__x___05Fh40212 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 9U));
    vlTOPp->mk_mac_int__DOT__x___05Fh39285 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 6U));
    vlTOPp->mk_mac_int__DOT__x___05Fh39594 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 7U));
    vlTOPp->mk_mac_int__DOT__x___05Fh46184 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1bU));
    vlTOPp->mk_mac_int__DOT__x___05Fh38667 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 4U));
    vlTOPp->mk_mac_int__DOT__x___05Fh38976 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 5U));
    vlTOPp->mk_mac_int__DOT__x___05Fh38047 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 2U));
    vlTOPp->mk_mac_int__DOT__x___05Fh38358 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 3U));
    vlTOPp->mk_mac_int__DOT__IF_carry_save_adder_unit_ripple_carry_adder_rg_ETC___05Fq8 
        = ((1U & (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                  ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh37741 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 1U));
    vlTOPp->mk_mac_int__DOT__x___05Fh45875 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x1aU));
    vlTOPp->mk_mac_int__DOT__x___05Fh45566 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x19U));
    vlTOPp->mk_mac_int__DOT__x___05Fh45257 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x18U));
    vlTOPp->mk_mac_int__DOT__x___05Fh44948 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x17U));
    vlTOPp->mk_mac_int__DOT__x___05Fh44639 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x16U));
    vlTOPp->mk_mac_int__DOT__x___05Fh44330 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x15U));
    vlTOPp->mk_mac_int__DOT__x___05Fh44021 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x14U));
    vlTOPp->mk_mac_int__DOT__x___05Fh43712 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x13U));
    vlTOPp->mk_mac_int__DOT__x___05Fh43403 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x12U));
    vlTOPp->mk_mac_int__DOT__x___05Fh43094 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x11U));
    vlTOPp->mk_mac_int__DOT__x___05Fh42785 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0x10U));
    vlTOPp->mk_mac_int__DOT__x___05Fh42476 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0xfU));
    vlTOPp->mk_mac_int__DOT__x___05Fh42167 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0xeU));
    vlTOPp->mk_mac_int__DOT__x___05Fh41858 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0xdU));
    vlTOPp->mk_mac_int__DOT__x___05Fh41549 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0xcU));
    vlTOPp->mk_mac_int__DOT__x___05Fh41240 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0xbU));
    vlTOPp->mk_mac_int__DOT__x___05Fh40931 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 0xaU));
    vlTOPp->mk_mac_int__DOT__x___05Fh40622 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 9U));
    vlTOPp->mk_mac_int__DOT__x___05Fh40313 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 8U));
    vlTOPp->mk_mac_int__DOT__x___05Fh40004 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 7U));
    vlTOPp->mk_mac_int__DOT__x___05Fh39695 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 6U));
    vlTOPp->mk_mac_int__DOT__x___05Fh39386 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 5U));
    vlTOPp->mk_mac_int__DOT__x___05Fh39077 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 4U));
    vlTOPp->mk_mac_int__DOT__x___05Fh38768 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 3U));
    vlTOPp->mk_mac_int__DOT__x___05Fh38459 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 2U));
    vlTOPp->mk_mac_int__DOT__x___05Fh38148 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2) 
                                               >> 1U));
    vlTOPp->mk_mac_int__DOT__IF_carry_save_adder_unit_ripple_carry_adder_rg_ETC___05Fq2 
        = ((1U & (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                  & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2))
            ? 2ULL : 0ULL);
    vlTOPp->RDY_mac_int_output = vlTOPp->mk_mac_int__DOT__RDY_mac_int_output;
    vlTOPp->mac_int_output = vlTOPp->mk_mac_int__DOT__mac_int_output;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32_D_IN 
        = ((6U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p23)) 
           | (1U & (IData)(vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p23_BIT_0_THEN_1_ETC___05Fq23)));
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_carry_save_adder_unit_result 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_carry_save_adder_unit_result;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_output_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_carry_save_adder_unit_result;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_out_EN 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_carry_save_adder_unit_result;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_result = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_result;
    vlTOPp->mk_mac_int__DOT__output_ready_D_IN = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_result;
    vlTOPp->mk_mac_int__DOT__rg_out_EN = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_result;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_wallace_multiplier_unit_endresult 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_endresult;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_out_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_endresult;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_result_EN 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_endresult;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_wallace_multiplier_unit_csa_unit_result 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_csa_unit_result;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_output_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_csa_unit_result;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_out_EN 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_wallace_multiplier_unit_csa_unit_result;
    vlTOPp->mk_mac_int__DOT__WILL_FIRE_RL_accumulation 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_accumulation;
    vlTOPp->mk_mac_int__DOT__accumulation_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_accumulation;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_input_ready_D_IN 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_accumulation;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_EN 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_accumulation;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp2_EN 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_accumulation;
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3_EN 
        = vlTOPp->mk_mac_int__DOT__CAN_FIRE_RL_accumulation;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_D_IN 
        = ((0x80U & ((~ ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_0_986_CONCAT_ETC___05F_d1990) 
                         >> 7U)) << 7U)) | (0x7fU & (IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_0_986_CONCAT_ETC___05F_d1990)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01_D_IN 
        = ((0x80U & ((~ ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_1_995_CONCAT_ETC___05F_d1999) 
                         >> 7U)) << 7U)) | (0x7fU & (IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_1_995_CONCAT_ETC___05F_d1999)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02_D_IN 
        = ((0x80U & ((~ ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_2_004_CONCAT_ETC___05F_d2008) 
                         >> 7U)) << 7U)) | (0x7fU & (IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_2_004_CONCAT_ETC___05F_d2008)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03_D_IN 
        = ((0x80U & ((~ ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_3_013_CONCAT_ETC___05F_d2017) 
                         >> 7U)) << 7U)) | (0x7fU & (IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_3_013_CONCAT_ETC___05F_d2017)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04_D_IN 
        = ((0x80U & ((~ ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_4_022_CONCAT_ETC___05F_d2026) 
                         >> 7U)) << 7U)) | (0x7fU & (IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_4_022_CONCAT_ETC___05F_d2026)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05_D_IN 
        = ((0x80U & ((~ ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_5_031_CONCAT_ETC___05F_d2035) 
                         >> 7U)) << 7U)) | (0x7fU & (IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_5_031_CONCAT_ETC___05F_d2035)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06_D_IN 
        = ((0x80U & ((~ ((IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_6_040_CONCAT_ETC___05F_d2044) 
                         >> 7U)) << 7U)) | (0x7fU & (IData)(vlTOPp->mk_mac_int__DOT__rg_inp_1_985_AND_rg_inp_2_983_BIT_6_040_CONCAT_ETC___05F_d2044)));
    vlTOPp->mk_mac_int__DOT__INV_pp79549___05Fq20 = 
        (0xffU & (~ (IData)(vlTOPp->mk_mac_int__DOT__pp7___05Fh59549)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p23_D_IN 
        = ((4U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13) 
                  >> 2U)) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh31672) 
                               ^ (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p15)) 
                              << 1U) | (1U & (IData)(vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p13_BIT_2_XOR_wa_ETC___05Fq22))));
    vlTOPp->mk_mac_int__DOT__x___05Fh30929 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh30931) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh30932));
    vlTOPp->mk_mac_int__DOT__x___05Fh26350 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh26352) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh26353));
    vlTOPp->mk_mac_int__DOT__x___05Fh27356 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh27358) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh27359));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p14_D_IN 
        = ((4U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh28700) 
                   << 2U) ^ (0xfffffffcU & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06)))) 
           | ((2U & ((0xfffffffeU & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06)) 
                     ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                        << 1U))) | (1U & (IData)(vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p06_BIT_0_THEN_1_ETC___05Fq21))));
    vlTOPp->mk_mac_int__DOT__x___05Fh27240 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh27242) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh27243));
    vlTOPp->mk_mac_int__DOT__x___05Fh26233 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh26235) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh26236));
    vlTOPp->mk_mac_int__DOT__x___05Fh26116 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh26118) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh26119));
    vlTOPp->mk_mac_int__DOT__IF_x8279_XOR_wallace_multiplier_unit_rg_p05_BI_ETC___05Fq13 
        = ((1U & ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh28279) 
                  ^ (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05)))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh27008 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh27010) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh27011));
    vlTOPp->mk_mac_int__DOT__x___05Fh27124 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh27126) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh27127));
    vlTOPp->mk_mac_int__DOT__x___05Fh26892 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh26894) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh26895));
    vlTOPp->mk_mac_int__DOT__x___05Fh35055 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh35057) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh35058));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30_202_BIT_7_236_X_ETC___05F_d1284 
        = ((0x80U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh35732) 
                      ^ (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32)) 
                     << 7U)) | ((0x40U & ((0xffffffc0U 
                                           & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30)) 
                                          ^ (0xffffffc0U 
                                             & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                << 4U)))) 
                                | (0x3fU & (IData)(vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p30_BIT_5_XOR_wa_ETC___05Fq3))));
    vlTOPp->mk_mac_int__DOT__x___05Fh34826 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh34828) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh34829));
    vlTOPp->mk_mac_int__DOT__x___05Fh34941 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh34943) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh34944));
    vlTOPp->mk_mac_int__DOT__x___05Fh32994 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32996) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32997));
    vlTOPp->mk_mac_int__DOT__x___05Fh32766 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32768) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32769));
    vlTOPp->mk_mac_int__DOT__x___05Fh32880 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32882) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32883));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_5_142_X_ETC___05F_d1189 
        = ((2U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh33495) 
                   ^ (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22)) 
                  << 1U)) | (1U & (IData)(vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p20_BIT_4_XOR_wa_ETC___05Fq18)));
    vlTOPp->mk_mac_int__DOT__x___05Fh32538 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32540) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32541));
    vlTOPp->mk_mac_int__DOT__x___05Fh32652 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32654) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32655));
    vlTOPp->mk_mac_int__DOT__x___05Fh32309 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32311) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32312));
    vlTOPp->mk_mac_int__DOT__x___05Fh32424 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32426) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32427));
    vlTOPp->mk_mac_int__DOT__x___05Fh25999 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh26001) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh26002));
    vlTOPp->mk_mac_int__DOT__x___05Fh25882 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25884) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25885));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_8_57_XOR_ETC___05F_d1072 
        = ((8U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh31403) 
                   << 3U) ^ (0x3ffffff8U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                            >> 2U)))) 
           | ((4U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh31361) 
                      << 2U) ^ (0x3ffffffcU & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                               >> 2U)))) 
              | ((2U & ((0xfffffffeU & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13)) 
                        ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p14) 
                           << 1U))) | (1U & (IData)(vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p13_BIT_0_THEN_1_ETC___05Fq16)))));
    vlTOPp->mk_mac_int__DOT__x___05Fh30128 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh30130) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh30131));
    vlTOPp->mk_mac_int__DOT__x___05Fh29900 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29902) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29903));
    vlTOPp->mk_mac_int__DOT__x___05Fh30014 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh30016) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh30017));
    vlTOPp->mk_mac_int__DOT__x___05Fh29672 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29674) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29675));
    vlTOPp->mk_mac_int__DOT__x___05Fh29786 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29788) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29789));
    vlTOPp->mk_mac_int__DOT__IF_x0603_XOR_wallace_multiplier_unit_rg_p12_BI_ETC___05Fq15 
        = ((1U & ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh30603) 
                  ^ (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12)))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh29444 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29446) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29447));
    vlTOPp->mk_mac_int__DOT__x___05Fh29558 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29560) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29561));
    vlTOPp->mk_mac_int__DOT__x___05Fh29215 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29217) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29218));
    vlTOPp->mk_mac_int__DOT__x___05Fh29330 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29332) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29333));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_45_BIT_5_62_XOR_ETC___05F_d891 
        = ((4U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh27855) 
                   << 2U) ^ (0x7ffffffcU & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                            >> 1U)))) 
           | ((2U & ((0xfffffffeU & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03)) 
                     ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                        << 1U))) | (1U & (IData)(vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p03_BIT_0_THEN_1_ETC___05Fq12))));
    vlTOPp->mk_mac_int__DOT__x___05Fh25650 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25652) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25653));
    vlTOPp->mk_mac_int__DOT__x___05Fh25766 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25768) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25769));
    vlTOPp->mk_mac_int__DOT__IF_x6684_XOR_wallace_multiplier_unit_rg_p02_BI_ETC___05Fq11 
        = ((1U & ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh26684) 
                  ^ (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02)))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh25418 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25420) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25421));
    vlTOPp->mk_mac_int__DOT__x___05Fh25534 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25536) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25537));
    vlTOPp->mk_mac_int__DOT__x___05Fh25185 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25187) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25188));
    vlTOPp->mk_mac_int__DOT__x___05Fh25302 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25304) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25305));
    vlTOPp->mk_mac_int__DOT__x___05Fh58242 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh58244) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh58245));
    vlTOPp->mk_mac_int__DOT__x___05Fh57876 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh57878) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh57879));
    vlTOPp->mk_mac_int__DOT__x___05Fh58059 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh58061) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh58062));
    vlTOPp->mk_mac_int__DOT__x___05Fh57510 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh57512) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh57513));
    vlTOPp->mk_mac_int__DOT__x___05Fh57693 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh57695) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh57696));
    vlTOPp->mk_mac_int__DOT__x___05Fh57144 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh57146) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh57147));
    vlTOPp->mk_mac_int__DOT__x___05Fh57327 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh57329) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh57330));
    vlTOPp->mk_mac_int__DOT__x___05Fh56778 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh56780) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh56781));
    vlTOPp->mk_mac_int__DOT__x___05Fh56961 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh56963) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh56964));
    vlTOPp->mk_mac_int__DOT__x___05Fh56412 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh56414) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh56415));
    vlTOPp->mk_mac_int__DOT__x___05Fh56595 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh56597) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh56598));
    vlTOPp->mk_mac_int__DOT__x___05Fh56046 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh56048) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh56049));
    vlTOPp->mk_mac_int__DOT__x___05Fh56229 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh56231) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh56232));
    vlTOPp->mk_mac_int__DOT__x___05Fh55680 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh55682) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh55683));
    vlTOPp->mk_mac_int__DOT__x___05Fh55863 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh55865) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh55866));
    vlTOPp->mk_mac_int__DOT__x___05Fh55314 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh55316) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh55317));
    vlTOPp->mk_mac_int__DOT__x___05Fh55497 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh55499) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh55500));
    vlTOPp->mk_mac_int__DOT__IF_x8789_XOR_carry_save_adder_unit_rg_inp3_BIT_ETC___05Fq9 
        = ((1U & ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh48789) 
                  ^ vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh54948 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh54950) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh54951));
    vlTOPp->mk_mac_int__DOT__x___05Fh55131 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh55133) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh55134));
    vlTOPp->mk_mac_int__DOT__x___05Fh54582 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh54584) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh54585));
    vlTOPp->mk_mac_int__DOT__x___05Fh54765 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh54767) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh54768));
    vlTOPp->mk_mac_int__DOT__x___05Fh54216 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh54218) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh54219));
    vlTOPp->mk_mac_int__DOT__x___05Fh54399 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh54401) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh54402));
    vlTOPp->mk_mac_int__DOT__x___05Fh53850 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh53852) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh53853));
    vlTOPp->mk_mac_int__DOT__x___05Fh54033 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh54035) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh54036));
    vlTOPp->mk_mac_int__DOT__x___05Fh53484 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh53486) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh53487));
    vlTOPp->mk_mac_int__DOT__x___05Fh53667 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh53669) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh53670));
    vlTOPp->mk_mac_int__DOT__x___05Fh53118 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh53120) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh53121));
    vlTOPp->mk_mac_int__DOT__x___05Fh53301 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh53303) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh53304));
    vlTOPp->mk_mac_int__DOT__x___05Fh52935 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh52937) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh52938));
    vlTOPp->mk_mac_int__DOT__x___05Fh52756 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh52758) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh52759));
    vlTOPp->mk_mac_int__DOT__x___05Fh22487 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh22489) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh22490));
    vlTOPp->mk_mac_int__DOT__x___05Fh22121 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh22123) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh22124));
    vlTOPp->mk_mac_int__DOT__x___05Fh22304 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh22306) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh22307));
    vlTOPp->mk_mac_int__DOT__x___05Fh21755 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh21757) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh21758));
    vlTOPp->mk_mac_int__DOT__x___05Fh21938 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh21940) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh21941));
    vlTOPp->mk_mac_int__DOT__x___05Fh21389 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh21391) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh21392));
    vlTOPp->mk_mac_int__DOT__x___05Fh21572 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh21574) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh21575));
    vlTOPp->mk_mac_int__DOT__x___05Fh21023 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh21025) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh21026));
    vlTOPp->mk_mac_int__DOT__x___05Fh21206 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh21208) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh21209));
    vlTOPp->mk_mac_int__DOT__x___05Fh20657 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh20659) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh20660));
    vlTOPp->mk_mac_int__DOT__x___05Fh20840 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh20842) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh20843));
    vlTOPp->mk_mac_int__DOT__x___05Fh20291 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh20293) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh20294));
    vlTOPp->mk_mac_int__DOT__x___05Fh20474 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh20476) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh20477));
    vlTOPp->mk_mac_int__DOT__x___05Fh19925 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh19927) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh19928));
    vlTOPp->mk_mac_int__DOT__x___05Fh20108 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh20110) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh20111));
    vlTOPp->mk_mac_int__DOT__x___05Fh19559 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh19561) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh19562));
    vlTOPp->mk_mac_int__DOT__x___05Fh19742 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh19744) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh19745));
    vlTOPp->mk_mac_int__DOT__IF_x2997_XOR_wallace_multiplier_unit_csa_unit___05FETC___05Fq6 
        = ((1U & ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh12997) 
                  ^ vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh19193 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh19195) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh19196));
    vlTOPp->mk_mac_int__DOT__x___05Fh19376 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh19378) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh19379));
    vlTOPp->mk_mac_int__DOT__x___05Fh18827 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh18829) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh18830));
    vlTOPp->mk_mac_int__DOT__x___05Fh19010 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh19012) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh19013));
    vlTOPp->mk_mac_int__DOT__x___05Fh18461 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh18463) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh18464));
    vlTOPp->mk_mac_int__DOT__x___05Fh18644 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh18646) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh18647));
    vlTOPp->mk_mac_int__DOT__x___05Fh18095 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh18097) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh18098));
    vlTOPp->mk_mac_int__DOT__x___05Fh18278 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh18280) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh18281));
    vlTOPp->mk_mac_int__DOT__x___05Fh17729 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh17731) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh17732));
    vlTOPp->mk_mac_int__DOT__x___05Fh17912 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh17914) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh17915));
    vlTOPp->mk_mac_int__DOT__x___05Fh17363 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh17365) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh17366));
    vlTOPp->mk_mac_int__DOT__x___05Fh17546 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh17548) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh17549));
    vlTOPp->mk_mac_int__DOT__x___05Fh17180 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh17182) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh17183));
    vlTOPp->mk_mac_int__DOT__x___05Fh17001 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh17003) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh17004));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d292 
        = ((2U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh1754) 
                   ^ (IData)((vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_csa_unit_ripple_car_ETC___05Fq1 
                              >> 1U))) << 1U)) | (1U 
                                                  & vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_csa_unit_ripple_car_ETC___05Fq5));
    vlTOPp->mk_mac_int__DOT__y___05Fh2164 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                                    >> 1U) 
                                                   & (IData)(
                                                             (vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_csa_unit_ripple_car_ETC___05Fq1 
                                                              >> 1U))));
    vlTOPp->mk_mac_int__DOT__y___05Fh2166 = (1U & (
                                                   (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                                    >> 1U) 
                                                   & (IData)(
                                                             (vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_csa_unit_ripple_car_ETC___05Fq1 
                                                              >> 1U))));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1586 
        = ((2U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh37741) 
                   ^ (IData)((vlTOPp->mk_mac_int__DOT__IF_carry_save_adder_unit_ripple_carry_adder_rg_ETC___05Fq2 
                              >> 1U))) << 1U)) | (1U 
                                                  & vlTOPp->mk_mac_int__DOT__IF_carry_save_adder_unit_ripple_carry_adder_rg_ETC___05Fq8));
    vlTOPp->mk_mac_int__DOT__y___05Fh38147 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                                >> 1U) 
                                               & (IData)(
                                                         (vlTOPp->mk_mac_int__DOT__IF_carry_save_adder_unit_ripple_carry_adder_rg_ETC___05Fq2 
                                                          >> 1U))));
    vlTOPp->mk_mac_int__DOT__y___05Fh38149 = (1U & 
                                              ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                                >> 1U) 
                                               & (IData)(
                                                         (vlTOPp->mk_mac_int__DOT__IF_carry_save_adder_unit_ripple_carry_adder_rg_ETC___05Fq2 
                                                          >> 1U))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07_D_IN 
        = ((0x80U & ((~ ((IData)(vlTOPp->mk_mac_int__DOT__INV_pp79549___05Fq20) 
                         >> 7U)) << 7U)) | (0x7fU & (IData)(vlTOPp->mk_mac_int__DOT__INV_pp79549___05Fq20)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03_18_BIT_4_31_XOR_ETC___05F_d909 
        = ((4U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh28359) 
                   << 2U) ^ (0xfffffffcU & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05)))) 
           | ((2U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh28317) 
                      << 1U) ^ (0xfffffffeU & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05)))) 
              | (1U & (IData)(vlTOPp->mk_mac_int__DOT__IF_x8279_XOR_wallace_multiplier_unit_rg_p05_BI_ETC___05Fq13))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30_202_BIT_11_213___05FETC___05F_d1286 
        = ((0xc00U & ((0xfffffc00U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30)) 
                      ^ (0xfffffc00U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                        << 4U)))) | 
           ((0x200U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh35816) 
                        << 9U) ^ (0xfffffe00U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32) 
                                                 << 7U)))) 
            | ((0x100U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh35774) 
                           << 8U) ^ (0xffffff00U & 
                                     ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p32) 
                                      << 7U)))) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30_202_BIT_7_236_X_ETC___05F_d1284))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30_202_BIT_8_228_A_ETC___05F_d1261 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh34941) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh34942)) 
            << 9U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh34826) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh34827)) 
                       << 8U) | ((0x80U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                            << 1U) 
                                           & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                              << 5U))) 
                                 | ((0x40U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                               << 1U) 
                                              & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                 << 5U))) 
                                    | ((0x20U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                                  << 1U) 
                                                 & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                    << 5U))) 
                                       | ((0x10U & 
                                           ((0xfffffff0U 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30)) 
                                            ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                               << 4U))) 
                                          | ((0xeU 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30)) 
                                             | (1U 
                                                & (IData)(vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p30_BIT_0_THEN_1_ETC___05Fq4)))))))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_9_110_X_ETC___05F_d1191 
        = ((0x20U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh33663) 
                      << 5U) ^ (0xffffffe0U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                               << 1U)))) 
           | ((0x10U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh33621) 
                         << 4U) ^ (0xfffffff0U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  << 1U)))) 
              | ((8U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh33579) 
                         << 3U) ^ (0xfffffff8U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  << 1U)))) 
                 | ((4U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh33537) 
                            << 2U) ^ (0xfffffffcU & 
                                      ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                       << 1U)))) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_5_142_X_ETC___05F_d1189)))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_6_134_A_ETC___05F_d1163 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32424) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32425)) 
            << 7U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32309) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32310)) 
                       << 6U) | ((0x20U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                            << 1U) 
                                           & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                              << 4U))) 
                                 | ((0x10U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                               << 1U) 
                                              & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                 << 4U))) 
                                    | ((8U & ((0xfffffff8U 
                                               & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20)) 
                                              ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                 << 3U))) 
                                       | ((6U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20)) 
                                          | (1U & (IData)(vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p20_BIT_0_THEN_1_ETC___05Fq17))))))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22_D_IN 
        = ((0x60U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13)) 
           | ((0x10U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh31445) 
                         << 4U) ^ (0x3ffffff0U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12) 
                                                  >> 2U)))) 
              | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_8_57_XOR_ETC___05F_d1072)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_4_89_XOR_ETC___05F_d1054 
        = ((2U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh30641) 
                   << 1U) ^ (0xfffffffeU & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12)))) 
           | (1U & (IData)(vlTOPp->mk_mac_int__DOT__IF_x0603_XOR_wallace_multiplier_unit_rg_p12_BI_ETC___05Fq15)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_4_89_AND_ETC___05F_d1015 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29330) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29331)) 
            << 5U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29215) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29216)) 
                       << 4U) | ((8U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                         << 1U) & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                   << 3U))) 
                                 | ((4U & ((0xfffffffcU 
                                            & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10)) 
                                           ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                              << 2U))) 
                                    | ((2U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10)) 
                                       | (1U & (IData)(vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p10_BIT_0_THEN_1_ETC___05Fq14)))))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02_27_BIT_7_28_XOR_ETC___05F_d893 
        = ((0x40U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh28060) 
                      << 6U) ^ (0xffffffc0U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                               << 1U)))) 
           | ((0x20U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                         << 4U) & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                                   << 5U))) | ((0x10U 
                                                & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh27939) 
                                                    << 4U) 
                                                   ^ 
                                                   (0x7ffffff0U 
                                                    & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                       >> 1U)))) 
                                               | ((8U 
                                                   & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh27897) 
                                                       << 3U) 
                                                      ^ 
                                                      (0x7ffffff8U 
                                                       & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02) 
                                                          >> 1U)))) 
                                                  | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_45_BIT_5_62_XOR_ETC___05F_d891)))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_45_BIT_4_70_XOR_ETC___05F_d866 
        = ((4U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh26764) 
                   << 2U) ^ (0xfffffffcU & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02)))) 
           | ((2U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh26722) 
                      << 1U) ^ (0xfffffffeU & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02)))) 
              | (1U & (IData)(vlTOPp->mk_mac_int__DOT__IF_x6684_XOR_wallace_multiplier_unit_rg_p02_BI_ETC___05Fq11))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_45_BIT_3_78_AND_ETC___05F_d802 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25302) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25303)) 
            << 4U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25185) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25186)) 
                       << 3U) | ((4U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00) 
                                         << 1U) & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                                   << 2U))) 
                                 | ((2U & ((0xfffffffeU 
                                            & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00)) 
                                           ^ ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p01) 
                                              << 1U))) 
                                    | (1U & (IData)(vlTOPp->mk_mac_int__DOT__IF_wallace_multiplier_unit_rg_p00_BIT_0_THEN_1_ETC___05Fq10))))));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_1_765_XO_ETC___05F_d1777 
        = ((2U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh48899) 
                   << 1U) ^ (0xfffffffeU & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
           | (1U & vlTOPp->mk_mac_int__DOT__IF_x8789_XOR_carry_save_adder_unit_rg_inp3_BIT_ETC___05Fq9));
    vlTOPp->mk_mac_int__DOT__IF_x2756_OR_y2757_THEN_1_ELSE_0___05Fq19 
        = (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh52756) 
            | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh52757))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d483 
        = ((2U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh13107) 
                   << 1U) ^ (0xfffffffeU & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
           | (1U & vlTOPp->mk_mac_int__DOT__IF_x2997_XOR_wallace_multiplier_unit_csa_unit___05FETC___05Fq6));
    vlTOPp->mk_mac_int__DOT__IF_x7001_OR_y7002_THEN_1_ELSE_0___05Fq7 
        = (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh17001) 
            | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh17002))
            ? 1U : 0U);
    vlTOPp->mk_mac_int__DOT__x___05Fh2163 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh2165) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2166));
    vlTOPp->mk_mac_int__DOT__x___05Fh38146 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh38148) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38149));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05_00_BIT_4_15_XOR_ETC___05F_d910 
        = ((0x10U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh28443) 
                      << 4U) ^ (0xfffffff0U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                                               << 2U)))) 
           | ((8U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh28401) 
                      << 3U) ^ (0x3ffffff8U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                                               >> 2U)))) 
              | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03_18_BIT_4_31_XOR_ETC___05F_d909)));
    vlTOPp->mk_mac_int__DOT__w41___05Fh34155 = ((0xf000U 
                                                 & ((0xfffff000U 
                                                     & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30)) 
                                                    ^ 
                                                    (0xfffff000U 
                                                     & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                        << 4U)))) 
                                                | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30_202_BIT_11_213___05FETC___05F_d1286));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30_202_BIT_10_216___05FETC___05F_d1262 
        = ((0x800U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                       << 1U) & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                 << 5U))) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh35055) 
                                               | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh35056)) 
                                              << 0xaU) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30_202_BIT_8_228_A_ETC___05F_d1261)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_13_087___05FETC___05F_d1193 
        = ((0x300U & ((0xfffff00U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                     >> 4U)) ^ (0x7fffff00U 
                                                & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                   >> 1U)))) 
           | ((0x80U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh33747) 
                         << 7U) ^ (0xffffff80U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                                  << 1U)))) 
              | ((0x40U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh33705) 
                            << 6U) ^ (0xffffffc0U & 
                                      ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p22) 
                                       << 1U)))) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_9_110_X_ETC___05F_d1191))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_8_118_A_ETC___05F_d1164 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32652) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32653)) 
            << 9U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32538) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32539)) 
                       << 8U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_6_134_A_ETC___05F_d1163)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13_028_BIT_2_038_A_ETC___05F_d1056 
        = ((0x30U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13) 
                      << 3U) & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p14) 
                                << 4U))) | ((8U & (
                                                   ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh30725) 
                                                    << 3U) 
                                                   ^ 
                                                   (0xfffffff8U 
                                                    & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12)))) 
                                            | ((4U 
                                                & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh30683) 
                                                    << 2U) 
                                                   ^ 
                                                   (0xfffffffcU 
                                                    & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12)))) 
                                               | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_4_89_XOR_ETC___05F_d1054))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_6_73_AND_ETC___05F_d1016 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29558) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29559)) 
            << 7U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29444) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29445)) 
                       << 6U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_4_89_AND_ETC___05F_d1015)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12_D_IN 
        = ((0x100U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh28144) 
                       << 8U) ^ (0xffffff00U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                << 3U)))) 
           | ((0x80U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh28102) 
                         << 7U) ^ (0xffffff80U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05) 
                                                  << 2U)))) 
              | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02_27_BIT_7_28_XOR_ETC___05F_d893)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03_18_BIT_2_47_AND_ETC___05F_d867 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh26892) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh26893)) 
            << 4U) | ((8U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03) 
                              << 2U) & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04) 
                                        << 3U))) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_45_BIT_4_70_XOR_ETC___05F_d866)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_45_BIT_5_62_AND_ETC___05F_d803 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25534) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25535)) 
            << 6U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25418) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25419)) 
                       << 5U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_45_BIT_3_78_AND_ETC___05F_d802)));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_5_745_XO_ETC___05F_d1779 
        = ((0x20U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh49343) 
                      << 5U) ^ (0xffffffe0U & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
           | ((0x10U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh49232) 
                         << 4U) ^ (0xfffffff0U & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
              | ((8U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh49121) 
                         << 3U) ^ (0xfffffff8U & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                 | ((4U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh49010) 
                            << 2U) ^ (0xfffffffcU & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                    | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_1_765_XO_ETC___05F_d1777)))));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_1_765_AN_ETC___05F_d1950 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh52935) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh52936)) 
            << 1U) | (1U & vlTOPp->mk_mac_int__DOT__IF_x2756_OR_y2757_THEN_1_ELSE_0___05Fq19));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d485 
        = ((0x20U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh13551) 
                      << 5U) ^ (0xffffffe0U & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
           | ((0x10U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh13440) 
                         << 4U) ^ (0xfffffff0U & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
              | ((8U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh13329) 
                         << 3U) ^ (0xfffffff8U & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                 | ((4U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh13218) 
                            << 2U) ^ (0xfffffffcU & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                    | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d483)))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d656 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh17180) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh17181)) 
            << 1U) | (1U & vlTOPp->mk_mac_int__DOT__IF_x7001_OR_y7002_THEN_1_ELSE_0___05Fq7));
    vlTOPp->mk_mac_int__DOT__y___05Fh2063 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh2163) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2164));
    vlTOPp->mk_mac_int__DOT__y___05Fh38048 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh38146) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38147));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13_D_IN 
        = ((0x40U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                     << 2U)) | ((0x20U & ((0xffffffe0U 
                                           & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                              << 1U)) 
                                          ^ (0xffffffe0U 
                                             & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                                                << 2U)))) 
                                | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05_00_BIT_4_15_XOR_ETC___05F_d910)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp2_D_IN 
        = ((0xffff0000U & ((- (IData)((1U & ((IData)(vlTOPp->mk_mac_int__DOT__w41___05Fh34155) 
                                             >> 0xfU)))) 
                           << 0x10U)) | (IData)(vlTOPp->mk_mac_int__DOT__w41___05Fh34155));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p41_D_IN 
        = vlTOPp->mk_mac_int__DOT__w41___05Fh34155;
    vlTOPp->mk_mac_int__DOT__w40___05Fh34153 = ((0xf000U 
                                                 & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30) 
                                                     << 1U) 
                                                    & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31) 
                                                       << 5U))) 
                                                | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30_202_BIT_10_216___05FETC___05F_d1262));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p31_D_IN 
        = ((0x800U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                      >> 4U)) | ((0x400U & ((0xffffc00U 
                                             & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                                                >> 4U)) 
                                            ^ (0x7ffffc00U 
                                               & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                                  >> 1U)))) 
                                 | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_13_087___05FETC___05F_d1193)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_10_102___05FETC___05F_d1165 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32880) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32881)) 
            << 0xbU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32766) 
                          | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32767)) 
                         << 0xaU) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_8_118_A_ETC___05F_d1164)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_10_41_XO_ETC___05F_d1057 
        = ((0x80U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh31017) 
                      << 7U) ^ (0xffffff80U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12)))) 
           | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh30929) 
                | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh30930)) 
               << 6U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p13_028_BIT_2_038_A_ETC___05F_d1056)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_8_57_AND_ETC___05F_d1017 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29786) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29787)) 
            << 9U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29672) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29673)) 
                       << 8U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_6_73_AND_ETC___05F_d1016)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03_18_BIT_4_31_AND_ETC___05F_d868 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh27124) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh27125)) 
            << 6U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh27008) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh27009)) 
                       << 5U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03_18_BIT_2_47_AND_ETC___05F_d867)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_45_BIT_7_46_AND_ETC___05F_d804 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25766) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25767)) 
            << 8U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25650) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25651)) 
                       << 7U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_45_BIT_5_62_AND_ETC___05F_d803)));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_9_725_XO_ETC___05F_d1781 
        = ((0x200U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh49787) 
                       << 9U) ^ (0xfffffe00U & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
           | ((0x100U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh49676) 
                          << 8U) ^ (0xffffff00U & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
              | ((0x80U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh49565) 
                            << 7U) ^ (0xffffff80U & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                 | ((0x40U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh49454) 
                               << 6U) ^ (0xffffffc0U 
                                         & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                    | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_5_745_XO_ETC___05F_d1779)))));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_3_755_AN_ETC___05F_d1951 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh53301) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh53302)) 
            << 3U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh53118) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh53119)) 
                       << 2U) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_1_765_AN_ETC___05F_d1950)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d487 
        = ((0x200U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh13995) 
                       << 9U) ^ (0xfffffe00U & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
           | ((0x100U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh13884) 
                          << 8U) ^ (0xffffff00U & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
              | ((0x80U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh13773) 
                            << 7U) ^ (0xffffff80U & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                 | ((0x40U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh13662) 
                               << 6U) ^ (0xffffffc0U 
                                         & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                    | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d485)))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d657 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh17546) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh17547)) 
            << 3U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh17363) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh17364)) 
                       << 2U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d656)));
    vlTOPp->mk_mac_int__DOT__y___05Fh2477 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 2U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2063));
    vlTOPp->mk_mac_int__DOT__y___05Fh2479 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 2U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2063));
    vlTOPp->mk_mac_int__DOT__y___05Fh38458 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 2U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38048));
    vlTOPp->mk_mac_int__DOT__y___05Fh38460 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 2U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38048));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_D_IN 
        = ((0xffff0000U & ((- (IData)((1U & ((IData)(vlTOPp->mk_mac_int__DOT__w40___05Fh34153) 
                                             >> 0xfU)))) 
                           << 0x10U)) | (IData)(vlTOPp->mk_mac_int__DOT__w40___05Fh34153));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p40_D_IN 
        = vlTOPp->mk_mac_int__DOT__w40___05Fh34153;
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_12_090___05FETC___05F_d1166 
        = ((0x2000U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                        << 1U) & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                  << 4U))) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh32994) 
                                                | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh32995)) 
                                               << 0xcU) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_10_102___05FETC___05F_d1165)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_12_29_XO_ETC___05F_d1058 
        = ((0x200U & ((0x1ffffe00U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                      >> 3U)) ^ (0x7ffffe00U 
                                                 & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                    >> 1U)))) 
           | ((0x100U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh31059) 
                          << 8U) ^ (0xffffff00U & (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p12)))) 
              | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_10_41_XO_ETC___05F_d1057)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_10_41_AN_ETC___05F_d1018 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh30014) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh30015)) 
            << 0xbU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh29900) 
                          | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh29901)) 
                         << 0xaU) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_8_57_AND_ETC___05F_d1017)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05_00_BIT_4_15_AND_ETC___05F_d869 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh27356) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh27357)) 
            << 8U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh27240) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh27241)) 
                       << 7U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p03_18_BIT_4_31_AND_ETC___05F_d868)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02_27_BIT_7_28_AND_ETC___05F_d805 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25999) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh26000)) 
            << 0xaU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh25882) 
                          | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh25883)) 
                         << 9U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p00_45_BIT_7_46_AND_ETC___05F_d804)));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_13_705_X_ETC___05F_d1783 
        = ((0x2000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh50231) 
                        << 0xdU) ^ (0xffffe000U & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
           | ((0x1000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh50120) 
                           << 0xcU) ^ (0xfffff000U 
                                       & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
              | ((0x800U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh50009) 
                             << 0xbU) ^ (0xfffff800U 
                                         & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                 | ((0x400U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh49898) 
                                << 0xaU) ^ (0xfffffc00U 
                                            & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                    | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_9_725_XO_ETC___05F_d1781)))));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_5_745_AN_ETC___05F_d1952 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh53667) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh53668)) 
            << 5U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh53484) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh53485)) 
                       << 4U) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_3_755_AN_ETC___05F_d1951)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d489 
        = ((0x2000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh14439) 
                        << 0xdU) ^ (0xffffe000U & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
           | ((0x1000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh14328) 
                           << 0xcU) ^ (0xfffff000U 
                                       & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
              | ((0x800U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh14217) 
                             << 0xbU) ^ (0xfffff800U 
                                         & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                 | ((0x400U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh14106) 
                                << 0xaU) ^ (0xfffffc00U 
                                            & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                    | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d487)))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d658 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh17912) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh17913)) 
            << 5U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh17729) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh17730)) 
                       << 4U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d657)));
    vlTOPp->mk_mac_int__DOT__x___05Fh2476 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh2478) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2479));
    vlTOPp->mk_mac_int__DOT__x___05Fh38457 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh38459) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38460));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p30_D_IN 
        = ((0xc000U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20) 
                        << 1U) & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21) 
                                  << 4U))) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_082_BIT_12_090___05FETC___05F_d1166));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p21_D_IN 
        = ((0xc00U & ((0x1ffffc00U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                                      >> 3U)) ^ (0x7ffffc00U 
                                                 & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                                    >> 1U)))) 
           | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_12_29_XO_ETC___05F_d1058));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_12_29_AN_ETC___05F_d1019 
        = ((0x2000U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                        << 1U) & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                  << 3U))) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh30128) 
                                                | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh30129)) 
                                               << 0xcU) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_10_41_AN_ETC___05F_d1018)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11_D_IN 
        = ((0x1000U & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                       << 5U)) | ((0x800U & ((0xfffff800U 
                                              & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                 << 4U)) 
                                             ^ (0xfffff800U 
                                                & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                                                   << 5U)))) 
                                  | ((0x400U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh27544) 
                                                 << 0xaU) 
                                                ^ (0xfffffc00U 
                                                   & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                                                      << 5U)))) 
                                     | ((0x200U & (
                                                   ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                                                    << 5U) 
                                                   & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                                                      << 6U))) 
                                        | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p05_00_BIT_4_15_AND_ETC___05F_d869)))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04_09_BIT_7_10_AND_ETC___05F_d806 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh26233) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh26234)) 
            << 0xcU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh26116) 
                          | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh26117)) 
                         << 0xbU) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p02_27_BIT_7_28_AND_ETC___05F_d805)));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_17_685_X_ETC___05F_d1785 
        = ((0x20000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh50675) 
                         << 0x11U) ^ (0xfffe0000U & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
           | ((0x10000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh50564) 
                            << 0x10U) ^ (0xffff0000U 
                                         & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
              | ((0x8000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh50453) 
                              << 0xfU) ^ (0xffff8000U 
                                          & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                 | ((0x4000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh50342) 
                                 << 0xeU) ^ (0xffffc000U 
                                             & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                    | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_13_705_X_ETC___05F_d1783)))));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_7_735_AN_ETC___05F_d1953 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh54033) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh54034)) 
            << 7U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh53850) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh53851)) 
                       << 6U) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_5_745_AN_ETC___05F_d1952)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d491 
        = ((0x20000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh14883) 
                         << 0x11U) ^ (0xfffe0000U & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
           | ((0x10000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh14772) 
                            << 0x10U) ^ (0xffff0000U 
                                         & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
              | ((0x8000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh14661) 
                              << 0xfU) ^ (0xffff8000U 
                                          & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                 | ((0x4000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh14550) 
                                 << 0xeU) ^ (0xffffc000U 
                                             & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                    | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d489)))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d659 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh18278) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh18279)) 
            << 7U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh18095) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh18096)) 
                       << 6U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d658)));
    vlTOPp->mk_mac_int__DOT__y___05Fh2376 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh2476) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2477));
    vlTOPp->mk_mac_int__DOT__y___05Fh38359 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh38457) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38458));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p20_D_IN 
        = ((0xc000U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10) 
                        << 1U) & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p11) 
                                  << 3U))) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_21_BIT_12_29_AN_ETC___05F_d1019));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p10_D_IN 
        = ((0x4000U & (((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p06) 
                        << 7U) & ((IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p07) 
                                  << 8U))) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh26350) 
                                                | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh26351)) 
                                               << 0xdU) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_rg_p04_09_BIT_7_10_AND_ETC___05F_d806)));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_21_665_X_ETC___05F_d1787 
        = ((0x200000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh51119) 
                          << 0x15U) ^ (0xffe00000U 
                                       & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
           | ((0x100000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh51008) 
                             << 0x14U) ^ (0xfff00000U 
                                          & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
              | ((0x80000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh50897) 
                               << 0x13U) ^ (0xfff80000U 
                                            & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                 | ((0x40000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh50786) 
                                  << 0x12U) ^ (0xfffc0000U 
                                               & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                    | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_17_685_X_ETC___05F_d1785))));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_9_725_AN_ETC___05F_d1954 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh54399) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh54400)) 
            << 9U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh54216) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh54217)) 
                       << 8U) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_7_735_AN_ETC___05F_d1953)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d493 
        = ((0x200000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh15327) 
                          << 0x15U) ^ (0xffe00000U 
                                       & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
           | ((0x100000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh15216) 
                             << 0x14U) ^ (0xfff00000U 
                                          & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
              | ((0x80000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh15105) 
                               << 0x13U) ^ (0xfff80000U 
                                            & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                 | ((0x40000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh14994) 
                                  << 0x12U) ^ (0xfffc0000U 
                                               & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                    | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d491))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d660 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh18644) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh18645)) 
            << 9U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh18461) 
                        | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh18462)) 
                       << 8U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d659)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d293 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh2375) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2376)) 
            << 3U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh2062) 
                        ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2063)) 
                       << 2U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d292)));
    vlTOPp->mk_mac_int__DOT__y___05Fh2788 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 3U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2376));
    vlTOPp->mk_mac_int__DOT__y___05Fh2790 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 3U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2376));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1587 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh38358) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38359)) 
            << 3U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh38047) 
                        ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38048)) 
                       << 2U) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1586)));
    vlTOPp->mk_mac_int__DOT__y___05Fh38767 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 3U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38359));
    vlTOPp->mk_mac_int__DOT__y___05Fh38769 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 3U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38359));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_25_645_X_ETC___05F_d1789 
        = ((0x2000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh51563) 
                           << 0x19U) ^ (0xfe000000U 
                                        & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
           | ((0x1000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh51452) 
                              << 0x18U) ^ (0xff000000U 
                                           & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
              | ((0x800000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh51341) 
                                << 0x17U) ^ (0xff800000U 
                                             & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                 | ((0x400000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh51230) 
                                   << 0x16U) ^ (0xffc00000U 
                                                & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                    | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_21_665_X_ETC___05F_d1787))));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_11_715_A_ETC___05F_d1955 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh54765) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh54766)) 
            << 0xbU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh54582) 
                          | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh54583)) 
                         << 0xaU) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_9_725_AN_ETC___05F_d1954)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d495 
        = ((0x2000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh15771) 
                           << 0x19U) ^ (0xfe000000U 
                                        & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
           | ((0x1000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh15660) 
                              << 0x18U) ^ (0xff000000U 
                                           & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
              | ((0x800000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh15549) 
                                << 0x17U) ^ (0xff800000U 
                                             & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                 | ((0x400000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh15438) 
                                   << 0x16U) ^ (0xffc00000U 
                                                & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                    | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d493))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d661 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh19010) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh19011)) 
            << 0xbU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh18827) 
                          | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh18828)) 
                         << 0xaU) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d660)));
    vlTOPp->mk_mac_int__DOT__x___05Fh2787 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh2789) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2790));
    vlTOPp->mk_mac_int__DOT__x___05Fh38766 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh38768) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38769));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_29_625_X_ETC___05F_d1791 
        = ((0x20000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh52007) 
                            << 0x1dU) ^ (0xe0000000U 
                                         & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
           | ((0x10000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh51896) 
                               << 0x1cU) ^ (0xf0000000U 
                                            & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
              | ((0x8000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh51785) 
                                 << 0x1bU) ^ (0xf8000000U 
                                              & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                 | ((0x4000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh51674) 
                                    << 0x1aU) ^ (0xfc000000U 
                                                 & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
                    | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_25_645_X_ETC___05F_d1789))));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_13_705_A_ETC___05F_d1956 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh55131) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh55132)) 
            << 0xdU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh54948) 
                          | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh54949)) 
                         << 0xcU) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_11_715_A_ETC___05F_d1955)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d497 
        = ((0x20000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh16215) 
                            << 0x1dU) ^ (0xe0000000U 
                                         & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
           | ((0x10000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh16104) 
                               << 0x1cU) ^ (0xf0000000U 
                                            & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
              | ((0x8000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh15993) 
                                 << 0x1bU) ^ (0xf8000000U 
                                              & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                 | ((0x4000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh15882) 
                                    << 0x1aU) ^ (0xfc000000U 
                                                 & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
                    | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d495))));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d662 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh19376) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh19377)) 
            << 0xdU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh19193) 
                          | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh19194)) 
                         << 0xcU) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d661)));
    vlTOPp->mk_mac_int__DOT__y___05Fh2687 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh2787) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2788));
    vlTOPp->mk_mac_int__DOT__y___05Fh38668 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh38766) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38767));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1_D_IN 
        = ((0x80000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh52229) 
                            << 0x1fU) ^ (0x80000000U 
                                         & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
           | ((0x40000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh52118) 
                               << 0x1eU) ^ (0xc0000000U 
                                            & vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp3))) 
              | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_29_625_X_ETC___05F_d1791));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_15_695_A_ETC___05F_d1957 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh55497) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh55498)) 
            << 0xfU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh55314) 
                          | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh55315)) 
                         << 0xeU) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_13_705_A_ETC___05F_d1956)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1_D_IN 
        = ((0x80000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh16437) 
                            << 0x1fU) ^ (0x80000000U 
                                         & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
           | ((0x40000000U & (((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh16326) 
                               << 0x1eU) ^ (0xc0000000U 
                                            & vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp3))) 
              | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d497));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d663 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh19742) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh19743)) 
            << 0xfU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh19559) 
                          | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh19560)) 
                         << 0xeU) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d662)));
    vlTOPp->mk_mac_int__DOT__y___05Fh3099 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 4U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2687));
    vlTOPp->mk_mac_int__DOT__y___05Fh3101 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 4U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2687));
    vlTOPp->mk_mac_int__DOT__y___05Fh39076 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 4U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38668));
    vlTOPp->mk_mac_int__DOT__y___05Fh39078 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 4U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38668));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_17_685_A_ETC___05F_d1958 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh55863) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh55864)) 
            << 0x11U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh55680) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh55681)) 
                          << 0x10U) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_15_695_A_ETC___05F_d1957)));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d664 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh20108) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh20109)) 
            << 0x11U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh19925) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh19926)) 
                          << 0x10U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d663)));
    vlTOPp->mk_mac_int__DOT__x___05Fh3098 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh3100) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3101));
    vlTOPp->mk_mac_int__DOT__x___05Fh39075 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh39077) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39078));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_19_675_A_ETC___05F_d1959 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh56229) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh56230)) 
            << 0x13U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh56046) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh56047)) 
                          << 0x12U) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_17_685_A_ETC___05F_d1958));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d665 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh20474) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh20475)) 
            << 0x13U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh20291) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh20292)) 
                          << 0x12U) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d664));
    vlTOPp->mk_mac_int__DOT__y___05Fh2998 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh3098) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3099));
    vlTOPp->mk_mac_int__DOT__y___05Fh38977 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh39075) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39076));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_21_665_A_ETC___05F_d1960 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh56595) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh56596)) 
            << 0x15U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh56412) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh56413)) 
                          << 0x14U) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_19_675_A_ETC___05F_d1959));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d666 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh20840) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh20841)) 
            << 0x15U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh20657) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh20658)) 
                          << 0x14U) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d665));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d294 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh2997) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2998)) 
            << 5U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh2686) 
                        ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2687)) 
                       << 4U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d293)));
    vlTOPp->mk_mac_int__DOT__y___05Fh3410 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 5U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2998));
    vlTOPp->mk_mac_int__DOT__y___05Fh3412 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 5U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh2998));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1588 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh38976) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38977)) 
            << 5U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh38667) 
                        ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38668)) 
                       << 4U) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1587)));
    vlTOPp->mk_mac_int__DOT__y___05Fh39385 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 5U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38977));
    vlTOPp->mk_mac_int__DOT__y___05Fh39387 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 5U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh38977));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_23_655_A_ETC___05F_d1961 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh56961) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh56962)) 
            << 0x17U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh56778) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh56779)) 
                          << 0x16U) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_21_665_A_ETC___05F_d1960));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d667 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh21206) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh21207)) 
            << 0x17U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh21023) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh21024)) 
                          << 0x16U) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d666));
    vlTOPp->mk_mac_int__DOT__x___05Fh3409 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh3411) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3412));
    vlTOPp->mk_mac_int__DOT__x___05Fh39384 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh39386) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39387));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_25_645_A_ETC___05F_d1962 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh57327) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh57328)) 
            << 0x19U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh57144) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh57145)) 
                          << 0x18U) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_23_655_A_ETC___05F_d1961));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d668 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh21572) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh21573)) 
            << 0x19U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh21389) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh21390)) 
                          << 0x18U) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d667));
    vlTOPp->mk_mac_int__DOT__y___05Fh3309 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh3409) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3410));
    vlTOPp->mk_mac_int__DOT__y___05Fh39286 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh39384) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39385));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_27_635_A_ETC___05F_d1963 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh57693) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh57694)) 
            << 0x1bU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh57510) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh57511)) 
                          << 0x1aU) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_25_645_A_ETC___05F_d1962));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d669 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh21938) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh21939)) 
            << 0x1bU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh21755) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh21756)) 
                          << 0x1aU) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d668));
    vlTOPp->mk_mac_int__DOT__y___05Fh3721 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 6U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3309));
    vlTOPp->mk_mac_int__DOT__y___05Fh3723 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 6U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3309));
    vlTOPp->mk_mac_int__DOT__y___05Fh39694 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 6U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39286));
    vlTOPp->mk_mac_int__DOT__y___05Fh39696 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 6U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39286));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_29_625_A_ETC___05F_d1964 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh58059) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh58060)) 
            << 0x1dU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh57876) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh57877)) 
                          << 0x1cU) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_27_635_A_ETC___05F_d1963));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d670 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh22304) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh22305)) 
            << 0x1dU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh22121) 
                           | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh22122)) 
                          << 0x1cU) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d669));
    vlTOPp->mk_mac_int__DOT__x___05Fh3720 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh3722) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3723));
    vlTOPp->mk_mac_int__DOT__x___05Fh39693 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh39695) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39696));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2_D_IN 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh58242) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh58243)) 
            << 0x1fU) | (vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_rg_inp1_612_BIT_29_625_A_ETC___05F_d1964 
                         << 1U));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2_D_IN 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh22487) 
             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh22488)) 
            << 0x1fU) | (vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_rg_inp1_18_BI_ETC___05F_d670 
                         << 1U));
    vlTOPp->mk_mac_int__DOT__y___05Fh3620 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh3720) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3721));
    vlTOPp->mk_mac_int__DOT__y___05Fh39595 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh39693) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39694));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d295 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh3619) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3620)) 
            << 7U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh3308) 
                        ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3309)) 
                       << 6U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d294)));
    vlTOPp->mk_mac_int__DOT__y___05Fh4032 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 7U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3620));
    vlTOPp->mk_mac_int__DOT__y___05Fh4034 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 7U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3620));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1589 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh39594) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39595)) 
            << 7U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh39285) 
                        ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39286)) 
                       << 6U) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1588)));
    vlTOPp->mk_mac_int__DOT__y___05Fh40003 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 7U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39595));
    vlTOPp->mk_mac_int__DOT__y___05Fh40005 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 7U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39595));
    vlTOPp->mk_mac_int__DOT__x___05Fh4031 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh4033) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4034));
    vlTOPp->mk_mac_int__DOT__x___05Fh40002 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh40004) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40005));
    vlTOPp->mk_mac_int__DOT__y___05Fh3931 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh4031) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4032));
    vlTOPp->mk_mac_int__DOT__y___05Fh39904 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh40002) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40003));
    vlTOPp->mk_mac_int__DOT__y___05Fh4343 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 8U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3931));
    vlTOPp->mk_mac_int__DOT__y___05Fh4345 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 8U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3931));
    vlTOPp->mk_mac_int__DOT__y___05Fh40312 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 8U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39904));
    vlTOPp->mk_mac_int__DOT__y___05Fh40314 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 8U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39904));
    vlTOPp->mk_mac_int__DOT__x___05Fh4342 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh4344) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4345));
    vlTOPp->mk_mac_int__DOT__x___05Fh40311 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh40313) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40314));
    vlTOPp->mk_mac_int__DOT__y___05Fh4242 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh4342) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4343));
    vlTOPp->mk_mac_int__DOT__y___05Fh40213 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh40311) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40312));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d296 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh4241) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4242)) 
            << 9U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh3930) 
                        ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh3931)) 
                       << 8U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d295)));
    vlTOPp->mk_mac_int__DOT__y___05Fh4654 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 9U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4242));
    vlTOPp->mk_mac_int__DOT__y___05Fh4656 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 9U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4242));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1590 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh40212) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40213)) 
            << 9U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh39903) 
                        ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh39904)) 
                       << 8U) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1589)));
    vlTOPp->mk_mac_int__DOT__y___05Fh40621 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 9U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40213));
    vlTOPp->mk_mac_int__DOT__y___05Fh40623 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 9U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40213));
    vlTOPp->mk_mac_int__DOT__x___05Fh4653 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh4655) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4656));
    vlTOPp->mk_mac_int__DOT__x___05Fh40620 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh40622) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40623));
    vlTOPp->mk_mac_int__DOT__y___05Fh4553 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh4653) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4654));
    vlTOPp->mk_mac_int__DOT__y___05Fh40522 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh40620) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40621));
    vlTOPp->mk_mac_int__DOT__y___05Fh4965 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0xaU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4553));
    vlTOPp->mk_mac_int__DOT__y___05Fh4967 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0xaU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4553));
    vlTOPp->mk_mac_int__DOT__y___05Fh40930 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0xaU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40522));
    vlTOPp->mk_mac_int__DOT__y___05Fh40932 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0xaU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40522));
    vlTOPp->mk_mac_int__DOT__x___05Fh4964 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh4966) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4967));
    vlTOPp->mk_mac_int__DOT__x___05Fh40929 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh40931) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40932));
    vlTOPp->mk_mac_int__DOT__y___05Fh4864 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh4964) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4965));
    vlTOPp->mk_mac_int__DOT__y___05Fh40831 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh40929) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40930));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d297 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh4863) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4864)) 
            << 0xbU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh4552) 
                          ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4553)) 
                         << 0xaU) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d296)));
    vlTOPp->mk_mac_int__DOT__y___05Fh5276 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0xbU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4864));
    vlTOPp->mk_mac_int__DOT__y___05Fh5278 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0xbU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh4864));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1591 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh40830) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40831)) 
            << 0xbU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh40521) 
                          ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40522)) 
                         << 0xaU) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1590)));
    vlTOPp->mk_mac_int__DOT__y___05Fh41239 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0xbU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40831));
    vlTOPp->mk_mac_int__DOT__y___05Fh41241 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0xbU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh40831));
    vlTOPp->mk_mac_int__DOT__x___05Fh5275 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh5277) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5278));
    vlTOPp->mk_mac_int__DOT__x___05Fh41238 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh41240) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41241));
    vlTOPp->mk_mac_int__DOT__y___05Fh5175 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh5275) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5276));
    vlTOPp->mk_mac_int__DOT__y___05Fh41140 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh41238) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41239));
    vlTOPp->mk_mac_int__DOT__y___05Fh5587 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0xcU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5175));
    vlTOPp->mk_mac_int__DOT__y___05Fh5589 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0xcU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5175));
    vlTOPp->mk_mac_int__DOT__y___05Fh41548 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0xcU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41140));
    vlTOPp->mk_mac_int__DOT__y___05Fh41550 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0xcU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41140));
    vlTOPp->mk_mac_int__DOT__x___05Fh5586 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh5588) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5589));
    vlTOPp->mk_mac_int__DOT__x___05Fh41547 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh41549) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41550));
    vlTOPp->mk_mac_int__DOT__y___05Fh5486 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh5586) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5587));
    vlTOPp->mk_mac_int__DOT__y___05Fh41449 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh41547) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41548));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d298 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh5485) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5486)) 
            << 0xdU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh5174) 
                          ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5175)) 
                         << 0xcU) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d297)));
    vlTOPp->mk_mac_int__DOT__y___05Fh5898 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0xdU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5486));
    vlTOPp->mk_mac_int__DOT__y___05Fh5900 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0xdU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5486));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1592 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh41448) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41449)) 
            << 0xdU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh41139) 
                          ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41140)) 
                         << 0xcU) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1591)));
    vlTOPp->mk_mac_int__DOT__y___05Fh41857 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0xdU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41449));
    vlTOPp->mk_mac_int__DOT__y___05Fh41859 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0xdU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41449));
    vlTOPp->mk_mac_int__DOT__x___05Fh5897 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh5899) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5900));
    vlTOPp->mk_mac_int__DOT__x___05Fh41856 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh41858) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41859));
    vlTOPp->mk_mac_int__DOT__y___05Fh5797 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh5897) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5898));
    vlTOPp->mk_mac_int__DOT__y___05Fh41758 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh41856) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41857));
    vlTOPp->mk_mac_int__DOT__y___05Fh6209 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0xeU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5797));
    vlTOPp->mk_mac_int__DOT__y___05Fh6211 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0xeU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5797));
    vlTOPp->mk_mac_int__DOT__y___05Fh42166 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0xeU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41758));
    vlTOPp->mk_mac_int__DOT__y___05Fh42168 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0xeU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41758));
    vlTOPp->mk_mac_int__DOT__x___05Fh6208 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh6210) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6211));
    vlTOPp->mk_mac_int__DOT__x___05Fh42165 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh42167) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42168));
    vlTOPp->mk_mac_int__DOT__y___05Fh6108 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh6208) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6209));
    vlTOPp->mk_mac_int__DOT__y___05Fh42067 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh42165) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42166));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d299 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh6107) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6108)) 
            << 0xfU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh5796) 
                          ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh5797)) 
                         << 0xeU) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d298)));
    vlTOPp->mk_mac_int__DOT__y___05Fh6520 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0xfU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6108));
    vlTOPp->mk_mac_int__DOT__y___05Fh6522 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0xfU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6108));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1593 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh42066) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42067)) 
            << 0xfU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh41757) 
                          ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh41758)) 
                         << 0xeU) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1592)));
    vlTOPp->mk_mac_int__DOT__y___05Fh42475 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0xfU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42067));
    vlTOPp->mk_mac_int__DOT__y___05Fh42477 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0xfU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42067));
    vlTOPp->mk_mac_int__DOT__x___05Fh6519 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh6521) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6522));
    vlTOPp->mk_mac_int__DOT__x___05Fh42474 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh42476) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42477));
    vlTOPp->mk_mac_int__DOT__y___05Fh6419 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh6519) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6520));
    vlTOPp->mk_mac_int__DOT__y___05Fh42376 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh42474) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42475));
    vlTOPp->mk_mac_int__DOT__y___05Fh6831 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0x10U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6419));
    vlTOPp->mk_mac_int__DOT__y___05Fh6833 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0x10U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6419));
    vlTOPp->mk_mac_int__DOT__y___05Fh42784 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x10U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42376));
    vlTOPp->mk_mac_int__DOT__y___05Fh42786 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x10U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42376));
    vlTOPp->mk_mac_int__DOT__x___05Fh6830 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh6832) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6833));
    vlTOPp->mk_mac_int__DOT__x___05Fh42783 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh42785) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42786));
    vlTOPp->mk_mac_int__DOT__y___05Fh6730 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh6830) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6831));
    vlTOPp->mk_mac_int__DOT__y___05Fh42685 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh42783) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42784));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d300 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh6729) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6730)) 
            << 0x11U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh6418) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6419)) 
                          << 0x10U) | (IData)(vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d299)));
    vlTOPp->mk_mac_int__DOT__y___05Fh7142 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0x11U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6730));
    vlTOPp->mk_mac_int__DOT__y___05Fh7144 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0x11U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh6730));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1594 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh42684) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42685)) 
            << 0x11U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh42375) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42376)) 
                          << 0x10U) | (IData)(vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1593)));
    vlTOPp->mk_mac_int__DOT__y___05Fh43093 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x11U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42685));
    vlTOPp->mk_mac_int__DOT__y___05Fh43095 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x11U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42685));
    vlTOPp->mk_mac_int__DOT__x___05Fh7141 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh7143) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7144));
    vlTOPp->mk_mac_int__DOT__x___05Fh43092 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh43094) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43095));
    vlTOPp->mk_mac_int__DOT__y___05Fh7041 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh7141) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7142));
    vlTOPp->mk_mac_int__DOT__y___05Fh42994 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh43092) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43093));
    vlTOPp->mk_mac_int__DOT__y___05Fh7453 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0x12U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7041));
    vlTOPp->mk_mac_int__DOT__y___05Fh7455 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0x12U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7041));
    vlTOPp->mk_mac_int__DOT__y___05Fh43402 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x12U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42994));
    vlTOPp->mk_mac_int__DOT__y___05Fh43404 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x12U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42994));
    vlTOPp->mk_mac_int__DOT__x___05Fh7452 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh7454) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7455));
    vlTOPp->mk_mac_int__DOT__x___05Fh43401 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh43403) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43404));
    vlTOPp->mk_mac_int__DOT__y___05Fh7352 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh7452) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7453));
    vlTOPp->mk_mac_int__DOT__y___05Fh43303 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh43401) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43402));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d301 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh7351) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7352)) 
            << 0x13U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh7040) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7041)) 
                          << 0x12U) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d300));
    vlTOPp->mk_mac_int__DOT__y___05Fh7764 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0x13U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7352));
    vlTOPp->mk_mac_int__DOT__y___05Fh7766 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0x13U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7352));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1595 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh43302) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43303)) 
            << 0x13U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh42993) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh42994)) 
                          << 0x12U) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1594));
    vlTOPp->mk_mac_int__DOT__y___05Fh43711 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x13U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43303));
    vlTOPp->mk_mac_int__DOT__y___05Fh43713 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x13U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43303));
    vlTOPp->mk_mac_int__DOT__x___05Fh7763 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh7765) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7766));
    vlTOPp->mk_mac_int__DOT__x___05Fh43710 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh43712) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43713));
    vlTOPp->mk_mac_int__DOT__y___05Fh7663 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh7763) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7764));
    vlTOPp->mk_mac_int__DOT__y___05Fh43612 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh43710) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43711));
    vlTOPp->mk_mac_int__DOT__y___05Fh8075 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0x14U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7663));
    vlTOPp->mk_mac_int__DOT__y___05Fh8077 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0x14U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7663));
    vlTOPp->mk_mac_int__DOT__y___05Fh44020 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x14U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43612));
    vlTOPp->mk_mac_int__DOT__y___05Fh44022 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x14U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43612));
    vlTOPp->mk_mac_int__DOT__x___05Fh8074 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh8076) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8077));
    vlTOPp->mk_mac_int__DOT__x___05Fh44019 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh44021) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44022));
    vlTOPp->mk_mac_int__DOT__y___05Fh7974 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh8074) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8075));
    vlTOPp->mk_mac_int__DOT__y___05Fh43921 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh44019) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44020));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d302 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh7973) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7974)) 
            << 0x15U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh7662) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7663)) 
                          << 0x14U) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d301));
    vlTOPp->mk_mac_int__DOT__y___05Fh8386 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0x15U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7974));
    vlTOPp->mk_mac_int__DOT__y___05Fh8388 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0x15U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh7974));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1596 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh43920) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43921)) 
            << 0x15U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh43611) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43612)) 
                          << 0x14U) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1595));
    vlTOPp->mk_mac_int__DOT__y___05Fh44329 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x15U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43921));
    vlTOPp->mk_mac_int__DOT__y___05Fh44331 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x15U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh43921));
    vlTOPp->mk_mac_int__DOT__x___05Fh8385 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh8387) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8388));
    vlTOPp->mk_mac_int__DOT__x___05Fh44328 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh44330) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44331));
    vlTOPp->mk_mac_int__DOT__y___05Fh8285 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh8385) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8386));
    vlTOPp->mk_mac_int__DOT__y___05Fh44230 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh44328) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44329));
    vlTOPp->mk_mac_int__DOT__y___05Fh8697 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0x16U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8285));
    vlTOPp->mk_mac_int__DOT__y___05Fh8699 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0x16U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8285));
    vlTOPp->mk_mac_int__DOT__y___05Fh44638 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x16U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44230));
    vlTOPp->mk_mac_int__DOT__y___05Fh44640 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x16U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44230));
    vlTOPp->mk_mac_int__DOT__x___05Fh8696 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh8698) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8699));
    vlTOPp->mk_mac_int__DOT__x___05Fh44637 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh44639) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44640));
    vlTOPp->mk_mac_int__DOT__y___05Fh8596 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh8696) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8697));
    vlTOPp->mk_mac_int__DOT__y___05Fh44539 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh44637) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44638));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d303 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh8595) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8596)) 
            << 0x17U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh8284) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8285)) 
                          << 0x16U) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d302));
    vlTOPp->mk_mac_int__DOT__y___05Fh9008 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0x17U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8596));
    vlTOPp->mk_mac_int__DOT__y___05Fh9010 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0x17U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8596));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1597 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh44538) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44539)) 
            << 0x17U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh44229) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44230)) 
                          << 0x16U) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1596));
    vlTOPp->mk_mac_int__DOT__y___05Fh44947 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x17U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44539));
    vlTOPp->mk_mac_int__DOT__y___05Fh44949 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x17U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44539));
    vlTOPp->mk_mac_int__DOT__x___05Fh9007 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh9009) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9010));
    vlTOPp->mk_mac_int__DOT__x___05Fh44946 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh44948) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44949));
    vlTOPp->mk_mac_int__DOT__y___05Fh8907 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh9007) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9008));
    vlTOPp->mk_mac_int__DOT__y___05Fh44848 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh44946) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44947));
    vlTOPp->mk_mac_int__DOT__y___05Fh9319 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0x18U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8907));
    vlTOPp->mk_mac_int__DOT__y___05Fh9321 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0x18U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8907));
    vlTOPp->mk_mac_int__DOT__y___05Fh45256 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x18U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44848));
    vlTOPp->mk_mac_int__DOT__y___05Fh45258 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x18U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44848));
    vlTOPp->mk_mac_int__DOT__x___05Fh9318 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh9320) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9321));
    vlTOPp->mk_mac_int__DOT__x___05Fh45255 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh45257) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45258));
    vlTOPp->mk_mac_int__DOT__y___05Fh9218 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh9318) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9319));
    vlTOPp->mk_mac_int__DOT__y___05Fh45157 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh45255) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45256));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d304 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh9217) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9218)) 
            << 0x19U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh8906) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh8907)) 
                          << 0x18U) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d303));
    vlTOPp->mk_mac_int__DOT__y___05Fh9630 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0x19U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9218));
    vlTOPp->mk_mac_int__DOT__y___05Fh9632 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0x19U) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9218));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1598 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh45156) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45157)) 
            << 0x19U) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh44847) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh44848)) 
                          << 0x18U) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1597));
    vlTOPp->mk_mac_int__DOT__y___05Fh45565 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x19U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45157));
    vlTOPp->mk_mac_int__DOT__y___05Fh45567 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x19U) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45157));
    vlTOPp->mk_mac_int__DOT__x___05Fh9629 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh9631) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9632));
    vlTOPp->mk_mac_int__DOT__x___05Fh45564 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh45566) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45567));
    vlTOPp->mk_mac_int__DOT__y___05Fh9529 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh9629) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9630));
    vlTOPp->mk_mac_int__DOT__y___05Fh45466 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh45564) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45565));
    vlTOPp->mk_mac_int__DOT__y___05Fh9941 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                              >> 0x1aU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9529));
    vlTOPp->mk_mac_int__DOT__y___05Fh9943 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                              >> 0x1aU) 
                                             & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9529));
    vlTOPp->mk_mac_int__DOT__y___05Fh45874 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x1aU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45466));
    vlTOPp->mk_mac_int__DOT__y___05Fh45876 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x1aU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45466));
    vlTOPp->mk_mac_int__DOT__x___05Fh9940 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh9942) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9943));
    vlTOPp->mk_mac_int__DOT__x___05Fh45873 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh45875) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45876));
    vlTOPp->mk_mac_int__DOT__y___05Fh9840 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh9940) 
                                             | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9941));
    vlTOPp->mk_mac_int__DOT__y___05Fh45775 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh45873) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45874));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d305 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh9839) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9840)) 
            << 0x1bU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh9528) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9529)) 
                          << 0x1aU) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d304));
    vlTOPp->mk_mac_int__DOT__y___05Fh10252 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x1bU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9840));
    vlTOPp->mk_mac_int__DOT__y___05Fh10254 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x1bU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh9840));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1599 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh45774) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45775)) 
            << 0x1bU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh45465) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45466)) 
                          << 0x1aU) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1598));
    vlTOPp->mk_mac_int__DOT__y___05Fh46183 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x1bU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45775));
    vlTOPp->mk_mac_int__DOT__y___05Fh46185 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x1bU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh45775));
    vlTOPp->mk_mac_int__DOT__x___05Fh10251 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh10253) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10254));
    vlTOPp->mk_mac_int__DOT__x___05Fh46182 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh46184) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46185));
    vlTOPp->mk_mac_int__DOT__y___05Fh10151 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh10251) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10252));
    vlTOPp->mk_mac_int__DOT__y___05Fh46084 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh46182) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46183));
    vlTOPp->mk_mac_int__DOT__y___05Fh10563 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x1cU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10151));
    vlTOPp->mk_mac_int__DOT__y___05Fh10565 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x1cU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10151));
    vlTOPp->mk_mac_int__DOT__y___05Fh46492 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x1cU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46084));
    vlTOPp->mk_mac_int__DOT__y___05Fh46494 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x1cU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46084));
    vlTOPp->mk_mac_int__DOT__x___05Fh10562 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh10564) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10565));
    vlTOPp->mk_mac_int__DOT__x___05Fh46491 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh46493) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46494));
    vlTOPp->mk_mac_int__DOT__y___05Fh10462 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh10562) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10563));
    vlTOPp->mk_mac_int__DOT__y___05Fh46393 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh46491) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46492));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d306 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh10461) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10462)) 
            << 0x1dU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh10150) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10151)) 
                          << 0x1cU) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d305));
    vlTOPp->mk_mac_int__DOT__y___05Fh10874 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x1dU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10462));
    vlTOPp->mk_mac_int__DOT__y___05Fh10876 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x1dU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10462));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1600 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh46392) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46393)) 
            << 0x1dU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh46083) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46084)) 
                          << 0x1cU) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1599));
    vlTOPp->mk_mac_int__DOT__y___05Fh46801 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x1dU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46393));
    vlTOPp->mk_mac_int__DOT__y___05Fh46803 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x1dU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46393));
    vlTOPp->mk_mac_int__DOT__x___05Fh10873 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh10875) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10876));
    vlTOPp->mk_mac_int__DOT__x___05Fh46800 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh46802) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46803));
    vlTOPp->mk_mac_int__DOT__y___05Fh10773 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh10873) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10874));
    vlTOPp->mk_mac_int__DOT__y___05Fh46702 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh46800) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46801));
    vlTOPp->mk_mac_int__DOT__y___05Fh11185 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x1eU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10773));
    vlTOPp->mk_mac_int__DOT__y___05Fh11187 = ((vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x1eU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10773));
    vlTOPp->mk_mac_int__DOT__y___05Fh47110 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp2 
                                               >> 0x1eU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46702));
    vlTOPp->mk_mac_int__DOT__y___05Fh47112 = ((vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_inp1 
                                               >> 0x1eU) 
                                              & (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46702));
    vlTOPp->mk_mac_int__DOT__x___05Fh11184 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh11186) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh11187));
    vlTOPp->mk_mac_int__DOT__x___05Fh47109 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh47111) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh47112));
    vlTOPp->mk_mac_int__DOT__y___05Fh11084 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh11184) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh11185));
    vlTOPp->mk_mac_int__DOT__y___05Fh47011 = ((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh47109) 
                                              | (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh47110));
    vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry_adder_rg_out_D_IN 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh11083) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh11084)) 
            << 0x1fU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh10772) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh10773)) 
                          << 0x1eU) | vlTOPp->mk_mac_int__DOT__wallace_multiplier_unit_csa_unit_ripple_carry___05FETC___05F_d306));
    vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_out_D_IN 
        = ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh47010) 
             ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh47011)) 
            << 0x1fU) | ((((IData)(vlTOPp->mk_mac_int__DOT__x___05Fh46701) 
                           ^ (IData)(vlTOPp->mk_mac_int__DOT__y___05Fh46702)) 
                          << 0x1eU) | vlTOPp->mk_mac_int__DOT__carry_save_adder_unit_ripple_carry_adder_rg_in_ETC___05F_d1600));
}

VL_INLINE_OPT void Vtop::_combo__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mk_mac_int__DOT__rg_inp_3_EN = vlTOPp->EN_mac_int_input;
    vlTOPp->mk_mac_int__DOT__rg_inp_3_D_IN = vlTOPp->mac_int_input_inp_3;
    vlTOPp->mk_mac_int__DOT__input_ready_D_IN = vlTOPp->EN_mac_int_input;
    vlTOPp->mk_mac_int__DOT__rg_inp_1_EN = vlTOPp->EN_mac_int_input;
    vlTOPp->mk_mac_int__DOT__rg_inp_1_D_IN = vlTOPp->mac_int_input_inp_1;
    vlTOPp->mk_mac_int__DOT__rg_inp_2_EN = vlTOPp->EN_mac_int_input;
    vlTOPp->mk_mac_int__DOT__rg_inp_2_D_IN = vlTOPp->mac_int_input_inp_2;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
        Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((RST_N & 0xfeU))) {
        Verilated::overWidthError("RST_N");}
    if (VL_UNLIKELY((EN_mac_int_input & 0xfeU))) {
        Verilated::overWidthError("EN_mac_int_input");}
}
#endif  // VL_DEBUG
