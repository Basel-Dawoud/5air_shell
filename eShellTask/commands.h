#ifndef COMMANDS_H
#define COMMANDS_H

// Printing The Current Working Directory
void currDir(void);

// Printing the input string
void Echo(void);

// Copying a file to another
void cop(int argc, char **argv);

// Moving a file to another place
void MV(int argc, char **argv);

// Print help information
void Help(void);

// Exit the shell
void Exit(void);

// Changing the directory to the target path
int changeDirectory(const char *path);

// Print all environment variables
void envir(void);

// Execute an external command
//void executeExternalCommand(const char *command, char **args);


// Determine if the command is internal
int isBuiltinCommand(const char *command);

// mycd path : change the current directory
// Changing the directory to the target path
int mycd(const char *path);

#endif // COMMANDS_H

