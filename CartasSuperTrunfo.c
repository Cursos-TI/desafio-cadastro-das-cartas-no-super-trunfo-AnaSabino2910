#include <stdio.h>

#define MAX_CARTAS 32

int main() {
    char estados[MAX_CARTAS];
    char codigos[MAX_CARTAS][4];
    char nomes[MAX_CARTAS][50];
    unsigned long int populacoes[MAX_CARTAS];
    float areas[MAX_CARTAS];
    float pibs[MAX_CARTAS];
    int pontosTuristicos[MAX_CARTAS];
    float densidade[MAX_CARTAS];  // Densidade populacional
    float pibPerCapita[MAX_CARTAS]; // PIB per capita
    float superPoder[MAX_CARTAS]; // Super poder

    int totalCartas, i, carta1, carta2;

    // Pergunta quantas cartas deseja cadastrar
    printf("Quantas cartas deseja cadastrar? ");
    scanf("%d", &totalCartas);

    if (totalCartas > MAX_CARTAS) {
        printf("Número máximo de cartas é %d.\n", MAX_CARTAS);
        return 1;
    }

    // Cadastro das cartas
    for (i = 0; i < totalCartas; i++) {
        printf("\n--- Cadastro da Carta %d ---\n", i + 1);
        
        printf("Estado (A-H): ");
        scanf(" %c", &estados[i]);
        while (getchar() != '\n');

        printf("Código (Ex: A01): ");
        scanf(" %s", codigos[i]);
        while (getchar() != '\n');

        printf("Nome da cidade: ");
        scanf(" %[^\n]", nomes[i]);
        while (getchar() != '\n');

        printf("População: ");
        scanf("%lu", &populacoes[i]);

        printf("Área (km²): ");
        scanf("%f", &areas[i]);

        printf("PIB: ");
        scanf("%f", &pibs[i]);

        printf("Pontos turísticos: ");
        scanf("%d", &pontosTuristicos[i]);

        // Calcula densidade populacional
        densidade[i] = (areas[i] > 0) ? (populacoes[i] / areas[i]) : 0;

        // Calcula PIB per capita
        pibPerCapita[i] = (populacoes[i] > 0) ? (pibs[i] / populacoes[i]) : 0;

        // Calcula o super poder (densidade é invertida para favorecer valores menores)
        superPoder[i] = populacoes[i] + areas[i] + pibs[i] + pibPerCapita[i] + pontosTuristicos[i] + (1 / (densidade[i] + 1));
    }

    // Exibe todas as cartas cadastradas
    printf("\n--- Cartas Cadastradas ---\n");
    for (i = 0; i < totalCartas; i++) {
        printf("%d. %s (%s) - População: %lu, Área: %.2f km², PIB: %.2f, Pontos turísticos: %d\n",
               i + 1, nomes[i], codigos[i], populacoes[i], areas[i], pibs[i], pontosTuristicos[i]);
    }

    // Escolher cartas para comparar
    printf("\nEscolha duas cartas para comparar (digite os números de 1 a %d): ", totalCartas);
    scanf("%d %d", &carta1, &carta2);

    carta1--; // Ajusta para índice do array
    carta2--;

    // Exibe as cartas escolhidas
    printf("\n--- Comparação das Cartas ---\n");
    printf("\nCarta 1 - %s (%s)\n", nomes[carta1], codigos[carta1]);
    printf("Carta 2 - %s (%s)\n", nomes[carta2], codigos[carta2]);

    printf("\nResultados das Comparações:\n");
    printf("População: %s\n", (populacoes[carta1] > populacoes[carta2]) ? "Carta 1 vence" : "Carta 2 vence");
    printf("Área: %s\n", (areas[carta1] > areas[carta2]) ? "Carta 1 vence" : "Carta 2 vence");
    printf("PIB: %s\n", (pibs[carta1] > pibs[carta2]) ? "Carta 1 vence" : "Carta 2 vence");
    printf("Pontos turísticos: %s\n", (pontosTuristicos[carta1] > pontosTuristicos[carta2]) ? "Carta 1 vence" : "Carta 2 vence");
    printf("Densidade populacional: %s\n", (densidade[carta1] < densidade[carta2]) ? "Carta 1 vence" : "Carta 2 vence");
    printf("PIB per Capita: %s\n", (pibPerCapita[carta1] > pibPerCapita[carta2]) ? "Carta 1 vence" : "Carta 2 vence");
    printf("Super Poder: %s\n", (superPoder[carta1] > superPoder[carta2]) ? "Carta 1 vence" : "Carta 2 vence");

    return 0;
}




   
