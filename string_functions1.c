#include "shell.h"

/**
 * string_copy - this function copy a string
 * @dest: the destination of string
 * @src: the source of string
 *
 * Return: pointer to destination
 */
char *string_copy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);

}
