#ifndef ENTITY_STOREOBJECT_STOREOBJECT_H_
#define ENTITY_STOREOBJECT_STOREOBJECT_H_

typedef struct struct_Object{

	int id;
	char* nume;
	char* producator;
	int cantitate;

}storeObject;


storeObject* storeObject_init(int id, char* nume, char* producator, int cantitate); // se initializeaza un obiect
void storeObject_destroy(storeObject* self);// se distruge un obiect

char* storeObject_get_nume(storeObject* self);// se obtine numele obiectului
char* storeObject_get_producator(storeObject* self);//se obtine producatorul obiectului
int storeObject_get_cantitate(storeObject* self);//se obtine cantitatea obiectului
int storeObject_getId(storeObject* self);//se obtine id-ul obiectului 
void storeObject_set_nume(storeObject* self, char* nume); // se seteaza numele obiectului
void storeObject_set_producator(storeObject* self, char* producator);// se seteaza producatorul obiectului
void storeObject_set_cantitate(storeObject* self, int cantitate);// se seteaza cantitatea obiectului
void storeObject_setId(storeObject* self, int id); // se seteaza id-ul obiectului

#endif 
