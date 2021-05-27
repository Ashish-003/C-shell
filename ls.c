#include "headers.h"
int h_flag = 0;
int all_flag = 0;
char date[100];


void fun_ls(char** c){
char arg[10000];
h_flag = 0;
all_flag = 0;
int flag = 0;
	for(int i =1;i<size_st;i++){
		if(c[i][0] == '-'){
			if(strcmp(c[i],"-l")==0){
				all_flag = 1;
			}
			else if(strcmp(c[i],"-a")==0){
				h_flag = 1;
			}
			else if(strcmp(c[i],"-al")==0 || strcmp(c[i],"-la")==0){
				all_flag = 1;
				h_flag = 1;
			}
		}
	}
	for(int i =1;i<size_st;i++){
		if(c[i][0] != '-'){
			flag = 1;
			printf("%s :\n",c[i]);
			list(c[i]);
		}		
	}
	if(!flag){

			list(".");
		}
	
}
void list(char* path){
	struct dirent *de;
	//printf("1%s1",path);
	if(strcmp(path,"~") == 0){
		path = source_dir;
	}
	DIR *dr = opendir(path);
	if(dr == NULL){
		printf("Could not open the directory\n" ); 
        return ; 
	}
	while((de = readdir(dr) ) != NULL){
		
		if((h_flag == 0 && de->d_name[0] != '.')|| h_flag == 1){
			if(all_flag == 1){
			print_prop(de -> d_name);
		}
			printf("%s\n",de -> d_name );
		
	}

	}
	//printf("\n");
	closedir(dr);
	return ;
}
void print_prop(char* file){
	struct stat stats;
	lstat(file,&stats);
	strftime(date, 100, "%h %d %H:%M", localtime(&(stats.st_ctime)));
	printf( (S_ISDIR(stats.st_mode)) ? "d" : "-");
    printf( (stats.st_mode & S_IRUSR) ? "r" : "-");
    printf( (stats.st_mode & S_IWUSR) ? "w" : "-");
    printf( (stats.st_mode & S_IXUSR) ? "x" : "-");
    printf( (stats.st_mode & S_IRGRP) ? "r" : "-");
    printf( (stats.st_mode & S_IWGRP) ? "w" : "-");
    printf( (stats.st_mode & S_IXGRP) ? "x" : "-");
    printf( (stats.st_mode & S_IROTH) ? "r" : "-");
    printf( (stats.st_mode & S_IWOTH) ? "w" : "-");
    printf( (stats.st_mode & S_IXOTH) ? "x " : "- ");
    printf(" %d ", (int)stats.st_nlink);
    //printf(" %d %s %s",stats.st_nlink);
    //printf(" %d\n",stats.st_size );
    struct group *gr = getgrgid(stats.st_gid);
    struct passwd *pw = getpwuid(stats.st_uid);
    printf(" %s", pw->pw_name);
    printf(" %s", gr->gr_name);
    printf(" %5d ", (int)stats.st_size);
    printf(" %s    ", date);
   
  //  printf(" \t%s\n", name->d_name);
   /// print()
}
