#include "main.h"

/**
 * tokenize - Tokenize a string into an array of strings
 *
 * This function takes a string as input and tokenizes it into an array of
 * strings using a specified delimiter. The resulting array is suitable for
 * use as command arguments.
 *
 * @line: The string to tokenize.
 *
 * Return: An array of strings representing the tokenized input, or NULL
 *         if unsuccessful.
 */

char	**tokenize(char *line)
{
	char *tok = NULL;
	char **cmd = NULL;
	char *temp = NULL;
	int count = 0;
	int i = 0;

	if (!line)
		return (NULL);
	temp = _strdup(line);
	tok = strtok(temp, DELIMI);
	if (tok == NULL)
	{
		free(line), line = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (tok)
	{
		count++;
		tok = strtok(NULL, DELIMI);
	}
	free(temp), temp = NULL;

	cmd = malloc(sizeof(char *) * (count + 1));
	if (!cmd)
	{
		free(line), line = NULL;
		return (NULL);
	}

	tok = strtok(line, DELIMI);
	while (tok)
	{
		cmd[i++] = _strdup(tok);
		tok = strtok(NULL, DELIMI);
	}
	cmd[i] = NULL;
	free(line), line = NULL;
	return (cmd);
}
