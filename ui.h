#ifndef UI_UI_H_
#define UI_UI_H_



#include "controller.h"

typedef struct{
	controller* contr;
}ui;

typedef enum enumerare_comenzi {

	afara = 0,
	printare = 1,
	curatare_consola = 2,
	adaugare = 3,
	modificare = 4,
	stergere = 5,
	filtrare = 6,
	sortare = 7
}comenzi;


/*
	se printeza meniul
*/
void print_menu();

/*
	se obitme comanda
*/
int ui__getCMD();

/*
	se executa comanda
*/
void ui__execCMD(ui* self, int cmd);

/*
	se ruleaza interfata ui
*/
void ui_run(ui* self);

/*
	se initializeaza interfata ui
*/
ui* ui_init();

/*
	se distruge interfata ui
*/
void ui_destroy(ui* self);

/*
	se afiseaza elementele din vector
*/
void ui_printare(ui* self);

/*
	se iau datele de la utilizator
*/
void ui_adaugare(ui* self);

/*
	se sterge un obiect pe baza unui id dat de utilizator
*/
void ui_sterge(ui* self);

/*
	se filtreaza dupa un criteriu dat de utilizator
*/
void ui_filtrare(ui* self);

/*
	se sorteaza dupa un criteriu dat de utilizator
*/
void ui_sortare(ui* self);

/*
	se printeaza un vector
*/
void printare_vector(vector* vec);



#endif