#include "main.h"

/**
 * free_memory- this function used to free memory of list.
 * @list: aloccated memory to where will store readed data.
 */
void free_memory(char **list)
{
	int i = 0;

	if (list != NULL)
	{
		while (list[i] != NULL)
		{
			free(list[i]);
			list[i] = NULL;
			i++;
		}
		free(list);
	}
}

/**
 * _realloc- mimic the work done by realloc function.
 * @p: Pointer to the memory to be reallocated and used.
 * @oldS: Variable that holds the Size of the current memory block.
 * @newS: Variable that holds theSize of the new memory block.
 * Return: A pointer to the reallocated memory block or NULL
 * in case of failure.
 */
void *_realloc(void *p, size_t oldS, size_t newS)
{
	void *n_point = NULL;

	n_point = malloc(newS);
	if (newS == 0)
	{
		free(p);
		return (NULL);
	}

	if (n_point == NULL)
		return (NULL);
	if (p != NULL && oldS > 0)
	{
		size_t copySize = (oldS < newS) ? oldS : newS;

		memcpy(n_point, p, copySize);
		free(p);
	}
	return (n_point);
}
