#include <stdio.h>
#include <math.h>
#define TAMANHO_DA_LINHA 15

float raiz(float num);

void printarLinha();
void printarSaidaEquacao(double saidas[], int tamanhoDoArray);
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

void printarSaidaEquacao(double saidas[], int tamanhoDoArray)
{
    if(tamanhoDoArray <= 0)
    {
        puts("\nNao existe raiz real\n");
        printarLinha();
        return;
    }
	    
    printf("\nRaizes:\n");
    
    for(int i = 0; i < tamanhoDoArray; i++)
        printf("x%d: %f\n", i, saidas[i]);
        
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
    double raizes[1];
    raizes[0] = -a;
    printarSaidaEquacao(raizes, 1);
}

void resolveEquacaoGrau1(double a, double b)
{
    double raizes[1];
	raizes[0] = -b/a;
	printarSaidaEquacao(raizes, 1);
}

void resolveEquacaoGrau2(double a, double b, double c)
{
    double raizes[2];
    
	float delta = b*b - 4*a*c;
	
    if(delta < 0)
	    printarSaidaEquacao(raizes, 0);
	else if(delta == 0)
	{
		raizes[0] = -b/2*a;
		printarSaidaEquacao(raizes, 1);
	}
	else
	{
		raizes[0] = (-b + raiz(delta))/(2*a);
		raizes[1] = (-b - raiz(delta))/(2*a);
	    printarSaidaEquacao(raizes, 2);
	}
}

void resolveEquacaoGrau3(double a, double b, double c, double d)
{
    double p, q, delta, delta2, modulo, e, r, t;
    double x1, x2, x3, y1, y2, y2_2, y3, y3_2;
    
    double raizes[3];
    
    p = -pow(b, 2)/3*a*a + c/a;
    q = (2*pow(b, 3) - 9*a*b*c + 27*a*a*d)/27*pow(a, 3);
    delta = (q*q/4) + (pow(p, 3)/27);
    e = pow(-delta, 0.5);
    r = pow(q*q/4 + e*e, 0.5);
    t = acos((-q)/(2*r));

    if(delta >= 0){
        y1 = cbrt(-q/2+raiz(delta))+cbrt(-q/2-raiz(delta)); 
        delta2 = pow((y1/2), 2) + q/y1;
        modulo = raiz((delta2*delta2));
        y2 = -y1/2;
         y2_2 = raiz(modulo); 
        y3 = -y1/2;
         y3_2 = raiz(modulo); 

        x1 = y1 - a/3;
        x2 = y2 - a/3;   
        x3 = y3 - a/3;
        
        raizes[0] = x1;
        raizes[1] = x2 + y2_2;
        raizes[2] = x2 + y3_2;
    } 
    else
    {
        x1 = 2 * cbrt(r) * cos((t/3)) - b/3;
        x2 = 2 * cbrt(r) * cos(((t + (360/(180.0/M_PI)))/3)) - b/3;
        x3 = 2 * cbrt(r) * cos(((t + (720/(180.0/M_PI)))/3)) - b/3;
        
        raizes[0] = x1;
        raizes[1] = x2;
        raizes[2] = x3;
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
    
    //double _a[] = {2.1, 5.4, 5.8};
    //printarSaidaEquacao(_a, 3);

    return 0;
}