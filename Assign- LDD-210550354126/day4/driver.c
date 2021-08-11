#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>

static int device_open(struct inode *pinode, struct file *pfile)
{
		printk("Inside open");
			return 0;
}
static ssize_t device_read(struct file *pfile, char *buffer, size_t length, loff_t *offset)
{
		printk("Inside read");
			return 0;
}
static ssize_t device_write(struct file *pfile, const char *buffer, size_t length, loff_t *offset)
{
		printk("Inside write");
			return length;
}
static int device_release(struct inode *pinode, struct file *pfile)
{
		printk("Inside release");
			return 0;
}




struct file_operations f_oper={

	.open	= device_open,
	.read	= device_read,
	.write	= device_write,
	.release= device_release,

};


static int Major;


static int __init driver_entry(void)
{
	printk("We are in Init Function\n");
	/*Registering char driver with kernel */
	Major = register_chrdev(0, "Simple Char Driver",&f_oper);
	if(Major<0)
	{
		printk(KERN_ALERT "Registering char device failed with %d\n", Major);
		return Major;
	}
	printk(KERN_INFO"I was assigned major number %d ", Major);
	


return 0;
}

void __exit driver_exit(void)
{
	
	printk("We are in Exit function\n");
	
       unregister_chrdev(Major, "Simple Char Driver");
/*	if (ret<0)
		printk(KERN_ALERT "ERROR IN UNREGISTER %d", ret);*/
}

module_init(driver_entry);
module_exit(driver_exit);

