# this is a make file for a kernel object
# see online for more information
CONFIG_MODULE_SIG=n
# will build "hello.ko"
obj-m += lkm.o

# we have no file "hello.c" in this example
# therefore we specify: module hello.ko relies on
# main.c and greet.c ... it's this makefile module magic thing..
# see online resources for more information
# YOU DON'T need this IF you have *.c-file with the name of the
# final kernel module :)
lkm-objs := \
	src/api/ftrace_hook_api.o \
	src/api/hook_functions_api.o \
	src/api/check_srv6.o \
	src/hooks/ipv6_rcv/hook.o \
	src/hooks/ipv6_rcv/impl.o \
	src/hooks/ipv6_rcv_finish/impl.o \
	src/hooks/ip6_rcv_finish_core/impl.o \
	src/hooks/tcp_rcv_established/impl.o \
	src/hooks/tcp_v4_do_rcv/impl.o \
	src/hooks/tcp_v4_rcv/impl.o \
	src/hooks/tcp_v4_rcv/hook.o \
	src/prepare/resolve_function_address.o \
	src/tools/tools.o \
	src/module_starter.o \




OUTPUT_DIR = "./build"

# 这个必须要是 headers 的绝对路径才能行
ccflags-y += -I/home/zhf/Projects/linux/loadable_kernel_module/headers

all: compile
	echo "successful make"

compile:
	make -C /lib/modules/5.19.0/build/ M=$(PWD) modules

mv:
	mv .*.cmd *.ko *.o *.mod *.mod.c Module.symvers modules.order $(OUTPUT_DIR)

clean:
	rm -rf .*.cmd *.ko *.o *.mod *.mod.c Module.symvers modules.order
	# make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
