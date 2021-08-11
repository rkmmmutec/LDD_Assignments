#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include"kern_add.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rajeev");

static int x = 0;
static int y = 0;


module_param(x , int, S_IRUGO);
module_param(y , int, S_IRUGO);

static int __init add_init(void)
{
	        printk("Average of two number is %d", my_add(x,y));
		        return 0;
}
static void __exit add_exit(void)
{
}

module_init(add_init);
module_exit(add_exit);
