#include <stdio.h> // scanf e putchar


typedef struct
{
    int x, y;
} ponto;

typedef enum 
{
    true = 1, false = 0
} bool;


bool testes(void);

ponto p[8];


int main(void)
{
    for(int i = 1; i <= 7; i++)
        scanf("%d %d", &p[i].x, &p[i].y);
    
    if( testes() ) // Realiza todos os testes para saber se foi inserido um pinheiro ou não
        putchar('S');
    else
        putchar('N');

    return 0;
}


bool teste1(void);
bool teste2(void);
bool teste3(void);
bool teste4(void);
bool teste5(void);
bool teste6(void);
bool teste7(void);
bool teste8(void);

int distancia_quadrada( ponto *p1, ponto *p2 );
int absoluto(int x);


bool testes(void)
{
    return ( teste1() && teste2() && teste3() && teste4() && teste5() && teste6() && teste7() && teste8() );
}


/* Checar se o angulo p2p1p3 é agudo (vértice em p1).
* Isso é equivalente a checar se a relação entre segmentos (p2p3)^2 < (p1p2)^2 + (p1p3)^2 é verdadeira
*/
bool teste1(void)
{
    return ( distancia_quadrada(&p[2], &p[3]) < distancia_quadrada(&p[1], &p[2]) + distancia_quadrada(&p[1], &p[3]) );
}


// Checar se os segmentos p1p2 = p1p3. Afim de programar menos e otimizar o tempo iremos checar se (p1p2)^2 = (p1p3)^2
bool teste2(void)
{
    return ( distancia_quadrada(&p[1], &p[2]) == distancia_quadrada(&p[1], &p[3]) );
}


/* Checar se os pontos p2, p3, p4, p5 estão alinhados.
* A equação para checar se tais pontos estão alinhdos é:
* (x2*y3 + x3*y4 + x4*y5 + x5*y2) - (x3*y2 + x4*y3 + x5*y4 + x2*y5) = 0
* Ou, x2*y3 + x3*y4 + x4*y5 + x5*y2 = x3*y2 + x4*y3 + x5*y4 + x2*y5
*/
bool teste3(void)
{
    return ( ( p[2].x*p[3].y + p[3].x*p[4].y + p[4].x*p[5].y + p[5].x*p[2].y ) ==
        ( p[3].x*p[2].y + p[4].x*p[3].y + p[5].x*p[4].y + p[2].x*p[5].y ) );
}


/* Checar se o ponto médio dos segmentos p2p3 e p4p5 são coincidentes
* Isso é equivalente a checar se (x2 + x3)/2 = (x4 + x5)/2 e (y2 + y3)/2 = (y4 + y5)/2
* Ou, de forma mais simples, (x2 + x3) = (x4 + x5) e (y2 + y3) = (y4 + y5)
*/
bool teste4(void)
{
    return ( p[2].x + p[3].x == p[4].x + p[5].x && p[2].y + p[3].y == p[4].y + p[5].y );
}


/* Checa se o segmento p2p3 > p4p5. Para otimizar o tempo e programar menos usaremos a comparação (p2p3)^2 > (p4p5)^2
* OBS.: esta comparação otimizada só é valida porque é garantido que segmentos são maiores que 1 ou inexistentes
*/
bool teste5(void)
{
    return ( distancia_quadrada(&p[2], &p[3]) > distancia_quadrada(&p[4], &p[5]) );
}


/* Checar se p4p6 e p5p7 são perpendiculares a p2p3.
* Isso equivalente a analisar se os triângulos p4p6p2 e p5p7p3 são retângulos em p4 e p5
* Por pitágoras, verificaremos se (p2p6)^2 = (p2p4)^2 + (p4p6)^2 e (p3p7)^2 = (p3p5)^2 + (p5p7)^2
*/
bool teste6(void)
{
    return ( distancia_quadrada(&p[2], &p[6]) == distancia_quadrada(&p[2], &p[4]) + distancia_quadrada(&p[4], &p[6]) &&
        distancia_quadrada(&p[3], &p[7]) == distancia_quadrada(&p[3], &p[5]) + distancia_quadrada(&p[5], &p[7]) );
}


// Checar se os segmentos p4p6 = p5p7. Afim de programar menos e otimizar o tempo iremos checar se (p4p6)^2 = (p5p7)^2
bool teste7(void)
{
    return ( distancia_quadrada(&p[4], &p[6]) == distancia_quadrada(&p[5], &p[7]) );
}


/* Checar se p1 e p6 estão separados pela reta p2p3
* Uma maneira de fazer isso é analizar a área dos polígonos p1p2p3 e p1p2p6p3:
* Se a área de p1p2p3 for menor que a área de p1p2p6p3, implica que p6 está do lado aposto a p1 pela reta p2p3;
* Se as áreas forem iguais, implica que p6 pertence a p2p3; e
* Se a área de p1p2p3 for maior que a área de p1p2p6p3, implica que p6 está no mesmo lado que p1 pela reta p2p3.
*
* A equação da área para ambos cada um é:
* [p1p2p3] = |(x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3)| / 2
* [p1p2p6p3] = |(x1*y2 + x2*y6 + x6*y3 + x3*y1) - (x2*y1 + x6*y2 + x3*y6 + x1*y3)| / 2
*/
bool teste8(void)
{
    return ( absoluto( (p[1].x*p[2].y + p[2].x*p[3].y + p[3].x*p[1].y) -
                (p[2].x*p[1].y + p[3].x*p[2].y + p[1].x*p[3].y) ) <=
             absoluto( (p[1].x*p[2].y + p[2].x*p[6].y + p[6].x*p[3].y + p[3].x*p[1].y) -
                (p[2].x*p[1].y + p[6].x*p[2].y + p[3].x*p[6].y + p[1].x*p[3].y) ) );
}


int distancia_quadrada( ponto *p1, ponto *p2 )
{
	// Equação da distância entre pontos d^2 = (x1 - x2)^2 + (y1 - y2)^2
	return (p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y);
}


int absoluto(int x)
{
    return (x < 0) ? -x : x ;
}