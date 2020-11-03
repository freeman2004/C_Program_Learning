 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 #include <unistd.h>
 #include <signal.h>

 #define ec_neg1(s,m) if((s) == -1) {perror(m); exit(errno);}



 static void handler_sg1(int signum)
 { 
   write(1,"A\n", 2);
 }

 static void handler_sg2(int signum)
 { 
   write(1,"B\n", 2);
 }

 int main(int argc, char *argv[])
 {

   struct sigaction sa;

   memset(&sa, 0, sizeof(sa));
   sa.sa_handler = handler_sg1;
   ec_neg1(sigaction(SIGUSR1, &sa, NULL), "sigaction");
   sa.sa_handler = handler_sg2;
   ec_neg1(sigaction(SIGUSR2, &sa, NULL), "sigaction");

   printf("receiver started...\n");

   while(1)
     ;


  return 0;
 }
