// uptime. How long has xv6 been up
#include "types.h"
#include "user.h"

// seconds per minute
#define SPM (60)
// seconds per hour
#define SPH (60 * SPM)

#define pad(x, y) if ((x) < 10) printf(1, "0"); printf(1, "%d%s", (x), (y));

int
main(int argc, char *argv[])
{
  // int ticks = uptime();
  // int ms = ticks % TPS; // TPS in pdx.h
  // int s  = ticks / TPS;
  // int hours = (s / SPH);
  // int mins  = (s - (SPH * hours)) / 60;
  // int secs  = (s - (hours * SPH) - (mins * SPM));

  // pad(hours, ":"); // note that hours is not bounded, so may take more than 2 digits
  // pad(mins,  ":");
  // pad(secs,  ".");

  // // milliseconds
  // if (ms < 10)  printf(1, "0");
  // if (ms < 100) printf(1, "0");
  // printf(1, "%d\n", ms);


    int start_time = uptime();
    int end_time = 0;
    int ret;

   // int cur_arg=1;
    ret = fork();
    if (ret == 0){
      exec(argv[1], argv+1);
      printf(2, "FAILED: exec failed to execute %s\n", argv[1]);
      exit();
    }
    else if(ret == -1){
      printf(2, "FAILED: fork failed\n");
    }
    else{
      wait();
  
      end_time=uptime();
      printf(1,"%s ran in %d milli seconds\n", argv[1],end_time-start_time); 

    }
  

  exit();
}
