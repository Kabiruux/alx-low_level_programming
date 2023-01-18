#include <stdlib.h>
#include "dog.h"
/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: pointer to a new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int k, j, i;
	dog_t *h;

	if (name == NULL || owner == NULL)
		return (NULL);
	h = malloc(sizeof(dog_t));
	if (h == NULL)
		return (NULL);
	for (k = 0; name[k]; k++)
		;
	k++;
	h->name = malloc(k * sizeof(char));
	if (h->name == NULL)
	{
		free(h);
		return (NULL);
	}
	for (i = 0; i < k; i++)
		h->name[i] = name[i];
	h->age = age;
	for (j = 0; owner[j]; j++)
		;
	j++;
	h->owner = malloc(j * sizeof(char));
	if (h->owner == NULL)
	{
		free(h->name);
		free(h);
		return (NULL);
	}
	for (i = 0; i < j; i++)
		h->owner[i] = owner[i];
	return (h);
}
