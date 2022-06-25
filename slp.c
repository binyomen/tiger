#include "slp.h"
#include "util.h"

A_stm A_CompoundStm(A_stm stm1, A_stm stm2) {
    MALLOC(A_stm, s);
    *s = (struct A_stm_){
        .kind = A_compoundStm,
        .u.compound.stm1 = stm1,
        .u.compound.stm2 = stm2,
    };
    return s;
}

A_stm A_AssignStm(string id, A_exp exp) {
    MALLOC(A_stm, s);
    *s = (struct A_stm_){
        .kind = A_assignStm,
        .u.assign.id = id,
        .u.assign.exp = exp,
    };
    return s;
}

A_stm A_PrintStm(A_expList exps) {
    MALLOC(A_stm, s);
    *s = (struct A_stm_){
        .kind = A_printStm,
        .u.print.exps = exps,
    };
    return s;
}

A_exp A_IdExp(string id) {
    MALLOC(A_exp, e);
    *e = (struct A_exp_){
        .kind = A_idExp,
        .u.id = id,
    };
    return e;
}

A_exp A_NumExp(int num) {
    MALLOC(A_exp, e);
    *e = (struct A_exp_){
        .kind = A_numExp,
        .u.num = num,
    };
    return e;
}

A_exp A_OpExp(A_exp left, A_binop oper, A_exp right) {
    MALLOC(A_exp, e);
    *e = (struct A_exp_){
        .kind = A_opExp,
        .u.op.left = left,
        .u.op.oper = oper,
        .u.op.right = right,
    };
    return e;
}

A_exp A_EseqExp(A_stm stm, A_exp exp) {
    MALLOC(A_exp, e);
    *e = (struct A_exp_){
        .kind = A_eseqExp,
        .u.eseq.stm = stm,
        .u.eseq.exp = exp,
    };
    return e;
}

A_expList A_PairExpList(A_exp head, A_expList tail) {
    MALLOC(A_expList, e);
    *e = (struct A_expList_){
        .kind = A_pairExpList,
        .u.pair.head = head,
        .u.pair.tail = tail,
    };
    return e;
}

A_expList A_LastExpList(A_exp last) {
    MALLOC(A_expList, e);
    *e = (struct A_expList_){
        .kind = A_lastExpList,
        .u.last = last,
    };
    return e;
}
