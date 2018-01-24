/*
* Solução de alysonNBS
* Problema Falta Uma da OBI - 2016 - Segunda Fase - Nível 2
* Link da prova: http://olimpiada.ic.unicamp.br/extras/provas/ProvaOBI2016_f2p2.pdf
*/

/* Comentários da solução:
*
* Idéia para resolver o problema:
*
* Deve-se construir uma matriz que indique o número de vezes que o número y aparece na posição x
* Analisando a questão e usando o método matemático é visivel que cada número y deve aparecer exatamente (n-1)! vezes,
* Ou seja, o número que não aparecer (n-1)! = (n!)/n vezes em determinada posição,
* É o número que deve aparecer naquela posição no cartão de permutação faltando 
*/

#include <cstdio>

#define MAX 40320 // MAX = 8! = 40320

int fatorial(int x);

int main(void)
{
    int numero[8][8], cartao[MAX][8], n, aux, n_fatorial;

    scanf("%d", &n);

    n_fatorial = fatorial(n);

    for(int i = 0; i < (n_fatorial - 1); i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &cartao[i][j]);


    //reset da matriz numero para o valor 0
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            numero[i][j] = 0;


    aux = n_fatorial/n; //número de vezes que um número deve aparecer em cada posição


    for(int i = 0; i < n; i++)
    {
        //indica quantas vezes cada número aparece no posição i do cartão
        for(int j = 0; j < (n_fatorial - 1); j++)
            numero[i][ (cartao[j][i] - 1) ]++;

        //escolhe o número que não apareceu (n!/n) vezes e o exibi
        for(int j = 0; j < n; j++)
            if( numero[i][j] != aux )
                printf("%d", j+1);
        
        //garanti que haja espaços APENAS entre os numeros
        if( i != (n-1) )
            printf(" ");
    }

    return 0;
}

int fatorial(int x)
{
    if(x == 0) return 1;
    return x*fatorial(x-1);
}