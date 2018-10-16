//
//  main.c
//  Assignment 5
//
//  Created by Mark Dietrich on 10/4/18.
//  Copyright © 2018 Mark Dietrich. All rights reserved.
//

/* 
 * This program reads in 28,29,30, or 31 integer values as temperatures from the user.
 * Upon receiving these values, the number of hot days (over 32 degrees farenheit) are calculated
 * followed by printed the temperatures into a table.
 */
#include <stdio.h>

//Define the min and max number of temperatures allowed
#define MIN_TEMPS 28
#define MAX_TEMPS 31

//Sentinal Value
#define SENTINAL_VALUE -500

//Function prototypes
int read_temps(int[]);
int hot_days(int[], int);
void print_temps(int[], int, int);

/*  This main function calls all the appropriate functoins to run the program
 * @param: void
 * @return int
 */
int main(void) {
    
    int temps[MAX_TEMPS];
    
    int numTemps = read_temps(temps);
    int hotDays = hot_days(temps, numTemps);
    print_temps(temps, numTemps, hotDays);
    
    return 0;
}

/* This function reads in the temperatures from the usre as puts them into the array.
 * It returns the number of values read in.
 * @param: int[]
 * @return int
 */
int read_temps(int data[]){
    
    int num_read = 0;
    int input_temp;
    
    puts("Enter The Temperatures For The Past Month\n");
    printf("--> Enter %i to QUIT\n",SENTINAL_VALUE);
    puts("-------------------------------------");
    
    do {
        printf("Enter Temperature %2i/(%i-%i):\t",num_read+1,MIN_TEMPS,MAX_TEMPS);
        
        if (scanf("%i",&input_temp)){
            if(input_temp == SENTINAL_VALUE){
                if(num_read >= MIN_TEMPS){
                    break;
                }else{
                    printf("--> You must enter at least %i more temperatures\n\n",MIN_TEMPS-num_read);
                }
            }else{
                data[num_read] = input_temp;
                num_read++;
            }
        }else{
            char ch;
            while((ch = getchar() != '\n'));
            puts("--> You must enter an integer value\n");
        }
    }while (num_read < MAX_TEMPS);
    
    return num_read;
}


/* This function skims through the array and determines how many values are greater than 32 degrees and returns it.
 * @param: int[], int
 * @return int
 */
int hot_days(int data[], int numTemps){
    
    int numHotDays = 0;
    
    for (int i = 0; i < numTemps; i++) {
        if(data[i] > 32){
            numHotDays++;
        }
    }
    return numHotDays;
}

/* This function prints the temperatures out to the user in a table, while also calculating the average temperature.
 * @param: int[], int, int
 * @return void
 */
void print_temps(int data[], int numTemps, int hotDays){
    
    int avgTemp = 0;
    
    printf("\n\t\tTemperatures for the month");
    for (int i = 0; i < numTemps; i++) {
        if(i % 7 == 0){
            printf("\n");
            if(numTemps>7){
                puts("-------------------------------------------------------------------------------------");
                printf("| ");
            }else{
                if(numTemps==1){
                    printf("-------------");
                }else{
                    for (int j = 0; j < numTemps; j++) {
                        if(j+1 == numTemps){
                            printf("-------------");
                        }else{
                            printf("------------");
                        }
                    }
                }
                printf("\n");
                printf("| ");
            }
        }
        if(i > 8){
            printf("(%i) %4i | ",i+1,data[i]);
            avgTemp += data[i];
        }else{
            printf("(%i) %5i | ",i+1,data[i]);
            avgTemp += data[i];
        }
    }
    
    printf("\n");
    int leftOver = numTemps % 7;
    
    if(leftOver==1){
        printf("-------------");
    }else if(leftOver == 0){
        puts("-------------------------------------------------------------------------------------");
    }else{
        for (int j = 0; j < leftOver; j++) {
            if(j+1 == leftOver){
                printf("-------------");
            }else{
                printf("------------");
            }
        }
    }
    printf("\n");
    
    avgTemp /= numTemps;
    
    printf("\tAverage Temperature:   %3i\n",avgTemp);
    printf("\tHot Days:              %3i",hotDays);
}
