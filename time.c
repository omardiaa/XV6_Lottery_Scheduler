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


  for(int i=0;i<argc;i++){
    int ret;

    ret = fork();
    if (ret == 0){
      exec(argv[i], argv);
      printf(2, "FAILED: exec failed to execute %s\n", argv[i]);
      exit();
    }
    else if(ret == -1){
      printf(2, "FAILED: fork failed\n");
    }
    else{
      printf(1, "Executing wait on: %s\n",argv[i]);
      wait();
      printf(1, "Finished Executing wait on: %s\n",argv[i]);

    }
  }
  

  exit();
}
