#ifndef COMMANDS_H
#define COMMANDS_H

// Printing The Current Working Directory
void currDir(void);

// Printing the input string
void Echo();

// Copying a file to another
void cop(int argc, char **argv);

// Moving a file to another place
void MV(int argc, char **argv);

// Print help information
void Help(void);

// Exit the shell
void Exit(void);

#endif // COMMANDS_H

