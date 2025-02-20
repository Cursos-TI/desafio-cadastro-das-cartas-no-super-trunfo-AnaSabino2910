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

    //ESCOLHA DO ATRIBUTOA SER COMPARADO
    unsigned long int atributo1 = populacoes[carta1];
    unsigned long int atributo2 = populacoes[carta2];
    char atributoNome[] = "Populações";

    //EXIBE AS CARTAS ESCOLHIDAS
    printf("\n--- COMPARAÇÃO DAS CARTAS ---\n");
    printf("Carta 1 - %s (%s) | %s: %lu\n", nomes[carta1], codigos[carta1], atributoNome, atributo1);
    printf("Carta 2 - %s (%s) | %s: %lu\n", nomes[carta2], codigos[carta2], atributoNome, atributo2);

    //DETERMINA A VENCEDORA
    if (atributo1 > atributo2) {
        printf("\nA Carta 1 venceu na comparação por %s !\n", atributoNome);    
    } else if (atributo2 > atributo1) {
        printf("\nA Carta 2 venceu na comparação por %s !\n", atributoNome);
    } else{
        printf("\nEmpate! Ambas as cartas temo mesmo valor de %s.\n", atributoNome);
    }
    return 0;
}