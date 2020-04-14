#include "shell.h"

/**
 * execute_program - Execute a program
 * @token: Input recieved from strtok
 * @argv: Argument Input
 * @number: Number of times entered by console
 */

void execute_program(char **token, char *argv, int number)
{
	pid_t childPID;
	int exec = 0, val_builtin = 0;

	if (token[0] == NULL)
		return;

	val_builtin = is_buitin(token);
	if (val_builtin == 1)
	{
		free_memory(token);
		return;
	}

	childPID = fork();
	if (childPID < 0)
	{
		printf("Error during fork\n");
		free_memory(token);
		exit(EXIT_FAILURE);
	}
	else if (childPID != 0)
	{
		wait(NULL);
		return;
	}
	else
	{
		exec = execve(token[0], token, NULL);
		if (exec < 0)
		{
			printf("%s: %d: %s: not found\n", argv, number, token[0]);

			free(token);
			exit(EXIT_FAILURE);
		}
		free_memory(token);
		exit(EXIT_SUCCESS);
	}
}
