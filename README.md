# Calculadora com threads

Atividade da disciplina de Sistemas Distribuídos, ministrada pelo
Prof. Dr. Julio Cesar. UFC, Campus Jardins de Anita, Itapajé.

Calculadora que faz as quatro operações com dois números, em duas versões: com
Pthreads (uma thread por operação) e com OpenMP (o laço das operações dividido
entre threads). Cada operação espera 1 segundo, para simular uma conta
demorada.

Autores: Jhefferson Abrahão Alves Barbosa Souza e Pablo Pinto Barbosa.

## Como rodar

```
make
time ./calc_pthreads 10 20
time ./calc_openmp 10 20
```

As duas levam 1 segundo, porque as quatro contas rodam ao mesmo tempo.
