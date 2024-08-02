# 5air Shell

Welcome to the 5air Shell project! This is a simple shell implementation written in C that supports built-in commands execution.

This project implements a simple shell with basic command functionalities, including printing the current working directory, echoing strings, copying files, moving files, and providing help information.

## Features

- **currDir**: Prints the current working directory.
- **Echo**: Prints the input string to the standard output.
- **cop**: Copies a file from source to destination, with an optional append mode.
- **MV**: Moves (or renames) a file from source to destination.
- **Help**: Provides information about available commands.
- **Exit**: Terminates the shell with a goodbye message.

## Usage

After compiling, you can run the shell using:

```bash
./bashell
```

### Commands

1. **currDir**
   - **Usage**: `currDir`
   - **Description**: Prints the current working directory.

2. **Echo**
   - **Usage**: `Echo <string>`
   - **Description**: Prints the user input string on stdout.

3. **cop**
   - **Usage**: `cop <sourcePath> <destinationPath> [-a]`
   - **Description**: Copies a file from the source path to the destination path. Use `-a` to append content to the target file.
   - **Example**: `cop file1.txt file2.txt` (or `cop -a file1.txt file2.txt`)

4. **MV**
   - **Usage**: `MV <sourcePath> <destinationPath>`
   - **Description**: Moves a file from the source path to the destination path.
   - **Example**: `MV file1.txt backup/file1.txt`

5. **Help**
   - **Usage**: `Help`
   - **Description**: Prints help information about available commands.

6. **Exit**
   - **Usage**: `Exit`
   - **Description**: Terminates the shell and prints a goodbye message.

## Examples

1. **Print the Current Working Directory**
   ```bash
   5air> currDir
   ```

2. **Echo a String**
   ```bash
   5air> Echo Hello, World!
   ```

3. **Copy a File**
   ```bash
   5air> cop file1.txt file2.txt
   ```
   Or with append mode:
   ```bash
   5air> cop -a text.txt text2.txt
   ```

4. **Move a File**
   ```bash
   5air> MV /home/vm/Desktop/shellTask/text.txt /home/vm/Desktop/text.txt
   ```

5. **Print Help Information**
   ```bash
   5air> Help
   ```

6. **Exit the Shell**
   ```bash
   5air> Exit
   ```

## Contact

For questions or feedback, please reach out to baseldawoud2003@gmail.com.
