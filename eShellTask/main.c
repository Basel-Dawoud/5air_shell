#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


#define MAX_BUFFER_SIZE 1024

// Print all environment variables (same as env)
void envir(void) {
    extern char **environ;
    char **env = environ;
    while (*env) {
        printf("%s\n", *env++);
    }
}

// Printing The Current Working Directory
void currDir(void) {
    size_t size = MAX_BUFFER_SIZE;
    char bufarr[MAX_BUFFER_SIZE];
    char *buf = bufarr;
    char *dir = getcwd(buf, size);

    if (dir != NULL) {
        printf("The current working directory is: %s\n", buf);
    } else {
        perror("Error getting current working directory");
    }
}

// Printing the input string
void Echo(void) {
    char *token;

    // Tokenize the input string
    token = strtok(NULL, " ");

    // Walk through tokens
    while (token != NULL) {
        printf(" %s", token);
        token = strtok(NULL, " ");
    }
    printf("\n");
}

// Copying a file to another
void cop(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: cop <sourcePath> <targetPath> [-a]\n");
        return;
    }

    const char *srcPath = argv[1];
    const char *destPath = argv[2];
    int append = 0;

    if (argc == 4 && strcmp(argv[1], "-a") == 0) {
        append = 1;
        srcPath = argv[2];
        destPath = argv[3];
    }

    int srcfd = open(srcPath, O_RDONLY);
    if (srcfd == -1) {
        perror("Error opening source file");
        return;
    }

    int flags = O_WRONLY | O_CREAT | (append ? O_APPEND : O_TRUNC);
    int destfd = open(destPath, flags, 0644);
    if (destfd == -1) {
        perror("Error opening destination file");
        close(srcfd);
        return;
    }

    char buff[MAX_BUFFER_SIZE];
    ssize_t bytesRead;
    while ((bytesRead = read(srcfd, buff, sizeof(buff))) > 0) {
        if (write(destfd, buff, bytesRead) != bytesRead) {
            perror("Error writing to destination file");
            close(srcfd);
            close(destfd);
            return;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from source file");
    }

    close(srcfd);
    close(destfd);
}

// Moving a file to another place
void MV(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: MV <sourcePath> <targetPath>\n");
        return;
    }

    const char *srcPath = argv[1];
    const char *destPath = argv[2];

    if (rename(srcPath, destPath) == -1) {
        perror("Error moving file");
    }
}

// Print help information
void Help(void) {
    printf("Supported commands are:\n");
    printf("1- currDir : Print the current working directory\n");
    printf("2- Echo <string> : Print the user input string on stdout\n");
    printf("3- cop <sourcePath> <destinationPath> [-a] : Copy a file to another file\n");
    printf("   Use -a option to append to the target file\n");
    printf("4- MV <sourcePath> <destinationPath> : Move a file to another place\n");
    printf("5- mycd <path> : Change the current working directory to the specified path\n");
    printf("6- Exit : Print 'Good Bye' and terminate the shell\n");
    printf("7- Help : Print this help message\n");
}

// Exit the shell
void Exit(void) {
    printf("Good Bye :)\n");
    exit(0);
}


// Determine if the command is internal
int isBuiltinCommand(const char *command) {
    const char *builtinCommands[] = {"currDir", "Echo", "cop", "MV", "Help", "Exit", "envir", "mycd", "type"};
    for (int i = 0; i < sizeof(builtinCommands) / sizeof(builtinCommands[0]); i++) {
        if (strcmp(command, builtinCommands[i]) == 0) {
            return 1; // True, it's a built-in command
        }
    }
    return 0; // False, it's not a built-in command
}

// Changing the directory to the target path
int mycd(const char *path) {
    if (chdir(path) == -1) {
        perror("chdir");
        return -1;
    }
    return 0;
}


// Function to execute an external command
void executeExternalCommand(const char *command, char **args) {
    /*Debugging output
    printf("Executing command: %s\n", command);
    if (args[0] != NULL) {
        printf("Arguments:\n");
        for (int i = 0; args[i] != NULL; ++i) {
            printf("  args[%d] = %s\n", i, args[i]);
        }
    }*/
    if (execvp(command, args) == -1) {
        perror("execvp");
        exit(EXIT_FAILURE);  // Exit with failure status
    }
}
