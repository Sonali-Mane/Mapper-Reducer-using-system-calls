 #include <stdio.h>
 #include <unistd.h>
 #include <stdarg.h>
 int v = 5;
 int main()
 {int n,fd[2];
char buf[10000];
pipe(fd);
 printf("Before fork\n");   /* Executable only by the parent */
 pid_t pid = fork();               /* At the time of the call parent exists */
  
char *args[]={"./mapper",NULL};
char *args1[]={"./reducer",NULL};
  
pid_t pid1=fork();
printf("\n---------------pdi of child process: %d\n",pid1);
if(pid1==0)
{
printf("\n--------------------------------------------------------------in child pid :%d\n",getpid());
close(fd[0]);
 dup2(fd[1],STDOUT_FILENO);
execvp(args[0],args);
write(fd[1],STDOUT_FILENO,10000);
}
  
 if (pid == 0)               
   {

close(fd[1]);
    dup2(fd[0],STDIN_FILENO);
    n=read(STDIN_FILENO,buf,10000);   
    execvp(args1[0],args1);
      
   
   }
else{
	//wait();
	//wait(NULL );
  close(fd[0]);
  close(fd[1]);
  printf("Parent"); 

}



  exit(0);
  
  
 }
