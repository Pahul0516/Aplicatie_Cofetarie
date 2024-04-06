#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>
#include "storeObject.h"

storeObject* storeObject_init(int id, char* nume, char* producator, int cantitate)
{	
	storeObject* obj = malloc(sizeof(storeObject));
	obj->id = id;

	obj->nume = nume;
	obj->producator = producator;

	obj->cantitate = cantitate;
	return obj;
}

void storeObject_destroy(storeObject* self)
{
	self->id = 0;
	free(self->nume);
	free(self->producator);
	self->cantitate = 0;
	free(self);
}

char* storeObject_get_nume(storeObject* self)
{
	return self->nume;
}

char* storeObject_get_producator(storeObject* self)
{
	return self->producator;
}

int storeObject_get_cantitate(storeObject* self)
{
	return self->cantitate;
}

void storeObject_set_nume(storeObject* self, char* nume)
{
	self->nume = nume;
}

void storeObject_set_producator(storeObject* self, char* producator)
{
	self->producator = producator;
}

void storeObject_set_cantitate(storeObject* self, int cantitate)
{
	self->cantitate = cantitate;
}

int storeObject_getId(storeObject* self)
{
	return self->id;
}

void storeObject_setId(storeObject* self, int id)
{
	self->id = id;
}