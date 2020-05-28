/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: huang lam
 *
 * Created on May 27, 2020, 1:55 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 
 */
void message(int source[]) {
    //use the rand() method to have the number 4 digits from 1 to 5
    //stored to endgame[];
    int i;
    for (i = 0; i < 4; i++) {
        source[i] = i + 1; //rand() % 6 + 0;
    }
    //Display tutorial of this game
    printf("Welcome to MasterMind!!\n");
    printf("\n");
    printf("At each turns , you will enter your guess for the playing board.\n");
    printf("A valid guess ash 4 values in between 0 and 5");
    printf("Each guess will have each number within the guess separate by space.\n");
    printf("When you are ready, enter your first guess.\n");
    printf("From that point on, you will be told how many prefect and imperfect matches you have\n");
    printf("After this message you will guess again. You have 10 chance. Good luck!\n");
}

//funtion play game will compare your number with the result;

int play(int dest[]) {
    int perfect = 0, imperfect = 0;
    int i, j, k, n = 4;
    int arr[4];
    scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
    for (i = 0; i < 4; i++) {
        if (arr[i] == dest[i]) {
            perfect++;
        }
    }
    for (i = 0; i < 4; i++)
        for (j = 0; j < n; j++) {
            if (arr[j] == dest[i]) {
                imperfect++;
                for (k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
                break;
            }
        }
    printf("You guess %d perfect and %d imperfect \n", perfect, imperfect - perfect);
    if (perfect == 4) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char** argv) {
    int anwser, i, j;

    time_t start_t, end_t;
    double diff_t;
    int minute, second;
    int source[4], dest[4]; //store 4 digits nubmers
    //show tutorial and make random 4 digits number store in array
    message(source);
    //count 10 turns

    for (i = 0; i < 10; i++) {
        //play return 1 if 4 digits number you guess are same 4 digits numbers by message();
        for (j = 0; j < 4; j++) {
            dest[j] = source[j];
        }
        anwser = play(dest);

        // time will start after the first time you guess
        if (i == 0) {
            time(&start_t);
        }
        //if anwser == 1 then the you will win and the game will over
        if (anwser == 1) {
            time(&end_t);
            //diff_t is time by seconds
            diff_t = difftime(end_t, start_t);
            // convert seconds to minutes
            minute = diff_t / 60;
            second = diff_t - (minute * 60);
            printf("You have won the game in %d turn and %d:%d !!", i, minute, second);
            break;
        }
        if (i == 9) {
            printf("Sorry, you have exceeded the maximum number of turn. You lose\n");
            printf("Here is winning board:");
            int j;
            for (j = 0; j < 4; j++) {
                printf("%2d", source[j]);
            }
        }
    }

}

