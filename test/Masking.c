/*
 * =====================================================================================
 *
 *       Filename:  Masking.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 07 June 2020 11:05:34  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>

static void PrintBinary(unsigned int Number) {
    int i=0;
    for(i=31;i>=0;i--){
        printf("%d ",(Number>>i)&1);
    }
    printf("\n");
}


int main() {
    unsigned int Mask;
    unsigned int LowerValue;
    printf("Enter Mask Vale [0-32]\n");
    scanf("%i",&Mask);
    LowerValue = (1 << (32 - Mask)) - 1;
    PrintBinary(LowerValue);
}
