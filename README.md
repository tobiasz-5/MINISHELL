# Our Awesome Shell Project

![Shell Parsing Overview](https://i.ibb.co/DzCHpdY/tekkens.png)

## Description

This project is a custom implementation of a simple shell in C. The shell is capable of:
- Parsing command lines
- Executing commands with arguments
- Handling pipes (`|`)
- Managing input/output redirection (`>`, `<`, `>>`)
- Supporting environment variable expansion (`$VAR`)
- Handling basic built-in commands such as `cd`, `pwd`, `echo`, `export`, etc.

## Features

- **Command Parsing**: The shell reads and interprets commands entered by the user.
- **Pipelines**: You can chain commands together using pipes (`|`).
- **Redirections**: Standard input/output can be redirected using operators like `>`, `>>`, and `<`.
- **Environment Variables**: Variables can be set and expanded during command execution.
- **Built-in Commands**: Common shell commands like `cd`, `exit`, `echo`, and others are implemented directly in the shell.
  
## Technologies

- **C Language**: The entire shell is written in C.
- **Lex and Yacc**: Used for tokenizing and parsing command-line input.
  
## Usage

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/shell-project.git
    cd shell-project
    ```

2. Compile the shell:
    ```bash
    make
    ```

3. Run the shell:
    ```bash
    ./my_shell
    ```

4. Example usage:
    ```bash
    ls -l | grep "txt" > output.txt
    ```

## Project Structure

