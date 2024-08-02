#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

#include "commands.h"

#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define MAX_READB 1024

extern char **environ;  // Declaration of environ

// Function to execute an external command
void executeExternalCommand(const char *command, char **args) {
    if (execvp(command, args) == -1) {
        perror("execvp");
        exit(EXIT_FAILURE);  // Exit with failure status
    }
}

int main(int argc, char **argv) {
    char commandBuff[MAX_READB];
    char *token;
    ssize_t readSize = 0;
    const char *shellMsg = "5air> ";

    while (1) {
        /* Display prompt message */
        if (write(STDOUT, shellMsg, strlen(shellMsg)) == -1) {
            perror("write");
            return 1;
        }

        /* Read input from standard input */
        readSize = read(STDIN, commandBuff, MAX_READB);
        if (readSize == -1) {
            perror("read");
            return 1;
        }
        if (readSize == 0) {
            // End of file (EOF) or no input; continue to the next iteration
            continue;
        }

        /* Null-terminate the buffer */
        commandBuff[readSize] = '\0';

        /* Get the first token "Command" */
        token = strtok(commandBuff, " \n");
        if (token != NULL) {
            if (isBuiltinCommand(token)) {
                // Handle built-in commands
                if (strcmp(token, "currDir") == 0) {
                    currDir();
                } else if (strcmp(token, "Echo") == 0) {
                    Echo();
                } else if (strcmp(token, "cop") == 0) {
                    char *args[4];
                    int i = 0;
                    args[i++] = token;
                    while ((token = strtok(NULL, " \n")) != NULL && i < 4) {
                        args[i++] = token;
                    }
                    args[i] = NULL;  // Null-terminate the argument list
                    cop(i, args);
                } else if (strcmp(token, "MV") == 0) {
                    char *args[3];
                    int i = 0;
                    args[i++] = token;
                    while ((token = strtok(NULL, " \n")) != NULL && i < 3) {
                        args[i++] = token;
                    }
                    args[i] = NULL;  // Null-terminate the argument list
                    MV(i, args);
                } else if (strcmp(token, "Help") == 0) {
                    Help();
                } else if (strcmp(token, "Exit") == 0) {
                    Exit();
                } else if (strcmp(token, "envir") == 0) {
                    envir();
                } else if (strcmp(token, "mycd") == 0) {
                    char *args[2];
                    int i = 0;
                    args[i++] = token;
                    while ((token = strtok(NULL, " \n")) != NULL && i < 2) {
                        args[i++] = token;
                    }
                    args[i] = NULL;  // Null-terminate the argument list
                    if (i > 1) {
                        mycd(args[1]);
                    } else {
                        fprintf(stderr, "Usage: mycd <path>\n");
                    }
                }
            } else {
                // External commands
                pid_t pid = fork();
                if (pid == -1) {
                    perror("Failed to fork!");
                } else if (pid == 0) {  // Child process
                    // Dynamic allocation for arguments
                    char *args[MAX_READB / 2];
                    int i = 0;
                    args[i++] = token;
                    
                    while ((token = strtok(NULL, " \n")) != NULL) {
                        if (i >= (MAX_READB / 2 - 1)) {
                            fprintf(stderr, "Too many arguments\n");
                            exit(EXIT_FAILURE);
                        }
                        args[i++] = token;
                    }
                    args[i] = NULL;  // Null-terminate the argument list

                    executeExternalCommand(args[0], args);
                } else {  // Parent process
                    int wstatus;
                    if (waitpid(pid, &wstatus, 0) == -1) {
                        perror("waitpid");
                    }
                }
            }
        }
    }

    return 0;
}

