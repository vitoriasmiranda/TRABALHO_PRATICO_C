#include <stdio.h>
#include <stdlib.h>

#define MAX_FIGURAS 10
#define PI 3.14159

/*Trabalho Pratico: Sistema de C�lculo de Propriedades Geom�tricas*/
/*Aluna: Vitoria de Souza Miranda Matricula: 24.2.8019*/

/*Os valores utilizados para teste do c�digo foram:
Circulo: Raio = 4

Retangulo: Largura = 4 , Altura = 2

Triangulo: Base = 5, Altura = 3  Lado1 = 4, Lado2 = 4, Lado3 = 4*/

/* Funcoes para calculos geometricos */
float calcularAreaCirculo(float raio) {
    return PI * raio * raio;
}

float calcularPerimetroCirculo(float raio) {
    return 2 * PI * raio;
}

float calcularAreaRetangulo(float largura, float altura) {
    return largura * altura;
}

float calcularPerimetroRetangulo(float largura, float altura) {
    return 2 * (largura + altura);
}

float calcularAreaTriangulo(float base, float altura) {
    return 0.5 * base * altura;
}

float calcularPerimetroTriangulo(float lado1, float lado2, float lado3) {
    return lado1 + lado2 + lado3;
}

/*Fun��o para exibir o menu*/
void exibirMenu() {
    printf("\nEscolha a figura geometrica:\n");
    printf("1. Circulo\n");
    printf("2. Retangulo\n");
    printf("3. Triangulo\n");
    printf("Escolha a operacao:\n");
    printf("1. Calcular Area\n");
    printf("2. Calcular Perimetro\n");
}

/* Fun��o para validar entradas positivas */
float validarEntradaPositiva(const char *mensagem) {
    float valor;
    do {
        printf("%s", mensagem);
        scanf("%f", &valor);
        if (valor <= 0) {
            printf("Valor invalido! Digite um numero positivo.\n");
        }
    } while (valor <= 0);
    return valor;
}

