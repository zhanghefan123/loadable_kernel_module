#ifndef ZEUSNET_KERNEL_TOOLS_H
#define ZEUSNET_KERNEL_TOOLS_H
#include <net/route.h>
#define LOG_PREFIX "[zeusnet's kernel info]:"
void LOG_WITH_PREFIX(char* msg);
void LOG_WITH_EDGE(char* msg);
bool TEST_RESOLVED(void* pointer, const char* function_name);
bool resolve_functions_addresses(void** pointers, const char** function_names, int length);
#endif
