#include "slp.h"

A_stm prog() {
    const A_stm aAssignment = A_AssignStm("a", A_OpExp(A_NumExp(5), A_plus, A_NumExp(3)));
    const A_exp aPlusOne = A_OpExp(A_IdExp("a"), A_minus, A_NumExp(1));
    const A_stm print1 = A_PrintStm(A_PairExpList(A_IdExp("a"), A_LastExpList(aPlusOne)));
    const A_exp tenTimesA = A_EseqExp(print1, A_OpExp(A_NumExp(10), A_times, A_IdExp("a")));

    return A_CompoundStm(
        aAssignment,
        A_CompoundStm(
            A_AssignStm("b", tenTimesA),
            A_PrintStm(A_LastExpList(A_IdExp("b")))));
}
