#include <stdio.h>
#include <stdlib.h>
#include "Jogador.h"


Jogador Novo_Jogador(char *NomeJ)
{
	Jogador *Jog;

	Objecto *pobj;
	
	Jog = malloc(sizeof(Jogador));

	strcpy(Jog->Id_Jogador, NomeJ);

	Jog->Saude = 20;
	
	Jog->Mochila = malloc(sizeof(Objecto) * 2);

	for (int i = 0;i <= 2;i++)
	{
		if (i == 1)
		{
			Jog->Mochila[i] = Novo_Obj("faca");

			printf("\nPeso: %4.2f\n", Jog->Mochila[i].Peso);
			printf("\nRaridade: %d\n", Jog->Mochila[i].Rar);
			printf("\nAtaque: %d\n", Jog->Mochila[i].ATK);
			printf("\nDefesa: %d\n", Jog->Mochila[i].DEF);
			printf("\nN usos: %d\n", Jog->Mochila[i].N_uso);
		}

		if (i == 2)
			Jog->Mochila[i] = Novo_Obj("aspirina");
	}

}
