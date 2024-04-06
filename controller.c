#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "controller.h"
#include "storeObject.h"


controller* controller_init()
{
	controller* c = NULL;
	c = malloc(sizeof(controller));
	return c;
}

void controller_destroy(controller* self)
{
	free(self);
}

void controller_AddObject(controller* self, int id, char* nume, char* producator, int cantitate)
{
	storeObject* obj = NULL;
	obj = storeObject_init(id, nume, producator, cantitate);
	repository_AddObject(self->repo, obj);
}

void controller_DeleteObject(controller* self, int id)
{
	repository_DeleteObjectById(self->repo, id);
}

void controller_UpdateObject(controller* self, int id, char* nume, char* producator, int cantitate)
{
	storeObject* new_obj = NULL;
	new_obj = storeObject_init(id, nume, producator, cantitate);
	repository_DeleteObjectById(self->repo, id);
	repository_AddObject(self->repo, new_obj);
}

vector* controller_ShowAllObjects(controller* this)
{
	return this->repo->vectorul_de_obiecte;
}

void controller_filtrare(controller* self, char c, int cantitate, vector* vec)
{
	if (c != '\0')
	{
		repository_FindByCharacter(self->repo, c, vec);
	}
	else
	{
		repository_FindByQuantity(self->repo, cantitate, vec);
	}
}

vector* controller_Sort(controller* self, vector* vec, int criteriu, int mod)
{
	repository_Copy(self->repo, vec);
	if (criteriu == 1)
		vector_Sort_By_Name(vec);
	else
		vector_Sort_By_Quantity(vec);
	if (mod == 2)
		vec = vector_Reverse(vec);
	return vec;
}
