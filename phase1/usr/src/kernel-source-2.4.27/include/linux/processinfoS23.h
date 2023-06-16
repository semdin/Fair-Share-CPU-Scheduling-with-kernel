#ifndef __LINUX_PROCESSINFOS23_H
#define __LINUX_PROCESSINFOS23_H
#include <linux/linkage.h>
#include <linux/types.h>
struct processdataS23 {
	int flag; /* flag for option */
	pid_t pid; /* process id */
	pid_t pidparent; /* process id of parent process */
	long processcounter; /* counter value of the process */
	long nice; /* nice value of the process */
	long uid; /* user id of process owner */
	long gidparent; /* group id of parent process’s owner */
	//unsigned long priority; /* real time priority of the process */
	int priority; /* real time priority of the process */
	long weight; /* weight is 0 if counter is 0, otherwise; value calculated
	with counter/2+20-nice */
};
#endif

