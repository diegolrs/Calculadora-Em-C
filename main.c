#include <stdio.h>
#include <math.h>
#define TAMANHO_DA_LINHA 15

typedef struct 
{
    double parteReal;
    double parteImaginaria;
} SaidaEquacao;

float raiz(float num);

void printarLinha();
void printarSaidaEquacao(SaidaEquacao saidas[], int tamanhoDoArray);
void printarFatorial(int numero, int numeroEmFatorial);

void lerEntradasEquacaoGrau2();
void lerEntradasEquacaoGrau3();
void lerNumeroEAplicarFatorial();

void resolveEquacao(double a, double b, double c, double d);
void resolveEquacaoGrau0(double a);
void resolveEquacaoGrau1(double a, double b);
void resolveEquacaoGrau2(double a, double b, double c);
void resolveEquacaoGrau3(double a, double b, double c, double d);

// Operacoes Basicas ---------------
float raiz(float num)
{
    return sqrt(num);
}

float soma(float numero1, float numero2)
{
    return numero1 + numero2;
}

float subtracao(float numero1, float numero2)
{
    return numero1 - numero2;
}

float produto(float numero1, float numero2)
{
    return numero1 * numero2;
}

float divisao(float numero1, float numero2)
{
    return numero1 / numero2;
}

int mod(int numero1, int numero2)
{
    return numero1 % numero2;
}

int fatorial(int num)
{
    if(num <= 1)
        return 1;
        
    return num * fatorial(num -1);    
}

// Printando Itens ---------------
void printarLinha()
{
    int i = 0;
    
    for(i = 0; i < TAMANHO_DA_LINHA; i++)
        printf("-");
        
    puts("");
}

void printarSaidaEquacao(SaidaEquacao saidas[], int tamanhoDoArray)
{
    if(tamanhoDoArray <= 0)
    {
        puts("\nNao existe raiz real\n");
        printarLinha();
        return;
    }
	    
    printf("\nRaizes:\n");
    
    for(int i = 0; i < tamanhoDoArray; i++)
    {
        int temParteImaginaria = saidas[i].parteImaginaria != 0;
      
        if(temParteImaginaria)
          printf("x%d: %f + %fi\n", i, saidas[i].parteReal, saidas[i].parteImaginaria);
        else
          printf("x%d: %f\n", i, saidas[i].parteReal);
    }
        
    printarLinha();
}

void printarFatorial(int numero, int numeroEmFatorial)
{
    printf("\nNumero %d em fatorial: %d\n", numero, numeroEmFatorial);
    printarLinha();
}

// Lendo entradas ----------------
void lerNumeroEAplicarFatorial()
{
    puts("");
    printarLinha();
    
    int numero = 0;
    printf("Digite o numero para aplicar fatorial: ");
    scanf("%d", &numero);
    
    printarFatorial(numero, fatorial(numero));
}

void lerEntradasEquacaoGrau2()
{
    double a, b, c;
    
    puts("");
    printarLinha();
    
    printf("Digite o A de uma equacao de segundo grau: ");
    scanf("%lf", &a);
    printf("Digite o B de uma equacao de segundo grau: ");
    scanf("%lf", &b);
    printf("Digite o C de uma equacao de segundo grau: ");
    scanf("%lf", &c);
    
    resolveEquacao(0, a, b, c);
}

void lerEntradasEquacaoGrau3()
{
    double a, b, c, d;
    
    puts("");
    printarLinha();
    
    printf("Digite o A de uma equacao de terceiro grau: ");
    scanf("%lf", &a);
    printf("Digite o B de uma equacao de terceiro grau: ");
    scanf("%lf", &b);
    printf("Digite o C de uma equacao de terceiro grau: ");
    scanf("%lf", &c);
    printf("Digite o D de uma equacao de terceiro grau: ");
    scanf("%lf", &d);
    
    resolveEquacao(a, b, c, d);
}


void resolveEquacaoGrau0(double a)
{	
    SaidaEquacao raizes[1];
    raizes[0].parteReal = -a;
    raizes[0].parteImaginaria = 0;
    printarSaidaEquacao(raizes, 1);
}

