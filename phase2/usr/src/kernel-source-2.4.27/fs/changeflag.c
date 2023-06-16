#include <linux/changeflag.h>
#include <stdbool.h>
#include <linux/kernel.h>

asmlinkage int sys_changeflag(){
	extern bool schFlag;
	schFlag = false;
	return 0;
}
