#include <stdio.h>
#define DIM 100
#define T 100

float calcola_media(int count, float v[]){
    int i;
    float somma = 0;
    if (count <= 0) return 0;
    for ( i = 0; i < count; i++){
        somma += v[i];
    }
    return somma / count;
}

float trova_massimo(float N[T], int giorni){
    if (giorni <= 0) return 0;
    float max = N[0];
    int j;
    for ( j = 1; j < giorni; j++){
        if (N[j] > max){
            max = N[j];
        }
    }
    return max;
}

float trova_minimo(float N[T], int giorni){
    if (giorni <= 0) return 0;
    float min = N[0];
    int j;
    for ( j = 1; j < giorni; j++){
        if (N[j] < min){
            min = N[j];
        }
    }
    return min;
}

int conta_maggiori_di_media(float N[T], int giorni){
    if (giorni == 0) return 0;

    float media = 0;
    for (int i = 0; i < giorni; i++) {
        media += N[i];
    }
    media /= giorni;

    int count = 0;
    for (int i = 0; i < giorni; i++) {
        if (N[i] > media) {
            count++;
        }
    }

    return count;
}


int main() {
    int i;
    int giorni;
    float N[T];


    printf("inserisci il numero di giorni che vuoi consultare\n");
    if (scanf("%d", &giorni) != 1) return 1;

    if (giorni < 1 || giorni > 31) {
        printf("errato questo numero di giorni non valido !\n");
        return 1;
    }

    for (i = 0; i < giorni; i++) {
        printf("inserisci la temperatura del %d° giorno\n", i + 1);
        scanf("%f", &N[i]);
    }
    for (i = 0; i < giorni; i++) {
        printf("-la temperatura del %d° giorno e' %.2f\n", i + 1, N[i]);
    }

    float avg = calcola_media(giorni, N);
    printf("-la media delle temperature e': %.2f°\n", avg);

    float massimo = trova_massimo(N, giorni);
    printf("-la temperatura massima e': %.2f°\n", massimo);

    float minimo = trova_minimo(N, giorni);
    printf("-la temperatura minima e' : %.2f°\n", minimo);

    int sopraLaMedia = conta_maggiori_di_media(N, giorni);
    printf("-I giorni con la temperatura sopra la media sono %d\n", sopraLaMedia);
    return 0;
}