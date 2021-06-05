
//Mohammed Ahmed 1001655176

#include <stdio.h>
#define BITS  8

void ConvertDecimalToBinary(int num, char numbers[])
{
    
   int binary[BITS];
    
   int index = BITS - 1;
    
    while(index >= 0)
    {
        //stores least significant bit
        binary[index] = num & 1;

        index--;

        //right shift
        num >>= 1;
    }
    
    int i;
    for(i = 0; i < BITS; i++)
    {
        
        if(binary[i] == 0)
        {
            numbers[i] = 48;
        }
        else
        {
            numbers[i] = 49;
        }
        
        
    }

    
}


int main(void)
{
    
    //initializing variables
    int num1 = -1;
    int num2 = -1;
    int result = 0;
    char operand[2];
    
  
    char numbers1[BITS];
    char numbers2[BITS];
    char numbersResult[BITS];
    
    

    
    
    
    //Checks in number is betweee  0-255
    while (num1 < 0 || num1 > 255 || num2 > 255 || num2 < 0)
    {
        
        //prompt for bitwise calculator
        printf("Bitwise Calculator \n\n");
        printf("Enter two base 10 values with a bitwise operator to see the decimal result and the binary result. The format is \n\n");
        printf("FirstNumber BitwiseOperator SecondNumber \n\n");
        printf("For example, enter the expression \n\n");
        printf("2 & 3 \n\n");
        printf("This calculator can used with &, |, ^, << and >>\n\n");
        printf("Please note that the spaces between numbers and operator is essential and the two entered values must be between 0 and 255 \n\n");
        
        //Enter numbers
        printf("Enter expression:  ");
        scanf("%d %s%d", &num1, &operand[1], &num2);
        
        //checks for valid input
        
        if(!(num1 < 0 || num1 > 255 || num2 > 255 || num2 < 0))
        {
            //Checks if the right operator is typed in
                   if(operand[1] == '&' || operand[1] == '|' ||operand[1] == '<' ||operand[1] == '>' || operand[1] == '^')
                   {
                       
                       //convert operators
                       ConvertDecimalToBinary(num1, numbers1);
                       ConvertDecimalToBinary(num2, numbers2);
                       
                       
                       
                       //and
                       if(operand[1] == '&')
                       {
                           result = num1 & num2;
                           ConvertDecimalToBinary(result, numbersResult);
                           
                       }
                       
                       //or
                       if(operand[1] == '|')
                       {
                           result = num1 | num2;
                           ConvertDecimalToBinary(result,numbersResult);
                           
                       }
                       
                       //XOR
                       if(operand[1] == '^')
                       {
                           result = num1 ^ num2;
                           ConvertDecimalToBinary(result, numbersResult);
                           
                       }
                       
                       //left shift
                       if(operand[1] == '<')
                       {
                           
                           result = num1 << num2;
                           ConvertDecimalToBinary(result, numbersResult);
                           
                       }
                       
                       //right shift
                       if(operand[1] == '>')
                       {
                           
                           result = num1 << num2;
                           ConvertDecimalToBinary(result, numbersResult);
                           
                       }
                       
            
                       //prints base 10 calculation
                       printf("\nIn base 10.. \n\n");
                       
                       if(operand[1] == '<' || operand[1] == '>')
                       {
                           printf("%d %c%c %d = %d \n\n", num1,operand[1],operand[1],num2,result);
                       }
                       else
                       {
                         printf("%d %c %d = %d \n\n", num1,operand[1],num2,result);
                       }
                       
                       
                       
                       
                       //binary calculations
                       printf("In %d bit based 2...\n\n", (int)BITS);
                       
                       //output binary numbers
                       int i;
                       printf("\n");
                       
                       //prints numbers1
                       printf("   ");
                       for(i=0; i<BITS; i++)
                       {
                           printf("%c", numbers1[i]);
                       }
                       
                       //prints operator symbol
                       if(operand[1] == '<' || operand[1] == '>')
                       {
                           printf(" \n%c%c \n",operand[1],operand[1]);
                       }
                       else
                       {
                         printf(" \n%c \n",operand[1]);
                       }
                       
                       
                       //print numbers2
                       int j;
                       printf("   ");
                       for(j=0; j<BITS; j++)
                       {
                           printf("%c", numbers2[j]);
                       }
                       
                       
                       
                       //print equal sign
                       int m;
                       printf("\n");
                       printf("   ");
                       for(m = 0; m < BITS; m++)
                       {
                           printf("=");
                       }
                       printf("\n");
                       
                       
                       
                       //prints numbersResult
                       int k;
                       printf("   ");
                       for(k=0; k<BITS; k++)
                       {
                           printf("%c", numbersResult[k]);
                       }
                       
                       printf("\n\n");
                       
                       

                       
                   }
                   else
                   {
                       
                       printf("Operator %c is not supported by this calculator \n", operand[1]);
                       
                   }
            
        }
        
        
        

    
    }
    
    return 0;
}
