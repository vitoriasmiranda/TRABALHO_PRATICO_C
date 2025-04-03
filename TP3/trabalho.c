#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_FIGURAS 10
#define PI 3.14159

//Os valores utilizados para teste do codigo foram:
//Circulo: Raio = 4

//Retangulo: Largura = 4 , Altura = 2

//Triangulo: Base = 5, Altura = 3  Lado1 = 4, Lado2 = 4, Lado3 = 4


// Estrutura para representar uma figura geométrica
typedef struct {
    char nome[20];
    char tipo[20];
    float dimensoes[3]; // Dependendo do tipo, armazena raio, largura/altura, ou lados
    float area;
    float perimetro;
} Figura;

// Função recursiva para calcular o fatorial
int fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

// Função para calcular a área de um polígono irregular usando a fórmula de Shoelace
float calcularAreaIrregular(float x[], float y[], int n) {
    float area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (x[i] * y[j]) - (x[j] * y[i]);
    }
    return fabs(area) / 2.0;
}

// Função para calcular o perímetro de um polígono irregular, incluindo o fatorial
float calcularPerimetroIrregular(float x[], float y[], int n) {
    float perimetro = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        perimetro += sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
    }
    // Exemplo de uso do fatorial no cálculo do perímetro
    return perimetro / fatorial(n);
}

// Função para validar se os lados formam um triângulo válido
int validarTriangulo(float lado1, float lado2, float lado3) {
    return (lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) && (lado2 + lado3 > lado1);
}

// Função para calcular a área de um círculo
float calcularAreaCirculo(float raio) {
    return PI * raio * raio;
}

// Função para calcular o perímetro de um círculo
float calcularPerimetroCirculo(float raio) {
    return 2 * PI * raio;
}

// Função para calcular a área de um retângulo
float calcularAreaRetangulo(float largura, float altura) {
    return largura * altura;
}

// Função para calcular o perímetro de um retângulo
float calcularPerimetroRetangulo(float largura, float altura) {
    return 2 * (largura + altura);
}

// Função para calcular a área de um triângulo
float calcularAreaTriangulo(float base, float altura) {
    return 0.5 * base * altura;
}

// Função para calcular o perímetro de um triângulo
float calcularPerimetroTriangulo(float lado1, float lado2, float lado3) {
    return lado1 + lado2 + lado3;
}

// Função para trocar as dimensões de duas figuras usando ponteiros
void trocarDimensoes(Figura *figura1, Figura *figura2) {
    float tempDimensoes[3];
    memcpy(tempDimensoes, figura1->dimensoes, sizeof(tempDimensoes));
    memcpy(figura1->dimensoes, figura2->dimensoes, sizeof(tempDimensoes));
    memcpy(figura2->dimensoes, tempDimensoes, sizeof(tempDimensoes));
}


// Função para exibir o menu de figuras
void exibirMenuFiguras() {
    printf("\nEscolha a figura geometrica:\n");
    printf("1. Circulo\n");
    printf("2. Retangulo\n");
    printf("3. Triangulo\n");
    printf("4. Figura Irregular\n");
}

// Função para exibir o menu de operações
void exibirMenuOperacoes() {
    printf("\nEscolha a operacao:\n");
    printf("1. Calcular Area\n");
    printf("2. Calcular Perimetro\n");
    printf("3. Trocar Dimensoes de Figuras\n");
}

// Função para validar entradas positivas
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

// Função para inicializar uma figura
void inicializarFigura(Figura *figura, const char *tipo, const char *nome) {
    strcpy(figura->tipo, tipo);
    strcpy(figura->nome, nome);
    figura->area = 0.0;
    figura->perimetro = 0.0;
    memset(figura->dimensoes, 0, sizeof(figura->dimensoes));
}

