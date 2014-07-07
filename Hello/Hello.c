//
//	The "Hello World" Module!!
//

#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

/*
 *	Adding module parameters
 *	You need to pass all the parameters while loading the module
 *	Else, you might get a "verification failed/tainting kernel"
 *	error message
 */
static int howmany = 1;
static char* whom = "world";
module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static int hello_init(void)
{ 
	int i;
	for(i=0;i<howmany;i++)
	{
		printk(KERN_ALERT "Hello, %s\n" ,whom);
	}
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel %s\n" ,whom);
}

module_init(hello_init);
module_exit(hello_exit);
