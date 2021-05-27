#include "headers.h"

void take_input(char** c){
	char inp_old[10001];
	//char 
	int i = 0;
	if(fgets(inp_old,10000,stdin) == 0){
		ctrl_d = 1;
	}

	char* token;
	strcpy(inp,inp_old);
	inp_old[strlen(inp_old) - 1] = '\0';
	token = strtok(inp_old,";");
	
	
	//printf("jhelo %d\n",strlen(inp_old) );
	while(token != NULL){
		c[i] = token;
		i++;
		token = strtok(NULL,";");
	}

	size = i;
	c[size] = NULL;
	//printf("122 %s\n",c[0]);
	//printf("jhelllo %d\n",strlen(inp_old) );
}
void reset_input(char** inp1,char** inp_p){
	for(int i = 0;i<100;i++){
	inp1[i] = "";
	inp_p[i] = "";
}
size = 0;
size_st = 0;
}
void process_input(char* str,char** c){
	char delim[] = " \t";
	char *token = strtok(str,delim);
	int i = 0;
	while(token != NULL){
		c[i] = token;
		 
		 token = strtok(NULL,delim);
		 i++;
	}
	int str_size = i;
	c[str_size] = NULL;
	size_st = str_size;
}