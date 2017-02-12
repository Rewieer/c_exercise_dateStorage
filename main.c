#include <stdio.h>
#include <stdlib.h>

/*
31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  M  M  M  M  M  M  M M D D D D D D D D

This is not the most efficient way to store because months can go from 0 to 11 (4 bits) and
days can go from 0 to 31 (5 bits).
We could have dates of 23 bits and represent 8 million dates.

It easy to compare because the most significants digits of the date are on the left
(that is the year) and the least significants digits are on the right (the day).

TODO : work it
31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y  Y M M M M M D D D D
*/

int storeDate(int year, int month, int day){
    int finalNumber = year << 16;
    month = month << 8;
    finalNumber += month;
    finalNumber += day;

    return finalNumber;
}

int getDayFromDate(int date){
    return date & 0x000000FF;
}

int getMonthFromDate(int date){
    return (date >> 8) & 0x000000FF;
}

int getYearFromDate(int date){
    return (date >> 16) & 0x0000FFFF;
}

int askForDate(){
    int year = 0, month = 0, day = 0;
    printf("Enter the day, the month and the year\n");
    scanf("%d %d %d", &day, &month, &year);

    return storeDate(year, month, day);
}

int main()
{
    int currentDate = askForDate();

    printf("The number is %d\n", currentDate);
    printf("Day : %d\n", getDayFromDate(currentDate));
    printf("Month : %d\n", getMonthFromDate(currentDate));
    printf("Year : %d\n", getYearFromDate(currentDate));

    int secondDate = askForDate();

    if(secondDate > currentDate){
        printf("Your last date is after your first date\n");
    } else if(secondDate < currentDate){
        printf("Your last date is before your first date\n");
    } else {
        printf("You basically entered the same dates\n");
    }

    return 0;
}
