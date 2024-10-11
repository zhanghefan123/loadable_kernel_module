//
// Created by root on 2/8/24.
//
#include "prepare/resolve_function_address.h"
#include "hooks/ipv6_rcv/ipv6_rcv.h"
#include "hooks/ip6_rcv_finish_core/ip6_rcv_finish_core.h"

/*
 * 使用 kallsyms_lookup_name 进行函数地址的查找
 */
bool resolve_function_address(void){
    bool result;
    result = resolve_ipv6_rcv_inner_functions_address();
    if(!result){
        return result;
    }
    result = resolve_ip6_rcv_finish_core_inner_functions_address();
    return result;
}