#pragma once
//#define TAM_MAX 50
#include "Objecto.h"

typedef struct dadosj Jogador;
struct dadosj
{
	char Id_Jogador[50];
	int Saude;
	Objecto *Mochila;
};

Jogador Novo_Jogador(char *NomeJ);
