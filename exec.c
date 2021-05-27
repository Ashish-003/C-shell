#include "headers.h"
void exec(char** c){
	//printf("\n1 %s aloo\n",c[0] );
	if(ifredirect(c)){
           redirect(c);
        }
	else{
	if(strcmp(c[0],"echo") == 0){
		//("dnln11111fls\n");
		fun_echo(c);

	}
	else if(strcmp(c[0],"pwd") == 0){
		//printf("dnln22222fls\n");
		fun_pwd();
	}
	else if(strcmp(c[0],"cd") == 0){
		fun_cd(c);
	}
	else if(strcmp(c[0],"ls") == 0){
		fun_ls(c);
	}
	else if(strcmp(c[0],"pinfo") == 0){

		fun_pinfo(c);
	
	}
	else if(strcmp(c[0],"history") == 0){
		show_history(c);
	}
	else if(strcmp(c[0],"setenv") == 0){
		fun_setenv(c);
	}
	else if(strcmp(c[0],"unsetenv") == 0){
		fun_unsetenv(c);
	}
	else if(strcmp(c[0],"jobs") == 0){
		fun_jobs();
	}
	else if(strcmp(c[0],"quit") == 0){
		fun_quit();
	}
	else if(strcmp(c[0],"overkill") == 0){
		fun_overkill();
	}
	else if(strcmp(c[0],"kjob") == 0){
		fun_kjob(c);
	}
	else if(strcmp(c[0],"fg") == 0){
		exec_fg(c);
	}
	else if(strcmp(c[0],"bg") == 0){
		exec_bg(c);
	}
	else{
		fgbg(c);
	}
}

}