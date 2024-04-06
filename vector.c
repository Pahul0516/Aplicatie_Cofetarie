#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <crtdbg.h>
#include "vector.h"

vector* vector_init()
{
	vector* vec = NULL;
	vec = malloc(sizeof(vector));
	vec->size = 0;
	vec->capacitate = capacitate_initiala;
	vec->entitati = malloc(vec->capacitate * sizeof(TElem));
	return vec;
}

void vector_destory(vector* self)
{
	for (int i = 0; i<self->size; i++)
	{
		storeObject_destroy(vector_getAt(self, i));
	}
	vector_setLen(self, 0);
	vector_setCapacity(self, 0);
	free(self->entitati);
	free(self);
}

int vector_getCapacity(vector* self)
{
	return self->capacitate;
}

void vector_setCapacity(vector* self, int capacitate)
{
	self->capacitate = capacitate;
}

int vector_getLen(vector* self)
{
	return self->size;
}

void vector_setLen(vector* self, int Len)
{
	self->size = Len;
}

void vector_incLen(vector* self)
{
	self->size++;
}

void vector_push_back(vector* self, storeObject* entitate)
{
	if (vector_getCapacity(self) == vector_getLen(self))
	{
		vector_setCapacity(self, vector_getCapacity(self) * 2);
		self->entitati = realloc(self->entitati, self->capacitate * sizeof(storeObject));
	}
	self->entitati[vector_getLen(self)] = entitate;
	vector_incLen(self);
}

void vector_remove_at(vector* self, int poz)
{
	int i;
	storeObject* de_distrus = NULL;
	de_distrus = vector_getAt(self, poz);
	storeObject_destroy(de_distrus);
	for (i = poz; i < vector_getLen(self) - 1; i++)
	{
		self->entitati[i] = self->entitati[i+1];
	}
	self->entitati[vector_getLen(self) - 1] = NULL;
	vector_setLen(self, vector_getLen(self) - 1);
}


storeObject* vector_getAt(vector* self, int pos)
{
	return self->entitati[pos];
}

void vector_Sort_By_Name(vector* self)
{
	int len = vector_getLen(self);
	storeObject* aux;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if ( strcmp( storeObject_get_nume(vector_getAt(self, i)),storeObject_get_nume(vector_getAt(self, j)) ) > 0)
			{
				aux = self->entitati[i];
				self->entitati[i] = self->entitati[j];
				self->entitati[j] = aux;
			}
		}
	}
}

void vector_Sort_By_Quantity(vector* self)
{
	int len = vector_getLen(self);
	storeObject* aux;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (storeObject_get_cantitate(vector_getAt(self, i)) > storeObject_get_cantitate(vector_getAt(self, j)))
			{
				aux = self->entitati[i];
				self->entitati[i] = self->entitati[j];
				self->entitati[j] = aux;
			}
		}
	}
}

vector* vector_Reverse(vector* self)
{
	vector* invers = NULL;
	invers = vector_init();

	int len = vector_getLen(self);
	for (int i = len - 1; i >= 0; i--)
	{
		char* nume = malloc(100 * sizeof(char));
		char* producator = malloc(100 * sizeof(char));
		int id, cantitate;
		id = storeObject_getId(vector_getAt(self, i));
		strcpy(nume, storeObject_get_nume(vector_getAt(self, i)));
		strcpy(producator, storeObject_get_producator(vector_getAt(self, i)));
		cantitate = storeObject_get_cantitate(vector_getAt(self, i));
		storeObject* obj = storeObject_init(id, nume, producator, cantitate);
		vector_push_back(invers, obj);
	}
	vector_destory(self);
	return invers;
}


