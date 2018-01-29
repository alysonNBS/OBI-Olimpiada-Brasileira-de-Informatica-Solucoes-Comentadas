/*
* By @alysonNBS
* Problema Falta Uma da OBI - 2016 - Segunda Fase - Nível 2
* Link da prova: http://olimpiada.ic.unicamp.br/extras/provas/ProvaOBI2016_f2p2.pdf
*/

/* Comentários da solução:
*
* Como o problema tem uma input pequena, a analise será feita de forma mais longa, simples e fácil de entender
* Basta analisar se a quantidade de doces é suficiente para evoluir três, dois, um ou nenhum das pô-que-mão
*/

#include <stdio.h> // scanf e putchar

int main(void)
{
    int N, X, Y, Z;

    scanf("%d%*c%d%*c%d%*c%d%*c", &N, &X, &Y, &Z); // %d para leitura do inteiro e %*c para ignorar a quebra de linha


    if( X + Y + Z <= N) // possui a quantidade de doces para evoluir as três pô-que-mão 
        putchar('3');
    else if((X + Y <= N) || // possui quantidade de doces para alimentar a primeiro e a segunda pô-que-mão
            (X + Z <= N) || // ou possui quantidade de doces para alimentar a primeiro e a terceira pô-que-mão
            (Y + Z <= N)) // ou possui quantidade de doces para alimentar a segunda e a terceira pô-que-mão
        putchar('2');
    else if( X <= N || Y <= N || Z <= N ) // possui quantidade de doces para evoluir pelo menos uma pô-que-mão
        putchar('1');
    else // a quantidade de doces não é suficiente para evoluir nenhhuma das três pô-que-mão
        putchar('0');


    return 0;
}