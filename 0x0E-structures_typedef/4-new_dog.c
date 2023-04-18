#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog.
 * @name: name of the dog.
 * @age: age of the dog.
 * @owner: owner of the dog.
 *
 * Return: struct dog.
 * if fails, returns NULL.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *p_dog;
	int i, lname, lowner;

	if (name == NULL || owner == NULL)
		return (NULL);

	p_dog = malloc(sizeof(*p_dog));
	if (p_dog == NULL)
		return (NULL);

	lname = 0;
	while (name[lname] != '\0')
		lname++;
	p_dog->name = malloc(lname + 1);
	if (p_dog->name == NULL)
	{
		free(p_dog);
		return (NULL);
	}
	for (i = 0; i <= lname; i++)
		p_dog->name[i] = name[i];

	lowner = 0;
	while (owner[lowner] != '\0')
		lowner++;
	p_dog->owner = malloc(lowner + 1);
	if (p_dog->owner == NULL)
	{
		free(p_dog->name);
		free(p_dog);
		return (NULL);
	}
	for (i = 0; i <= lowner; i++)
		p_dog->owner[i] = owner[i];

	p_dog->age = age;

	return (p_dog);
}
