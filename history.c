#include "headers.h"
//store commmands
char path[10000];


void init_his(){
	strcpy(path,source_dir);
	sprintf(path,"%s/history",path);
	///printf("%s\n",path );
	FILE *fd = fopen(path,"r");
	if(fd == NULL){
		fd = fopen(path,"w");
		fprintf(fd,"0\n");
		//printf(" null\n");
	}
	else{
		fseek(fd,0,SEEK_END);
		int ftells= ftell(fd);
		if(ftells == 0){
			fd = fopen(path,"w");
			fprintf(fd, "0\n" );
		}
	}
	fseek(fd,0,SEEK_SET);
char waste,buff[1000];
	fscanf(fd,"%d",&histsize);
	fscanf(fd,"%c",&waste);
	for(int i = 0;i<histsize;i++){
		fscanf(fd,"%[^\n]s",buff);
		fscanf(fd,"%c",&waste);
		//printf("buff %s\n",buff );
		if(i){
			strcpy(hist[i],buff);
		}
		
	}
	//fprintf(fd,"setttt\n");
	fclose(fd);

}
void store(){
	
	int i;
	FILE *fd = fopen(path,"r");
	if (fd == NULL){
		perror("historypath");
		//exit(0);
	}
	//printf("sfsfff\n");
	i = 0;
		if(histsize == 20){
			{
				while(i<19){
					strcpy(hist[i],hist[i+1]);
					i++;
				}
				histsize--;
			}
		}
		//printf("fdf1111ffff32ffff %d %s\n",histsize,inp);
	
		if(histsize==0){
		strcpy(hist[histsize],inp);
		histsize++;}
		else{
			if(strcmp(hist[histsize-1],inp)!=0){
				strcpy(hist[histsize],inp);
				histsize++;
			}
		}

		fd = fopen(path,"w+");

		if(fd==NULL)
		{
		perror("historypath");
		exit(0);
		}

		fseek(fd,0,SEEK_SET);

		fprintf(fd, "%d\n",histsize);
		i = 0;
		while(i<histsize){
			fprintf(fd, "%s\n",hist[i]);
			i++;
		}
		fclose(fd);
	

}
//show history
void show_history(char** c){
	int arg;
	char buff[10000],waste;
	if(size_st>1){
		 arg = atoi(c[1]);
	}
		int j = 0;
		if(size_st == 1){
		if(histsize >= 10){
			j = histsize - 10;
		}
		int k = 1;
		
			for(;j<histsize;j++){
				printf("%d %s\n",k++,hist[j] );
			}
		}
		else{
			if(histsize >=arg  ){
				j = histsize-arg;
			}
			int k = 1;
		
			for(;j<histsize;j++){
				printf("%d %s\n",k++,hist[j] );
			}
		}
}