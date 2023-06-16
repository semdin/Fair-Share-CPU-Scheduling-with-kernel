#include <stdio.h>
#include <stdlib.h>
#include <linux/changeflag.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sched.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {

  changeflag();

	int i=0;
	while( true )
	{
		i = (i+1)%1000;
        //if (i == 0)
          //break;
	}

    return 0;
}
