#include <stdio.h>
#define MAX_CARTAS 32 // 8 ESTADOS * 4 CIDADES

int main(){
    char estado[MAX_CARTAS];
    char codigo[MAX_CARTAS][4];
    char cidade[MAX_CARTAS][50];
    int populacao[MAX_CARTAS];
    float area[MAX_CARTAS];
    float pib[MAX_CARTAS];
    float densidadepopulacional[MAX_CARTAS];// DENSIDADE POPULACIONAL
    float pibpercapita[MAX_CARTAS];// PIB PER CAPITA
    int pontosturisticos[MAX_CARTAS];
    
    int totalCartas, i;

    //PERGUNTA QUANTAS CARTAS DESEJA CADASTRAR?
    printf("Quantas cartas deseja cadastrar? \n");
    scanf("%d", &totalCartas);

    if (totalCartas > MAX_CARTAS){
        printf("Número máximo de cartas é %d.\n", MAX_CARTAS);
        return 1;
    }
    //CADASTRO DE CARTAS
    for (i = 0; i < totalCartas; i++) {
        printf("*** Cadastro de Cartas %d ***\n", i + 1);

        printf("Estado (EX: A-H): ");
        scanf(" %c", &estado[i]);

        printf("Código (EX: A01 - H04): ");
        scanf("%s", codigo[i]); 

        printf("Nome da Cidade: ");
        scanf(" %[^\n]", cidade[i]);

        printf("População: ");
        scanf("%d", &populacao[i]);

        printf("Aréa (Km²): ");
        scanf("%f", &area[i]);

        printf("PIB: ");
        scanf("%f", &pib[i]);

        printf("Pontos turísticos: ");
        scanf("%d", &pontosturisticos[i]);

        //CALCULO DENSIDADE POPULACIONAL
        if (area[i] > 0) {
            densidadepopulacional[i] = populacao[i] / area[i];
        } else {
            densidadepopulacional[i] = 0; //EVITA DIVISÃO POR ZERO
        }

        //CALCULO DO PIB por pecapita
        if (populacao[i] > 0) {
            pibpercapita[i] = pib[i] / populacao[i];
        } else {
            pibpercapita[i] = 0;
        }
    }
      // EXIBE CARTAS CADSATRADAS
    printf("\n--- CARTAS CADSATRADAS ---\n");
    for (i = 0; i < totalCartas; i++) {
      printf("\nCarta %d\n", i + 1);
      printf("Código: %s\n", codigo[i]);
      printf("Estado: %c\n", estado[i]);
      printf("Cidade: %s\n", cidade[i]);
      printf("População: %d\n", populacao[i]);
      printf("Aréa: %.2f km²\n", area[i]);
      printf("PIB: R$ %.2f\n", pib[i]);
      printf("Densidade Populacional: %.2f hab/km²\n", densidadepopulacional[i]);
      printf("PIB por per capita: R$ %.2f\n", pibpercapita[i]);
      printf("Pontos Turisticos: %d\n", pontosturisticos[i]);
    }
    return 0;

}


   




   
