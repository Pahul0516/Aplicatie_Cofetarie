#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <crtdbg.h>
#include "ui.h"
#include "storeObject.h"
#include "validator.h"

ui* ui_init()
{
	ui* uii = NULL;
	uii = malloc(sizeof(ui));
	return uii;
}

void ui_destroy(ui* self)
{
	free(self);
}

void ui_printare(ui* self)
{
	printf("\nComponentele sunt:\n");
	vector* vect = controller_ShowAllObjects(self->contr);
	storeObject* aux;
	int i = 0;
	int len = vector_getLen(vect);

	for (i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (storeObject_getId(vector_getAt(vect,i)) > storeObject_getId(vector_getAt(vect, j)))
			{
				aux = vect->entitati[i];
				vect->entitati[i] = vect->entitati[j];
				vect->entitati[j] = aux;
			}
		}
	}

	for (i = 0; i < len; ++i)
	{
		storeObject* currObj = (storeObject*)(vector_getAt(vect, i));
		printf("%d %s %s %d\n", storeObject_getId(currObj), storeObject_get_nume(currObj), storeObject_get_producator(currObj), storeObject_get_cantitate(currObj));
	}
	printf("\n");
}

void ui_adaugare(ui* self) {

	int id;
	char* nume;
	char* producator;
	int cantitate;

	nume =(char*) malloc(100*sizeof(char));
	producator =(char*) malloc(100*sizeof(char));

	int len_vector = vector_getLen(self->contr->repo->vectorul_de_obiecte);
	if (len_vector == 0)
	{
		id = 1;
	}
	else
	{
		int maxi = -1;
		for (int i = 0; i < len_vector; i++)
		{
			if (storeObject_getId(vector_getAt(self->contr->repo->vectorul_de_obiecte, i)) > maxi)
			{
				maxi = storeObject_getId(vector_getAt(self->contr->repo->vectorul_de_obiecte, i));
			}
		}
		id = maxi + 1;
	}

	printf("Dati un nume: ");
	scanf_s("%s", nume, 100);
	while (valideaza_nume(nume, self->contr->repo->vectorul_de_obiecte) == 1)
	{
		printf("Acest obiect exista deja. Te rog sa intorduci alt obiect:\n");
		printf("Dati un nume: ");
		scanf_s("%s", nume, 100);
	}

	printf("Dati un producator: ");
	scanf_s("%s", producator, 100);
	while (valideaza_producator(producator) == 1)
	{
		printf("Un producator nu poate sa contina doar litere:\n");
		printf("Dati un producator: ");
		scanf_s("%s", producator, 100);
	}


	printf("Dati o cantitate: ");
	scanf_s("%d", &cantitate);
	while (valideaza_cantitate(cantitate) == 1)
	{
		printf("Cantitatea trebuie sa fie pozitiva:\n");
		printf("Dati o cantitate: ");
		scanf("%d", &cantitate);
	}

	controller_AddObject(self->contr, id, nume, producator, cantitate);
}

void ui_modifica(ui* self)
{
	int id;
	char* nume;
	char* producator;
	int cantitate;

	nume = (char*)malloc(100 * sizeof(char));
	producator = (char*)malloc(100 * sizeof(char));
	
	printf("Dati un ID al produsului pe care doriti sa il modificati: ");
	scanf_s("%d", &id);

	printf("Dati un nume: ");
	scanf_s("%s", nume, 100);

	printf("Dati un producator: ");
	scanf_s("%s", producator, 100);

	printf("Dati o cantitate: ");
	scanf_s("%d", &cantitate);



	controller_UpdateObject(self->contr, id, nume, producator, cantitate);
}

void ui_sterge(ui* self)
{
	int id;

	printf("Dati un ID al produsului pe care doriti sa il stergeti: ");
	scanf_s("%d", &id);

	controller_DeleteObject(self->contr, id);
}

void printare_vector(vector* vec)
{
	printf("\nComponentele sunt:\n");
	int len = vec->size;
	for (int i = 0; i < len; i++)
	{
		storeObject* currObj = (storeObject*)(vector_getAt(vec, i));
		printf("%d %s %s %d\n", storeObject_getId(currObj), storeObject_get_nume(currObj), storeObject_get_producator(currObj), storeObject_get_cantitate(currObj));
	}
	printf("\n");
}

void ui_filtrare(ui* self)
{
	int criteriu;

	printf("Criterii disponibile:\n");

	printf("  1.Numele incepe cu o litera data. \n");
	printf("  2.Cantitate. \n");
	printf("  ");
	scanf_s("  %d", &criteriu);
	if (criteriu == 1)
	{
		char c;
		printf("    Va rog sa introduceti o litera: ");

		scanf_s("    %c", &c, 1);
		vector* vec = NULL;
		vec = vector_init();
		controller_filtrare(self->contr, c, 0, vec);
		printare_vector(vec);
		vector_destory(vec);
	}
	else
	{
		int cantitate;
		char ch = '\0';
		printf("Va rog sa introduceti o cantitate: ");
		scanf_s("  %d", &cantitate);
		vector* vec = NULL;
		vec = vector_init();
		controller_filtrare(self->contr, ch, cantitate, vec);
		printare_vector(vec);
		vector_destory(vec);
	}
}

void ui_sortare(ui* self)
{
	int criteriu, mod;

	printf("Criterii disponibile:\n");

	printf("  1.Sortare dupa nume \n");
	printf("  2.Sortare dupa cantitate \n");
	printf("  ");
	scanf_s("  %d", &criteriu);
	
	printf("  Cum soriti sa se sorteze:\n");
	printf("    1.Crescator \n");
	printf("    2.Descrescator \n");
	printf("    ");
	scanf_s("  %d", &mod);

	vector* vec = NULL;
	vec = vector_init();
	vec = controller_Sort(self->contr, vec, criteriu, mod);
	printare_vector(vec);
	vector_destory(vec);
}


void print_menu()
{
	printf("Meniu:\n");
	printf("1. Afisare obiecte:\n");
	printf("2. Curatare consola:\n");
	printf("3. Adaugare\n");
	printf("4. Modificare dupa id\n");
	printf("5. Stergere dupa id\n");
	printf("6. Filtrare\n");
	printf("7. Sortare\n");


}

int ui__getCMD()
{
	int cmd = afara;

	scanf_s("%d", &cmd);

	return cmd;
}


void ui__execCMD(ui* self, int cmd)
{
	switch (cmd)
	{
	case printare:
		ui_printare(self);
		break;
	case curatare_consola:
		system("cls");
		break;
	case adaugare:
		ui_adaugare(self);
		break;
	case modificare:
		ui_modifica(self);
		break;
	case stergere:
		ui_sterge(self);
		break;
	case filtrare:
		ui_filtrare(self);
		break;
	case sortare:
		ui_sortare(self);
		break;
	}
}

void ui_run(ui* self)
{
	while (1)
	{
		print_menu();
		int cmd = ui__getCMD();
		switch (cmd)
		{
		case afara:
			return;
		default:
			ui__execCMD(self, cmd);
		}
	}
}