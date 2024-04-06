#ifndef REPOSITORY_REPOSITORY_H_
#define REPOSITORY_REPOSITORY_H_

#include "vector.h"
#include "storeObject.h"

typedef struct{
	vector* vectorul_de_obiecte;
}repository;

repository* repository_init(); // se initializaeza un repo
void repository_destroy(repository* self); // se disturge un repo


int repository_GetSize(repository* self); // se obtine lungimea vectorului contiunt de repo
void repository_AddObject(repository* self, storeObject* newObject); // se aduaga un obiect in vectorul din repo
void repository_DeleteObjectById(repository* self, int id); // se strege un element din vectorul contiunt de repo 
storeObject* repository_FindById(repository* self, int id); // se returneaza un obiect gasit in vectorul din repo
void repository_FindByCharacter(repository* self, char c, vector* vec); // se cauta un obiect dupa un criteriu
void repository_FindByQuantity(repository* self, int cantitate, vector* vec); // se cauta un obiect dupa un criteriu
void repository_Copy(repository* self, vector* vec);// se copiaza vectorul din repo in alt vector

#endif 