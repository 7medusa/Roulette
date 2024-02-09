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
int first18[19];
int last18[19];
int red[5] = {1, 3, 5, 7, 9};
int black[5] = {2, 4, 6, 8};

int jetons = 10;
int max_length_total = sizeof(total) / sizeof(total[0]) - 1;

int array_check_f(int array[], int input) {//function, to check if a number is in a specific array
    int i;
    int max_length_array = sizeof(array);
    for(i = 0; i < max_length_array; i++) {
        if(input == array[i]) {
            return 0;
        }
    }
    return -1;
}

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
    printf("eine zahl zwischen 0 und 9, 37 fuer rot und 38 fuer schwarz, 39 für odd, 40 für even, 41 fuer die ersten 18, 42 fuer die letzten 18, -1 fuer verlassen\n");
    printf("ihre eingabe:\n>");
    scanf("%d", &input);//input for the number to bet
    getchar();

    if(input < 0 || input > 42) {
        return -1;//false input
    }
    else if(input == -1) {
        return -1;
    }
    else {
        return input;
    }
}

int jetons_f() {
    int input;
    printf("jetons input:\n>");
    scanf("%d", &input);//input for the bet
    getchar();

    if(input > jetons) {
        printf("false input\n");
        return jetons_f();
    }
    else {
        jetons -= input;
        return input;
    }
}

void run() {//main function
    while(jetons > 0) {
        printf("jetons: %d\n", jetons);

        int input = input_f();
        int random = random_f();
        int jetons_input;

        if (input == -1) {
            printf("good bye");
            return;
        }
        else if (input == 37) {
            jetons_input = jetons_f();
            printf("rot");//debugging mit for schleife jeden teil des array überprüfen
            return;//debugging
        }
        else if (input == 38) {
            jetons_input = jetons_f();
            printf("schwarz");//debugging
            return;//debugging
        }
        else if (input == 39) {
            jetons_input = jetons_f();
            printf("odd");//debugging
            return;//debugging
        }
        else if (input == 40) {
            jetons_input = jetons_f();
            printf("even");//debugging
            return;//debugging
        }
        else if(input == 41) {
            jetons_input = jetons_f();
            printf("ersten 18");
            return;
        }
        else if(input == 42) {
            jetons_input = jetons_f();
            printf("letzten 18");
            return;
        }
        else {
            jetons_input = jetons_f();
            printf("the number is %d\n", random);
            if(input == random) {
                printf("win\n");
                jetons = jetons + jetons_input * 2;
            }
            else {
                printf("loose\n");
            }
        }
    }
    printf("you dont have any jetons anymore\n");
}

int main() {
    //define arrays
    array_f(total, 0, 36);
    array_f(even, 2, 36, 2);
    array_f(odd, 1, 36, 2);
    array_f(first18, 1, 18, 1);
    array_f(last18, 19, 36, 1);

    run();
    return 0;
}
