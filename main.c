#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void initialize(char col1[], char col2[], char col3[], char col4[], char col5[], char col6[], char col7[], char col8[], char col9[], char col10[]) {
    for (int i = 0; i < 200; i++) {
        col1[i] = ' ';
        col2[i] = ' ';
        col3[i] = ' ';
        col4[i] = ' ';
        col5[i] = ' ';
        col6[i] = ' ';
        col7[i] = ' ';
        col8[i] = ' ';
        col9[i] = ' ';
        col10[i] = '=';
    }
}
int random_in_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}
int main () {
    srand(time(NULL));
    int game = 1;
    int frame = 0;
    float kmh = 20;
    printf("Este programa mostra uma visualizacao da velocidade, assumindo que cada caractere (= ou -) e 1 metro.\n");
    printf("Introduza a velocidade (kmh): ");
    scanf("%f", &kmh);
    float meters_per_second = kmh * 1000 / 3600;
    int slp = (int)(1000000 / meters_per_second);
    int speed_static = 0, speed_variable = speed_static;
    char col1[200], col2[200], col3[200], col4[200], col5[200], col6[200], col7[200], col8[200], col9[200], col10[200];
    initialize(col1, col2, col3, col4, col5, col6, col7, col8, col9, col10);
    while (game == 1) {
        // atualizar o carro
        if (frame % 2) {
            col9[0] = 'O';
            col9[1] = '-';
            col9[2] = '-';
            col9[3] = '-';
            col9[4] = '0';
            col8[0] = '/';
            col7[1] = '_';
            col8[1] = 'o';
            col7[2] = '_';
            col8[2] = 'o';
            col7[3] = '_';
            col8[3] = 'D';
            col8[4] = '\\';
        } else {
            col9[0] = '0';
            col9[1] = '-';
            col9[2] = '-';
            col9[3] = '-';
            col9[4] = 'O';
            col8[0] = '/';
            col7[1] = '_';
            col8[1] = 'o';
            col7[2] = '_';
            col8[2] = 'o';
            col7[3] = '_';
            col8[3] = 'D';
            col8[4] = '\\';
        }
        // printar o mapa
        // -----------------------------------------------------
        for (int i = 0; i < 200; i++) {printf("%c", col1[i]);}
        printf("\n");
        for (int i = 0; i < 200; i++) {printf("%c", col2[i]);}
        printf("\n");
        for (int i = 0; i < 200; i++) {printf("%c", col3[i]);}
        printf("\n");
        for (int i = 0; i < 200; i++) {printf("%c", col4[i]);}
        printf("\n");
        for (int i = 0; i < 200; i++) {printf("%c", col5[i]);}
        printf("\n");
        for (int i = 0; i < 200; i++) {printf("%c", col6[i]);}
        printf("\n");
        for (int i = 0; i < 200; i++) {printf("%c", col7[i]);}
        printf("\n");
        for (int i = 0; i < 200; i++) {printf("%c", col8[i]);}
        printf("\n");
        for (int i = 0; i < 200; i++) {printf("%c", col9[i]);}
        printf("\n");
        for (int i = 0; i < 200; i++) {printf("%c", col10[i]);}
        printf("\n");
        // -----------------------------------------------------
        // atualizar o mapa
        if (speed_variable == 0) { // se chegou a hora de mover o mapa (consoante a dificuldade)...
            // clouds
            int random_num1 = random_in_range(0, 5);
            if (random_num1 == 0) {
                int random_num2 = random_in_range(0, 3);
                if (random_num2 == 0) {
                    col2[196] = '(';
                    col1[197] = '_';
                    col1[198] = '_';
                    col2[197] = '_';
                    col2[198] = '_';
                    col2[199] = ')';
                } else if (random_num2 == 1) {
                    col3[195] = '(';
                    col2[196] = '_';
                    col2[197] = '_';
                    col2[198] = '_';
                    col3[196] = '_';
                    col3[197] = '_';
                    col3[198] = '_';
                    col3[199] = ')';
                } else if (random_num2 == 2) {
                    col4[196] = '(';
                    col3[197] = '_';
                    col3[198] = '_';
                    col4[197] = '_';
                    col4[198] = '_';
                    col4[199] = ')';
                } else if (random_num2 == 3) {
                    col5[196] = '(';
                    col4[197] = '_';
                    col4[198] = '_';
                    col5[197] = '_';
                    col5[198] = '_';
                    col5[199] = ')';
                }
            }
            // buracos na estrada
            int random_num3 = random_in_range(0, 5);
            if (random_num3 == 0) {
                col10[199] = '-';
            }
            // Casinhas
            int random_num4 = random_in_range(0, 40);
            if (random_num4 == 0) {
                col9[199] = '|';
                col8[199] = '|';
                col7[199] = '\\';
                col6[198] = '\\';
                col6[197] = '_';
                col7[197] = 'o';
                col6[196] = '/';
                col7[195] = '/';
                col8[195] = '|';
                col9[195] = '|';
                col9[198] = '0';
                col9[196] = '0';
                col8[198] = '0';
                col8[196] = '0';
            } else if (random_num4 == 20) {
                col9[199] = '|';
                col8[199] = '\\';
                col7[198] = '\\';
                col7[197] = '_';
                col8[197] = 'o';
                col7[196] = '/';
                col8[195] = '/';
                col9[195] = '|';
                col9[198] = '0';
                col9[196] = '0';
            }
            // mover tudo para a esquerda sempre que o tick mudar
            for (int i = 0; i < 199; i++) {
                col1[i] = col1[i + 1];
                col2[i] = col2[i + 1];
                col3[i] = col3[i + 1];
                col4[i] = col4[i + 1];
                col5[i] = col5[i + 1];
                col6[i] = col6[i + 1];
                col7[i] = col7[i + 1];
                col8[i] = col8[i + 1];
                col9[i] = col9[i + 1];
                col10[i] = col10[i + 1];
            }
            col7[0] = ' ';
            col1[199] = ' ';
            col2[199] = ' ';
            col3[199] = ' ';
            col4[199] = ' ';
            col5[199] = ' ';
            col6[199] = ' ';
            col7[199] = ' ';
            col8[199] = ' ';
            col9[199] = ' ';
            col10[199] = '=';
            speed_variable = speed_static;
        }
        printf("Speed (kmh): %f\n", kmh);
        printf("Distancia percorrida em km: %f\n", (float)frame / 1000);
        // atualizar a tela
        // speed_variable--; // tick rate update
        usleep(slp); // sleep for the calculated duration
        system("clear"); // clear screen
        frame++;
    }
    return 0;
}
