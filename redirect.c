#include "headers.h"

int ifredirect(char** c){
	int i = 0;
	while(i<size_st){
		if(strcmp(c[i],"<") == 0 || strcmp(c[i],">") == 0 || strcmp(c[i],">>")==0)
		{
			//printf("kjndsjnds\n");
			return 1;
		}
		i++;
	}
return 0;
}

int redirect(char** c){
	char infile[100000];
	char outfile[100000];
	int f1,f2,f3,pos,fd[2];
	f1 = 0;
	f2 = 0;
	f3 = 0;
	pos = 100;
	int incop,outcop;
	//printf("sfn:");
	/*for(int i = 0;i<size_st;i++){
		//printf("%s ",c[i] );
	}
	//printf("\n");*/
	for(int i = 0;i<size_st;i++){
		if(strcmp(c[i],"<") == 0){
			f1 = i;
			pos = f1;
			strcpy(infile,c[f1+1]);		
		}
		if(strcmp(c[i],">") == 0){
			f2 = i;
			//printf("strcpy\n");
			for(int j= 0;j<size_st;j++){
				//printf("%s ",c[j] );
				//c[i] = NULL;
			}
			//printf("\n");
			//printf("%d \n",f2 );
			//printf("%s ",c[0] );
			strcpy(outfile,c[f2+1]);
			//printf("out %s\n",c[f2+1] );
			//printf("size : %d : ",size_st);
			//for(int l = 0;l<size_st;l++){
				//printf("%s ",c[0] );
				//c[i] = NULL;
			//}
			//printf("\n");
			if(f2 <= pos){
				pos = f2;
			}
			fd[1]=open(outfile,O_WRONLY | O_CREAT | O_TRUNC,0644);
			close(fd[1]);
			}
		if(strcmp(c[i],">>") == 0){
			f3 = i;
			strcpy(outfile,c[f3+1]);
			if(f3 <= pos){
				pos = f3;
			}
			fd[1]=open(outfile,O_WRONLY | O_CREAT | O_APPEND,0644);
			close(fd[1]);
		}
	}

	if(f1 == 0 && f2 == 0 && f3 == 0){
		return 0;
	}
	
	size_st = pos;
	c[pos] = NULL;
	int pid;
	pid  = fork();
	if(pid<0)
	{
		close(fd[1]);
		perror("Fork error");
		return 0;
	}
	if(pid==0)
	{	
		//outcop = dup(1);
		if(f1){
		struct stat tmp;
			int grad = stat(infile,&tmp);
			if(grad<0)
			{
				perror(infile);
			}
			

			fd[0] = open(infile,O_RDONLY,0644);
			incop = dup(0);
			dup2(fd[0],0);
			close(fd[0]);
		}
		if(f2>f3){
			fd[1]=open(outfile,O_WRONLY | O_CREAT | O_TRUNC,0644);

		}
		else if(f3>f2){
			fd[1]=open(outfile,O_WRONLY | O_CREAT | O_APPEND,0644);

		}
		//printf("f %d %d %d %d\n",f2,f3,size_st,pos);
		//printf("fdfff\n");
		/*for(int j = 0;j<pos;j++){
			//printf("%s ",c[j] );
		}*/
		//printf("\n");
		//sleep(3);
		if(f2 || f3){
			if(dup2(fd[1],1)<0)
			{
				perror("dup2 failed");
				return 0;
			}
		close(fd[1]);
		}


		exec(c);
		dup2(outcop,1);
		dup2(incop,0);
		exit(0);
//
	}
	else
	{
		wait(NULL);
		
		
	}
		
return 0;
}