#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rajeev Kumar Sharma");

static char* chvr = "Rajeev";
static int intvr = 5;


module_param(chvr, charp, S_IRUGO);
module_param(intvr, int, S_IRUGO);


static int __init param_entry(void)
{
	printk(KERN_ALERT "\n We are in init function\n");
	printk(KERN_ALERT "\n The value of chvr is %s \n", chvr);
	printk(KERN_ALERT "\n The value of intvr is %d \n", intvr);
	return 0;
}
static void __exit param_exit(void)
{
	printk("\n Good Bye Parameter");

}

module_init(param_entry);
module_exit(param_exit);
