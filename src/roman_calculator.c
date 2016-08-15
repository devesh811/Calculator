#include "roman_calculator.h"
#define size 100

static int i = 0;
char *roman_result;

//Helper functions
void convert_to_roman(int);
int convert_to_decimal(char *);
void roman_string(char *, int);
void roman_string_odd(char *, char *);
int digitValue(char c);

char* addition_operation(char *input_num1, char *input_num2)
{
    i = 0;
    int result = 0;
    roman_result = malloc(size);
    
    //Converts roman to decimal
    int num1 = convert_to_decimal(input_num1);
    int num2 = convert_to_decimal(input_num2);

    result = num1 + num2;

    //Converts decimal to roman
    convert_to_roman(result);

    return roman_result;
}

char* subtraction_operation(char *input_num1, char *input_num2)
{
    i = 0;
    int result = 0;
    roman_result = malloc(size);

    //Converts roman to decimal
    int num1 = convert_to_decimal(input_num1);
    int num2 = convert_to_decimal(input_num2);
    
    if (num1 < num2)
        return "";

    else
    {
        result = num1 - num2;
	//Converts roman to decimal
        convert_to_roman(result);
    }
    return roman_result;
}

int convert_to_decimal(char *input1)
{
    int k = 0;
    char input[size];
    strcpy(input,input1);
    int number = 0;
    while(input[k]){
        if(digitValue(input[k]) >= digitValue((input[k + 1])))
            number = number + digitValue(input[k]);
         else
         {
            number = number + (digitValue((input[k + 1])) - digitValue(input[k]));
             k++;
         }
         k++;
    }
    return number;
}

int digitValue(char c){

    int value=0;

    switch(c)
	{
         case 'I': value = 1; break;
         case 'V': value = 5; break;
         case 'X': value = 10; break;
         case 'L': value = 50; break;
         case 'C': value = 100; break;
         case 'D': value = 500; break;
         case 'M': value = 1000; break;
         case '\0': value = 0; break;
         default: value = 0;
    }

    return value;
}
void convert_to_roman(int result)
{

    while(result != 0)
    {
         if(result >= 1000)
         {
             roman_string("M",result/1000);
             result = result - (result/1000) * 1000;
         }
         else if(result >=500)
         {
             if(result < (500 + 4 * 100))
             {
                 roman_string("D",result/500);
                 result = result - (result/500) * 500;
             }
             else
             {
                 roman_string_odd("C","M");
                 result = result - (1000-100);
             }
         }
         else if(result >=100)
         {
             if(result < (100 + 3 * 100))
             {
                 roman_string("C",result/100);
                 result = result - (result/100) * 100;
             }
             else
             {
                 roman_string_odd("L","D");
                 result = result - (500-100);
             }
         }
         else if(result >=50)
         {
             if(result < (50 + 4 * 10))
             {
                 roman_string("L",result/50);
                 result = result - (result/50) * 50;
             }
             else
             {
                 roman_string_odd("X","C");
                 result = result - (100-10);
             }
         }
         else if(result >=10)
         {
             if(result < (10 + 3 * 10))
             {
                 roman_string("X",result/10);
                 result = result - (result/10) * 10;
             }
             else
             {
                 roman_string_odd("X","L");
                 result = result - (50-10);
             }
         }
         else if(result >=5)
         {
             if(result < (5 + 4 * 1))
             {
                 roman_string("V",result/5);
                 result = result - (result/5) * 5;
             }
             else
             {
                 roman_string_odd("I","X");
                 result = result - (10-1);
             }
         }
         else if(result >=1)
         {
             if(result < 4)
             {
                 roman_string("I",result/1);
                 result = result - (result/1) * 1;
             }
             else
             {
                 roman_string_odd("I","V");
                 result = result - (5-1);
             }
         }
    }

}

//Helper Functions
void roman_string(char *a, int n)
{
    for (int j= 0; j < n; j++)
        roman_result[i++] = *a;
}

void roman_string_odd(char *a, char *b)
{
    roman_result[i++] = *a;
    roman_result[i++] = *b;
}
