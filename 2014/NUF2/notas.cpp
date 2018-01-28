/*
* By @alysonNBS
* Problema Notas da OBI - 2014 - Segunda Fase - Nível Universitário
* Link da prova: http://olimpiada.ic.unicamp.br/extras/provas/ProvaOBI2014_prog_f2nu.pdf
*/

/* Comentários da solução:
*
* Idéia para resolver o problema:
*
* É preciso ler as notas em um vetor
* Após a leitura, ordene eles em ordem crescente
* Feito isso, basta percorrer o vetor e contar quantas vezes cada nota está aparecendo
* Se uma nota aparecer mais vezes ou tantas vezes quanto as suas anteriores, essa nota passará a ocupar a maior nota
*/

#include <cstdio> // printf e scanf
#include <algorithm> // sort

using namespace std; // ativar biblioteca algorithm

int main(void)
{
    int n, nota[200], maior_nota, maior_frequencia;

    maior_nota = maior_frequencia = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", nota+i);


    sort(nota, nota+n); // ordena as notas em ordem crescente


    for(int i = 1, frequencia; i < n; i++)
    {
        frequencia = 0;

        while(nota[i-1] == nota[i] && i < n)
        {
            frequencia++;
            i++;
        }

        if(maior_frequencia <= frequencia && frequencia > 0)
        {
            maior_frequencia = frequencia;
            maior_nota = nota[i-1]; // o valor da nota de maior frequência está na posição i-1 do vetor
        }
        else if(maior_frequencia == 0)
        {
            // a maior frequencia continua a ser 0, ou seja, todos apareceram apenas uma vez, logo, não houve interação no contador i
            maior_nota = nota[i];
        } 
    }

    
    printf("%d\n", maior_nota);

    return 0;
}