int main(){
    int figura, operacao, num_figuras, i;
    float raio, largura, altura_retangulo, altura_triangulo, lado1, lado2, lado3, base;
    char continuar;

     /* Vetores para armazenar os dados das figuras */
    char nomes[MAX_FIGURAS][20];    /* Nomes das Figuras */
    float dados_figuras[MAX_FIGURAS][5] = {0}; /* [raio, largura, altura, �rea, per�metro]*/
    int contador_figuras = 0;    /* Contador de figuras armazenada */


    do {
        printf("Quantas figuras voce deseja calcular? (Maximo %d)\n", MAX_FIGURAS);
        scanf("%d", &num_figuras);

        if (num_figuras > MAX_FIGURAS) {
            printf("Numero de figuras excede o limite maximo de %d.\n", MAX_FIGURAS);
            continue;
        }

        for (i = 0; i < num_figuras; i++){
            exibirMenu();
            scanf("%d", &figura);


            /*Verifica��o de entrada inv�lida para a figura*/
            while (figura < 1 || figura > 3) {
                printf("Opcao invalida! Por favor, escolha uma figura valida (1, 2 ou 3):\n");
                scanf("%d", &figura);
            }

            scanf("%d", &operacao);

            /*Verifica��o de entrada inv�lida para a opera��o*/
            while (operacao < 1 || operacao > 2) {
                printf("Opcao invalida! Por favor, escolha uma opcao valida (1 ou 2):\n");
                scanf("%d", &operacao);
            }

            switch (figura) {
                case 1:
                    /*C�rculo*/
                    raio = validarEntradaPositiva("Digite o raio do circulo: ");
                    if (operacao == 1) {
                        dados_figuras[contador_figuras][3] = calcularAreaCirculo(raio); /* �rea */
                     printf("Area do circulo: %.2f\n", dados_figuras[contador_figuras][3]);
                    } else {
                        dados_figuras[contador_figuras][4] = calcularPerimetroCirculo(raio); /* Per�metro*/
                        printf("Perimetro do circulo: %.2f\n", dados_figuras[contador_figuras][4]);
                    }
                    dados_figuras[contador_figuras][0] = raio; /*Raio*/
                    snprintf(nomes[contador_figuras], 20, "Circulo %d", contador_figuras + 1); /*Nome*/
                    break;

                case 2:
                    /*Retangulo*/
                    largura = validarEntradaPositiva("Digite a largura do retangulo: ");
                    altura_retangulo = validarEntradaPositiva("Digite a altura do retangulo: ");
                    if (operacao == 1) {
                        dados_figuras[contador_figuras][3] = calcularAreaRetangulo(largura, altura_retangulo); /*�rea*/
                        printf("Area do retangulo: %.2f\n", dados_figuras[contador_figuras][3]);
                    } else {
                        dados_figuras[contador_figuras][4] = calcularPerimetroRetangulo(largura, altura_retangulo); /*Per�metro*/
                        printf("Perimetro do retangulo: %.2f\n", dados_figuras[contador_figuras][4]);
                    }
                    dados_figuras[contador_figuras][1] = largura; /*Largura*/
                    dados_figuras[contador_figuras][2] = altura_retangulo; /* Altur*/
                    snprintf(nomes[contador_figuras], 20, "Retangulo %d", contador_figuras + 1); /*Nome*/
                    break;

                case 3:
                    /*Tri�ngulo*/
                    if (operacao == 1) {
                        base = validarEntradaPositiva("Digite a base do triangulo: ");
                        altura_triangulo = validarEntradaPositiva("Digite a altura do triangulo: ");
                        dados_figuras[contador_figuras][3] = calcularAreaTriangulo(base, altura_triangulo); /*�rea*/
                        printf("Area do triangulo: %.2f\n", dados_figuras[contador_figuras][3]);
                    } else {
                        lado1 = validarEntradaPositiva("Digite o comprimento do primeiro lado do triangulo: ");
                        lado2 = validarEntradaPositiva("Digite o comprimento do segundo lado do triangulo: ");
                        lado3 = validarEntradaPositiva("Digite o comprimento do terceiro lado do triangulo: ");
                        dados_figuras[contador_figuras][4] = calcularPerimetroTriangulo(lado1, lado2, lado3); /*Per�metro*/
                        printf("Perimetro do triangulo: %.2f\n", dados_figuras[contador_figuras][4]);
                    }
                    snprintf(nomes[contador_figuras], 20, "Triangulo %d", contador_figuras + 1); /*Nome*/
                    break;

            }
            contador_figuras++;
        }

        /* Exibir dados tabulares */
        printf("\nDados das figuras:\n");
        printf("------------------------------------------------------------\n");
        printf("Nome\t\tRaio\tLargura\tAltura\tArea\tPerimetro\n");
        printf("------------------------------------------------------------\n");
        for (i = 0; i < contador_figuras; i++) {
            if (strstr(nomes[i], "Circulo") != NULL) {
                /* Exibe apenas raio, �rea e per�metro para o c�rculo*/
                printf("%s\t\t%.2f\t-\t-\t%.2f\t%.2f\n",
                       nomes[i], dados_figuras[i][0], dados_figuras[i][3], dados_figuras[i][4]);
            } else if (strstr(nomes[i], "Retangulo") != NULL) {
                /*Exibe largura, altura, �rea e per�metro para o ret�ngulo*/
                printf("%s\t\t-\t%.2f\t%.2f\t%.2f\t%.2f\n",
                       nomes[i], dados_figuras[i][1], dados_figuras[i][2], dados_figuras[i][3], dados_figuras[i][4]);
            } else if (strstr(nomes[i], "Triangulo") != NULL) {
                /*Exibe base, altura, �rea e per�metro para o tri�ngulo*/
                printf("%s\t\t-\t-\t%.2f\t%.2f\t%.2f\n",
                       nomes[i], dados_figuras[i][2], dados_figuras[i][3], dados_figuras[i][4]);
            }
        }
        printf("------------------------------------------------------------\n");

        /*Perguntar se o usu�rio deseja calcular a �rea e/ou per�metro de outra figura*/
        do {
            printf("Deseja calcular a area e/ou perimetro de outra figura? (s/n): ");
            scanf(" %c", &continuar);
            if (continuar != 's' && continuar != 'n') {
                printf("Entrada invalida. Por favor, digite 's' para sim ou 'n' para nao.\n");
            }
        } while (continuar != 's' && continuar != 'n');

    } while (continuar == 's');
    return 0;
}