//
//  main.c
//  Assignment3
//
//  Created by Mark Dietrich on 9/17/18.
//  Copyright © 2018 Mark Dietrich. All rights reserved.
//

/* This program is a menu driven application that computes the properties of a
 * sphere (radius, surface area, circumference, and volume), given a user inputed
 * diameter. Depending on the option choice, the program will computer the specfic
 * choice, prints the value to the user, and then repeat the menu for additional operations.
 */

#include <stdio.h> //Standard library
#include <stdbool.h> //Needed for booleans
#include <math.h> //Math library

//#include "functionPrototypes.h"

//Function Prototypes
void displayMenu(void);

double getDiameter(void);

bool validateDiameter(double diameter);
bool selectionIsValid(unsigned short selection);

double computeRadius(double diameter);
double computerSurfaceArea(double radius);
double computerCircumference(double diameter);
double computerVolume(double radius);

double roundTo2Decimal(double);
void invalidTypeError(void);

void quit(void);

//Constants
#define INVALID_VALUE -1.0
#define DIAMETER_MIN 0.0
#define SELECTION_MIN 1
#define SELECTION_MAX 5

#define ERROR_INVALID_INPUT_TYPE "ERROR: Invalid input type!"
#define ERROR_INVALID_SELECTION_INPUT_RANGE "ERROR: Input must be in range 1-5!"
#define ERROR_INVALID_DIAMETER_INPUT_RANGE "ERROR: Input must be greater than or equal to 0.0!"

/* This function calls displayMenu to start off the program.
 * @param: void
 * @return: int
 */
int main(void) {
    
    displayMenu();
    quit();
    return 0;
}


/* This function will continusouly ask the user a series of options
 * until they choose to quit the program. It calls a series of other
 * functions in order to compute the selection.
 * @param: void
 * @return: void
 */
void displayMenu(void){
    
    unsigned short selection = INVALID_VALUE;
    
    do{
        puts("------------------------------------------------------------");
        puts("\t\t\t\t\t\t\tPROPTERTIES OF SPHERE");
        puts("1.  Calculate radius");
        puts("2.  Calculate surface area");
        puts("3.  Calculate circumference");
        puts("4.  Calculate volume");
        puts("5.  Quit");
        printf("\nSelect: ");
        
        if(scanf("%hu",&selection)){
            if(!selectionIsValid(selection)){
                printf("%s\n",ERROR_INVALID_SELECTION_INPUT_RANGE);
            }else{
                puts("-------------------------------");
                if(selection == 1){
                    puts("CALCULATING RADIUS...\n");
                    double radius = roundTo2Decimal(computeRadius(getDiameter()));
                    printf("The radius is: %g\n",radius);
                }else if(selection == 2){
                    puts("CALCULATING SURFACE AREA...\n");
                    double surfaceArea = roundTo2Decimal(computerSurfaceArea(computeRadius(getDiameter())));
                    printf("The surface area is: %g\n",surfaceArea);
                }else if(selection == 3){
                    puts("CALCULATING CIRCUMFERENCE...\n");
                    double circumference = roundTo2Decimal(computerCircumference(getDiameter()));
                    printf("The circumference is: %g\n",circumference);
                }else if(selection == 4){
                    puts("CALCULATING VOLUME...\n");
                    double volume = roundTo2Decimal(computerVolume(computeRadius(getDiameter())));
                    printf("The volume is: %g\n",volume);
                }
            }
        }else{
            invalidTypeError();
            puts("");
        }
    }while (selection != 5);
}


/* This function will validate whether or not the selection is within the
 * appropriate range (0 < selection < 6).
 * @param: unsigned short selection
 * @return: bool
 */
bool selectionIsValid(unsigned short selection){
    
    if(selection >= SELECTION_MIN && selection <= SELECTION_MAX){
        return true;
    }else{
        return false;
    }
}


/* This function asks for user input for the diameter. If its invalid type, error
 * will be presented. If invalid range, error will be presented.
 * @param: void
 * @return: double diameter
 */
double getDiameter(void){
    
    double diameter = INVALID_VALUE;

    while(!validateDiameter(diameter)){
        printf("Enter the diameter: ");
        if(scanf("%lg",&diameter)){
            if(!validateDiameter(diameter)){
                printf("%s\n\n",ERROR_INVALID_DIAMETER_INPUT_RANGE);
            }
        }else{
            invalidTypeError();
            puts("\n");
        }
    }
    return diameter;
}


/* This function will validate whether or not the diameter is within the
 * appropriate range (diameter >= 0.0).
 * @param: double diameter
 * @return: void
 */
bool validateDiameter(double diameter){
    
    if(diameter >= DIAMETER_MIN){
        return true;
    }else{
        return false;
    }
}


/* This function clears the input buffer and displays an invalid type error.
 * @param: void
 * @return: void
 */
void invalidTypeError(void){
    
    //Clears the inputs buffer when an incorrect type was read (in this case, char)
    char ch;
    while((ch = getchar()) != '\n');
    printf("%s",ERROR_INVALID_INPUT_TYPE);
}


/* This function rounds value to 2 decimal places.
 * @param: double value
 * @return: double
 */
double roundTo2Decimal(double value){
    return roundf(value * 100) / 100; //rounds value to nearest two decimal places
}


/* This function computes the radius.
 * @param: double diameter
 * @return: double
 */
double computeRadius(double diameter){
    return diameter/2;
}


/* This function computes the surface area.
 * @param: double radius
 * @return: double
 */
double computerSurfaceArea(double radius){
    return (4 * M_PI * pow(radius, 2)); //radius raised to the power of 2
}


/* This function computes the circumference.
 * @param: double diameter
 * @return: double
 */
double computerCircumference(double diameter){
    return M_PI * diameter;
}


/* This function computes the volume.
 * @param: double radius
 * @return: double
 */
double computerVolume(double radius){
    return 4 * M_PI / 3 * pow(radius, 3); //radius raised to the power of 3
}


/* This function prints a goodbye statement.
 * @param: void
 * @return: void
 */
void quit(void){
    puts("\n\t\t\tGoodbye!\n");
    puts("-------------------------------");
}
