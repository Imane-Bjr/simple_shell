#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _getline - Read a line from standard input.
 * @line_stock: A pointer to pointer to character where
 * the read line willl be stored.
 * @init_size: A pointer to variable that holds the initial buffer size.
 * Return: The number of characters read or -1 on failure.
 */
ssize_t _getline(char **line_stock, size_t *init_size)
{
	char *new_buff;
	ssize_t numb_bytes = 0;
	size_t pos = 0;
	size_t new_size;

	if (line_stock == NULL || init_size == NULL)
		return (-1);

	if (*line_stock == NULL || *init_size == 0)
	{
		*init_size = 128;
		*line_stock = malloc(*init_size * sizeof(char));
		if (*line_stock == NULL)
		{
			return (-1);
		}
	}
	for (;;)
	{
		if (pos >= *init_size - 1)
		{
			new_size = *init_size * 2;
			new_buff = _realloc(*line_stock, *init_size * sizeof(char),
			 new_size * sizeof(char));
			if (new_buff == NULL)
			{
				return (-1);
			}
			*line_stock = new_buff;
			*init_size = new_size;
		}
		if (numb_bytes <= 0 && pos == 0)
			return (-1);
		(*line_stock)[pos] = '\0';
		return (pos);
	}
}
