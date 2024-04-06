#define _CRT_SECURE_NO_WARNINGS

#include <malloc.h>
#include <string.h>
#include <assert.h>
#include "teste.h"
#include "storeObject.h"
#include "vector.h"
#include "repository.h"
#include "controller.h"
#include "validator.h"

void teste_validator()
{
	vector* vec = NULL;
	vec = vector_init(vec);
	int id = 1, cantitate = 100;
	char* nume, * producator;
	nume = malloc(100 * sizeof(char));
	producator = malloc(100 * sizeof(char));
	strcpy(nume, "faina");
	strcpy(producator, "fainarie");

	storeObject* obj1 = NULL;
	obj1 = storeObject_init(id, nume, producator, cantitate);
	vector_push_back(vec, obj1);

	char* nume2, * producator2;
	nume2 = malloc(100 * sizeof(char));
	producator2 = malloc(100 * sizeof(char));
	id = 2;
	cantitate = -500;
	strcpy(nume2, "faina");
	strcpy(producator2, "fainarie12");
	storeObject* obj2 = NULL;
	obj2 = storeObject_init(id, nume2, producator2, cantitate);

	assert(valideaza_nume(nume2, vec) == 1);
	assert(valideaza_producator(producator2) == 1);
	assert(valideaza_cantitate(cantitate) == 1);


	char* nume3, * producator3;
	nume3 = malloc(100 * sizeof(char));
	producator3 = malloc(100 * sizeof(char));
	id = 2;
	cantitate = 400;
	strcpy(nume3, "sare");
	strcpy(producator3, "jsdfhbsj");
	storeObject* obj3 = NULL;
	obj3 = storeObject_init(id, nume3, producator3, cantitate);

	assert(valideaza_nume(nume3, vec) == 0);
	assert(valideaza_producator(producator3) == 0);
	assert(valideaza_cantitate(cantitate) == 0);

	storeObject_destroy(obj2);
	storeObject_destroy(obj3);
	vector_destory(vec);
}

void teste_store_Object()
{
	int id = 1, cantitate = 100;
	char* nume, * producator;
	nume = malloc(100 * sizeof(char));
	producator = malloc(100 * sizeof(char));
	strcpy(nume, "faina");
	strcpy(producator, "fainarie");
	storeObject* obj = NULL;
	obj = storeObject_init(id, nume, producator, cantitate);

	assert(storeObject_getId(obj) == 1);
	assert(strcmp(storeObject_get_nume(obj), "faina") == 0);
	assert(strcmp(storeObject_get_producator(obj), "fainarie") == 0);
	assert(storeObject_get_cantitate(obj) == 100);
	

	storeObject_setId(obj, 2);
	assert(storeObject_getId(obj) == 2);
	
	strcpy(nume, "zahar");
	storeObject_set_nume(obj, nume);
	assert(strcmp(storeObject_get_nume(obj), "zahar") == 0);

	strcpy(producator, "Mitrut");
	storeObject_set_producator(obj, producator);
	assert(strcmp(storeObject_get_producator(obj), "Mitrut") == 0);

	storeObject_set_cantitate(obj, 200);
	assert(storeObject_get_cantitate(obj) == 200);

	storeObject_destroy(obj);
}

