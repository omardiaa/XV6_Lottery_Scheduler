/*
  A basic test suite for Portland State University CS333 Operating Systems Project 2.
  Created by Joe Coleman
*/
#ifdef CS333_P2
#include "types.h"
#include "user.h"

// comment out tests for features the student doesn't have implemented
// Note the CPUTIME_TEST requires GETPROCS_TEST
#define GETPROCS_TEST

#ifdef GETPROCS_TEST
#include "uproc.h"
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
