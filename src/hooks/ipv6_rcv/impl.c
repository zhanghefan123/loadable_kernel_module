#include <linux/netfilter.h>
#include "tools/tools.h"
#include "hooks/ipv6_rcv/ipv6_rcv.h"
#include "hooks/ipv6_rcv_finish/ipv6_rcv_finish.h"
#include "api/check_srv6.h"

char* ip6_rcv_core = "ip6_rcv_core";

asmlinkage struct sk_buff *(*original_ip6_rcv_core)(struct sk_buff *skb, struct net_device *dev, struct net *net);

/**
 * 进行 ipv6_rcv 内部函数的解析
 * @return
 */
bool resolve_ipv6_rcv_inner_functions_address(void) {
    bool resolve_result;
    LOG_WITH_EDGE("start to resolve ipv6_rcv inner functions address");
    original_ip6_rcv_core = get_function_address(ip6_rcv_core);
    resolve_result = TEST_RESOLVED(original_ip6_rcv_core, ip6_rcv_core);
    if(!resolve_result){
        return resolve_result;
    }
    LOG_WITH_EDGE("end to resolve ipv6_rcv inner functions address");
    return resolve_result;
}

/**
 *
 * 自定义 ipv6_rcv
 * @param skb 数据包
 * @param dev 设备
 * @param pt 数据包类型
 * @param orig_dev 入设备
 * @return
 */
int self_defined_ipv6_rcv(struct sk_buff *skb,
                          struct net_device *dev,
                          struct packet_type *pt,
                          struct net_device *orig_dev){
    // 记录开始的时间
    u64 start_time;

    // 检测是否是 srv6 并且上层承载的是 TCP 数据包
    bool is_srv6_packet = check_if_srv6_and_tcp(skb);

    start_time = ktime_get_real_ns();

    struct net *net = dev_net(skb->dev);

    skb = original_ip6_rcv_core(skb, dev, net);
    if (skb == NULL)
        return NET_RX_DROP;

    int result = self_defined_ip6_rcv_finish(net, NULL, skb, is_srv6_packet, start_time);

    return result;
}