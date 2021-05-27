#include "headers.h"
int ifpipe(char** c){
	int f,arr[1000];
	f = 0;
	for(int i = 0;i< size_st;i++){
		if(strcmp(c[i],"|") == 0){
			arr[f] = i;
			f++;
		}
	}
	for(int i=1;i<f;i++)
	{
		if(arr[i]-arr[i-1]==1)
		{
			return -1;
		}
	}
	if(f>0){
		if(arr[0] == 0 || arr[f-1] == size_st-1){
			return -1;
		}
	}
	return(f);
}
void piping(char** c){
	//printf("pahunch apipe\n");
	char** temp;
	int pipeno,oldsize;
	int stdin,stdout,infd,outfd,k,j;
	oldsize = size_st;
	temp = (char**)malloc(100*sizeof(char*));
	stdin = dup(0);
	stdout = dup(1);
	for(int i = 0;i<size_st;i++){
		if(strcmp(c[i],"|") == 0){
			pipeno ++;
		}
	}
	infd = dup(stdin);
	//printf("sufbsknfksjd\n");
	j = 0;
	int arr[2];
	//printf("no. %d\n",pipeno );
	for(int i = 0;i<pipeno;i++){
		//printf("i %d\n",i );
		//printf("gggggggggggggggg\n");
		if(dup2(infd,0)!=0){
			perror("Dup2 error");
		}

		close(infd);

		if(pipe(arr) == -1){
			perror("Piping Failed");
		}

		infd = arr[0]; 
		outfd = arr[1];
		if(dup2(outfd,1)!=1){
			perror("Dup2 failed");
		}
		close(outfd);
		k = 0;
		//printf("bdhafkb\n");
		while(strcmp(c[j],"|") != 0){
			temp[k] = (char*)malloc(10000);
			strcpy(temp[k],c[j]);
			write(stdout,"for - ",strlen("for - "));
		//	printf("%s\n",temp[k] );
			j++;
			k++;
		}
		j++;
		size_st = k;
		temp[k] = NULL;
		exec(temp);
	}
	//printf("siurrn\n");
	//write(stdout,"sshbnj\n",strlen("sshbnj\n"));
	if(dup2(infd,0)!=0){
			perror("Dup2 error");
		}
	close(infd);
	//outfd = dup(stdout);
	//printf("siurrn\n");
	///write(stdout,"hbnj",strlen("hbnj"));

	if(dup2(stdout,1)!=1){
			perror("Dup2 failed");
		}
	//close(outfd);
	k = 0;
	close(outfd);
	//printf("jjjj %d %d\n",j,k );
	while(j<oldsize){
		temp[k] = (char*)malloc(10000);
			strcpy(temp[k],c[j]);
			//printf("ksbkkk  - ");
			//printf("%s\n",temp[k] );
			j++;
			k++;
		}
	size_st = k;
	temp[k] = NULL;
	exec(temp);
	dup2(stdin,0);
	dup2(stdout,1);
	return;
}