#include "pipe_networking.h"

static void sighandler(int sig){
	if(sig == SIGINT){
		remove("request");
		exit(0);
	}
}

int main() {
  signal(SIGINT,sighandler);
  int to_client, from_client;
  while(1){
  	from_client = server_handshake( &to_client );
  	char input[100];
	while(read(from_client,input,100)){
	    printf("server: received <%s>\n",input);
	    char output[strlen(input)];
	    for(int i=0;i<strlen(input);i++)
	    	output[i] = input[strlen(input)-i-1];
	    output[strlen(input)] = '\0';
	    write(to_client,output,strlen(input));
	}
  }
}
