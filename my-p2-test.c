/*
  A basic test suite for Portland State University CS333 Operating Systems Project 2.
  Created by Joe Coleman
*/
#ifdef CS333_P2
#include "types.h"
#include "user.h"

// comment out tests for features the student doesn't have implemented
// Note the CPUTIME_TEST requires GETPROCS_TEST
#define CPUTIME_TEST
#define GETPROCS_TEST


#ifdef GETPROCS_TEST
#include "uproc.h"
#endif

#ifdef GETPROCS_TEST
#ifdef CPUTIME_TEST
// Simple test to have the program sleep for 200 milliseconds to see if CPU_time properly doesn't change
// And then gets CPU_time again to see if elapsed CPU_total_ticks is reasonable
static int
getcputime(char * name, struct uproc * table){
  struct uproc *p = 0;
  int size;

  size = getprocs(64, table);
  for(int i = 0; i < size; ++i){
    if(strcmp(table[i].name, name) == 0){
      p = table + i;
      break;
    }
  }
  if(p == 0){
    printf(2, "FAILED: Test program \"%s\" not found in table returned by getprocs\n", name);
    return -1;
  }
  else
    return p->CPU_total_ticks;
}

static void
testcputime(char * name){
  struct uproc *table;
  uint time1, time2, pre_sleep, post_sleep;
  int success = 0;
  int i, num;

  printf(1, "\n----------\nRunning CPU Time Test\n----------\n");
  table = malloc(sizeof(struct uproc) * 64);
  if (!table) {
    printf(2, "Error: malloc() call failed. %s at line %d\n", __FUNCTION__, __LINE__);
    exit();
  }
  printf(1, "This will take a couple seconds\n");

  // Loop for a long time to see if the elapsed CPU_total_ticks is in a reasonable range
  time1 = getcputime(name, table);
  for(i = 0, num = 0; i < 1000000; ++i){
    ++num;
    if(num % 100000 == 0){
      pre_sleep = getcputime(name, table);
      sleep(200);
      post_sleep = getcputime(name, table);
      if((post_sleep - pre_sleep) >= 100){
        printf(2, "FAILED: CPU_total_ticks changed by 100+ milliseconds while process was asleep\n");
        success = -1;
      }
    }
  }
  time2 = getcputime(name, table);
  if((time2 - time1) < 0){
    printf(2, "FAILED: difference in CPU_total_ticks is negative.  T2 - T1 = %d\n", (time2 - time1));
    success = -1;
  }
  if((time2 - time1) > 400){
    printf(2, "ABNORMALLY HIGH: T2 - T1 = %d milliseconds.  Run test again\n", (time2 - time1));
    success = -1;
  }
  printf(1, "T2 - T1 = %d milliseconds\n", (time2 - time1));
  free(table);

  if(success == 0)
    printf(1, "** All Tests Passed! **\n");
}
#endif
#endif

#ifdef GETPROCS_TEST
// Fork to 64 process and then make sure we get all when passing table array
// of sizes 1, 16, 64, 72. NOTE: caller does all forks.
static int
testprocarray(int max, int expected_ret){
  struct uproc * table;
  int ret, success = 0;

  table = malloc(sizeof(struct uproc) * max);  // bad code, assumes success
  if (!table) {
    printf(2, "Error: malloc() call failed. %s at line %d\n", __FUNCTION__, __LINE__);
    exit();
  }
  ret = getprocs(max, table);
  sleep(2000);

  if (ret != expected_ret){
    printf(2, "FAILED: getprocs(%d) returned %d, expected %d\n", max, ret, expected_ret);
    success = -1;
  }
  else{
    printf(2, "getprocs() was asked for %d processes and returned %d. SUCCESS\n", max, expected_ret);
  }
  free(table);
  return success;
}

static int
testinvalidarray(void){
  struct uproc * table;
  int ret;

  table = malloc(sizeof(struct uproc));
  if (!table) {
    printf(2, "Error: malloc() call failed. %s at line %d\n", __FUNCTION__, __LINE__);
    exit();
  }
  ret = getprocs(1024, table);
  free(table);
  if(ret >= 0){
    printf(2, "FAILED: called getprocs with max way larger than table and returned %d, not error\n", ret);
    return -1;
  }
  return 0;
}

static void
testgetprocs(){
  int ret, success;

  printf(1, "\n----------\nRunning GetProcs Test\n----------\n");
  printf(1, "Filling the proc[] array with dummy processes\n");
  // Fork until no space left in ptable
  ret = fork();
  if (ret == 0){
    while((ret = fork()) == 0);
    if(ret > 0){
      wait();
      exit();
    }
    // Only return left is -1, which is no space left in ptable
    success  = testinvalidarray();
    success |= testprocarray( 1,  1);
    success |= testprocarray(16, 16);
    success |= testprocarray(64, 64);
    success |= testprocarray(72, 64);
    if (success == 0)
      printf(1, "** All Tests Passed **\n");
    exit();
  }
  wait();
}
#endif

int
main(int argc, char *argv[])
{
  #ifdef GETPROCS_TEST
  testgetprocs();  // no need to pass argv[0]
  #endif
  printf(1, "\n** End of Tests **\n");
  exit();
}
#endif
