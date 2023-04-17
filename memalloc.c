#include "shell.h"

/**
* _realloc - Reallocate a memory block using malloc and free
* @ptr: Pointer to the previously allocated memory
* @old_size: Size, in bytes, of the allocated space for ptr
* @new_size: New size, in bytes.
* Return: Pointer to the newly allocated memory block,
* or NULL if the function fails
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *p1 = ptr;
	unsigned int i, s;


	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (new_size > old_size)
		s = old_size;
	for (i = 0; i < s; i++)
		new_ptr[i] = p1[i];

	free(ptr);
	return (new_ptr);
}
