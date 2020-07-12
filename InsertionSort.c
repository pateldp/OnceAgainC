/*
 * =====================================================================================
 *
 *       Filename:  InsertionSort.c
 *
 *    Description:  Insertion Sort Method
 *
 *        Version:  1.0
 *        Created:  Sunday 12 July 2020 10:20:19  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), Diptesh Patel
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>

void PrintList (const int *list, const unsigned int len) {
    int idx;
    for(idx=0;idx<len;idx++) {
        printf("%u\t",list[idx]);
    }
    printf("\n");
}

int* InsertionSort(int *list, const unsigned int len) {
    int i,j,temp,key;
    for(i=1;i<len;i++) {
        key = list[i];
        for(j=i-1;j>=0 && list[j] > key;j--){
            list[j+1] = list[j];
        }
        list[j+1] = key;
    }
}


int main () {
    int list[] = {2,4,1,6,9,5,10,8,3,7};
    printf("---- Unsorted List ----\n");
    unsigned int len = sizeof(list)/sizeof(int);
    PrintList(list,len);
    if(!InsertionSort(&list,len)) {
        printf("Error in Sorting Numbers");
    } else {
        printf("---- Sorted List ----\n");
        PrintList(list,len);
    }
    return 0;
}
