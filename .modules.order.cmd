cmd_/home/zhf/Projects/srv6_kernel/modules.order := {   echo /home/zhf/Projects/srv6_kernel/srv6.ko; :; } | awk '!x[$$0]++' - > /home/zhf/Projects/srv6_kernel/modules.order
