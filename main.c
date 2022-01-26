#include<stdio.h>
#include<ctype.h>

void SizeOfVariables(void);
int IsLeapYear(int);
int IsVowel(char);
void ReverseNumber(long);

// Task A - function retrieves the size of declared variables 
void SizeOfVariables(void){
    // declared a series of variables with different types 
    char c;
    short s;
    int i; 
    unsigned int ui;
    unsigned long int ul;
    float f; 
    double d;
    long double ld;
    void *ptr;
    
    // prints out the size in bytes of each variable along with name of the variable 
    // sizeof command returns the size of variables in bytes 
    printf("\n\nThe size of char: %zu bytes\n ",sizeof(c));
    printf("\n\nThe size of short: %zu bytes\n ", sizeof(s));
    printf("\n\nThe size of int is: %zu bytes\n",sizeof(i));
    printf("\n\nThe size of unsigned int: %zu bytes\n",sizeof(ui));
    printf("\n\nThe size of unsigned long int: %zu bytes \n",sizeof(ul));
    printf("\n\nThe size of float: %zu bytes\n",sizeof(f));
    printf("\n\nThe size of double:  %zu bytes\n", sizeof(d));
    printf("\n\nThe size of long double:  %zu bytes\n",sizeof(ld));
    printf("\n\nThe size of *ptr:  %zu bytes\n",sizeof(ptr));
    
}


// Task B -- checks to see if a given year is a leap year or not 
int IsLeapYear(int aYear){
    
    // if and else-if statements check to see if leap year conditions are met 
    if(aYear % 4 == 0 || aYear % 400 == 0 && aYear > 1752){
        printf(" \n is a LEAP YEAR! \n",aYear);
    }else if(aYear % 100 == 0){
        printf(" \n is  NOT a LEAP YEAR! \n",aYear);
    }else{
        printf(" \n is  NOT a LEAP YEAR! \n",aYear);
    }
    return 0;

}   

// Task C -- checks to see if a given character is a vowel or consonant; returns an "error" message if entered character is not in ASCII alphabet 
int IsVowel(char aLetter){
    int vowelIn;
    // defined vowelIn as the conditions needed for a vowel -- applies to both lowercase and uppercase vowels 
    vowelIn = (aLetter == 'a' || aLetter == 'A' || aLetter == 'e' || aLetter == 'E' || aLetter == 'i' || aLetter == 'I' || aLetter =='o' || aLetter =='O' || aLetter == 'u' || aLetter == 'U');
    
    // isalpha function is used to check whether a character is part of the alphabet or not -- a premade C function in the <ctype.h> library 
    // error message occurs when user enters a non-ASCII character 
    if(!isalpha(aLetter)){
        printf("Error! You entered a non-alphabetic character.");
    }
    else if(vowelIn){
        printf("\n %c is a vowel. \n", aLetter);
    // if user input is not a vowel or a non-alphabetic character, it's a consonant 
    }else{
        printf("\n %c is a consonant. \n ", aLetter);
    }
    return 0;
}

// Task D - takes in a number and outputs the reverse (for both positive and negative) 
void ReverseNumber(long aNumber){
    long reverseNum, sumNum = 0; 
    
    // used a while loop to iterate through each element of the long entry -- will iterate as long as aNumber doesn't equal 0 
    while(aNumber!=0){
        // first a modulus 10 operation is performed 
        sumNum = aNumber % 10;
        // then reverseNum is multiplied by 10 and added to whatever outputs from previous line 
        reverseNum = reverseNum * 10 + sumNum; 
        // then aNumber is divded by 10 to finally reverse the number 
        aNumber = aNumber/10;
    }
    // prints the output of the while loop, which is the reversed number 
    printf("\nThe reverse of the inputted number is %ld \n", reverseNum);
}

int main(){
    SizeOfVariables();
    int aYear;
    printf("\n\n Enter The Year: ");
    scanf("%d",&aYear);
    IsLeapYear(aYear);
   
    long aNumber; 
    printf("\nPlease enter a number: ");
    scanf("%ld", &aNumber);
    ReverseNumber(aNumber);
    
    
    char aLetter; 
    printf("Please enter a character: ");
    scanf("%c",&aLetter);
    IsVowel(aLetter);
   
}
    //int num1, num2; // declares 2 variables called num1 and num2
    //float fraction;    
    //char character;
    //char str[50];   // char array of size 50
   // printf("Enter two numbers\n"); // print f means "print formatted" 
    
    // Taking integer as input from user
    //scanf(" %d%i", &num1, &num2);
    //printf("\n\nThe two numbers You have entered are %d and %i\n\n", num1, num2);
    // Taking float or fraction as input from the user
    //printf("\n\nEnter a Decimal number\n");
   // scanf(" %f", &fraction); 
    //printf("\n\nThe float or fraction that you have entered is %f", fraction);
    // Taking Character as input from the user
   // printf("\n\nEnter a Character\n");
   // scanf(" %c",&character);
    //printf("\n\nThe character that you have entered is %c and the ASCII number is %d", character, character);
    //getchar();
    //printf("\n\nEnter your complete name:\n\n\n");
   // gets(str);
   // printf("\n\nWelcome to ECEGR 2020  %s\n\n\n", str);
   // printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    
   
    //printf("Press Enter to quit");
    //scanf("%c",&character);
    //return 0; 


