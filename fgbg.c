#include "headers.h"
void fgbg(char** c){
	int flag =0;
	for(int i = 0;i<size_st;i++){
		if(strcmp(c[i],"&") == 0){
			flag = 1;
	}
	
}
	if(!flag){
			fun_fg(c);
			//printf("dcjsd cds\n");
		}
		else{
			fun_bg(c);
		}
	
}

void fun_fg(char** c){
	int pid;
	int status;
	//printf("hhhhhhhhh\n");
	pid = fork();

	if(pid<0){
		printf("ERROR: forking of child process failed\n");
		return;
	}
	if(pid == 0){
		setpgid(0,0);
		
		//close(2);
		/*for(int i = 0;i<size_st;i++){
			printf("%s ",c[i] );
		}*/
		//printf("10000\n");
		if(execvp(*c,c)<0){
			printf("Invalid Command\n");
			//printf("aloo\n");
			exit(0);
		}

		exit(0);
	}
	else{

		//wait(NULL);
		tcsetpgrp(0,pid);
		waitpid(pid,&status,WUNTRACED);
		if(WIFSTOPPED(status)){
			procs[job_size].pid = pid;
			procs[job_size].status = 1;
			strcpy(procs[job_size].com,c[0]);
			job_size++;
			//printf("job %d\n",job_size );
		}
		signal(SIGTTOU,SIG_IGN);
		tcsetpgrp(0,getpid());
		signal(SIGTTOU,SIG_DFL);	
		//printf("alooooo\n");
		//printf("ssssss\n");
	}


}
void fun_bg(char** c){
int pid;
	int status;
	//printf("hhhhhhhhh\n");
	c[size_st -1] = NULL;
	
	
	pid = fork();
	
	if(pid<0){
		printf("ERROR: forking of child process failed\n");
		return;
	}
	if(pid == 0){
		setpgid(0,0);
		if(execvp(*c,c)<0){
			printf("Invalid Command\n");
			//printf("aloo\n");jvdsdjtt
			exit(0);
		}
	exit(0);
	}else{
		   //////////////////////////
		  //::wait(NULL);///////////
		
		//close(2);
		///printf("jhakaas");/////////
		//printf("aloo\n");
		procs[job_size].pid = pid;
		procs[job_size].status = 1;
		strcpy(procs[job_size].com,c[0]);
		job_size++;
		//printf("bjob %d\n",job_size );
		
		signal(SIGCHLD,checkbg);//
	    ///printf("ssssss\n");///
	   	/////////////////////////
	}


}

void checkbg(){
	//printf("kdjnf\n");
	int pid,status,j;
	
	while((pid = waitpid(-1,&status,WNOHANG | WUNTRACED)) >0){
		if(WIFEXITED(status))
		{
			for(int i = 0;i<job_size;i++){
				if(procs[i].pid == pid){
					procs[i].status = 0;
					fprintf(stderr,"\nProcess %s with pid %d exited normally\n",procs[i].com,pid);
				}
			}
	}
//printf("check bg\n");

}
for (int i = 0; i < job_size; ++i)
{
	/* code */
	if (procs[i].status)
	{
		/* code */
		procs[j] = procs[i];
		j++;
	}
}
job_size = j;
}

void exec_bg(char** c){
	if(size_st!= 2){
		printf("Invalid Input\n");

	}
	else{
	int jobid = atoi(c[1]);
	if(procs[jobid-1].status == 1){
		printf("This process is running now\nName = %s\nJobid = %d\nPid = %d\n",procs[jobid-1].com,jobid,procs[jobid-1].pid);
		kill(procs[jobid-1].pid,SIGCONT);
	}
	else{
		printf("Process with jobid %d doesn't exist\n",jobid);
	}
}
}
void exec_fg(char** c){
	int status;
	if(size_st!= 2){
		printf("Invalid Input\n");
	}
	else{
	int jobid = atoi(c[1]);
	int pid = procs[jobid-1].pid;
	if(procs[jobid-1].status == 1){
		kill(pid,SIGCONT);
		tcsetpgrp(0,pid);
		waitpid(pid,&status,WUNTRACED);
		signal(SIGTTOU,SIG_IGN);
		tcsetpgrp(0,getpid());
		signal(SIGTTOU,SIG_DFL);
	}
	else{
		printf("Process with jobid %d doesn't exist\n",jobid);
	}

}
}
int fun_jobs(){
	char dest[1000];
	char pid[100],res[100];
	int k = 1;
	//printf("jobsize  %d\n",job_size);
	for(int i = 0;i<job_size;i++){
		if(procs[i].status != 0){
			sprintf(dest,"/proc/%d/stat",procs[i].pid);
			FILE *p = fopen(dest,"r");
			if(p == NULL){
				procs[i].status = 0;
				continue;
			}
			fscanf(p,"%s %s %s",pid,pid,res);
			if(strcmp(res,"T") == 0){				
				printf("[%d] Stopped %s [%d]\n",i+1,pid,procs[i].pid);		
			}
			else{
				printf("[%d] Running %s [%d]\n",i+1,pid,procs[i].pid);
			}
			k++;
		}
	}
}