#include "absyn.h"
#include "symbol.h"
#include "util.h"

A_var A_SimpleVar(A_pos pos, S_symbol sym) {
    MALLOC(A_var, p);
    *p = (struct A_var_){
        .kind = A_simpleVar,
        .pos = pos,
        .u.simple = sym,
    };
    return p;
}

A_var A_FieldVar(A_pos pos, A_var var, S_symbol sym) {
    MALLOC(A_var, p);
    *p = (struct A_var_){
        .kind = A_fieldVar,
        .pos = pos,
        .u.field.var = var,
        .u.field.sym = sym,
    };
    return p;
}

A_var A_SubscriptVar(A_pos pos, A_var var, A_exp exp) {
    MALLOC(A_var, p);
    *p = (struct A_var_){
        .kind = A_subscriptVar,
        .pos = pos,
        .u.subscript.var = var,
        .u.subscript.exp = exp,
    };
    return p;
}

A_exp A_VarExp(A_pos pos, A_var var) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_varExp,
        .pos = pos,
        .u.var = var,
    };
    return p;
}

A_exp A_NilExp(A_pos pos) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_nilExp,
        .pos = pos,
    };
    return p;
}

A_exp A_IntExp(A_pos pos, int i) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_intExp,
        .pos = pos,
        .u.intt = i,
    };
    return p;
}

A_exp A_StringExp(A_pos pos, string s) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_stringExp,
        .pos = pos,
        .u.stringg = s,
    };
    return p;
}

A_exp A_CallExp(A_pos pos, S_symbol func, A_expList args) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_callExp,
        .pos = pos,
        .u.call.func = func,
        .u.call.args = args,
    };
    return p;
}

A_exp A_OpExp(A_pos pos, A_oper oper, A_exp left, A_exp right) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_opExp,
        .pos = pos,
        .u.op.oper = oper,
        .u.op.left = left,
        .u.op.right = right,
    };
    return p;
}

A_exp A_RecordExp(A_pos pos, S_symbol typ, A_efieldList fields) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_recordExp,
        .pos = pos,
        .u.record.typ = typ,
        .u.record.fields = fields,
    };
    return p;
}

A_exp A_SeqExp(A_pos pos, A_expList seq) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_seqExp,
        .pos = pos,
        .u.seq = seq,
    };
    return p;
}

A_exp A_AssignExp(A_pos pos, A_var var, A_exp exp) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_assignExp,
        .pos = pos,
        .u.assign.var = var,
        .u.assign.exp = exp,
    };
    return p;
}

A_exp A_IfExp(A_pos pos, A_exp test, A_exp then, A_exp elsee) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_ifExp,
        .pos = pos,
        .u.iff.test = test,
        .u.iff.then = then,
        .u.iff.elsee = elsee,
    };
    return p;
}

A_exp A_WhileExp(A_pos pos, A_exp test, A_exp body) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_whileExp,
        .pos = pos,
        .u.whilee.test = test,
        .u.whilee.body = body,
    };
    return p;
}

A_exp A_ForExp(A_pos pos, S_symbol var, A_exp lo, A_exp hi, A_exp body) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_forExp,
        .pos = pos,
        .u.forr.var = var,
        .u.forr.lo = lo,
        .u.forr.hi = hi,
        .u.forr.body = body,
        .u.forr.escape = TRUE,
    };
    return p;
}

A_exp A_BreakExp(A_pos pos) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_breakExp,
        .pos = pos,
    };
    return p;
}

A_exp A_LetExp(A_pos pos, A_decList decs, A_exp body) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_letExp,
        .pos = pos,
        .u.let.decs = decs,
        .u.let.body = body,
    };
    return p;
}

A_exp A_ArrayExp(A_pos pos, S_symbol typ, A_exp size, A_exp init) {
    MALLOC(A_exp, p);
    *p = (struct A_exp_){
        .kind = A_arrayExp,
        .pos = pos,
        .u.array.typ = typ,
        .u.array.size = size,
        .u.array.init = init,
    };
    return p;
}

