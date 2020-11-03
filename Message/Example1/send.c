#include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
 #include <time.h>
 #include <signal.h>

 #define ec_neg1(s,m) if((s) == -1) {perror(m); exit(errno);}


 int main(int argc, char *argv[])
 {
  pid_t pid;
  int sleepVal;

  struct timespec ts;

  if(argc == 3)
  {
    pid = atoi(argv[1]);
    sleepVal= atoi(argv[2]);

    ts.tv_sec = 0;
    ts.tv_nsec = sleepVal * 1000000L;

    printf("sender started...\n");

    char msg[100] = "AABBBABA";
    int i;

    for (i = 0; msg[i] != '\0'; ++i)
    {
          if(msg[i] == 'A')
              kill(pid, SIGUSR1);
          else if( msg[i] == 'B')
              kill(pid, SIGUSR2);

          //Wait for sleepVal  milliseconds after every signal
          ec_neg1(nanosleep(&ts, NULL),"nanosleep failed")
    }

    printf("done.\n");

  }

  return 0;
 } 
