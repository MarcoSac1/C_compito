#include<stdio.h>
#define DIM 1000

int main(){
    int array[DIM];
    int i;
    int count = 0;
    int somma = 0;
    float media = 0;
    int length = sizeof(array) / sizeof (array[0]);
    int valido = 0;

    while(!valido) {
        printf("Inserisci un numero intero: ");
        scanf("%d", &array[0]);
        
        if(array[0] == 0) {
            printf("Valore errato! Il primo valore non può essere 0.\n");
            valido = 0;
        } else {
            valido = 1;
            count = 1;
            somma = array[0];
        }
    }

    for(i=1; i < length ; i++){
        printf("Inserisci un numero intero: ");
        scanf("%d", &array[i]);

        if (array[i] == 0) {
            break;
        } else {
            count++;
            somma += array[i];
        }
    }

    printf("\nHai inserito %d numeri.\n", count);
    
    printf("La somma dei numeri che hai inserito e': %d\n", somma);
    media = (float) somma / count;
    printf("La media dei numeri che hai inserito e': %.2f\n", media);

    int min = array[0];
    int max = array[0];

    for (i=0; i < count; i++){
        if(array[i] > max){
            max = array[i];
        }
        if(array[i] < min){
            min = array[i];
        }
    }

    printf("Il valore massimo e': %d\n", max);
    printf("Il valore minimo e': %d\n", min);

    int pari = 0;
    int dispari = 0;

    for(i=0; i<count; i++){
        if(array[i]%2==0){
            pari++;
        } else {
            dispari++;
        }
    }

    printf("I numeri pari sono: %d\n", pari);
    printf("I numeri dispari sono: %d\n", dispari);
}