#include <stdio.h>
#include<stdio.h> 
#include<string.h> 
#include<fcntl.h> 
#include<errno.h> 
#include<unistd.h> 
#include<stdlib.h> 
#include<dirent.h>
#include<time.h>
#include<sys/stat.h> 
#include<sys/wait.h>
#include<pwd.h>
#include<grp.h>
#include<termios.h>
#include<string.h>
#include<sys/select.h>
#include<dirent.h>
 int size; //number of commands
int size_st; // number of args
char source_dir[1024];
//char hist[24][10000];

int ctrl_d;

char prev_dir[1024];

char inp[10000];

int histsize;

char hist[40][10000];

struct node {
	int status,pid;
	char com[1000];
};

 struct node procs[1000];

 int job_size;

void prompt();

void take_input(char **c);

void process_input(char* str,char** c);

void fun_echo(char **c);

void fun_pwd();

void fun_cd(char** c);

void exec(char **c);

void reset_input(char** inp1,char** inp_p);

void fun_ls(char** c);

void print_prop(char* file);

void list(char* path);

void fgbg(char** c);

void fun_fg(char** c);

void fun_bg(char** c);

void fun_pinfo(char** c);

void history(char** c);

void init_his();

void show_history(char** c);

void store();

void checkbg();

int ifredirect(char** c);

int redirect(char** c);

int fun_setenv(char** c);

int fun_unsetenv(char** c);

void piping(char** c);

int ifpipe(char** c);

int fun_jobs();

void handler1(int signum);

void handler2(int signum);

void fun_quit();

void fun_overkill();

void fun_kjob(char** c);

void exec_bg(char** c);

void exec_fg(char** c);