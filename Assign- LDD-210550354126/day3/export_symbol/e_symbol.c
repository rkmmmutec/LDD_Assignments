#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rajeev");

static int my_add(int a, int b)
{
	        return ((a+b)/2);
}

EXPORT_SYMBOL(my_add);

