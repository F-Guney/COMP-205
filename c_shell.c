#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <unistd.h>
#include <sys/wait.h>
#include "reverse_order.h"
#include "root_calculator.h"

char **get_input(char *);
int cd(char *);
int history(char *[], int);

int main() {
    char **command;
    char *input;
    pid_t child_pid;
    int stat_loc;
    int current = 0;

    
    while (1) {
	input = readline("user@shell --> ");
        command = get_input(input);

        if (!command[0]) {      /* Handle empty commands */
            free(input);
            free(command);
            continue;
        }

        if (strcmp(command[0], "cd") == 0) {
            if (cd(command[1]) < 0) {
		perror(command[1]);
		
            }

            /* Skip the fork */
            continue;
        }
	
	if (strcmp(command[0], "exit") == 0) {
		exit(0);
	}

	if (strcmp(command[0], "reverse_order") == 0) {
		reverse_order();
	}

	if (strcmp(command[0], "root_calculator") == 0) {
		root_calculator();
	}

		
        child_pid = fork();
        if (child_pid < 0) {
            perror("Fork failed");
            exit(1);
        }

        if (child_pid == 0) {
            /* Never returns if the call is successful */
            if (execvp(command[0], command) < 0) {
		perror(command[0]);
                exit(0);
            }
        } else {
            waitpid(child_pid, &stat_loc, WUNTRACED);
        }

        free(input);
        free(command);
    }

    return 0;
}

char **get_input(char *input) {
    char **command = malloc(8 * sizeof(char *));
    if (command == NULL) {
        perror("malloc failed");
        exit(1);
    }

    char *separator = " ";
    char *parsed;
    int index = 0;

    parsed = strtok(input, separator);
    while (parsed != NULL) {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;
    return command;
}

int cd(char *path) {
    return chdir(path);
}