A_dec A_FunctionDec(A_pos pos, A_fundecList function) {
    MALLOC(A_dec, p);
    *p = (struct A_dec_){
        .kind = A_functionDec,
        .pos = pos,
        .u.function = function,
    };
    return p;
}

A_dec A_VarDec(A_pos pos, S_symbol var, S_symbol typ, A_exp init) {
    MALLOC(A_dec, p);
    *p = (struct A_dec_){
        .kind = A_varDec,
        .pos = pos,
        .u.var.var = var,
        .u.var.typ = typ,
        .u.var.init = init,
        .u.var.escape = TRUE,
    };
    return p;
}

A_dec A_TypeDec(A_pos pos, A_nametyList type) {
    MALLOC(A_dec, p);
    *p = (struct A_dec_){
        .kind = A_typeDec,
        .pos = pos,
        .u.type = type,
    };
    return p;
}

A_ty A_NameTy(A_pos pos, S_symbol name) {
    MALLOC(A_ty, p);
    *p = (struct A_ty_){
        .kind = A_nameTy,
        .pos = pos,
        .u.name = name,
    };
    return p;
}

A_ty A_RecordTy(A_pos pos, A_fieldList record) {
    MALLOC(A_ty, p);
    *p = (struct A_ty_){
        .kind = A_recordTy,
        .pos = pos,
        .u.record = record,
    };
    return p;
}

A_ty A_ArrayTy(A_pos pos, S_symbol array) {
    MALLOC(A_ty, p);
    *p = (struct A_ty_){
        .kind = A_arrayTy,
        .pos = pos,
        .u.array = array,
    };
    return p;
}

A_field A_Field(A_pos pos, S_symbol name, S_symbol typ) {
    MALLOC(A_field, p);
    *p = (struct A_field_){
        .pos = pos,
        .name = name,
        .typ = typ,
        .escape = TRUE,
    };
    return p;
}

A_fieldList A_FieldList(A_field head, A_fieldList tail) {
    MALLOC(A_fieldList, p);
    *p = (struct A_fieldList_){
        .head = head,
        .tail = tail,
    };
    return p;
}

A_expList A_ExpList(A_exp head, A_expList tail) {
    MALLOC(A_expList, p);
    *p = (struct A_expList_){
        .head = head,
        .tail = tail,
    };
    return p;
}

A_fundec A_Fundec(A_pos pos, S_symbol name, A_fieldList params, S_symbol result, A_exp body) {
    MALLOC(A_fundec, p);
    *p = (struct A_fundec_){
        .pos = pos,
        .name = name,
        .params = params,
        .result = result,
        .body = body,
    };
    return p;
}

A_fundecList A_FundecList(A_fundec head, A_fundecList tail) {
    MALLOC(A_fundecList, p);
    *p = (struct A_fundecList_){
        .head = head,
        .tail = tail,
    };
    return p;
}

A_decList A_DecList(A_dec head, A_decList tail) {
    MALLOC(A_decList, p);
    *p = (struct A_decList_){
        .head = head,
        .tail = tail,
    };
    return p;
}

A_namety A_Namety(S_symbol name, A_ty ty) {
    MALLOC(A_namety, p);
    *p = (struct A_namety_){
        .name = name,
        .ty = ty,
    };
    return p;
}

A_nametyList A_NametyList(A_namety head, A_nametyList tail) {
    MALLOC(A_nametyList, p);
    *p = (struct A_nametyList_){
        .head = head,
        .tail = tail,
    };
    return p;
}

A_efield A_Efield(S_symbol name, A_exp exp) {
    MALLOC(A_efield, p);
    *p = (struct A_efield_){
        .name = name,
        .exp = exp,
    };
    return p;
}

A_efieldList A_EfieldList(A_efield head, A_efieldList tail) {
    MALLOC(A_efieldList, p);
    *p = (struct A_efieldList_){
        .head = head,
        .tail = tail,
    };
    return p;
}
