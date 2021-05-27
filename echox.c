#include "headers.h"
/*void fun_echo(char inp_str[]){
	char *str[100000];
	const char delim[2]= " \t";
	char *token = strtok(inp_str,delim);
	int i = 0;
	int str_size = 0;
	printf("\n");
	if(inp_str[0] == '\0'){
		//printf("fvsdv\n");
		printf("\n");
		return;
	}
	else{
	while(token != NULL){
		//printf("fvsfv\n");
		str[i] = token;
		i++;	
		token = strtok(NULL,delim);
	}

	str_size = i;
	str[str_size] = NULL;
	///printf("%s\n",str[4] );
	for(i = 0;i<str_size-1;i++){
	
		printf("%s ",str[i]);
			//printf("deecb %d\n",i);
	}
	printf("%s\n",str[str_size-1]);
	}
}*/
void fun_echo(char** str){
	//printf("\n");
	
		for (int i = 1;i<size_st-1;i++){
			printf("%s ",str[i]);

		}
		printf("%s\n",str[size_st-1]);
	
}
