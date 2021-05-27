#include "headers.h"

char* inp1[100];
char* inp_p[100];
int size1;
int main()
{		
      getcwd(source_dir,1023);
      ctrl_d = 0;
      job_size = 0;
      histsize = 0;
      init_his();
      strcpy(prev_dir,source_dir);
      signal(SIGINT,handler1);
      signal(SIGTSTP,handler2);
  		while(1){
        reset_input(inp_p,inp1);

        prompt();
        //take_input(inp1);
       //ch     ar str1[100] = "ck cks c       jd dcjdhbc  hhh";
       //TAKE INPUT HERE

      take_input(inp1);
      if(ctrl_d){
        fun_quit();
      }
      inp[strlen(inp) - 1] = '\0';
      if(strlen(inp))
       store();
       //printf("%d\n",size );

       for(int i = 0;i<size;i++){
       process_input(inp1[i],inp_p);

      
      // printf("\n%d %s \n je :%s size : %d \n",i,inp1[1],inp_p[0],size_st);
      int idk = ifpipe(inp_p);
      if(size_st!=0){
        if(idk<0){
          printf("Invalid piping\n");
        }
        else if(idk>0){
            //printf("aya pipe\n");
            piping(inp_p);
         } 
         else{
        exec(inp_p);
        }
        
          

     }


       }

    
}
}