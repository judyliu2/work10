#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


static void sighandler (int signo);

static void sighandler(int signo){
  if (signo == SIGINT){
    printf("Program will exit due to SIGINT\n");
    exit(1);
  }
  
  if (signo == SIGUSR1){
    printf("SIGUSR1 Received. PID: %d\n", getpid());
  }
  
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(1){

   kill(getpid(), SIGUSR1); //sends signal to to intiate SIGUSR1 msg
    sleep(1);
  }
}
