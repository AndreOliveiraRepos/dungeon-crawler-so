#include <stdio.h>
#include <stdlib.h>
#include "Objecto.h"

Objecto Novo_Obj(char *str)
{
	Objecto *obj;

	obj = malloc(sizeof(Objecto));

	if (strcmp(str,"sandes") == 0)
	{
		obj->Peso = 0.5;
		obj->Rar = 10;
		obj->ATK = 0;
		obj->DEF = 0;
		obj->N_uso = 1;

		return *obj;
	}

	if (strcmp(str, "aspirina") == 0)
	{
		obj->Peso = 0.1;
		obj->Rar = 20;
		obj->ATK = 0;
		obj->DEF = 0;
		obj->N_uso = 1;

		return *obj;
	}
	
	if (strcmp(str, "xarope") == 0)
	{
		obj->Peso = 1;
		obj->Rar = 4;
		obj->ATK = 0;
		obj->DEF = 0;
		obj->N_uso = 1;

		return *obj;
	}

	if (strcmp(str,"faca")==0)
	{
		obj->Peso = 2;
		obj->Rar = 5;
		obj->ATK = 5;
		obj->DEF = 0;
		obj->N_uso = 99;

		return *obj;
	}
	
	if (strcmp(str, "espada") == 0)
	{
		obj->Peso = 8;
		obj->Rar = 3;
		obj->ATK = 8;
		obj->DEF = 2;
		obj->N_uso = 99;

		return *obj;
	}

	if (strcmp(str, "granada") == 0)
	{
		obj->Peso = 1;
		obj->Rar = 3;
		obj->ATK = 30;
		obj->DEF = 0;
		obj->N_uso = 1;

		return *obj;
	}

	if (strcmp(str, "escudo") == 0)
	{
		obj->Peso = 4;
		obj->Rar = 4;
		obj->ATK = 5;
		obj->DEF = 5;
		obj->N_uso = 99;

		return *obj;
	}
	
	if (strcmp(str, "moeda") == 0)
	{
		obj->Peso = 0.1;
		obj->Rar = 5;
		obj->ATK = 0;
		obj->DEF = 0;
		obj->N_uso = 99;

		return *obj;
	}
	
	
}
