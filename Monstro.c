#include "Monstro.h"

Monstro NovoMonstro(char *nome)
{
	Monstro *m;
	m = malloc(sizeof(Monstro));
	if (strcmp(nome,"morcego")== 0)
	{
		strcpy(m->Nome, nome);
		m->ATK = 4;
		m->DEF = 4;
		m->HP = 5;
		m->Init = 10;
		strcpy(m->Status, "irrequieto");
		strcpy(m->Ment, "agressivo");
		m->drop = 0;
		return *m;
	}
	else if (strcmp(nome, "escorpiao")==0)
	{
		strcpy(m->Nome, nome);
		m->ATK = 4;
		m->DEF = 4;
		m->HP = 5;
		m->Init = 10;
		strcpy(m->Status, "irrequieto");
		strcpy(m->Ment, "agressivo");
		m->drop = 0;
		return *m;
	}
	else if (strcmp(nome, "lobisomem")==0)
	{
		strcpy(m->Nome, nome);
		m->ATK = 4;
		m->DEF = 4;
		m->HP = 5;
		m->Init = 10;
		strcpy(m->Status, "irrequieto");
		strcpy(m->Ment, "agressivo");
		m->drop = 0;
		return *m;
	}
	else if (strcmp(nome, "urso")==0)
	{
		strcpy(m->Nome, nome);
		m->ATK = 4;
		m->DEF = 4;
		m->HP = 5;
		m->Init = 10;
		strcpy(m->Status, "irrequieto");
		strcpy(m->Ment, "agressivo");
		m->drop = 0;
		return *m;
	}
	else if (strcmp(nome, "boss")==0)
	{
		strcpy(m->Nome, nome);
		m->ATK = 4;
		m->DEF = 4;
		m->HP = 5;
		m->Init = 10;
		strcpy(m->Status, "irrequieto");
		strcpy(m->Ment, "agressivo");
		m->drop = 0;
		return *m;
	}
	else
	{
		printf("Parametro de monstro inválido\n");
		return;
	}
}