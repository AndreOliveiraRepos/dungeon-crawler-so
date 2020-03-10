/* ------------------------------------------------------------------------------------- */
/* C�digo do cliente */

#include "dict.h"

int main() {
   int s_fifo_fd;          /* identificador do FIFO do servidor */
   int c_fifo_fd;          /* identificador do FIFO deste cliente */
   pergunta_t perg;        /* mensagem do "tipo" pergunta */ 
   resposta_t resp;        /* mensagem do "tipo" resposta */
   char c_fifo_fname[25];  /* nome do FIFO deste cliente */
   int read_res;

   /* cria o FIFO do cliente */
   perg.pid_cliente = getpid();
   sprintf(c_fifo_fname, CLIENT_FIFO, perg.pid_cliente);
   if (mkfifo(c_fifo_fname, 0777) == -1) {
      perror("\nmkfifo FIFO cliente deu erro");
      exit(EXIT_FAILURE);
   }
   fprintf(stderr,"\nFIFO do cliente criado");

   /* abre o FIFO do servidor p/ escrita */
   s_fifo_fd = open(SERVER_FIFO, O_WRONLY); /* bloqueante */
   if (s_fifo_fd == -1) {
      fprintf(stderr, "\nO servidor n�o est� a correr\n");
      unlink(c_fifo_fname);
      exit(EXIT_FAILURE);
   }
   fprintf(stderr,"\nFIFO do servidor aberto WRITE / BLOCKING");
   
   /* abertura read+write -> evita o comportamento de ficar */
   /* bloqueado no open. a execu��o prossegue logo mas as   */
   /* opera��es read/write (neste caso APENAS READ)         */
   /* continuam bloqueantes (mais f�cil)                    */
   c_fifo_fd = open(c_fifo_fname, O_RDWR); /* bloqueante */
   if (c_fifo_fd == -1) {
      perror("\nErro nao abrir o FIFO do cliente");
      close(s_fifo_fd);
      unlink(c_fifo_fname);
      exit(EXIT_FAILURE);
   }
   fprintf(stderr, "\nFIFO do cliente aberto para READ (+Write) BLOCK");

   memset(perg.palavra, '\0', TAM_MAX);

   while (1) {  /* "fim" para terminar cliente */
      /* ---- a) OBTEM PERGUNTA ---- */
      printf("\nPalavra a traduzir -> ");
      scanf("%s",perg.palavra);
      if (!strcasecmp(perg.palavra,"fim"))
         break;

      /* ---- b) ENVIA A PERGUNTA ---- */
      write(s_fifo_fd, & perg, sizeof(perg));
      /* ---- c) OBTEM A RESPOSTA ---- */
      read_res = read(c_fifo_fd, & resp, sizeof(resp));
      if (read_res == sizeof(resp))
         printf("\nTraducao -> %s", resp.palavra);
      else
         printf("\nSem resposta ou resposta incompreensivel"
                "[bytes lidos: %d]", read_res);
   }

   close(c_fifo_fd);
   close(s_fifo_fd);
   unlink(c_fifo_fname);
   return 0;
} /* fim da fun��o main do cliente*/
