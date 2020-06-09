/*
 * =====================================================================================
 *
 *       Filename:  StrtoIP.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Sunday 07 June 2020 10:37:10  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>

static void PrintBinary(unsigned int Number) {
    int i=0;
    for(i=31;i>=0;i--){
        printf("%d ",(Number>>i)&1);
    }
    printf("\n");
}

int main() {
    char StrIP[32] = "",TestIP[32] = "";
    unsigned int ip = 0,testingip=0;
    int Mask = 0;
    unsigned int UpperValue=0,LowerValue=0;
    printf("Enter A Valid IP Address\n");
    scanf("%s",StrIP);
    printf("Enter Mask Value [0-32]\n");
    scanf("%d",&Mask);
    printf("Enter Match IP Address\n");
    scanf("%s",TestIP);
    printf("Entered IP: [%s]\n",TestIP);
    ip = inet_network(StrIP);
    testingip = inet_network(TestIP);
    /*Masking Process*/
    LowerValue = ip & (~((1 << (32 - Mask)) - 1));
    UpperValue = ip | ((1 << (32 - Mask)) - 1);
    PrintBinary(ip);
    PrintBinary(LowerValue);
    PrintBinary(UpperValue);
    PrintBinary(testingip);
    if(testingip >= LowerValue && testingip <= UpperValue)
        printf("[%s] IP is Matched in CIDR Range[%s/%d]\n", TestIP,StrIP,Mask);
    else
        printf("[%s] IP is not Matched in CIDR Range [%s/%d]\n", TestIP,StrIP,Mask);
}
