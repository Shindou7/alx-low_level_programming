#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

#define MAXCOMMANDLENGTH 100

int main(void);
void Hcommand_line(char *command, char **args);
void fork_prompt(char *command);
void remove_newline(char *strings);
void write_prompt(int get_sigint);

/**Function to display the shell prompt*/

/**
 * write_prompt - Display the prompt.
 *@get_sigint: signal_Handler.
 *Return: nothing.
 */
void write_prompt(int get_sigint)
{
	(void)get_sigint;

	signal(SIGINT, write_prompt);
	write(STDOUT_FILENO, "\n$Amshi$ ", 9);
}

/**Function to remove the trailing newline character from strings*/
/**
 * remove_newline - Display the prompt.
 *@strings: signal_Handler.
 *Return: nothing.
 */
void remove_newline(char *strings)
{
	size_t length;

	if (strings == NULL)
		return;

	length = strlen(strings);

	if (length > 0 && strings[length - 1] == '\n')
		strings[length - 1] = '\0';
}

/**Function to fork and execute the user command*/
/**
 * fork_prompt - Display the prompt.
 *@command: signal_Handler.
 *Return: nothing.
 */
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
/**Child process*/
/**we change this line char* args[] = {command, NULL};by two line*/

		char *args[MAXCOMMANDLENGTH];

		Hcommand_line(command, args);
		if (execve(args[0], args, NULL) == -1)
		{
			perror("./shell");
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
/**
 * Hcommand_line - Display the prompt.
 *@command: signal_Handler.
 *@args: signal_Handler.
 *Return: nothing.
 */
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
/**
 * main - the main code.
 * Return: always 0.
 */
int main(void)
{
	char command[MAXCOMMANDLENGTH];

	signal(SIGINT, write_prompt);

	while (1)
	{

		write(STDOUT_FILENO, "$Amshi$ ", 8);
		/** Display the prompt to the user*/
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		} /*Call the function to remove the trailing newline character*/
		remove_newline(command);
		/**Execute the user command*/
		fork_prompt(command);
	}
	return (0);
}
