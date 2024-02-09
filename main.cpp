#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

//arrays for the different winner types
int total[37];
int even[30];
int odd[30];
int red[5] = {1, 3, 5, 7, 9};
int black[5] = {2, 4, 6, 8};
//1to18
//19to36

int score = 10;
int max_length_total = sizeof(total) / sizeof(total[0]) - 1;

void array_f(int array[], int min, int max, int step = 1) {//function to get information into arrays
    int i = 0;
    int n;
    for(n = min; n <= max; n += step) {
        array[i] = n;
        i++;
    }
}

int random_f() {
    srand(time(NULL));//the current time as the seed

    int random = total[0] + rand() % (max_length_total - total[0] + 1);//choosing the winner number
    return random;
}

int input_f() {
    int input;
    printf("eine zahl zwischen 0 und 9, 37 fuer rot und 38 fuer schwarz, 39 für odd, 40 für even, -1 fuer verlassen\n");
    printf("ihre eingabe:\n>");
    scanf("%d", &input);//input for the number to bet
    getchar();

    if(input < 0 || input > 40) {
        return -1;//false input
    }//bereich ändern
    else if(input == -1) {
        return -1;
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

void run() {//main function
    while(score > 0) {
        printf("aktueller score: %d\n", score);

        int input = input_f();
        int random = random_f();
        int score_input;

        if (input == -1) {
            printf("good bye");
            return;
        }
        else if (input == 37) {
            score_input = scoreabzug_f();
            printf("rot");//debugging mit for schleife jeden teil des array überprüfen
            return;//debugging
        }
        else if (input == 38) {
            score_input = scoreabzug_f();
            printf("schwarz");//debugging
            return;//debugging
        }
        else if (input == 39) {
            score_input = scoreabzug_f();
            printf("odd");//debugging
            return;//debugging
        }
        else if (input == 40) {
            score_input = scoreabzug_f();
            printf("even");//debugging
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
    //define arrays
    array_f(total, 0, 36);
    array_f(even, 2, 36, 2);
    array_f(odd, 1, 36, 2);

    run();
    return 0;
}
