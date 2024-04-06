#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_


#include "repository.h"
#include "storeObject.h"

typedef struct{
	repository* repo;
}controller;


controller* controller_init(); // se initializeaza un controller
void controller_destroy(controller* self); // se distruge un controller

vector* controller_ShowAllObjects(controller* this); // se returneaza un vector cu toate obiectele din controller
void controller_AddObject(controller* self, int id, char* nume, char* producator, int cantitate); // se aduaga un obiect de tip storeObject
void controller_DeleteObject(controller* self, int id); // se sterge un obiect pe baza unui id
void controller_UpdateObject(controller* self, int id, char* nume, char* producator, int cantitate); // se actualizeaza un obiect pe baza unui id prin inlocuirea acestuia cu un alt obiect
void controller_filtrare(controller* self, char c, int cantitate, vector* vec); // se gestioneaza ideea de filtrare pe baza unor criterii date de utilizator
vector* controller_Sort(controller* self, vector* vec, int criteriu, int mod); // se gestioneaza sortare pe baza unor criterii date de utilizator

#endif