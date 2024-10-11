cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project("Linux Kernel Module with CLion IDE support / CMake" VERSION 0.1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find kernel headers
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(KernelHeaders REQUIRED)


# find MODULE_LICENSE("GPL"), MODULE_AUTHOR() etc.
# thanks to "merseyviking" from stack overflow
add_definitions(-D__KERNEL__ -DMODULE)

# this is needed in order for CLion IDE to provide syntax highlightning
# this is independent from the actual kernel object that is built
add_executable(srv6
        src/api/ftrace_hook_api.c
        src/api/hook_functions_api.c
        src/api/check_srv6.c
        src/hooks/ipv6_rcv/hook.c
        src/hooks/ipv6_rcv/impl.c
        src/hooks/ipv6_rcv_finish/impl.c
        src/hooks/ip6_rcv_finish_core/impl.c
        src/prepare/resolve_function_address.c
        src/tools/tools.c
        src/module_starter.c
)

set(HEADERS_DIR /usr/src/linux-headers-5.19.0-41-generic/include
        /usr/src/linux-headers-5.19.0-41-generic/arch/x86/include
        /usr/include
        headers)

# CLion IDE will find symbols from <linux/*>
target_include_directories("srv6" PRIVATE ${HEADERS_DIR})