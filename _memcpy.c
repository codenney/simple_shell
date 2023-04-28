#include "main.h"

/**
 * _memcpy - function entry
 * Description: copies n chars from memory area src to dest
 * @dest: destination where src to be copied to
 * @src: source data to be copied
 * @n: number of bytes to copy
 */
void _memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;
	char *new_src = (char *)src;
	char *new_dest = (char *)dest;

	while (i < n)
		new_dest[i] = new_src[i];

}
