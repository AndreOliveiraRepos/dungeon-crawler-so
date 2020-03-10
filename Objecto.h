#pragma once
//#define TAM_MAX 50

typedef struct dados Objecto;
struct dados
{
	char Nome[50];
	float Peso;
	int Rar;
	int ATK;
	int DEF;
	int N_uso;
};

Objecto Novo_Obj(char *str);