void resolveEquacaoGrau1(double a, double b)
{
  SaidaEquacao raizes[1];
	raizes[0].parteReal = -b/a;
  raizes[0].parteImaginaria = 0;
	printarSaidaEquacao(raizes, 1);
}

void resolveEquacaoGrau2(double a, double b, double c)
{
    SaidaEquacao raizes[2];
    
    float delta = b*b - 4*a*c;
	
    if(delta < 0)
    {
        delta *= -1;

        raizes[0].parteReal = 0;
        raizes[0].parteImaginaria = (-b + raiz(delta))/(2*a);
    
	raizes[1].parteReal = 0;
	raizes[1].parteImaginaria = (-b - raiz(delta))/(2*a);

        printarSaidaEquacao(raizes, 2);
    }
    else if(delta == 0)
    {
        raizes[0].parteReal = -b/2*a;
        raizes[0].parteImaginaria = 0;
	printarSaidaEquacao(raizes, 1);
    }
    else
    {
        raizes[0].parteReal = (-b + raiz(delta))/(2*a);
        raizes[0].parteImaginaria = 0;
    
	raizes[1].parteReal = (-b - raiz(delta))/(2*a);
	raizes[1].parteImaginaria = 0;
    
	printarSaidaEquacao(raizes, 2);
    }
}

void resolveEquacaoGrau3(double a, double b, double c, double d)
{
    double A, B, C, D, p, q, delta, e, r, t;
    double x1, x2, x2real, x2imag, x3, x3real, x3imag;
    double y1, y1_2, y1_3, y2, y2_2, y2_3, y3;
    
    SaidaEquacao raizes[3];
    
    A = a/a;
    B = b/a;
    C = c/a;
    D = d/a;
    
    p = -pow(B, 2)/3*A*A + C/A;
    q = (2*pow(B, 3) - 9*A*B*C + 27*A*A*D)/27*pow(A, 3);
    delta = (q*q/4) + (pow(p, 3)/27);
    e = pow(-delta, 0.5);
    r = pow(q*q/4 + e*e, 0.5);
    t = acos((-q)/(2*r));

    if(delta >= 0)
    {
        y1 = cbrt(-q/2+(sqrt(delta))); 
        y2 = cbrt(-q/2-(sqrt(delta)));
        y3 = B/(3*A);
        x1 = y1 + y2 - y3;
        y1_2 = -y1/2;
        y2_2 = -y2/2;
        x2real = y1_2 + y2_2 - y3;
        y1_3 = (y1 * sqrt(3))/2;
        y2_3 = (y2 * -sqrt(3))/2;
        x2imag = y1_3 + y2_3;
        x3real = x2real;
        x3imag = -x2imag;

        raizes[0].parteReal = x1;
        raizes[0].parteImaginaria = 0;
      
        raizes[1].parteReal = x2real;
        raizes[1].parteImaginaria = x2imag;
      
        raizes[2].parteReal = x3real;
        raizes[2].parteImaginaria = x3imag;
    }
    else
    {
        raizes[0].parteReal = 2 * cbrt(r) * cos((t/3)) - B/3;
        raizes[0].parteImaginaria = 0;
      
        raizes[1].parteReal = 2 * cbrt(r) * cos(((t + (360/(180.0/M_PI)))/3)) - B/3;
        raizes[1].parteImaginaria = 0;
      
        raizes[2].parteReal = 2 * cbrt(r) * cos(((t + (720/(180.0/M_PI)))/3)) - B/3;
        raizes[2].parteImaginaria = 0;
    }
    
    printarSaidaEquacao(raizes, 3);
}

void resolveEquacao(double a, double b, double c, double d)
{
    if(a != 0)
        resolveEquacaoGrau3(a, b, c, d);
    else if (b != 0)
        resolveEquacaoGrau2(b, c, d);
    else if (c != 0)
        resolveEquacaoGrau1(c, d);
    else
        resolveEquacaoGrau0(d);
}

int main(void) 
{
    lerNumeroEAplicarFatorial();
    lerEntradasEquacaoGrau2();
    lerEntradasEquacaoGrau3();

    return 0;
}
