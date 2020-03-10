#include <stdio.h>
#include <stdlib.h>

typedef struct dados Monstro;
struct dados
{
	char Nome[100];
	int ATK;
	int DEF;
	int HP;
	int Init;
	char Ment[10];
	char Status[10];
	int drop;

};

Monstro NovoMonstro(char *nome);
int Atacar();
int Drop();