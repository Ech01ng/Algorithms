/*
[Assignment 1]

Program Description: A Menu Driven, C Program to help Bank customers manage their Personal Identification Number (PIN) on an Automated Teller Machine (ATM).

{ORIGINAL USER DEFAULT PIN = 1234}

Author : Joshua Sunil Mathew C22419706

Date of Completion  : 17/11/2022
*/

#include <stdio.h>
#include <stdlib.h>

// default pin as a global variable
int pin = 1234;

int main()
{ 
  int sel, pin1, pin2;
  int rightcounter = 0;
  int wrongcounter = 0;
  char choice;

// infinite loop displaying the menu, unless broken.
while (1) 
{ 
// prints menu and its 4 options.
    printf("\n\v\t---------ATM SERVICES---------\n\nPlease select an option, 1, 2, 3 or 4.\n\n");
    printf("1. Enter PIN and Verify Correct\n\n");
    printf("2. Change PIN\n\n");
    printf("3. Display the number of times PIN was entered (i) SUCESSFULLY and INCORRECTLY\n\n");
    printf("4. Exit Program\n\n");
      
// taking user input for option selection
    scanf("%d", &sel);
       
// Avoiding Character Input. 
    if (sel == getchar())
    { 
// this will make sure any character inputted will be assigned to the value of 0 - which is an invalid input - cancels out any character
        sel = (0);
    } // end if

   
  switch (sel)
  { // begin switch(sel)
        
// OPTION 1 - Enter and Verify PIN
    case 1:
    { // begin case 1

// prints instructions
      printf("Enter your 4 digit PIN: \n\n");

// The user should input the default PIN
      scanf("%d", &pin2);

// Avoiding Character Input. 
    if (pin,pin1,pin2 == getchar())
    { 
// this will make sure any character inputted will be assigned to the value of 0 - which is an invalid input - cancels out any character
        pin,pin1,pin2 = (0);
    }

// the following IF statements check whether PIN is more or less than 4 digits (range)
      if (pin > 9999)
      {
        printf("PIN cannot be more or less than 4 DIGITS! \nPlease try again!");
        wrongcounter++;
        continue;
      }// end if
      
      if (pin <= 999)
      {
        printf("PIN cannot be more or less than 4 DIGITS! \nPlease try again!");
        wrongcounter++;
        continue;
      }// end if

// Default Pin Verification 
      if (pin2 == pin)
      {
        printf("PIN Entered Succesfully");
        rightcounter++;
        continue;
      }

      else 
      {
        printf("PIN Entered Incorrect");
        wrongcounter++;
        break;
      }
      
// Verifying the Changed Pin to the Existing Pin. - option 2 
      if (pin == pin2) 
      { 
        printf("PIN Entered Succesfully");
        rightcounter++;
        continue;
      }// end if
      
// Verification - Incorrect
      else
      {
        printf("PIN Entered Incorrect");
        wrongcounter++;
        break;
      }  // end else
    } // end case 1

// taking user input for option selection
scanf("%d", &sel);
// Avoiding Character Input. 
    if (sel == getchar())
    { 
// this will make sure any character inputted will be assigned to the value of 0 - which is an invalid input - cancels out any character
        sel = (0);
    } // end if
      
// OPTION 2 - Changing PIN  
    case 2: 
    { // instructions
      printf("Please enter your new PIN: \n\n");
      scanf("%d", &pin1);

// the following IF statements check whether PIN is more or less than 4 digits (range)
      if (pin1 > 9999)
      {
        printf("Pin Either too Large or Invalid! \nPlease try again!");
        continue;
      }// end if
        
      if (pin1 <= 999)
      {
        printf("Pin Either too Small or Invalid! \nPlease try again!");
        continue;
      }// end if

// getting user to verify their changed PIN
      printf("Please verify your new PIN: \n\n");
      scanf("%d", &pin2);

// IF BOTH PINS EQUAL EACH OTHER - THEN IT CAN BE VERIFIED CORRECT
      if (pin1 == pin2) 
      {
        
// pin is assigned to existing pin
        pin = pin2;
        printf("PIN has been changed Succesfully");
        printf("\nYour New PIN is: %d", pin);
        
        break;
      } // end if 

      else 
      {
        printf("PIN does not match, try again!");
        break;
      } // end else
    } // end case 2

// taking user input for option selection
scanf("%d", &sel);
// Avoiding Character Input. 
    if (sel == getchar())
    { 
// this will make sure any character inputted will be assigned to the value of 0 - which is an invalid input - cancels out any character
        sel = (0);
    } // end if

// OPTION 3 - Displaying the number of incorrect and correct times the PIN has been entered. 
    case 3:
    {
      printf("\vDisplaying...\n");
      printf("\n (i) Total Successful attempts: %d, (ii) Total Incorrect attempts: %d", rightcounter, wrongcounter);
      break;
    } // end case 3
          

// taking user input for option selection
scanf("%d", &sel);
// Avoiding Character Input. 
    if (sel == getchar())
    { 
// this will make sure any character inputted will be assigned to the value of 0 - which is an invalid input - cancels out any character
        sel = (0);
    } // end if

//  OPTION 4 - to terminate the program gracefully. 
    case 4: 
    { // prints instructions for the user.
      printf("Are you sure you would like to exit the program?\n");
      printf("\n\tInput Y for YES, to Exit");
      printf("\n\tInput N for NO, to return back to main menu\n");
      scanf("%c", &choice);
          
// if user wants to exit the program    
      if (choice == 'y' || choice == 'Y')
      {
        printf("\nThank you for using ATM SERVICES \n\nProgram terminating gracefully...");
        
// Program Terminates
        exit(0);
      } //end if

// if user does not want to exit the program
      if (choice == 'n' || choice == 'N')
      {
        printf("\nreturning back to main menu...");
      } //end if

    } // end case 4
    
// to catch invalid selection of options i.e everything else inputted apart from 1 to 4 when selecting options.
    default:
    {
      printf("\nInvalid Option Entered! Please Try Again.");
      break;
    
    } // end default

  } // endswitch

} // endwhile

  
return 0;
} // endMain