#include "headers.h"

void fun_pinfo(char** c){

 char path[100000] = "/proc/";
 char path_f[100000];
 char path_1[100000];
 char path_2[100000];
 int mem;
int flag;
char curr_path[100001];
flag = 0;
 if(size_st>1){
 	strcat(path,c[1]);
 }
 else{
 	//printf("testing 1 %d\n",getpid());
 	sprintf(path,"%s%d",path,getpid());
 	//printf("pleeejjjj\n");
 	//strcpy(path,path_f);

 }
//printf("chaljaa\n");
 strcpy(path_2,path);

 strcpy(path_1,path);		//path_1 = proc/pid
 //printf("kjsbkd\n");
 strcat(path,"/stat");		//path = proc/pid/stat
 FILE* fd = fopen(path,"r");
 if(fd == NULL){
 	perror("pinfo");
 	return;
 }

 int pid;

 char status[3],res[30];
 fscanf(fd,"%d",&pid);
 fscanf(fd,"%s",res);
 fscanf(fd,"%s",status);
 printf("Process ID -- %d\nProcess Status -- %s\n",pid,status);
 fclose(fd);
 //strcpy(path_1,path);
 strcat(path_1,"/statm");	//path_1 = proc/pid/statm

 fd = fopen(path_1,"r");
 if(fd == NULL ){
 	perror("mem pinfo");
 	return;
 }
fscanf(fd,"%d",&mem);
printf("memory -- %d {Virtual Memory}\n",mem);
fclose(fd);
strcat(path_2,"/exe"); //path_2 = proc/pid/exe
 //printf("test : %s\n",path_2)
char buff[10000];
int len;
if((len = readlink(path_2,buff,sizeof(buff)-1))< 0){
	perror("readlink");
}
else{
		//getcwd(buff,100000);
	if(strlen(buff) < strlen(source_dir)){
		printf("Executable Path --> %s\n",buff);
		return;
	}
	else{

	for(int i = 0;i<strlen(source_dir );i++){
		if(source_dir[i] != buff[i]){
			flag = 1;
		}
	}
	if(!flag){
	printf("Executable Path --> ~%s\n", buff + strlen(source_dir));
	}
	else{
	printf("Executable Path --> %s\n", buff);

	}
}
}

}