#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

//arrays for the different winner types
int total[37];
int red[5] = {1, 3, 5, 7, 9};
int black[5] = {2, 4, 6, 8};

int score = 10;
int max_length_total = sizeof(total) / sizeof(total[0]) - 1;

void array_f(int array[], int min, int max) {//function to get information into arrays
    int i;
    for(i = min; i <= max; i++) {
        array[i] = i;
    }
}

int random_f() {
    srand(time(NULL));//the current time as the seed

    int random = total[0] + rand() % (max_length_total - total[0] + 1);//choosing the winner number
    return random;
}

int input_f() {
    int input;
    printf("eine zahl zwischen 0 und 9, 10 fuer rot und 11 fuer schwarz, 12 fuer verlassen\n");
    printf("ihre eingabe:\n>");
    scanf("%d", &input);//input for the number to bet
    getchar();

    if(input < 0 || input > 11) {
        return -1;//false input
    }
    else {
        return input;
    }
}

int scoreabzug_f() {
    int input;
    printf("score input:\n>");
    scanf("%d", &input);//input for the bet
    getchar();

    if(input > score) {
        printf("falsche eingabe\n");
        return scoreabzug_f();
    }
    else {
        score = score - input;
        return input;
    }
}

void run() {//check if you win, main function
    while(score > 0) {
        printf("aktueller score: %d\n", score);

        int input = input_f();
        int random = random_f();
        int score_input;

        if (input == -1) {
            printf("good bye");
            return;
        }
        else if (input == 10) {
            score_input = scoreabzug_f();
            printf("rot");//debugging mit for schleife jeden teil des array überprüfen
            return;//debugging
        }
        else if (input == 11) {
            score_input = scoreabzug_f();
            printf("schwarz");//debugging
            return;//debugging
        }
        else {
            score_input = scoreabzug_f();
            printf("die zahl lautet %d\n", random);
            if(input == random) {
                printf("gewonnen\n");
                score = score + score_input * 2;
            }
            else {
                printf("verloren\n");
            }
        }
    }
    printf("keine coins mehr\n");
}

int main() {
    array_f(total, 0, 36);//array gesamt
    //weitere arrays definieren
    run();
    return 0;
}