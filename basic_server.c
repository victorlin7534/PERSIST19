#include "pipe_networking.h"

void sighandler(int sig){
  
}

int main() {
  signal(SIGINT,sighandler);
  
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  while(1){
    char input[100];
    read(from_client,input,100);
    printf("server: received <%s>\n",input);

    char output[100];
    //process

    write(to_client,output,100);
  }
}