// Função para exibir o relatório detalhado
void exibirRelatorio(Figura *figuras, int contador_figuras) {
    printf("\nRelatorio de Figuras:\n");
    printf("----------------------------------------------------------------------------\n");
    printf("%-15s %-15s %-25s %-10s %-10s\n", "Nome", "Tipo", "Dimensoes", "Area", "Perimetro");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < contador_figuras; i++) {
        char dimensoesStr[50] = ""; // String para armazenar as dimensões formatadas
        if (strcmp(figuras[i].tipo, "Circulo") == 0) {
            snprintf(dimensoesStr, 50, "Raio: %.2f", figuras[i].dimensoes[0]);
        } else if (strcmp(figuras[i].tipo, "Retangulo") == 0) {
            snprintf(dimensoesStr, 50, "Larg: %.2f, Alt: %.2f", figuras[i].dimensoes[0], figuras[i].dimensoes[1]);
        } else if (strcmp(figuras[i].tipo, "Triangulo") == 0) {
            snprintf(dimensoesStr, 50, "Lados: %.2f, %.2f, %.2f", figuras[i].dimensoes[0], figuras[i].dimensoes[1], figuras[i].dimensoes[2]);
        } else if (strcmp(figuras[i].tipo, "Irregular") == 0) {
            snprintf(dimensoesStr, 50, "Lados: %d", (int)figuras[i].dimensoes[0]);
        }

        // Exibe os dados formatados
        printf("%-15s %-15s %-25s %-10.2f %-10.2f\n", figuras[i].nome, figuras[i].tipo, dimensoesStr, figuras[i].area, figuras[i].perimetro);
    }
    printf("----------------------------------------------------------------------------\n");
}

