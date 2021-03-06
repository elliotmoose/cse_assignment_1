#include "shell.h"

/*
 List all files matching the name in args[1] under current directory and subdirectories
*/
int shellFind(char **args)
{

  printf("shellFind is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'find' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellFind if execvp fails to allow loop to continue

  return 1;
}

/**
 Allows one to display the content of the file
 */
int shellDisplayFile(char **args)
{
  printf("shellDisplayFile is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'display' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellDisplayFile if execvp fails to allow loop to continue

  return 1;
}

/*
	List the items in the directory and subdirectory
*/
int shellListDirAll(char **args)
{

  printf("shellListDirAll is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'listdirall' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellListDirAll if execvp fails to allow loop to continue

  return 1;
}

/*
	List the items in the directory
*/
int shellListDir(char **args)
{
  printf("shellListDir is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'listdir' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellListDir

  return 1;
}

/**
   Counts how many lines are there in a text file. 
   A line is terminated by \n character
**/
int shellCountLine(char **args)
{
  printf("shellCountLine is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'countline' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellCountLine if execvp fails to allow loop to continue

  return 1;
}

/**
 * Allows one to create a daemon process
 */
int shellSummond(char **args)
{
  printf("shellDaemonize is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'summond' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellDaemonize if execvp fails to allow loop to continue

  return 1;
}


/**
 * Allows one to check daemon process
 * 
 */
int shellCheckDaemon(char **args)
{
  printf("shellCheckDaemon is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'checkdaemon' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellCheckDaemon if execvp fails to allow loop to continue

  return 1;
}

/**
   Allows one to change directory 
 */
int shellCD(char **args)
{
  printf("shellCD is called! \n");
  if (args[1] == NULL)
  {
    fprintf(stderr, "CSEShell: expected argument to \"cd\"\n");
  }
  else
  {
    // chdir() changes the current working directory of the calling process
    // to the directory specified in path.
    if (chdir(args[1]) != 0)
    { //use chdir
      perror("CSEShell:");
    }
  }

  return 1;
}

/**
   Prints out the usage and
   list of commands implemented
 */
int shellHelp(char **args)
{
  printf("shellHelp is called! \n");
  int i;
  printf("CSE Shell Interface\n");
  printf("Usage: command arguments\n");
  printf("The following commands are implemented:\n");

  for (i = 0; i < numOfBuiltinFunctions(); i++)
  {
    printf("  %s\n", builtin_commands[i]); //print all the commands that have been implemented in the shell program
  }

  return 1;
}

/**
  Returns 0, to terminate execution from the shellLoop
 */
int shellExit(char **args)
{
  exit(0);
  return 0;
}


/*
  Builtin function implementations.
*/
int shellUsage(char **args)
{
  int functionIndex = -1;

  // Check if the commands exist in the command list
  for (int i = 0; i < numOfBuiltinFunctions(); i++)
  {
    if (strcmp(args[1], builtin_commands[i]) == 0)
    {
      //pass it to the functions
      functionIndex = i;
    }
  }

  switch (functionIndex)
  {
  case 0:
    printf("Type: cd directory_name\n");
    break;
  case 1:
    printf("Type: help\n");
    break;
  case 2:
    printf("Type: exit\n");
    break;
  case 3:
    printf("Type: usage command\n");
    break;
  case 4:
    printf("Type: display filename\n");
    break;
  case 5:
    printf("Type: countline filename\n");
    break;
  case 6:
    printf("Type: listdir\n");
    printf("Type: listdir -a to list all contents in the current dir and its subdirs\n");
    break;
  case 7:
    printf("Type: listdirall\n");
    break;
  case 8:
    printf("Type: find filename_keyword\n");
    break;
  case 9:
    printf("Type: summond \n");
    break;
  case 10:
    printf("Type: checkdaemon \n");
    break;
  default:
    printf("Command %s not found\n", args[0]);
    break;
  }

  return 1;
}
/*
  End of builtin function implementations.
*/

/**
   Execute inputs when its in the default functions
   Otherwise, print error message and return to loop
 */
int shellExecuteInput(char **args)
{
  /** TASK 3 **/

  // 1. Check if args[0] is NULL. If it is, an empty command is entered, return 1
  if(args[0] == NULL) {
    return 1;
  }

  // 2. Otherwise, check if args[0] is in any of our builtin_commands, and that it is NOT cd, help, exit, or usage.
  int i;
  int is_builtin = 0;
  for(i = 0; i < sizeof(builtin_commands) / sizeof(builtin_commands[0]); i++)
  {
    
    //check is in builtin
    if(strcmp(builtin_commands[i], args[0]) == 0) {
      is_builtin = 1;      
      // 3. If conditions in (2) are satisfied, perform fork(). Check if fork() is successful. (check is not cd, help, exit, usage)
      if(i >= 4) {
        int pid = fork();
        if (pid < 0) {
          fprintf(stderr, "shellExecuteInput: Fork Failed");
        }
        else if(pid == 0) { //child process
          // 4. For the child process, execute the appropriate functions depending on the command in args[0]. Pass char ** args to the function.
          // printf("shellExecuteInput: Child running command %s\n", builtin_commands[i]);      
          builtin_commandFunc[i](args);          
          exit(0); //TODO: do I need to exit? 
        }
        else { //parent process
          // 5. For the parent process, wait for the child process to complete and fetch the child's return value.
          int status;
          // printf("shellExecuteInput: waiting for child\n");      
          waitpid(pid, &status, WUNTRACED);
          // wait(NULL); //wait for ANY child to complete      
          // printf("shellExecuteInput: Child completed with status: %d\n", status);      
          return status;
        }
        break; //should not fork more than once      
      }
      else { //if cd, help, exit, or usage.        
        builtin_commandFunc[i](args);          
        return 0;        
      }
    }
  }
    
  
  // 6. Return the child's return value to the caller of shellExecuteInput  
  // 7. If args[0] is not in builtin_command, print out an error message to tell the user that command doesn't exist and return 1
  if(is_builtin != 1) {
    printf("The command \"%s\" does not exist. Type help to see what commands are available.\n", args[0]);
  }

  return 0;
}

/**
   Read line from stdin, return it to the Loop function to tokenize it
 */
char* shellReadLine(void)
{
  /** TASK 1 **/
  // read one line from stdin using getline()
  // 1. Allocate a memory space to contain the string of input from stdin using malloc. Malloc should return a char* that persists even after this function terminates.
  char *char_buffer = malloc(sizeof(char) * 10);
  size_t size = 10;

  // 2. Check that the char* returned by malloc is not NULL
  if(char_buffer == NULL) {
    printf("shellReadLine malloc returned null");
    return NULL;
  }

  // 3. Fetch an entire line from input stream stdin using getline() function. getline() will store user input onto the memory location allocated in (1)
  getline(&char_buffer, &size, stdin);
  
  // free(char_buffer); //TODO: should i free here?

  // 4. Return the char*
  return char_buffer;
}

/**
 Receives the *line, and return char** that tokenize the line
**/

char **shellTokenizeInput(char *line)
{
  /** TASK 2 **/
  // 1. Allocate a memory space to contain pointers (addresses) to the first character of each word in *line. Malloc should return char** that persists after the function terminates.
  char **tokens = malloc(sizeof(char*) * 10);
  
  // 2. Check that char ** that is returend by malloc is not NULL
  if(tokens == NULL) {
    printf("shellTokenizeInput malloc returned null");
    return NULL;
  }
  
  // 3. Tokenize the *line using strtok() function
  int idx = 0;
  char* p_token = strtok(line, SHELL_INPUT_DELIM);
  if (p_token != NULL) {
    tokens[idx] = p_token;    
    idx += 1;    
  }
  
  // printf("%s\n", p_token);
  
  while (p_token != NULL)
  {
    // printf ("adding token at idx:%d token: %s\n", idx, p_token);
    p_token = strtok (NULL, SHELL_INPUT_DELIM);
    tokens[idx] = p_token;   
    // printf("%s\n", p_token);
    idx += 1;    
  }

   tokens[idx] = NULL; //dont forget to NULL terminate.

  // 4. Return the char **
  return tokens;
}

/**
  The main loop where one reads line,
  tokenize it, and then executes the command
 */
void shellLoop(void)
{
  //instantiate local variables
  char *line;  // to accept the line of string from user
  char **args; // to tokenize them as arguments separated by spaces
  int status;  // to tell the shell program whether to terminate shell or not

  /** TASK 4 **/
  //write a loop where you do the following:

  // 1. print the message prompt
  printf(">");
  // 2. clear the buffer and move the output to the console using fflush
  // fflush(stdin);
  // 3. clear the buffer to accept a new string in readLine()
  // 4. invoke shellReadLine() and store the output at line
  line = shellReadLine();
  // 5. invoke shellTokenizeInput(line) and store the output at args**
  args = shellTokenizeInput(line);
  // 6. execute the tokens using shellExecuteInput(args)

  // 7. free memory location containing the strings of characters
  // 8. free memory location containing char* to the first letter of each word in the input string
  
  // 9. check return value of shellExecuteInput. If 1, continue the loop (point 1) again and prompt for another input. Else, exit shell. 
  status = shellExecuteInput(args);
  if(status == 0) { //TODO: requirement says return 1, but ok return is 0??
    shellLoop();
  }
  else {
    printf("Shell terminated with status code %d\n", status);
    exit(0);
  }
}


int sum(int x, int y) {
  printf("sum ran");
  return x + y;
}
 
// void some_other_function(int (*sum_function_pointer)(int, int)) {
//   printf("Some other function ran");
//   sum_function_pointer(2,3);
// }

int main(int argc, char **argv)
{

  // printf("Shell Run successful. Running now: \n");


  //legal declaration and initialization of pointer to function
  // int (*sum_function_pointer)(int, int) = &sum;  

  // Run command loop
  shellLoop();
  // char* line = shellReadLine();
  // char* line = &"hello world elliot";
  // char** args = shellTokenizeInput(line);
  // int i;
  // for (i = 0; i < 3; i++) {
  //     printf("token at index %d is %s\n",i, args[i]);
  // }

  // shellExecuteInput(args);

  // printf("The fetched line is : %s \n", line);
  // free(line);

  return 0;
}
