/*
 * =====================================================================================
 *
 *       Filename:  SettingSunProblem.c
 *
 *    Description:  This problem was asked by Mailchimp.
 *
 *    You are given an array representing the heights of neighboring buildings on a city street, from east to west. The city assessor would like you to write an algorithm that returns how many of these buildings have a view of the setting sun, in order to properly value the street.
 *
 *    For example, given the array [3, 7, 8, 3, 6, 1], you should return 3, since the top floors of the buildings with heights 8, 6, and 1 all have an unobstructed view to the west.
 *
 *    Can you do this using just one forward pass through the array?
 *
 *        Version:  1.0
 *        Created:  Saturday 13 June 2020 11:11:02  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include<stdio.h>

int main()
{
    unsigned int building_floors[] = {3, 7, 8, 10, 6, 7};
    int idx=0;
    unsigned int max_floors=0, total_buildings=0;
    for(idx = (sizeof(building_floors)/sizeof(unsigned int))-1;idx>=0;idx--)
    {
        if(max_floors < building_floors[idx]) {
            printf("%u\t",building_floors[idx]);
            max_floors = building_floors[idx];
            total_buildings++;
        }
    }
    printf("\n");
    printf("There are %u buildings which can view the sunset\n",total_buildings);
}
