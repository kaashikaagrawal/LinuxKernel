#include <linux/sched/signal.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

void dfs(struct task_struct *task, int indent) {
    struct task_struct *child;
    struct list_head *list;
    int i;

    for (i = 0; i < indent; i++) {
        printk(KERN_CONT "\t");
    }
    printk(KERN_CONT "|--Name: %s PID: %d State: %u\n", task->comm, task->pid, task->__state);

    list_for_each(list, &task->children) {
        child = list_entry(list, struct task_struct, sibling);
        dfs(child, indent + 1);
    }
}

static int dfs_init(void) {
	
	printk(KERN_INFO "Listing all processes in tree structure:\n");
	
	dfs(&init_task, 0);
	
	return 0;
}

static void dfs_exit(void) {
	printk(KERN_INFO "Exiting...");	
}

module_init(dfs_init);
module_exit(dfs_exit);

