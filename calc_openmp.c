#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

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

int main(int argc, char *argv[]){
   char operacoes[4] = {'+', '-', '*', '/'};
   int a, b, i;

   if (argc < 3){
      printf("uso: %s a b\n", argv[0]);
      return 1;
   }
   a = atoi(argv[1]);
   b = atoi(argv[2]);

   //divide as quatro voltas do laco entre quatro threads
   omp_set_num_threads(4);
   #pragma omp parallel for
   for (i = 0; i < 4; i++){
      int resultado = calcula(operacoes[i], a, b);
      printf("thread %d: %d %c %d = %d\n", omp_get_thread_num(), a, operacoes[i], b, resultado);
   }
   return 0;
}
