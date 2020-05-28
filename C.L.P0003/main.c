/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: huang lam
 *
 * Created on May 26, 2020, 11:42 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
//read data from file database.txt
float loadData(){
    FILE * fptr;
    float cash;
    fptr = fopen("database.txt","r");
    if(fptr == NULL){ //if database not exist => new game
        cash = 10.00;
    }else{
        fscanf(fptr,"%f",&cash);
        if(cash == 0){
            cash = 10.00;
        }
    }
    fclose(fptr);
    return cash;
}
//main screen 
int mainScreen(float cash){
    int choose;
    printf("You have $%0.2f\n",cash);
    printf("Choose one of the following menu options:\n");
    printf("1) Play the slot machine.\n");
    printf("2) Save game.\n");
    printf("3) Cash out.\n");
    scanf("%d",&choose);
    return choose;
}

//funtion1: play game
void playGame(float *money){ 
    //use pointer money to change value of cash in funtion main
    float cash = *money;
    cash-=0.25; //- 25 cent each turn
    int random = rand()% 1000+ 99; // random number 99 to 1000 => will have 3 digits
    printf("The slot machine shows %d\n",random);
    int arr[3],i=0; //use array to separate digits numbers
    do{
        arr[i] = random%10;
        random /=10;
        i++;
    }while(random>0);
    //use if to compare 3 digits numbers
    if(arr[0]==arr[1]||arr[1]==arr[2]||arr[2]==arr[0]){ // 2 digits are same
        cash += 0.5;
        if(arr[0]==arr[1]==arr[2]){ // 3 digits are same
            cash += 9.5;
            printf("You win the big prize, $10.00!\n");
        }else{
            printf("You win 50 cents!\n");
        }
    }else{
        printf("Sorry you don't win anything!\n");
    }
    *money = cash; // return value for cash in main function update
}
void saveGame(float cash){
    FILE * fptr;
    // open database.txt to save data
    fptr = fopen("database.txt","w");
    if(fptr == NULL){
        printf("Can't save data!\n");
    }else{
        fprintf(fptr,"%0.2f",cash);
        printf("Your money had saved!\n");
    }
    fclose(fptr);
}
void cashOut(float cash){
    //just print good bye
    printf("Thank you for playing! You end with $%0.2f!\n",cash);
}
int main(int argc, char** argv) {
    int i;
    float *p,cash;
    p = &cash;
    cash = loadData();
    do{
        i=1;
        int choose = mainScreen(cash);
        switch(choose){
            case 1: playGame(&cash);
            break;
            case 2: saveGame(cash);
            break;
            case 3: cashOut(cash);
            i= 0;// break out do while loop
            break;
            default: printf("Choose again!\n");
        }
        if(cash == 0){
            i = 0;
            printf("Sorry you don't have any money to play more! Good bye...\n");
        }
    }while(i==1);
    return (EXIT_SUCCESS);
}

