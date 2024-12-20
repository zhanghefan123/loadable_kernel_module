//
// Created by kernel-dbg on 24-1-31.
//
#include <linux/string.h>
#include <linux/slab.h>
#include "tools/tools.h"
#include "api/ftrace_hook_api.h"


/**
 * log_with_prefix 带有前缀的输出
 * @param msg 用户想要输出的消息
 * @return 不进行返回
 */
void LOG_WITH_PREFIX(char* msg){
    const char* prefix = LOG_PREFIX;
    size_t prefix_length = strlen(prefix);
    size_t msg_length = strlen(msg);
    size_t total_length = prefix_length + msg_length + 2;
    char total_msg[total_length];
    memcpy(total_msg, prefix, prefix_length);
    memcpy(total_msg + prefix_length, msg, msg_length);
    total_msg[total_length - 2] = '\n';
    total_msg[total_length - 1] = '\0';
    printk(KERN_EMERG "%s", total_msg);
}

/**
 * 进行有边框的输出用户想要输出的信息
 * @param msg 用户想要输出的信息
 */
void LOG_WITH_EDGE(char* msg){
    char final_output_msg[101];
    int length_of_msg = (int)strlen(msg);
    int length_of_each_edge = (100 - length_of_msg) / 2;
    memset(final_output_msg, (int)('-'), length_of_each_edge);
    final_output_msg[length_of_each_edge] = '\0';
    strcat(final_output_msg, msg);
    memset(final_output_msg + strlen(final_output_msg), (int)('-'), 100-strlen(final_output_msg));
    final_output_msg[100] = '\0';
    LOG_WITH_PREFIX(final_output_msg);
}


/**
 * 检查是否成功解析了函数的指针
 * @param pointer 指针
 * @param function_name 函数名称
 * @return
 */
bool TEST_RESOLVED(void* pointer, const char* function_name){
    if(pointer != NULL){
        char result[50];
        sprintf(result, "%s resolved", function_name);
        LOG_WITH_PREFIX(result);
        return true;
    } else {
        char result[50];
        sprintf(result, "%s not resolved", function_name);
        LOG_WITH_PREFIX(result);
        return false;
    }
}

bool resolve_functions_addresses(void** pointers, const char** function_names, int length){
    int index;
    bool resolve_result;
    for(index = 0; index < length; index ++){
        pointers[index] = get_function_address(function_names[index]);
        resolve_result = TEST_RESOLVED(pointers[index], function_names[index]);
        if(!resolve_result){
            printk(KERN_EMERG "cannot resolve function %s\n", function_names[index]);
            return resolve_result;
        }
    }
    return resolve_result;
}