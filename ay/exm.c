#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

#define MAXCOMMANDLENGTH 100

int main();
void Hcommand_line(char *command, char **args);
void fork_prompt(char *command);
void remove_newline(char *strings);
void write_prompt(int get_sigint);

/**Function to display the shell prompt*/
void write_prompt(int get_sigint)
{
	(void)get_sigint;

	signal(SIGINT, write_prompt);
	write(STDOUT_FILENO, "\n$Amshi$ ", 10);
}

/**Function to remove the trailing newline character from strings*/
void remove_newline(char *strings)
{
	if (strings == NULL)
		return;

	size_t length = strlen(strings);

	if (length > 0 && strings[length - 1] == '\n')
		strings[length - 1] = '\0';
}

/**Function to fork and execute the user command*/
void fork_prompt(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
/**Child process
 * we change this line char* args[] = {command, NULL};by two line*/

		char *args[MAXCOMMANDLENGTH];

		Hcommand_line(command, args);
		if (execve(command, args, NULL) == -1)
		{
			perror("Command execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
/**Parent process*/
		int status;

		waitpid(pid, &status, 0);
	}
}
/**Function to parse the command and its arguments*/
void Hcommand_line(char *command, char **args)
{
	char *token = strtok(command, " ");
	int i = 0;

	while (token != NULL && i < MAXCOMMANDLENGTH - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}

int main()
{
	char command[MAXCOMMANDLENGTH];

	while (1)
	{
		write_prompt(0); /** Display the prompt to the user*/
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}/*Call the function to remove the trailing newline character*/
		remove_newline(command);       
         /**Execute the user command*/
		fork_prompt(command);
	}
	return (0);
}