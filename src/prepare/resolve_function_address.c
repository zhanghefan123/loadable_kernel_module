//
// Created by root on 2/8/24.
//
#include "prepare/resolve_function_address.h"
#include "hooks/hook_tcp_v4_rcv.h"
#include "impl/self_defined_tcp_rcv_established.h"

/*
 * 使用 kallsyms_lookup_name 进行函数地址的查找
 */
void resolve_function_address(void){
    //    resolve_tcp_v4_rcv_inner_functions_address();
    //    resolve_self_defined_tcp_rcv_established_inner_functions_address();
}