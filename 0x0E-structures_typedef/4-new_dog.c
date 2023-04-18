#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog with given name, age, owner
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: pointer to the new dog struct, or NULL
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	char *new_name, *new_owner;

/*Allocate memory for the dog struct*/

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

/*Allocate memory for the name and owner and copy them*/

	new_name = strdup(name);
	if (new_name == NULL)
	{
		free(new_dog);
		return (NULL);
	}
	new_owner = strdup(owner);
	if (new_owner == NULL)
	{
		free(new_name);
		free(new_dog);
		return (NULL);
	}
/*Initialize the dog struct*/
	new_dog->name = new_name;
	new_dog->age = age;
	new_dog->owner = new_owner;

/*Return the new dog struct*/
	return (new_dog);
}
