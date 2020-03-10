/* ------------------------------------------------------------------------------------- */
/* dict.h */

/* ficheiro header necess�rio aos clientes e servidor */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

/* nome do FIFO do servidor */
#define SERVER_FIFO "/tmp/dict_fifo"

/* nome do FIFO cada cliente. P %d ser� substitu�do pelo PID com sprintf */
#define CLIENT_FIFO "/tmp/resp_%d_fifo"

/* tamanho m�ximo de cada palavra */
#define TAM_MAX 50

/* estrutura da mensagem correspondente a um pedido cliente -> servidor*/
typedef struct {
   pid_t pid_cliente;
   char  palavra[TAM_MAX];
} pergunta_t;

/* estrutura da mensagem correspondente a uma resposta servidor -> cliente */
typedef struct {
   char palavra[TAM_MAX];
} resposta_t;
