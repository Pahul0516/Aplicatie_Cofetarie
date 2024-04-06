#define _CRTDBG_MAP_ALLOC
#include "controller.h"
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include <malloc.h>
#include "ui.h"
#include "repository.h"
#include "vector.h"
#include "teste.h"

void RunUI()
{
	ui* ui = NULL;
	controller* contr = NULL;
	repository* repo = NULL;
	vector* vec = NULL;

	vec = vector_init();
	repo = repository_init();
	contr = controller_init();
	ui = ui_init();

	repo->vectorul_de_obiecte = vec;
	contr->repo = repo;
	ui->contr = contr;


	ui_run(ui);


	vector_destory(vec);
	repository_destroy(repo);
	controller_destroy(contr);
	ui_destroy(ui);	
}

int main()
{
	RunUI();
	rulare_teste();
	_CrtDumpMemoryLeaks();
	return 0;
}