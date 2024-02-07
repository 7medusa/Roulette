#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>//zeit als seed für einen zufallsgenerator
//roulette test

int gesamt[37];
int rot[5] = {1, 3, 5, 7, 9};
int schwarz[5] = {2, 4, 6, 8};
int score = 10;
int max_length_gesamt = sizeof(gesamt) / sizeof(gesamt[0]) - 1;

void array_f(int array[], int min, int max) {
    int i;
    for(i = min; i <= max; i++) {
        array[i] = i;
    }
}

int random_f() {
    srand(time(NULL));//seed als aktuelle zeit um immer unterschiedlichen seed zu haben

    int random = gesamt[0] + rand() % (max_length_gesamt - gesamt[0] + 1);//wählt eine zahl aus mit min und max, min und max später ändern
    return random;
}

int eingabe_f() {
    int eingabe;
    printf("eine zahl zwischen 0 und 9, 10 fuer rot und 11 fuer schwarz, 12 fuer verlassen\n");
    printf("ihre eingabe:\n>");
    scanf("%d", &eingabe);
    getchar();

    if(eingabe < 0 || eingabe > 11) {
        return -1;
    }
    else {
        return eingabe;
    }
}

int scoreabzug_f() {
    int eingabe;
    printf("score input:\n>");
    scanf("%d", &eingabe);
    getchar();

    if(eingabe > score) {
        printf("falsche eingabe\n");
        return scoreabzug_f();
    }
    else {
        score = score - eingabe;
        return eingabe;
    }
}

void run() {
    while(score > 0) {
        printf("aktueller score: %d\n", score);

        int eingabe = eingabe_f();
        int random = random_f();
        int score_eingabe;

        if (eingabe == -1) {
            printf("good bye");
            return;
        }
        else if (eingabe == 10) {
            score_eingabe = scoreabzug_f();
            printf("rot");//debugging mit for schleife jeden teil des array überprüfen
            return;//debugging
        }
        else if (eingabe == 11) {
            score_eingabe = scoreabzug_f();
            printf("schwarz");//debugging
            return;//debugging
        }
        else {
            score_eingabe = scoreabzug_f();
            printf("die zahl lautet %d\n", random);
            if(eingabe == random) {
                printf("gewonnen\n");
                score = score + score_eingabe * 2;
            }
            else {
                printf("verloren\n");
            }
        }
    }
    printf("keine coins mehr\n");
}

int main() {
    array_f(gesamt, 0, 36);//array gesamt
    //weitere arrays definieren
    run();
    return 0;
}
