
#include<linux/init.h>
#include<linux/module.h>


static int hello_int(void)
{
	        printk("Hello World\n");
		        return 0;
}
static void hello_exit(void)
{
	        printk("Good Bye \n");
}
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rajeev Kumar Sharma");


module_init(hello_int);
module_exit(hello_exit);
