#include <linux/processinfoS23.h>
#include <linux/kernel.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/time.h>
#include <asm/current.h>
#include <linux/version.h>

int sys_processinfoS23(struct processdataS23 *data) {

    // Disable interrupts
    cli();

    // Create a local structure in kernel space to hold the user data
    struct processdataS23 newTaskStructure;

    // Copy the user data into the kernel space structure
    copy_from_user(&newTaskStructure, data, sizeof(struct processdataS23));

    int temp;
    struct task_struct *task = current;

    // Fill in the kernel space structure with process information
    newTaskStructure.pid = (data->flag > 23) ? 0 : task->pid;
    newTaskStructure.pidparent = (data->flag > 23) ? 0 : task->p_pptr->pid;
    newTaskStructure.uid = (data->flag > 23) ? 0 : task->uid;
    newTaskStructure.gidparent = (data->flag > 23) ? 0 : task->p_pptr->gid;
    newTaskStructure.priority = (data->flag > 23) ? 0 : task->rt_priority;
    newTaskStructure.nice = (data->flag > 23) ? 0 : task->nice;
    newTaskStructure.processcounter = task->counter;

    if (newTaskStructure.processcounter == 0) {
        newTaskStructure.weight = 0;
    } else {
        temp = (newTaskStructure.processcounter / 2) + 20 - newTaskStructure.nice;
        newTaskStructure.weight = (temp > 0) ? temp : 0;
    }

    if (newTaskStructure.flag > 23 || newTaskStructure.flag < 1) {

        // Copy the kernel space structure back to user space
        copy_to_user(data, &newTaskStructure, sizeof(struct processdataS23));

        // Re-enable interrupts
        sti();

        // Return -1
        return -EINVAL;
    }

    // Copy the kernel space structure back to user space
    copy_to_user(data, &newTaskStructure, sizeof(struct processdataS23));

    // Re-enable interrupts
    sti();

    // Return success
    return 0;
}
