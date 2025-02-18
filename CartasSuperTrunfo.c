#include <stdio.h>
#define MAX_CARTAS 32


int main(){

    char estados [MAX_CARTAS];
    char codigos[MAX_CARTAS][4];
    char cidades[MAX_CARTAS][50];
    unsigned long int populacoes[MAX_CARTAS];
    float areas[MAX_CARTAS];
    float pib[MAX_CARTAS];
    int pontosturisticos[MAX_CARTAS];
    float densidade[MAX_CARTAS];
    float pibpercapita[MAX_CARTAS];
    float superpoder[MAX_CARTAS];

    int totalCartas, i, carta1, carta2;
    
    //PERGUNTA QUANTAS CARTAS DESEJA CADASTRAR
    printf("Quantas cartas deseja cadastrar? ");
    scanf("%d", &totalCartas);
    
    if (totalCartas > MAX_CARTAS) {
        printf("Número máximo de cartas é %d. \n", MAX_CARTAS);
        return 1;
    }
    
    //cadastro das cartas
    for (i = 0; i < totalCartas; i++){
        printf("\n---CADASTRO DA CARTA %d ---\n", i + 1);

        printf("Estado (Ex: A - H): ");
        scanf(" %c", &estados[i]);
    

        printf("Código (Ex: A01): ");
        scanf(" %3s", codigos[i]);
        getchar();


        printf("Nome da cidade: ");
        fgets(cidades[i], sizeof(cidades[i]), stdin);
        cidades[i][strcspn(cidades[i], "\n")] = '\0';

        printf("População: ");
        scanf("%lu", &populacoes[i]);

        printf("Área (Km²): ");
        scanf("%f", &areas[i]);

        printf("PIB (em milhões): ");
        scanf("%f", &pib[i]);

        printf("Pontos turisticos: ");
        scanf("%d", &pontosturisticos[i]);

        //CALCULO DA DENSIDADE POPULACINAL EVITANDO DIVISÃO POR 0
        densidade[i] = (areas[i] > 0) ? populacoes[i] / areas[i] : 0;
        
        //CALCULO DO PIB PER CAPITA EVITANDO DIVISÃO POR 0
        pibpercapita[i] = (populacoes[i] > 0) ? pib[i] / populacoes[i] : 0;

        //CÁLCULO DO SUPER PODER
        //A DENSIDADE É INVERTIDA PARA QUE OS VALORESMENORES SEJAM CONSIDERADOS MELHORES
        superpoder[i] = populacoes[i] + areas[i] + pib[i] + pibpercapita[i] + pontosturisticos[i] + (1 / (densidade[i] + 1));

 
    }
    // EXIBIÇÃO DAS CARTAS CADASTRADAS
    printf("\n--- CARTAS CADASTRADAS ---\n");
    for (i = 0; i < totalCartas; i++) {
        printf("\nCartas %d\n", i + 1);
        printf("Código: %s\n", codigos[i]);
        printf("Estado: %c\n", estados[i]);
        printf("Cidade: %s\n", cidades[i]);
        printf("População: %lu\n", populacoes[i]);
        printf("Área: %.2f Km²\n", areas[i]);
        printf("Densidade Populacional: %.2f hab/ Km²\n", densidade[i]);
        printf("PIB: R$ %.2f milhões\n", pib[i]);
        printf("PIB per Capita: R$ %.2f\n", pibpercapita[i]);
        printf("Pontos Turisticos: %d\n", pontosturisticos[i]);
        printf("Super poder: %.2f\n", superpoder[i]);

    }

    //COMPARAÇÃO DE CARTAS
    printf("\nEscolha duas cartas para comparar (1 a %d):\n", totalCartas);
    printf("Carta 1: ");
    scanf("%d", &carta1);
    printf("Carta 2: ");
    scanf("%d", &carta2);

    carta1--;
    carta2--;
    if (carta1 < 0 || carta1 >= totalCartas || carta2 < 0 || carta2 >= totalCartas){
        printf("Cartas invalidas!\n");
        return 1;
    }
    
// COMPARAÇÃO DAS PROPRIEDADES
    printf("\n--- COMPARAÇÃO DAS CARTAS ---\n");
    printf("\n População: %lu vs %lu => ", populacoes[carta1], populacoes[carta2]);
    printf("%d\n", populacoes[carta1] > populacoes[carta2]);

    printf("Área: %.2f Km² vs %.2f Km² => ", areas[carta1], areas[carta2]);
    printf("%d\n", areas[carta1] > areas[carta2]);

    printf("PIB: R$ %.2f milhões vs R$ %.2f milhões => ", pib[carta1], pib[carta2]);
    printf("%d\n", pib[carta1] > pib[carta2]);

    printf("PIB per Capita: R$ %.2f vs R$ %.2f => ", pibpercapita[carta1], pibpercapita[carta2]);
    printf("%d\n", pibpercapita[carta1] > pibpercapita[carta2]);

    printf("Pontos Turisticos: %d vs %d => ", pontosturisticos[carta1], pontosturisticos[carta2]);
    printf("%d\n", pontosturisticos[carta1] < pontosturisticos[carta2]);

    printf("Densidade Populacional: %.2f vs %.2f => ", densidade[carta1], densidade[carta2]);
    printf("%d\n", densidade[carta1] > densidade[carta2]);
    
    printf("Super Poder: %.2f vs %.2f => ", superpoder[carta1], superpoder[carta2]);
    printf("%d\n", superpoder[carta1] > superpoder[carta2]);

    return 0;


}






   
