#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>//zeit als seed für einen zufallsgenerator
//roulette test

int gesamt[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int rot[5] = {1, 3, 5, 7, 9};
int schwarz[5] = {2, 4, 6, 8};
int score = 10;

int random_f() {
    int min = 0;//minimale zahl
    int max = 9;//maximale zahl

    srand(time(NULL));//seed als aktuelle zeit um immer unterschiedlichen seed zu haben

    int random = min + rand() % (max - min + 1);//wählt eine zahl aus mit min und max
    return random;
}

int eingabe_f() {
    while(true) {
        int eingabe;
        printf("eine zahl zwischen 0 und 9, 10 fuer rot und 11 fuer schwarz, 12 für verlassen\n");
        printf("ihre eingabe:\n>");
        scanf("%d", &eingabe);
        getchar();

        if(eingabe < 0 || eingabe > 12) {
            return -1;
        }
        else if(eingabe == 12) {
            return -1;
        }
        else {
            return eingabe;
        }
    }
}

int scoreabzug_f() {
    int eingabe;
    printf("score input:\n>");
    scanf("%d", &eingabe);

    if(eingabe > score) {
        printf("falsche eingabe\n");
        return scoreabzug_f();
    }
    else {
        score = score - eingabe;
        return eingabe;
    }
}

int main() {
    while(score > 0) {
        printf("aktueller score: %d\n", score);

        int eingabe = eingabe_f();
        int random = random_f();
        int score_eingabe;

        if (eingabe == -1) {
            printf("good bye");
            return -1;
        }
        else if (eingabe == 10) {
            scoreabzug_f();
            printf("rot");//debugging
        }
        else if (eingabe == 11) {
            scoreabzug_f();
            printf("schwarz");//debugging
        }
        else {
            score_eingabe = scoreabzug_f();
            if(eingabe == random) {
                printf("die zahl lautet %d\n", random);
                printf("gewonnen\n");
                score = score + score_eingabe * 2;
            }
            else {
                printf("die zahl lautet %d\n", random);
                printf("verloren\n");
            }
        }
    }
    return 0;
}
