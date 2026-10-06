#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//o que cada thread recebe
struct conta {
   int thread;
   char operacao;
   int a;
   int b;
};

//cada conta espera 1 segundo, para simular uma operacao demorada
int calcula(char operacao, int a, int b){
   sleep(1);
   if (operacao == '+')
      return a + b;
   if (operacao == '-')
      return a - b;
   if (operacao == '*')
      return a * b;
   if (b == 0)
      return 0; //evita divisao por zero
   return a / b;
}

//funcao executada por cada thread
void *faz_conta(void *arg){
   struct conta *c = (struct conta *) arg;
   int resultado = calcula(c->operacao, c->a, c->b);
   printf("thread %d: %d %c %d = %d\n", c->thread, c->a, c->operacao, c->b, resultado);
   return NULL;
}

int main(int argc, char *argv[]){
   char operacoes[4] = {'+', '-', '*', '/'};
   struct conta contas[4];
   pthread_t threads[4];
   int a, b, i;

   if (argc < 3){
      printf("uso: %s a b\n", argv[0]);
      return 1;
   }
   a = atoi(argv[1]);
   b = atoi(argv[2]);

   //cria uma thread para cada conta
   for (i = 0; i < 4; i++){
      contas[i].thread = i;
      contas[i].operacao = operacoes[i];
      contas[i].a = a;
      contas[i].b = b;
      pthread_create(&threads[i], NULL, faz_conta, (void *) &contas[i]);
   }

   //espera as quatro terminarem
   for (i = 0; i < 4; i++){
      pthread_join(threads[i], NULL);
   }
   return 0;
}
