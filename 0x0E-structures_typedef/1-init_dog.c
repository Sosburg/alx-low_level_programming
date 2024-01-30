#include "dog.h"
#include <stddef.h>

/**
*  * init_dog - initializes a variable of type struct dog
*   * @d: pointer to struct dog
*    * @name: name of the dog
*     * @age: age of the dog
*      * @owner: owner of the dog
*/
void init_dog(dog_t *d, char *name, float age, char *owner)
{
if (d != NULL)
{
d->name = name;
d->age = age;
d->owner = owner;
}
}

