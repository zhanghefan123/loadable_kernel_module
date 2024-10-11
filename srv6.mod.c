#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xafd744c6, "__x86_indirect_thunk_rbp" },
	{ 0x6a28d602, "ip_local_deliver" },
	{ 0x90de72a9, "register_ftrace_function" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x745a444f, "register_pernet_subsys" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa916b694, "strnlen" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6f935e35, "ftrace_set_filter_ip" },
	{ 0xa5a1793e, "unregister_ftrace_function" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xb0c2043a, "unregister_pernet_subsys" },
	{ 0xfb578fc5, "memset" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xe8b0db3e, "ip6_input" },
	{ 0xac8ecea2, "netdev_master_upper_dev_get_rcu" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xfcca5424, "register_kprobe" },
	{ 0x63026490, "unregister_kprobe" },
	{ 0x754d539c, "strlen" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x283f8ee6, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E90AC6D0C2E41AAD6C84C5A");
