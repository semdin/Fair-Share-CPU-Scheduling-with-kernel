#include <stdio.h>
#include <stdlib.h>
#include <linux/processinfoS23.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sched.h>


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Lutfen bir arguman giriniz.\n");
        return 1;
    }
    
    int flag = atoi(argv[1]);
    
    struct processdataS23 data;

    data.flag = flag;

    int ret = processinfoS23(&data);


    //printf("Process info for PID %d:\n", data.pid);

    if(flag > 23){
        printf("Process counter: %ld\n", data.processcounter);
        printf("Weight: %ld\n", data.weight);
    }
    else{
        printf("PID: %d\n", data.pid);
        printf("Parent PID: %d\n", data.pidparent);
        printf("UID: %d\n", data.uid);
        printf("Parent GID: %d\n", data.gidparent);
        printf("Priority: %ld\n", data.priority);
        printf("Nice value: %ld\n", data.nice);
        printf("Process counter: %ld\n", data.processcounter);
        printf("Weight: %ld\n", data.weight);
    }
    printf("%d\n", ret);

    
    sleep(10);
    return 0;
}
