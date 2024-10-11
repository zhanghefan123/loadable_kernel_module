#include "tools/tools.h"
#include "api/ftrace_hook_api.h"
#include "hooks/ip6_rcv_finish_core/ip6_rcv_finish_core.h"

char* tcp_v6_early_demux = "tcp_v6_early_demux";
asmlinkage void (*original_tcp_v6_early_demux)(struct sk_buff *skb);
char *udp_v6_early_demux = "udp_v6_early_demux";
asmlinkage void (*original_udp_v6_early_demux)(struct sk_buff *skb);
char *ip6_route_input = "ip6_route_input";
asmlinkage void (*original_ip6_route_input)(struct sk_buff *skb);

static inline bool skb_valid_dst(const struct sk_buff *skb) {
    struct dst_entry *dst = skb_dst(skb);
    return dst && !(dst->flags & DST_METADATA);
}

bool resolve_ip6_rcv_finish_core_inner_functions_address(void){
    bool resolve_result;
    LOG_WITH_EDGE("start to resolve ip6_rcv_finish_core inner functions address");

    original_tcp_v6_early_demux = get_function_address(tcp_v6_early_demux);
    resolve_result = TEST_RESOLVED(original_tcp_v6_early_demux, tcp_v6_early_demux);
    if(!resolve_result){
        return resolve_result;
    }

    original_udp_v6_early_demux = get_function_address(udp_v6_early_demux);
    resolve_result = TEST_RESOLVED(original_udp_v6_early_demux, udp_v6_early_demux);
    if(!resolve_result){
        return resolve_result;
    }

    original_ip6_route_input = get_function_address(ip6_route_input);
    resolve_result = TEST_RESOLVED(original_ip6_route_input, ip6_route_input);
    if(!resolve_result){
        return resolve_result;
    }

    LOG_WITH_EDGE("end to resolve ip6_rcv_finish_core inner functions address");
    return resolve_result;
}

void self_defined_ip6_rcv_finish_core(struct net *net, struct sock *sk,
                                struct sk_buff *skb)
{
    if (READ_ONCE(net->ipv4.sysctl_ip_early_demux) &&
        !skb_dst(skb) && !skb->sk) {
        switch (ipv6_hdr(skb)->nexthdr) {
            case IPPROTO_TCP:
                if (READ_ONCE(net->ipv4.sysctl_tcp_early_demux))
                    original_tcp_v6_early_demux(skb);
                break;
            case IPPROTO_UDP:
                if (READ_ONCE(net->ipv4.sysctl_udp_early_demux))
                    original_udp_v6_early_demux(skb);
                break;
        }
    }

    if (!skb_valid_dst(skb))
        original_ip6_route_input(skb);
}
