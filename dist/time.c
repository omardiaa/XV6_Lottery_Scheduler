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
    int start_time = uptime();
    int end_time = 0;
    int ret;

    ret = fork();
    if (ret == 0){
      exec(argv[1], argv+1);
      exit();
    }
    else if(ret == -1){
      printf(2, "FAILED: fork failed\n");
    }
    else{
      wait();
  
      end_time=uptime();
      
      int ms = (end_time-start_time) % TPS; // TPS in pdx.h
      int s  = (end_time-start_time) / TPS;
      printf(1,"%s ran in %d.", argv[1],s); 
      // milliseconds
      if (ms < 10)  printf(1, "0");
      if (ms < 100) printf(1, "0");
      printf(1, "%d seconds\n", ms); 

    }
  

  exit();
}
