#include "headers.h"
void fun_pwd(){
	char curr_dir[10001];
	//printf("sudbkdbk\n");
	getcwd(curr_dir,10000);

	printf("%s\n",curr_dir );
}
void fun_cd(char** c){
	char curr_dir[1024];
	//printf("sudbkdbk\n");
	getcwd(curr_dir,1023);
if(c[1] == NULL){
	chdir(c[1]);
}
else if(strcmp(c[1],"~") == 0 ){
chdir(source_dir);
}
else if(strcmp(c[1],"-") == 0 ){
	printf("%s\n",prev_dir );
	if(prev_dir!=curr_dir)
	chdir(prev_dir);
}
else{
	chdir(c[1]);
}
if(strcmp(curr_dir,prev_dir)!=0){
	strcpy(prev_dir,curr_dir);
}
}
void fun_quit(){
	fun_overkill();
	exit(0);
}
void fun_overkill()
{
	for(int i = 0;i<job_size;i++){
		kill(procs[i].pid,9);
		procs[i].status = 0;
	}
}

void fun_kjob(char** c){
	if(size_st!=3){
		printf("Invalid Input\n");

	}
	else{
		int id = atoi(c[1]);
		int pid = procs[id-1].pid;
		kill(pid,atoi(c[2]));
		procs[id-1].status = 0;
	}
}