#include "headers.h"

int fun_setenv(char** c){
	if(size_st > 3 || size_st==1){
		printf("Invalid input for setenv\n");
		return 1;
	}
	else{
	if(size_st == 2){
		c[2] = "";
	}
	
	if(setenv(c[1],c[2],1)!=0){
		perror("Setenv");
	}
}
}

int fun_unsetenv(char** c){
	if(size_st!=2)
	{
		printf("Invalid input for unsetnev\n");
		return 1;
	}
	else if(unsetenv(c[1])!=0)
	{
		perror("Unsetenv");
	}
}

