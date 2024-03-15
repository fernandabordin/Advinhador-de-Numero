#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int attempts = 5;

void printMenu() {
    printf("************************************************\n");
    printf("*        JOGO DE ADIVINHAR NÚMERO OCULTO      *\n");
    printf("************************************************\n");
    printf("\n");
    printf("Você tem %d tentativas para adivinhar um número de 0 a 999.\n", attempts);
    printf("\n");
    printf("Digite seu palpite: ");
}

int checkDifference(int guess, int number) {
    if (guess > number) return guess - number;
    else return number - guess;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int number;
    int guess;
    int difference;

    srand ( time(NULL) );
    number = rand() % 1000;

    while (attempts > 0) {
        printMenu();
        scanf("%d", &guess);
        system("cls");
        difference = checkDifference(guess, number);

        if (guess < 0 || guess > 999) { 
            printf("O número está entre 0 e 999, por favor digite um valor dentro desse intervalo.\n");
            attempts++;
        }
        else if (guess == number) {
            printf("Parabéns, você acertou o número!\n");
            return 0;
        }
        else if (difference > 15) printf("Muito frio.\n");
        else if (difference > 10 && difference < 15) printf("Frio.\n");
        else if (difference > 5 && difference < 10) printf("Quente.\n");
        else printf("Muito quente.\n");
        printf("\n\n");
        attempts--;
    }

    printf("Você perdeu, o número é: %d\n", number);

    return 0;
}