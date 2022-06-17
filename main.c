#include <stdio.h>
#include <math.h>
#define TAMANHO_DA_LINHA 15

typedef struct 
{
    double parteReal;
    double parteImaginaria;
} SaidaEquacao;

float raiz(float num, float exp);
float soma(float numero1, float numero2);
float subtracao(float numero1, float numero2);
float produto(float numero1, float numero2);
float divisao(float numero1, float numero2);
int mod(int numero1, int numero2);
float potencia(float numero1, float numero2);
unsigned long int fatorial(unsigned long int num);

void limparConsole();
void printarAbertura();
void printarLinha();

void exibirMenuPrincipal();
void exibirMenuCalculadoraBasica();
void exibirMenuCalculadoraFatorial();
void exibirMenuEquacaoGrau2();
void exibirMenuEquacaoGrau3();

void printarSaidaEquacao(SaidaEquacao saidas[], int tamanhoDoArray);
void printarFatorial(unsigned long int numero, unsigned long int numeroEmFatorial);

void aguardarEntrada();
void lerEntradasEquacaoGrau2();
void lerEntradasEquacaoGrau3();
void lerNumeroEAplicarFatorial();

void resolveEquacao(double a, double b, double c, double d);
void resolveEquacaoGrau0(double a);
void resolveEquacaoGrau1(double a, double b);
void resolveEquacaoGrau2(double a, double b, double c);
void resolveEquacaoGrau3(double a, double b, double c, double d);

void aguardarEntrada()
{
    fflush(stdin);
    char c = getchar();
    c = getchar();
}

void exibirMenuPrincipal()
{
    menu:
    {
        limparConsole();
        printarAbertura();
        
        int opcao;
        printf("\n\n Escolha um operacao:     \n \n ");
        printf ("1) Calculadora Basica\n ");
        printf ("2) Calcular Fatorial \n ");
        printf ("3) Equacao de Segundo Grau \n ");
        printf ("4) Equacao de Terceiro Grau \n ");
        printf ("\n\n ---> ");
        scanf("%d", &opcao);

        switch(opcao)
        {
          case 1:
              exibirMenuCalculadoraBasica();
              break;
          case 2:
              exibirMenuCalculadoraFatorial();
              break;
          case 3:
              exibirMenuEquacaoGrau2();
              break;
          case 4:
              exibirMenuEquacaoGrau3();
              break;
          default:
              goto menu;
        }
    }
}

void exibirMenuCalculadoraBasica()
{
    calcBasica:
    {
        limparConsole();
        printarAbertura();
        
        float num1, num2;
        char oper;

        printf("Calculadora das 4 operacoes\n\n");

        printf("Operacoes disponiveis\n\n");
        printf("'+' : soma\n");
        printf("'-' : subtracao\n");
        printf("'*' : multiplicao\n");
        printf("'/' : divisao\n");
        printf("'%%' : resto da divisao\n");
        printf("'p' : potencia\n");
        printf("'r' : raiz\n");

        printf("\nDigite a expressao no formato: numero1 operador numero2\n");
        printf("Exemplos: 2 + 2 ,  3.6 * 9\n");
        printf("Para voltar digite: 0 0 0\n\n");

        scanf("%f", &num1);
        scanf(" %c",&oper);
        scanf("%f", &num2);

        limparConsole();

        printf("Calculando: %.2f %c %.2f = ", num1,oper,num2);

        switch( oper )
        {
            case '+':
                printf("%.2f\n\n", soma(num1, num2));
                break;
            case '-':
                printf("%.2f\n\n", subtracao(num1, num2));
                break;
            case '*':
                printf("%.2f\n\n", produto(num1, num2));
                break;
            case '/':
                if(num2 != 0)
                    printf("%.2f\n\n", divisao(num1, num2));
                else
                    printf("Nao existe divisao por 0\n\n");
                break;
            case '%':
                printf("%d\n\n", mod((int)num1, (int)num2));
                break;
            case 'p':
                printf("%f\n\n", potencia(num1, num2));
                break;
            case 'r':
                printf("%f\n\n", raiz(num1, num2));
                break;
            default:
                if(num1 == 0 && oper == '0' && num2 == 0)
                {
                    exibirMenuPrincipal();
                    return;
                }
        }

        aguardarEntrada();
        goto calcBasica;
    }
}

void exibirMenuCalculadoraFatorial()
{
    lerNumeroEAplicarFatorial();
    aguardarEntrada();
    exibirMenuPrincipal();
}

void exibirMenuEquacaoGrau2()
{
    lerEntradasEquacaoGrau2();
    aguardarEntrada();
    exibirMenuPrincipal();
}

void exibirMenuEquacaoGrau3()
{
    lerEntradasEquacaoGrau3();
    aguardarEntrada();
    exibirMenuPrincipal();
}

// Operacoes Basicas ---------------
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

float raiz(float num, float exp)
{
	  return pow(num, 1/exp); //sqrt(num);
}

float potencia(float numero1, float numero2)
{
    return pow(numero1, numero2);
}

unsigned long int fatorial(unsigned long int num)
{
    if(num <= 1)
        return 1;
        
    return num * fatorial(num -1);    
}

// Printando Itens ---------------
void limparConsole()
{
    system("cls || clear");
}

void printarAbertura()
{
    printarLinha();
    puts("Calculadora Em C");
    puts("Introducao ao computador - 2021.2 UFPB");
    puts("Alunos: Diego Reis, Victor Cavalcanti, "
                  "Isaura Maia, Cassio Victor, Ciro Ramos, "
                  "Joao Pedro e Kalil de Sousa");
    printarLinha();
}

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

void printarFatorial(unsigned long int numero, unsigned long int numeroEmFatorial)
{
    printf("\nNumero %ld em fatorial: %ld\n", numero, numeroEmFatorial);
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
    raizes[0].parteImaginaria = (-b + sqrt(delta))/(2*a);
    
		raizes[1].parteReal = 0;
		raizes[1].parteImaginaria = (-b - sqrt(delta))/(2*a);

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
		raizes[0].parteReal = (-b + sqrt(delta))/(2*a);
    raizes[0].parteImaginaria = 0;
    
		raizes[1].parteReal = (-b - sqrt(delta))/(2*a);
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
    exibirMenuPrincipal();
    //printarAbertura();
    //lerNumeroEAplicarFatorial();
    //lerEntradasEquacaoGrau2();
    //lerEntradasEquacaoGrau3();

    return 0;
}
