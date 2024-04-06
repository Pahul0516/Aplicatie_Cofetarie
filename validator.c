#include <string.h>
#include "validator.h"
#include "vector.h"

int valideaza_nume(char* nume, vector* vec)
{
	int len = vector_getLen(vec);
	for (int i = 0; i < len; i++)
	{
		if (strcmp(storeObject_get_nume(vector_getAt(vec, i)), nume) == 0)
			return 1;
	}
	return 0;
}

int valideaza_producator(char* producator)
{
	size_t len = strnlen(producator, 100);
	for (int i = 0; i < len; i++)
	{
		if (!((producator[i] >= 'a' && producator[i] <= 'z') || (producator[i] >= 'a' && producator[i] <= 'z')))
			return 1;
	}
	return 0;
}

int valideaza_cantitate(int cantitate)
{
	if (cantitate > 0)
		return 0;
	else
		return 1;
}

