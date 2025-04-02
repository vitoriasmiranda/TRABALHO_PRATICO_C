#include <stdio.h>
#include <stdlib.h>

int main(){
    /*Vari�veis para escolha da figura e opera��o*/
    int figura, operacao, num_figuras, i;
    /* Vari�veis para armazenar os dados das figuras */
    float raio, largura, altura_retangulo, altura_triangulo, lado1, lado2, lado3, base, resultado;
    char continuar;

    do { /*In�cio do bloco de solicitar o n�mero de figuras*/
        printf("Quantas figuras voce deseja calcular?\n");
        scanf("%d", &num_figuras);

        for (i = 0; i < num_figuras; i++) {
            /*Menu de op��es para escolher a figura geom�trica*/
            printf("\nEscolha a figura geometrica %d:\n", i + 1);
            printf("1. Circulo\n");
            printf("2. Retangulo\n");
            printf("3. Triangulo\n");
            scanf("%d", &figura);

            /*Verifica��o de entrada inv�lida para a figura*/
            while (figura < 1 || figura > 3) {
                printf("Opcao invalida! Por favor, escolha uma figura valida (1, 2 ou 3):\n");
                scanf("%d", &figura);
            }

            /*Menu de op��es para escolher a opera��o*/
            printf("Escolha a operacao:\n");
            printf("1. Calcular Area\n");
            printf("2. Calcular Perimetro\n");
            scanf("%d", &operacao);

            /*Verifica��o de entrada inv�lida para a opera��o*/
            while (operacao < 1 || operacao > 2) {
                printf("Opcao invalida! Por favor, escolha uma opcao valida (1 ou 2):\n");
                scanf("%d", &operacao);
            }

            switch (figura) {
                case 1:
                    /*C�lculos para o c�rculo*/
                    printf("Digite o raio do circulo: ");
                    scanf("%f", &raio);
                    if (operacao == 1) {
                        /*Calcular e exibir a �rea do c�rculo*/
                        resultado = 3.14159 * raio * raio;
                        printf("Area do circulo: %.2f\n", resultado);
                    } else if (operacao == 2) {
                        /*Calcular e exibir o per�metro do c�rculo*/
                        resultado = 2 * 3.14159 * raio;
                        printf("Perimetro do circulo: %.2f\n", resultado);
                    }
                    /*Exibir dados do c�rculo*/
                    printf("Circulo - Raio: %.2f\n", raio);
                    break;

                case 2:
                    /*C�lculos para o ret�ngulo*/
                    printf("Digite a largura do retangulo: ");
                    scanf("%f", &largura);
                    printf("Digite a altura do retangulo: ");
                    scanf("%f", &altura_retangulo);
                    if (operacao == 1) {
                        /*Calcular e exibir a �rea do ret�ngulo*/
                        resultado = largura * altura_retangulo;
                        printf("Area do retangulo: %.2f\n", resultado);
                    } else if (operacao == 2) {
                        /*Calcular e exibir o per�metro do ret�ngulo*/
                        resultado = 2 * (largura + altura_retangulo);
                        printf("Perimetro do retangulo: %.2f\n", resultado);
                    }
                    /*Exibir dados do ret�ngulo*/
                    printf("Retangulo - Largura: %.2f, Altura: %.2f\n", largura, altura_retangulo);
                    break;

                case 3:
                    /*C�lculos para o tri�ngulo*/
                    if (operacao == 1) {
                        /*Solicitar base e altura para c�lculo da �rea*/
                        printf("Digite a base do triangulo: ");
                        scanf("%f", &base);
                        printf("Digite a altura do triangulo: ");
                        scanf("%f", &altura_triangulo);
                        /*Calcular e exibir a �rea do tri�ngulo*/
                        resultado = 0.5 * base * altura_triangulo;
                        printf("Area do triangulo: %.2f\n", resultado);
                        /*Exibir dados do tri�ngulo*/
                        printf("Triangulo - Base: %.2f, Altura: %.2f\n", base, altura_triangulo);
                    } else if (operacao == 2) {
                        /*Solicitar os comprimentos dos tr�s lados do tri�ngulo para o c�lculo do per�metro*/
                        printf("Digite o comprimento do primeiro lado do triangulo: ");
                        scanf("%f", &lado1);
                        printf("Digite o comprimento do segundo lado do triangulo: ");
                        scanf("%f", &lado2);
                        printf("Digite o comprimento do terceiro lado do triangulo: ");
                        scanf("%f", &lado3);
                        /*Calcular e exibir o per�metro do tri�ngulo*/
                        resultado = lado1 + lado2 + lado3;
                        printf("Perimetro do triangulo: %.2f\n", resultado);
                        /*Exibir dados do tri�ngulo*/
                        printf("Triangulo - Lados: %.2f, %.2f, %.2f\n", lado1, lado2, lado3);
                    }
                    break;
            }
        }

        /*Perguntar se o usu�rio deseja calcular a �rea e/ou per�metro de outra figura*/
        do {
            printf("Deseja calcular a area e/ou perimetro de outra figura? (s/n): ");
            scanf(" %c", &continuar);
            if (continuar != 's' && continuar != 'n') {
                printf("Entrada invalida. Por favor, digite 's' para sim ou 'n' para n�o.\n");
            }
        } while (continuar != 's' && continuar != 'n');

    } while (continuar == 's'); /*Continuar o loop se o usu�rio digitar "s"*/

    return 0;
}