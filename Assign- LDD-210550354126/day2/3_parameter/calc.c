#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rajeev Kumar Sharma");

static int my_func(char*s, int x, int y)
{
	if (strcmp(s,"add")==0)
	{
			return(x+y);
	}
	else if (strcmp(s,"sub")==0)
	{
			return(x-y);
	}
	else if (strcmp(s,"mul")==0)
	{
			return(x*y);
	}
	else if (strcmp(s,"div")==0)
	{
			return(x/y);
	}

return 0;

}

static int a=0;
static int b=0;
static char* s=0;

module_param(a, int, S_IRUGO);
module_param(b, int, S_IRUGO);
module_param(s, charp, S_IRUGO);

static int  __init param_entry(void)
{
	printk("Inputs by command line %d %d %s\n", a,b,s);
	printk("Calculated result is : %d\n ", my_func(s,a,b));
	return 0;
}

static void  __exit param_exit(void)
{
	printk("Successfully Clean\n");
}


module_init(param_entry);
module_exit(param_exit);
