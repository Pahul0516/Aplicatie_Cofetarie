#ifndef ENTITY_VECTOR_VECTOR_H_
#define ENTITY_VECTOR_VECTOR_H_

#include "storeObject.h"

#define capacitate_initiala 10


typedef storeObject TElem;
typedef struct{
	storeObject** entitati;
	int size;
	int capacitate;
}vector;

vector* vector_init(); // se initializeaza un vector
void vector_destory(vector* self); // se distruge un vector

int vector_getCapacity(vector* self); // se obtine capacitatea unui vector
int vector_getLen(vector* self); // se obtine lungimea unui  vecot
void vector_setCapacity(vector* self, int capacitate); // se seteaza capacitatea unui vector
void vector_setLen(vector* self, int Len); // se seteaza lungimea unui vector
void vector_incLen(vector* self); // se incrementeaza lungimea unui vecot
void vector_push_back(vector* self, storeObject* entitate); // se aduaga un element la vinalul vectorului
void vector_remove_at(vector* self, int poz); // se elimina elementul de la pozitia poz
storeObject* vector_getAt(vector* self, int poz); // se obtine elementul de la pozitia poz
void vector_Sort_By_Name(vector* self); // se sorteaza vectorul dupa un criteriu
void vector_Sort_By_Quantity(vector* self); // se sorteaza vectorul dupa un criteriu
vector* vector_Reverse(vector* self); // se inverseaza vectorul

#endif 