void teste_vector()
{
	int id = 1, cantitate = 100;
	char* nume, * producator;
	nume = malloc(100 * sizeof(char));
	producator = malloc(100 * sizeof(char));
	strcpy(nume, "faina");
	strcpy(producator, "fainarie");
	storeObject* obj = NULL;
	obj = storeObject_init(id, nume, producator, cantitate);

	char* nume2, * producator2;
	nume2 = malloc(100 * sizeof(char));
	producator2 = malloc(100 * sizeof(char));
	id = 2;
	cantitate = 500;
	strcpy(nume2, "arahide");
	strcpy(producator2, "fainarie");
	storeObject* obj3 = NULL;
	obj3 = storeObject_init(id, nume2, producator2, cantitate);

	vector* vec = NULL;
	vec = vector_init();
	vector_setCapacity(vec, 1);
	vector_push_back(vec, obj);
	vector_push_back(vec, obj3);
	assert(vector_getLen(vec) == 2);
	assert(vector_getCapacity(vec) == 2);
	vector_setCapacity(vec, 20);
	assert(vector_getCapacity(vec) == 20);
	vector_remove_at(vec, 0);
	assert(vector_getLen(vec) == 1);
	storeObject* obj2 = vector_getAt(vec, 0);
	assert(storeObject_getId(obj2) == 2);
	assert(strcmp(storeObject_get_nume(obj2), "arahide") == 0);
	assert(strcmp(storeObject_get_producator(obj2), "fainarie") == 0);
	assert(storeObject_get_cantitate(obj2) == 500);


	id = 4;
	cantitate = 4000;
	char* nume4 = NULL;
	char* producator4 = NULL;
	nume4 = malloc(100 * sizeof(char));
	producator4 = malloc(100 * sizeof(char));
	strcpy(nume4, "aafaina");
	strcpy(producator4, "fainarie");
	storeObject* obj4 = NULL;
	obj4 = storeObject_init(id, nume4, producator4, cantitate);

	vector_push_back(vec, obj4);
	vector_Sort_By_Name(vec);
	obj3 = vector_getAt(vec, 0);
	assert(strcmp(storeObject_get_nume(obj3), "aafaina") == 0);
	obj3 = vector_getAt(vec, 1);
	assert(strcmp(storeObject_get_nume(obj3), "arahide") == 0);
	vector_Sort_By_Quantity(vec);
	obj3 = vector_getAt(vec, 0);
	assert(storeObject_get_cantitate(obj3) == 500);
	obj3 = vector_getAt(vec, 1);
	assert(storeObject_get_cantitate(obj3) == 4000);

	vector* invers = NULL;
	invers = vector_Reverse(vec);
	obj3 = vector_getAt(invers, 0);
	assert(storeObject_get_cantitate(obj3) == 4000);
	obj3 = vector_getAt(invers, 1);
	assert(storeObject_get_cantitate(obj3) == 500);

	vector_destory(invers);
}


void teste_repository()
{
	repository* repo = NULL;
	repo = repository_init();
	vector* vec = NULL;
	vec = vector_init();
	repo->vectorul_de_obiecte = vec;
	assert(vector_getCapacity(repo->vectorul_de_obiecte) == 10);
	assert(vector_getLen(repo->vectorul_de_obiecte) == 0);

	int id = 1, cantitate = 100;
	char* nume, * producator;
	nume = malloc(100 * sizeof(char));
	producator = malloc(100 * sizeof(char));
	strcpy(nume, "faina");
	strcpy(producator, "fainarie");
	storeObject* obj1 = NULL;
	obj1 = storeObject_init(id, nume, producator, cantitate);

	char* nume2, * producator2;
	nume2 = malloc(100 * sizeof(char));
	producator2 = malloc(100 * sizeof(char));
	id = 2;
	cantitate = 500;
	strcpy(nume2, "arahide");
	strcpy(producator2, "fainarie");
	storeObject* obj2 = NULL;
	obj2 = storeObject_init(id, nume2, producator2, cantitate);

	repository_AddObject(repo, obj1);
	assert(repo->vectorul_de_obiecte->size == 1);

	repository_AddObject(repo, obj2);
	assert(repo->vectorul_de_obiecte->size == 2);

	assert(repository_GetSize(repo) == 2);

	repository_DeleteObjectById(repo, 2);
	assert(repository_GetSize(repo) == 1);

	storeObject* obj4 = repository_FindById(repo, 1);
	assert(obj4->id == 1);
	assert(obj4->cantitate == 100);
	assert(strcmp(obj4->nume,"faina") == 0);
	assert(strcmp(obj4->producator, "fainarie") == 0);


	id = 1;
	cantitate = 100;
	char* nume5, * producator5;
	nume5 = malloc(100 * sizeof(char));
	producator5 = malloc(100 * sizeof(char));
	strcpy(nume5, "arahide");
	strcpy(producator5, "fainarie");
	storeObject* obj5 = NULL;
	obj5 = storeObject_init(id, nume5, producator5, cantitate);
	repository_AddObject(repo, obj5);
	char ch = 'a';
	vector* vec2 = NULL;
	vec2 = vector_init();
	repository_FindByCharacter(repo, ch, vec2);
	storeObject* obj = vector_getAt(vec2, 0);
	assert(strcmp(obj->nume, "arahide") == 0);

	int c = 100;
	vector* vec3 = NULL;
	vec3 = vector_init();
	repository_FindByQuantity(repo, c, vec3);
	storeObject* obj7 = vector_getAt(vec3, 0);
	assert(strcmp(obj7->nume, "faina") == 0);

	vector* vec4 = NULL;
	vec4 = vector_init();
	repository_Copy(repo, vec4);
	storeObject* obj8 = vector_getAt(vec4, 0);
	assert(strcmp(obj8->nume, "faina") == 0);
	storeObject* obj9 = vector_getAt(vec4, 1);
	assert(strcmp(obj9->nume, "arahide") == 0);

	repository_destroy(repo);
	vector_destory(vec);
	vector_destory(vec2);
	vector_destory(vec3);
	vector_destory(vec4);
}