// Função principal
int main() {
    int figura, operacao, num_figuras, i;
    char continuar;

    // Vetor dinâmico para armazenar as figuras
    Figura *figuras = NULL;
    int contador_figuras = 0;

    do {
        printf("Quantas figuras voce deseja calcular? ");
        scanf("%d", &num_figuras);

        // Alocação dinâmica de memória para as figuras
        figuras = (Figura *)realloc(figuras, (contador_figuras + num_figuras) * sizeof(Figura));
        if (figuras == NULL) {
            printf("Erro ao alocar memoria!\n");
            return 1;
        }

        for (i = 0; i < num_figuras; i++) {
            exibirMenuFiguras();
            scanf("%d", &figura);

            // Verificação de entrada inválida para a figura
            while (figura < 1 || figura > 4) {
                printf("Opcao invalida! Por favor, escolha uma figura valida (1 a 4):\n");
                scanf("%d", &figura);
            }

            exibirMenuOperacoes();
            scanf("%d", &operacao);

            // Verificação de entrada inválida para a operação
            while (operacao < 1 || operacao > 3) {
                printf("Opcao invalida! Por favor, escolha uma opcao valida (1 a 3):\n");
                scanf("%d", &operacao);
            }

            // Opção para trocar dimensões de figuras
            if (operacao == 3) {
                if (contador_figuras < 2) {
                    printf("Eh necessario ter pelo menos duas figuras para trocar dimensoes.\n");
                    continue;
                }
                int idx1, idx2;
                printf("Digite o indice da primeira figura (1 a %d): ", contador_figuras);
                scanf("%d", &idx1);
                printf("Digite o indice da segunda figura (1 a %d): ", contador_figuras);
                scanf("%d", &idx2);
                if (idx1 < 1 || idx1 > contador_figuras || idx2 < 1 || idx2 > contador_figuras) {
                    printf("Indices invalidos!\n");
                    continue;
                }
                trocarDimensoes(&figuras[idx1 - 1], &figuras[idx2 - 1]);
                printf("Dimensoes trocadas com sucesso!\n");
                continue;
            }

            Figura *figuraAtual = &figuras[contador_figuras];

            switch (figura) {
                case 1: // Círculo
                    inicializarFigura(figuraAtual, "Circulo", "Circulo");
                    figuraAtual->dimensoes[0] = validarEntradaPositiva("Digite o raio do circulo: ");
                    if (operacao == 1) {
                        figuraAtual->area = calcularAreaCirculo(figuraAtual->dimensoes[0]);
                        printf("Area do circulo: %.2f\n", figuraAtual->area);
                    } else {
                        figuraAtual->perimetro = calcularPerimetroCirculo(figuraAtual->dimensoes[0]);
                        printf("Perimetro do circulo: %.2f\n", figuraAtual->perimetro);
                    }
                    snprintf(figuraAtual->nome, 20, "Circulo %d", contador_figuras + 1);
                    break;

                case 2: // Retângulo
                    inicializarFigura(figuraAtual, "Retangulo", "Retangulo");
                    figuraAtual->dimensoes[0] = validarEntradaPositiva("Digite a largura do retangulo: ");
                    figuraAtual->dimensoes[1] = validarEntradaPositiva("Digite a altura do retangulo: ");
                    if (operacao == 1) {
                        figuraAtual->area = calcularAreaRetangulo(figuraAtual->dimensoes[0], figuraAtual->dimensoes[1]);
                        printf("Area do retangulo: %.2f\n", figuraAtual->area);
                    } else {
                        figuraAtual->perimetro = calcularPerimetroRetangulo(figuraAtual->dimensoes[0], figuraAtual->dimensoes[1]);
                        printf("Perimetro do retangulo: %.2f\n", figuraAtual->perimetro);
                    }
                    snprintf(figuraAtual->nome, 20, "Retangulo %d", contador_figuras + 1);
                    break;

                case 3: // Triângulo
                    inicializarFigura(figuraAtual, "Triangulo", "Triangulo");
                    if (operacao == 1) {
                        figuraAtual->dimensoes[0] = validarEntradaPositiva("Digite a base do triangulo: ");
                        figuraAtual->dimensoes[1] = validarEntradaPositiva("Digite a altura do triangulo: ");
                        figuraAtual->area = calcularAreaTriangulo(figuraAtual->dimensoes[0], figuraAtual->dimensoes[1]);
                        printf("Area do triangulo: %.2f\n", figuraAtual->area);
                    } else {
                        figuraAtual->dimensoes[0] = validarEntradaPositiva("Digite o comprimento do primeiro lado do triangulo: ");
                        figuraAtual->dimensoes[1] = validarEntradaPositiva("Digite o comprimento do segundo lado do triangulo: ");
                        figuraAtual->dimensoes[2] = validarEntradaPositiva("Digite o comprimento do terceiro lado do triangulo: ");
                        if (!validarTriangulo(figuraAtual->dimensoes[0], figuraAtual->dimensoes[1], figuraAtual->dimensoes[2])) {
                            printf("Os lados fornecidos nao formam um triangulo valido!\n");
                            continue;
                        }
                        figuraAtual->perimetro = calcularPerimetroTriangulo(figuraAtual->dimensoes[0], figuraAtual->dimensoes[1], figuraAtual->dimensoes[2]);
                        printf("Perimetro do triangulo: %.2f\n", figuraAtual->perimetro);
                    }
                    snprintf(figuraAtual->nome, 20, "Triangulo %d", contador_figuras + 1);
                    break;

                case 4: // Figura Irregular
                    inicializarFigura(figuraAtual, "Irregular", "Irregular");
                    int n = validarEntradaPositiva("Digite o numero de lados da figura irregular: ");
                    float x[n], y[n];
                    for (int j = 0; j < n; j++) {
                        printf("Digite as coordenadas (x, y) do vertice %d: ", j + 1);
                        scanf("%f %f", &x[j], &y[j]);
                    }
                    figuraAtual->perimetro = calcularPerimetroIrregular(x, y, n);
                    figuraAtual->area = calcularAreaIrregular(x, y, n);
                    printf("Perimetro da figura irregular: %.2f\n", figuraAtual->perimetro);
                    printf("Area da figura irregular: %.2f\n", figuraAtual->area);
                    snprintf(figuraAtual->nome, 20, "Irregular %d", contador_figuras + 1);
                    break;
            }
            contador_figuras++;
        }

        // Exibir relatório detalhado
        exibirRelatorio(figuras, contador_figuras);

        // Perguntar se o usuário deseja continuar
        do {
            printf("Deseja calcular a area e/ou perimetro de outra figura? (s/n): ");
            scanf(" %c", &continuar);
            if (continuar != 's' && continuar != 'n') {
                printf("Entrada invalida. Por favor, digite 's' para sim ou 'n' para nao.\n");
            }
        } while (continuar != 's' && continuar != 'n');

    } while (continuar == 's');

    // Liberar memória alocada
    free(figuras);
    return 0;
}
