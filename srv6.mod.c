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
	{ 0x9040fe81, "__inet_lookup_established" },
	{ 0x5e56411d, "__skb_checksum_complete" },
	{ 0x343a1997, "tcp_enter_quickack_mode" },
	{ 0x955b36d8, "tcp_inbound_md5_hash" },
	{ 0xafd744c6, "__x86_indirect_thunk_rbp" },
	{ 0x1c319bbf, "__tracepoint_tcp_bad_csum" },
	{ 0x5d36106b, "__inet_lookup_listener" },
	{ 0xc0afb5d7, "cgroup_bpf_enabled_key" },
	{ 0xecd07f35, "tcp_child_process" },
	{ 0x90de72a9, "register_ftrace_function" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x4fabb8eb, "__xfrm_policy_check" },
	{ 0xd2800691, "nf_conntrack_destroy" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xc2fb483f, "__SCT__tp_func_tcp_bad_csum" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x745a444f, "register_pernet_subsys" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x47bd3647, "tcp_filter" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa916b694, "strnlen" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6f935e35, "ftrace_set_filter_ip" },
	{ 0x7a191044, "reuseport_migrate_sock" },
	{ 0x325212cb, "tcp_add_backlog" },
	{ 0xa3401d29, "inet_twsk_deschedule_put" },
	{ 0x8d51a14b, "inet_csk_reqsk_queue_drop_and_put" },
	{ 0x9eea5f67, "tcp_timewait_state_process" },
	{ 0xa5a1793e, "unregister_ftrace_function" },
	{ 0x2b32e610, "sk_free" },
	{ 0xf150501, "kfree_skb_reason" },
	{ 0x2d7ced32, "__SCK__tp_func_tcp_bad_csum" },
	{ 0x6e7e3993, "kmem_cache_free" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xb0c2043a, "unregister_pernet_subsys" },
	{ 0xfb578fc5, "memset" },
	{ 0x5d32007e, "kfree_skb_partial" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x34f242cd, "tcp_parse_options" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xf341ee35, "tcp_hashinfo" },
	{ 0xbfe275f7, "__pskb_pull_tail" },
	{ 0x18ce0411, "__cgroup_bpf_run_filter_sock_ops" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x61c4b812, "tcp_check_req" },
	{ 0x1b1eabfe, "sock_rfree" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0x38c1d4b8, "sock_pfree" },
	{ 0x161e7b1d, "dst_release" },
	{ 0xfcca5424, "register_kprobe" },
	{ 0x241e7d00, "tcp_rcv_state_process" },
	{ 0x63026490, "unregister_kprobe" },
	{ 0xa9320d27, "ktime_get_seconds" },
	{ 0x3cedd486, "inet_twsk_put" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x688e72e1, "__SCT__preempt_schedule_notrace" },
	{ 0xb5b54b34, "_raw_spin_unlock" },
	{ 0xd0e6ac13, "ipv4_dst_check" },
	{ 0x2d98f7f4, "__kfree_skb" },
	{ 0x283f8ee6, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "28031991C979B692CFB7C7A");