void teste_controller()
{
	controller* contr = NULL;
	contr = controller_init();
	repository* repo = NULL;
	repo = repository_init();
	vector* vec = NULL;
	vec = vector_init();

	contr->repo = repo;
	repo->vectorul_de_obiecte = vec;

	int id = 1, cantitate = 200;
	char* nume, * producator;
	nume = malloc(100 * sizeof(char));
	producator = malloc(100 * sizeof(char));
	controller_AddObject(contr, id, nume, producator, cantitate);

	id = 2;
	cantitate = 300;
	char* nume2 = malloc(100 * sizeof(char));
	char* producator2 = malloc(100 * sizeof(char));
	controller_AddObject(contr, id, nume2, producator2, cantitate);

	id = 3;
	cantitate = 400;
	char* nume3 = malloc(100 * sizeof(char));
	char* producator3 = malloc(100 * sizeof(char));
	controller_AddObject(contr, id, nume3, producator3, cantitate);

	vector* vec2 = NULL;
	vec2 = controller_ShowAllObjects(contr);
	assert(vector_getLen(vec2) == 3);
	controller_DeleteObject(contr, 3);
	vec2 = controller_ShowAllObjects(contr);
	assert(vector_getLen(vec2) == 2);


	id = 1;
	char* nume4 = NULL;
	nume4 = malloc(100 * sizeof(char));
	strcpy(nume4, "faina");
	char* producator4 = NULL;
	producator4 = malloc(100 * sizeof(char));
	strcpy(producator4, "altcineva");
	cantitate = 500;
	controller_UpdateObject(contr, id, nume4, producator4, cantitate);

	id = 2;
	char* nume5 = NULL;
	nume5 = malloc(100 * sizeof(char));
	strcpy(nume5, "mere");
	char* producator5 = NULL;
	producator5 = malloc(100 * sizeof(char));
	strcpy(producator5, "cineva");
	cantitate = 500;
	controller_UpdateObject(contr, id, nume5, producator5, cantitate);
	assert(storeObject_get_cantitate(vector_getAt(contr->repo->vectorul_de_obiecte,1)) == 500);

	vector* vec3 = NULL;
	vec3 = vector_init();
	char ch1 = 'm', ch2='\0';
	controller_filtrare(contr, ch1, 0, vec3);
	controller_filtrare(contr, ch2, 500, vec3);
	vector_destory(vec3);


	vector* vec5 = NULL;
	vec5 = vector_init();
	vec5 = controller_Sort(contr, vec5, 1, 2);
	vec5 = controller_Sort(contr, vec5, 2, 2);
	
	vector_destory(vec5);

	vector_destory(vec);
	repository_destroy(repo);
	controller_destroy(contr);
}


void rulare_teste()
{
	teste_validator();
	teste_store_Object();
	teste_vector();
	teste_repository();
	teste_controller();
}