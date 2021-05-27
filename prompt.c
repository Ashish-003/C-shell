#include "headers.h"
void prompt(){
	char hostname[1024];
	char* username;
	char curr_dir[1024];
	char* path;
	hostname[1023] ='\0';
	curr_dir[1023] ='\0';
	gethostname(hostname, 1023);
	getcwd(curr_dir,1023);
	username = getlogin();
	int len = strlen(curr_dir);
	int src_len = strlen(source_dir);
	//path[0] = "~";
	if(len < src_len){
    printf("%s@%s:%s$ ",username,hostname,curr_dir);  
    }
    else{
    	path = curr_dir;
  		path = path+src_len; 	
    	printf("%s@%s:~%s$ ",username,hostname,path);	
    }  
}

