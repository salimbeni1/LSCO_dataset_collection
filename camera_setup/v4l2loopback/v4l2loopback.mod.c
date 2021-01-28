#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x59253af, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x7ab86d23, __VMLINUX_SYMBOL_STR(param_array_ops) },
	{ 0xbf58a035, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x74b1e72, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x3cb3492a, __VMLINUX_SYMBOL_STR(param_ops_bool) },
	{ 0x81df99c, __VMLINUX_SYMBOL_STR(nonseekable_open) },
	{ 0x5158a229, __VMLINUX_SYMBOL_STR(noop_llseek) },
	{ 0xa1b26e7a, __VMLINUX_SYMBOL_STR(v4l2_event_unsubscribe) },
	{ 0x95b613a2, __VMLINUX_SYMBOL_STR(video_ioctl2) },
	{ 0xe0a7bdcd, __VMLINUX_SYMBOL_STR(misc_deregister) },
	{ 0xab92d3eb, __VMLINUX_SYMBOL_STR(misc_register) },
	{ 0x8adbe9b6, __VMLINUX_SYMBOL_STR(mutex_lock_killable) },
	{ 0xe17e2e72, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xc5960b5a, __VMLINUX_SYMBOL_STR(video_device_release) },
	{ 0xea421b3b, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x7f0bf186, __VMLINUX_SYMBOL_STR(device_create_file) },
	{ 0x676ccc49, __VMLINUX_SYMBOL_STR(__video_register_device) },
	{ 0xab40cca9, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x99077d08, __VMLINUX_SYMBOL_STR(v4l2_ctrl_handler_setup) },
	{ 0xdefe7579, __VMLINUX_SYMBOL_STR(v4l2_ctrl_new_custom) },
	{ 0xb4fc735b, __VMLINUX_SYMBOL_STR(idr_remove) },
	{ 0x506c77e6, __VMLINUX_SYMBOL_STR(v4l2_ctrl_handler_init_class) },
	{ 0x8fdf772a, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0xe60446b8, __VMLINUX_SYMBOL_STR(video_device_alloc) },
	{ 0x7fd563bf, __VMLINUX_SYMBOL_STR(v4l2_device_register) },
	{ 0xa850dafc, __VMLINUX_SYMBOL_STR(idr_alloc) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x84bc974b, __VMLINUX_SYMBOL_STR(__arch_copy_from_user) },
	{ 0xc322725d, __VMLINUX_SYMBOL_STR(vm_insert_page) },
	{ 0x5cd2d5bb, __VMLINUX_SYMBOL_STR(vmalloc_to_page) },
	{ 0xd6ee688f, __VMLINUX_SYMBOL_STR(vmalloc) },
	{ 0x2a098b39, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x4acce123, __VMLINUX_SYMBOL_STR(v4l2_fh_add) },
	{ 0x1f7386be, __VMLINUX_SYMBOL_STR(__ll_sc_atomic_add) },
	{ 0xafcb3db9, __VMLINUX_SYMBOL_STR(v4l2_fh_init) },
	{ 0x81f3f299, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x7f02188f, __VMLINUX_SYMBOL_STR(__msecs_to_jiffies) },
	{ 0x40a9b349, __VMLINUX_SYMBOL_STR(vzalloc) },
	{ 0x866f595d, __VMLINUX_SYMBOL_STR(v4l2_event_pending) },
	{ 0xb35dea8f, __VMLINUX_SYMBOL_STR(__arch_copy_to_user) },
	{ 0x88db9f48, __VMLINUX_SYMBOL_STR(__check_object_size) },
	{ 0x9c5bc552, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0xcb128141, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0x622598b1, __VMLINUX_SYMBOL_STR(init_wait_entry) },
	{ 0x4829a47e, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xabbbd444, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_bh) },
	{ 0xf6f0ffed, __VMLINUX_SYMBOL_STR(_raw_spin_lock_bh) },
	{ 0x3f5c6471, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0xd077ed64, __VMLINUX_SYMBOL_STR(v4l2_fh_exit) },
	{ 0x14abdb3c, __VMLINUX_SYMBOL_STR(v4l2_fh_del) },
	{ 0xf9a3efb9, __VMLINUX_SYMBOL_STR(__ll_sc_atomic_sub) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x60ea2d6, __VMLINUX_SYMBOL_STR(kstrtoull) },
	{ 0x20906cd5, __VMLINUX_SYMBOL_STR(idr_destroy) },
	{ 0xa9b248b6, __VMLINUX_SYMBOL_STR(idr_for_each) },
	{ 0xd56b5f64, __VMLINUX_SYMBOL_STR(ktime_get_ts64) },
	{ 0x5792f848, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x7cfe70d6, __VMLINUX_SYMBOL_STR(video_devdata) },
	{ 0xf12fd2bf, __VMLINUX_SYMBOL_STR(v4l2_ctrl_subscribe_event) },
	{ 0x526c3a6c, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xf33847d3, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x65345022, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xfa5bcf35, __VMLINUX_SYMBOL_STR(mod_timer) },
	{ 0x5cd885d5, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xaacc3134, __VMLINUX_SYMBOL_STR(idr_find_slowpath) },
	{ 0x93d60fcd, __VMLINUX_SYMBOL_STR(v4l2_ctrl_handler_free) },
	{ 0x2a9ff4da, __VMLINUX_SYMBOL_STR(v4l2_device_unregister) },
	{ 0x1a7cd5ca, __VMLINUX_SYMBOL_STR(video_unregister_device) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x1429df6b, __VMLINUX_SYMBOL_STR(device_remove_file) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x1fdc7df2, __VMLINUX_SYMBOL_STR(_mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

