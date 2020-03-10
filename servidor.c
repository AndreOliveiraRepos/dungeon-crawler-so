/* ------------------------------------------------------------------------------------- */
/* C�digo do servidor */

#include "dict.h"
#include <signal.h>

#define NPALAVRAS 7       /* N�mero de palavras conhecidas */

char * dicionario[NPALAVRAS][2] = {  /*  O dicion�rio      */
   { "memory",    "mem�ria" },       /*  � constitu�do     */
   { "computer",  "computador" },    /*  por uma matriz    */
   { "close",     "fechar" },        /*  bidimensional de  */
   { "open",      "abrir" },         /*  ponteiros para    */
   { "read",      "ler" },           /*  caracter.         */
   { "write",     "escrever" },      /*  [i][0] = palavra  */
   { "file",      "ficheiro" } };    /*  [i][1] = tradu��o */

int s_fifo_fd, c_fifo_fd; /* descritores de ficheiros (pipes) */

/* esta fun��o vai atender o sinal SIGINT para terminar o servidor */
void trataSig(int i) {
   fprintf(stderr, "\nServidor de dicionario a terminar "
                   "(interrompido via teclado)\n\n");
   close(s_fifo_fd);
   unlink(SERVER_FIFO);
   exit(EXIT_SUCCESS);    /* para terminar o processo */
}                         

int main() {
   pergunta_t perg;   /* mensagem do "tipo" pergunta */
   resposta_t resp;   /* mensagem do "tipo" resposta */
   
   int i, res;
   char c_fifo_fname[50];
   char * aux;
   printf("\nServidor de dicionario");
   if (signal(SIGINT,  trataSig) == SIG_ERR) {
       perror("\nNao foi possivel configurar o sinal SIGINT\n");
       exit(EXIT_FAILURE);
   }
   fprintf(stderr, "\nSinal SIGINT configurado");

   res = mkfifo(SERVER_FIFO, 0777);
   if (res == -1) {
      perror("\nmkfifo do FIFO do servidor deu erro");
      exit(EXIT_FAILURE);
   }
   fprintf(stderr, "\nFIFO servidor criado");

   /* prepara FIFO do servidor */
   /* abertura read+write -> evita o comportamento de ficar */
   /* bloqueado no open. a execu��o prossegue e as          */
   /* opera��es read/write (neste caso APENAS READ)         */
   /* continuam bloqueantes (mais f�cil de gerir)           */
   s_fifo_fd = open(SERVER_FIFO, O_RDWR);  /* bloqueante */
   if (s_fifo_fd == -1) {
      perror("\nErro ao abrir o FIFO do servidor (RDWR/blocking)");
      exit(EXIT_FAILURE);
   }
   fprintf(stderr,"\nFIFO aberto para READ (+WRITE) bloqueante");
   
   /* ciclo principal: read pedido -> write resposta -> repete */
   while (1) {  /* sai via SIGINT */
      /* ---- OBTEM PERGUNTA ---- */
      res = read(s_fifo_fd, & perg, sizeof(perg));
      if (res < sizeof(perg)) {
            fprintf(stderr,"\nRecebida pergunta incompleta "
                    "[bytes lidos: %d]", res);
            continue; /* n�o responde a cliente (qual cliente?) */
      }
      fprintf(stderr, "\nRecebido [%s]", perg.palavra);
      
      /* ---- PROCURA TRADUCAO ---- */
      strcpy(resp.palavra, "DESCONHECIDO"); /* caso n encontre */
      for (i=0; i<NPALAVRAS; i++)
         if (!strcasecmp(perg.palavra,dicionario[i][0])) {
            strcpy(resp.palavra,dicionario[i][1]);
            break;
         }
      fprintf(stderr, "\nResposta = [%s]", resp.palavra);

      /* ---- OBTEM FILENAME DO FIFO PARA A RESPOSTA ---- */   
      sprintf(c_fifo_fname, CLIENT_FIFO, perg.pid_cliente);

      /* ---- Abre FIFO do cliente p/ write ---- */   
      c_fifo_fd = open(c_fifo_fname, O_WRONLY);
      if (c_fifo_fd == -1)
         perror("\nErro no open - Ninguem quis a resposta");
      else {
         fprintf(stderr,"\nFIFO cliente aberto para WRITE");
         
         /* ---- ENVIA RESPOSTA ---- */   
         res = write(c_fifo_fd, & resp, sizeof(resp));
         if (res == sizeof(resp))
            fprintf(stderr,"\nescreveu a resposta");
         else
            perror("\nerro a escrever a resposta");

         close(c_fifo_fd); /* FECHA LOGO O FIFO DO CLIENTE! */
         fprintf(stderr,"\nFIFO cliente fechado");
      }
   } /* fim do ciclo principal do servidor */

   /* em principio n�o chega a este ponto - sai via SIGINT */
   close(s_fifo_fd);
   unlink(SERVER_FIFO);
   return 0;
} /* fim da fun��o main do servidor */
