#include <stdio.h>
// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

struct Carta {
    char estado;
    char codigo[4];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos;
    float densidade;
    float pibCapita;
    float superPoder;
};

int main() {
    // Cartas disponíveis usei o modelo de apresentação.
    struct Carta cartas[2] = {
        {'A', "A01", "São Paulo",     12325000, 1521.11, 699.28, 50},
        {'B', "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30}
    };

    // Calcula propriedades
    for (int i = 0; i < 2; i++) {
        cartas[i].densidade = cartas[i].populacao / cartas[i].area;
        cartas[i].pibCapita = (cartas[i].pib * 1000000000) / cartas[i].populacao;
        cartas[i].superPoder = cartas[i].populacao + cartas[i].area +
                               cartas[i].pib + cartas[i].pontos +
                               cartas[i].densidade + cartas[i].pibCapita;
    }

    int escolha1, escolha2, atributo;

    printf("=== ESCOLHA SUA CARTA ===\n");
    printf("1 - %s (%s)\n", cartas[0].cidade, cartas[0].codigo);
    printf("2 - %s (%s)\n", cartas[1].cidade, cartas[1].codigo);

    // Jogador 1 escolhe carta
    printf("\nJogador 1, escolha sua carta (1 ou 2): ");
    scanf("%d", &escolha1);

    // Não permitir cartas que não existem.
    while (escolha1 < 1 || escolha1 > 2) {
        printf("Opção inválida. Escolha 1 ou 2: ");
        scanf("%d", &escolha1);
    }

    // Jogador 2 escolhe carta (não pode repetir)
    printf("Jogador 2, escolha sua carta (1 ou 2, diferente do Jogador 1): ");
    scanf("%d", &escolha2);
    // Jogador 2 não pode escolher a mesma carta que jogador 1 (só tem 1 no jogo de cada)
    while (escolha2 < 1 || escolha2 > 2 || escolha2 == escolha1) {
        if (escolha2 == escolha1) {
            printf("Essa carta já foi escolhida pelo Jogador 1. Escolha a outra: ");
        } else {
            printf("Opção inválida. Escolha 1 ou 2: ");
        }
        scanf("%d", &escolha2);
    }

    struct Carta c1 = cartas[escolha1 - 1];
    struct Carta c2 = cartas[escolha2 - 1];

    // Escolha do qual opção vai ser disputada.
    printf("\n=== DISPUTA DISPONÍVEIS ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - PIB per Capita\n");
    printf("6 - Densidade Populacional (menor vence)\n");
    printf("7 - Super Poder\n");

    printf("\nEscolha o opção para competir: ");
    scanf("%d", &atributo);

    while (atributo < 1 || atributo > 7) {
        printf("Opção inválido. Escolha entre 1 e 7: ");
        scanf("%d", &atributo);
    }

    printf("\n=== RESULTADO ===\n");
    printf("Jogador 1: %s (%s)\n", c1.cidade, c1.codigo);
    printf("Jogador 2: %s (%s)\n\n", c2.cidade, c2.codigo);

    switch (atributo) {
        case 1:
            printf("População: %s vence\n", (c1.populacao > c2.populacao) ? c1.cidade : c2.cidade);
            break;
        case 2:
            printf("Área: %s vence\n", (c1.area > c2.area) ? c1.cidade : c2.cidade);
            break;
        case 3:
            printf("PIB: %s vence\n", (c1.pib > c2.pib) ? c1.cidade : c2.cidade);
            break;
        case 4:
            printf("Pontos Turísticos: %s vence\n", (c1.pontos > c2.pontos) ? c1.cidade : c2.cidade);
            break;
        case 5:
            printf("PIB per Capita: %s vence\n", (c1.pibCapita > c2.pibCapita) ? c1.cidade : c2.cidade);
            break;
        case 6:
            printf("Densidade Populacional (menor vence): %s vence\n", (c1.densidade < c2.densidade) ? c1.cidade : c2.cidade);
            break;
        case 7:
            printf("Super Poder: %s vence\n", (c1.superPoder > c2.superPoder) ? c1.cidade : c2.cidade);
            break;
    }

    return 0;
}
