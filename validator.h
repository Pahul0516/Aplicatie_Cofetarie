#ifndef VALIDATOR_H_
#define VALIDATOR_H_
#include "vector.h"
#include "storeObject.h"


int valideaza_nume(char* nume, vector* vec); // se verifica daca numele nu se gaseste deja in vector
int valideaza_producator(char* producator); // se verifica daca producatoul contine doar litere
int valideaza_cantitate(int cantitate); // se verifica daca cantitatea este pozitiva

#endif