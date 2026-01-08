#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>


#define MAX_LINE_SIZE 1024    //the maximum bytes of an inputted command line 
#define MAX_ARG_NUM  30       //the maximum number of arguments in a command line
#define MAX_DIR_LEN 128       //the maximum bytes of directory 

int shell_read_line(char *);
int get_line_args(char *, char **);
int shell_execute(char **, int);


int main(int argc_main, char *argv_main[])
{
  char *cmd_line;
  char ** cmd_args;
  char dir_buf[MAX_DIR_LEN];
  int argc, char_num, status;
  int wait_return, wait_status;
  int magic_flag = 0;
  
  cmd_line = argv_main[1];
  if(argc_main == 3){
    magic_flag = atoi(argv_main[2]); /* indicating that the test case contains a change directory  */
  }
  
  // Intialize command args
  if ((cmd_args = malloc(MAX_ARG_NUM * sizeof(char *))) == NULL) {
    printf("malloc() error for cmd_args\n");
    exit(-1);
  }
  memset(cmd_args, 0 , MAX_ARG_NUM);


  if( (argc = get_line_args(cmd_line, cmd_args)) <= 1){
    //"NULL" as the input or have error
    printf("Error: Not effective command.\n");
    exit(0);
  }
  if ( (status = shell_execute(cmd_args, argc)) < 0 )
    //break;
    exit(0);
    
  // for test case 1, need to check the current directory
  if(magic_flag == 1){
    getcwd(dir_buf,128);
    printf("%s\n",dir_buf);
  }
      

  return 0;
}

/* helper functions */
int shell_read_line(char * cmd_buf)
{
  int position = 0;
  char c;

  while (1) {
    // Read one character each time
    c = getchar();

    // For newline, put a null character and return.
    if ( c == '\n') {
      cmd_buf[position] = '\0';
      return position;
    } else {
      cmd_buf[position] = c;
      position++;

      //if too big, warning and return -1 
      if (position >= MAX_LINE_SIZE) {
        printf("The command size is too big\n");
        return -1;
      }
    }   
  }
}


int get_line_args(char * line, char ** args)
{
  int start_position = 0;
  int end_position = 0;
  char c;
  int argc = 0;
  while (argc < MAX_ARG_NUM ){
    //Jump to the first non-space/tab char
    while(1){
      c= line[start_position];
      if ( c == ' ' || c == '\t'){
        start_position ++;
      }else{
        break;
      }
    }
    //Check if the end of string - if yes, return the argument as NULL; otherwise, find the argument
    if ( c == '\0'){
      args[argc] = NULL;
      argc++;
      return argc;
    }else{
      end_position = start_position;

      //Move end_position to the end of the argument 
      while(1){
        end_position++;
        c= line[end_position];
        if ( c == ' ' || c == '\t' || c == '\0')
          break;
      }


      if( c != '\0'){ 
        line[end_position] = '\0';
        end_position++;
      }

      args[argc] = & line[start_position];  
      argc ++;

      start_position = end_position;

    }

  }

  //Should never go here; Return -1 for error
  return -1;

}
