# Enhanced 5air Shell

Ebashell is an enhanced version of Bashell with additional functionality for handling external commands. 

## Features

- **Built-in Commands**:

The following built-in commands are supported:

1. **currDir**: Prints the current working directory.
2. **Echo <string>**: Prints the user input string on stdout.
3. **cop <sourcePath> <destinationPath> [-a]**: Copies a file to another file. Use the `-a` option to append to the target file.
4. **MV <sourcePath> <destinationPath>**: Moves a file to another location.
5. **Exit**: Prints 'Good Bye' and terminates the shell.
6. **Help**: Prints this help message.
7. **mycd <path>**: Changes the current directory to the specified path.
8. **envir**: Prints environment variables.
9. **type <command>**: Checks if a command is a built-in command.

- **External Command Execution**: Executes commands using `execvp`.

In addition to the built-in commands, Ebashell supports execution of external commands. You can run any executable command available in the directories listed in your `PATH` environment variable.

## Usage

1. **Build the Shell**:
   Compile the shell using `gcc`:
   ```bash
   gcc main.c commands.c -o ebashell
   ```

2. **Run the Shell**:
   Start the shell with:
   ```bash
   ./ebashell
   ```

3. **Commands**:
   - `currDir` - Displays the current directory.
   - `Echo <string>` - Prints `<string>` to the terminal.
   - `cop <sourcePath> <destinationPath> [-a]` - Copies a file from `sourcePath` to `destinationPath`. Use `-a` to append to the destination file.
   - `MV <sourcePath> <destinationPath>` - Moves a file from `sourcePath` to `destinationPath`.
   - `Help` - Displays this help message.
   - `Exit` - Exits the shell with a "Good Bye" message.
   - `envir` - Shows environment variables.
   - `mycd <path>` - Changes the directory to `<path>`.
   - `type <command>` - Checks if `<command>` is a built-in command or an executable file in the system `PATH`.

## Example

To run the shell and use its commands:

```bash
./ebashell
```

In the shell prompt:
```text
5air> Help
Supported commands are:
1- currDir : Print the current working directory
2- Echo <string> : Print the user input string on stdout
3- cop <sourcePath> <destinationPath> [-a] : Copy a file to another file
   Use -a option to append to the target file
4- MV <sourcePath> <destinationPath> : Move a file to another place
5- mycd <path> : Change the current working directory to the specified path
6- Exit : Print 'Good Bye' and terminate the shell
7- Help : Print this help message
5air> Echo Hello World
Hello World
5air> currDir
/home/user/yourdirectory
5air> cop file1.txt file2.txt -a
5air> MV oldfile.txt newfile.txt
5air> mycd /new/directory
5air> type Echo
Echo: Built-in Command
5air> Exit
Good Bye
```

Notes

    The type command can be used to check if a command is a built-in command or if it's an executable file in your PATH.
    The shell will handle both built-in and external commands according to the functionality described above.

Example of External Commands

```bash
./ebashell


```text
$ ./ebashell
5air> ls
commands.c  commands.h.gch  ebashell  main.o	 text.txt
commands.h  commands.o	    main.c    text2.txt
5air> pwd
/home/vm/Desktop/eShellTask
5air> mkdir new_directory
5air> cd new_directory
5air> touch new_file.txt
5air> Exit
Good Bye
```

## Adding New Features

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Basel-Dawoud/shell.git
   ```

2. **Create a New Branch**:
   ```bash
   git checkout -b feature-branch
   ```

3. **Make Your Changes**.

4. **Commit Your Changes**:
   ```bash
   git add .
   git commit -m "Added new features"
   ```

5. **Push Your Changes**:
   ```bash
   git push origin feature-branch
   ```

## Acknowledgments

- [GNU C Library](https://www.gnu.org/software/libc/) for system-level functionality.
- [GitHub](https://github.com) for version control and collaboration.
