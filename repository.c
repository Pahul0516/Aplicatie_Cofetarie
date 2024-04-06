#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <crtdbg.h>
#include "repository.h"
#include "storeObject.h"


repository* repository_init()
{
	repository* repo = NULL;
	repo = malloc(sizeof(repository));
	return repo;
}

void repository_destroy(repository* self)
{
	free(self);
}
 
int repository_GetSize(repository* self)
{
	return vector_getLen(self->vectorul_de_obiecte);
}

void repository_AddObject(repository* self, storeObject* newObject)
{
	vector_push_back(self->vectorul_de_obiecte, newObject);
}

void repository_DeleteObjectById(repository* self, int id)
{
	int i = 0;
	for (i = 0; i < repository_GetSize(self); i++)
	{
		if (storeObject_getId(vector_getAt(self->vectorul_de_obiecte, i)) == id)
		{
			vector_remove_at(self->vectorul_de_obiecte, i);
		}
	}
}

storeObject* repository_FindById(repository* self, int id)
{
	int i = 0;
	int len = repository_GetSize(self);
	storeObject* de_returnat = NULL;
	for (i = 0; i < len; i++)
	{
		if (storeObject_getId(vector_getAt(self->vectorul_de_obiecte, i)) == id)
		{
			de_returnat = vector_getAt(self->vectorul_de_obiecte, i);
		}
	}
	return de_returnat;
}

void repository_FindByCharacter(repository* self, char c, vector* vec)
{

	int i = 0, contor = 0;
	int len = repository_GetSize(self);
	for (i = 0; i < len; i++)
	{
		if (storeObject_get_nume(vector_getAt(self->vectorul_de_obiecte,i))[0] == c)
		{
			contor++;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (storeObject_get_nume(vector_getAt(self->vectorul_de_obiecte, i))[0] == c)
		{
			int id, cantitate;
			char* nume = NULL;
			char* producator = NULL;
			nume = malloc(100 * sizeof(char));
			producator = malloc(100 * sizeof(char));
			id = storeObject_getId(vector_getAt(self->vectorul_de_obiecte, i));
			strcpy(nume, storeObject_get_nume(vector_getAt(self->vectorul_de_obiecte, i)));
			strcpy(producator, storeObject_get_producator(vector_getAt(self->vectorul_de_obiecte, i)));
			cantitate = storeObject_get_cantitate(vector_getAt(self->vectorul_de_obiecte, i));
			storeObject* obj = NULL;
			obj = storeObject_init(id, nume, producator, cantitate);
			vector_push_back(vec, obj);
		}
	}
}

void repository_FindByQuantity(repository* self, int cantitate, vector* vec)
{
	int i = 0, contor = 0;
	int len = repository_GetSize(self);
	for (i = 0; i < len; i++)
	{
		if (storeObject_get_cantitate(vector_getAt(self->vectorul_de_obiecte, i)) <= cantitate)
		{
			contor++;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (storeObject_get_cantitate(vector_getAt(self->vectorul_de_obiecte, i)) <= cantitate)
		{
			int id, cantitatea;
			char* nume = NULL;
			char* producator = NULL;
			nume = malloc(100 * sizeof(char));
			producator = malloc(100 * sizeof(char));
			id = storeObject_getId(vector_getAt(self->vectorul_de_obiecte, i));
			strcpy(nume, storeObject_get_nume(vector_getAt(self->vectorul_de_obiecte, i)));
			strcpy(producator, storeObject_get_producator(vector_getAt(self->vectorul_de_obiecte, i)));
			cantitatea = storeObject_get_cantitate(vector_getAt(self->vectorul_de_obiecte, i));
			storeObject* obj = NULL;
			obj = storeObject_init(id, nume, producator, cantitatea);
			vector_push_back(vec, obj);
		}
			
	}
}

void repository_Copy(repository* self, vector* vec)
{
	int i = 0;
	int len = repository_GetSize(self);
	for (i = 0; i < len; i++)
	{
		int id, cantitate;
		char* nume = NULL;
		char* producator = NULL;
		nume = malloc(100 * sizeof(char));
		producator = malloc(100 * sizeof(char));
		id = storeObject_getId(vector_getAt(self->vectorul_de_obiecte, i));
		strcpy(nume, storeObject_get_nume(vector_getAt(self->vectorul_de_obiecte, i)));
		strcpy(producator, storeObject_get_producator(vector_getAt(self->vectorul_de_obiecte, i)));
		cantitate = storeObject_get_cantitate(vector_getAt(self->vectorul_de_obiecte, i));
		storeObject* obj = NULL;
		obj = storeObject_init(id, nume, producator, cantitate);
		vector_push_back(vec, obj);
	}
}
