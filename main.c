#include <stdio.h>
#define INT_SIZE sizeof(int) * 8 // this gives integer size in bits 

// function declarations 
long Factorial(long num);
int isPalindrome(long value);
int HighestBitSet(int value); 
void ReverseIt(void);
void ReverseItAgain(void);
void Pyramid(int lines); 
int binaryConvert(); 

// Task A - calculate the factorial of the given value and return the value 
long Factorial(long num){
    long fact=1;
    
    // if/else statement checks whether you can find the factorial or not 
    // can't find the factorial of anything less than or equal to zero 
    if(num <=0){
        return 0; 
    }
    // if num > 0, you can find its factorial 
    else{
        for(int a = 1; a <=num; a++){
            fact *= a; 
        }
        return fact; 
    }
}
// Task B - determine if the given value’s digits are a palindrome (a palindrome is word, number, phrase, or other sequence of characters which reads the same backward as forward) 
int isPalindrome(long value){
    long temp, reverseNum, sumNum = 0;  
    temp = value;
    // used a while loop to iterate through each element of the long entry -- will iterate as long as aNumber doesn't equal 0 
    while(value!=0){
        // first a modulus 10 operation is performed 
        sumNum = value % 10;
        // then reverseNum is multiplied by 10 and added to whatever outputs from previous line 
        reverseNum = reverseNum * 10 + sumNum; 
        // then value is divded by 10 to finally reverse the number 
        value = value/10;
    }
    if(reverseNum == temp){
        printf(" is a PALINDROME!");
    }
    else{
        printf(" is NOT a palindrome!");
    }
}

// Task C - determine the position of the highest bit that is set (0 index); Print out the value as a decimal value, in binary and the highest bit set
int HighestBitSet(int value){
    int number, order = -1; 
    for(int i=0; i < INT_SIZE; i++){
        if((number>>i) & 1){
            order = i;
        }
    }
    if(order != 1){
        printf("\n The highest order bit set in %d is %d", number, order); 
    }
    else{
        printf("0 has no bit set"); 
    }
    return 0;
}

// made a separate binary converter function that runs before HighestBitSet to provide binary equivalent 
int binaryConvert(){
    int a[10], num, y, z;
    printf("\n Please Enter a Decimal Number You want to Convert  :  ");
    scanf("%d", &num);
    
    for(y = 0; num > 0; y++){
        a[y] = num % 2;
        num = num / 2;
    }
    
    printf("\n Binary Equivalent of a Given Number =  ");
    for(z = y - 1; z >= 0; z--){
        printf(" %d ", a[z]);
    }
    printf("\n");
    return 0; 
}
// Task D - input 5 floating point values. Print them out in reverse order to that in which they were entered; Save the values to a file first in the order they were entered and in reverse order
void ReverseIt(void){
    // declare a file pointer called reversefile 
    FILE *reverseFile;
    reverseFile = fopen("Lab_2Valencia/ReverseIt.txt","w+");
    float store[5];
    // prints the inputted float values 
    printf("\n Please enter a float value: \n");
    for(int a = 0; a < 5; a++){
        float value; 
        scanf("%f",&value);
        store[a] = value; 
        fprintf(reverseFile, "%f\n",value);
    }
    // prints the reverse of inputted floats 
    for(int b = 5; b > 0; b--){
        printf("%f\n",store[b-1]);
        fprintf(reverseFile, "%f\n",store[b-1]);
    }
}
// Task E - function should open the file that was saved in (D), read the values and prints them all out.
void ReverseItAgain(void){
    FILE *reverseFile; 
    reverseFile = fopen("Lab_2Valencia/ReverseIt.txt","r"); // the "r" means to read the mentioned file 
    float n0, n1, n2, n3, n4, n5, n6, n7, n8, n9; 
    fscanf(reverseFile, "%f %f %f %f %f %f %f %f %f %f", &n0, &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8,&n9);
    printf("%f %f %f %f %f %f %f %f %f %f \n", n0, n1, n2, n3, n4, n5, n6, n7, n8,n9); 
}

// Task F - make a pyramid using asterisks depending on number the user inputs + save into a file 
void Pyramid(int lines){
    FILE *pyramidFile;
    // part 1 produces the pyramid itself, size according to user input 
   int i, space, rows, k = 0;
   printf("\n Enter the number of rows: ");
   scanf("%d", &rows);
   pyramidFile = fopen("Lab_2Valencia/pyramidFile.txt","w+");
   for (i = 1; i <= rows; ++i, k = 0) {
      for (space = 1; space <= rows - i; ++space) {
         printf("  ");
      }
      while (k != 2 * i - 1) {
         printf("* ");
         ++k;
      }
      printf("\n");
   }
    for (i = 1; i <= rows; ++i, k = 0) {
      for (space = 1; space <= rows - i; ++space) {
         fprintf(pyramidFile,"  ");
      }
      while (k != 2 * i - 1) {
         fprintf(pyramidFile,"* ");
         ++k;
      }
      fprintf(pyramidFile,"\n");
   }
}


int main(){
    // declares local long variable to test Factorial function 
    long numTest;
    printf("Enter a number to find its factorial: ");
    scanf("%ld",&numTest);
    printf("The factorial of %ld is: %ld \n",numTest,Factorial(numTest));
    
    // declare local long variables to check if they're palindromes 
    //long value; 

    // ask user for long number to check for palindrome
   // printf(" \n Please enter a number: ");
   // scanf("%ld",&value);
   // isPalindrome(value); 
    //binaryConvert(); 
    //int value; 
    //HighestBitSet(value);
    
    //ReverseIt(); 
    //ReverseItAgain();
    
    // calls Pyramid function to produce an asterisk pyramid 
    //int lines;
    //Pyramid(lines);
}

 


