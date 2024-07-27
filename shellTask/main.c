#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "commands.h"

#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define MAX_READB 1024

int main(void) {
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
        printf("\n");

        if (token != NULL) {
            if (strcmp(token, "currDir") == 0) {
                currDir();
            } else if (strcmp(token, "Echo") == 0) {
                Echo();
            } else if (strcmp(token, "cop") == 0) {
                char *args[4];
                int i = 0;
                while (token != NULL && i < 4) {
                    args[i++] = token;
                    token = strtok(NULL, " \n");
                }
                cop(i, args);
            } else if (strcmp(token, "mv") == 0) {
                char *args[3];
                int i = 0;
                while (token != NULL && i < 3) {
                    args[i++] = token;
                    token = strtok(NULL, " \n");
                }
                MV(i, args);
            } else if (strcmp(token, "help") == 0) {
                Help();
            } else if (strcmp(token, "exit") == 0) {
                Exit();
            } else {
                printf("Unknown command: %s\n", token);
            }
        }
    }

    return 0;
}

