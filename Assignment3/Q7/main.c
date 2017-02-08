#include <stdio.h>
#include <stdlib.h>

int str_to_num(char *str)
{
    int i, num = 0;
    for (i = 0; i < strlen(str); ++i)
    {
        num *= 10;
        num += str[i] - '0';
    }
    return num;
}

int leap_year(int year)
{
    if (year % 4) return 0;
    if ((year % 100 == 0) && (year % 400)) return 0;
    return 1;
}

int main(int argc, char *argv[])
{
    int year = str_to_num(argv[1]);
    int i, day = 1, month, mdays, flag;
    for (i = 1900; i < year; ++i)
    {
        if (leap_year(i)) day = (day + 366) % 7;
        else day = (day + 365) % 7;
    }
    mdays = str_to_num(argv[2]);
    day = (day + mdays - 1) % 7;
    for (month = 1, flag = 1; flag; ++month)
    {
        switch(month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10: if (mdays > 31) mdays -= 31;
                     else flag = 0;
                     break;

            case 2:  if (mdays > 28 + leap_year(year))
                        mdays -= 28 + leap_year(year);
                     else flag = 0;
                     break;

            case 4:
            case 6:
            case 9:
            case 11: if (mdays > 30) mdays -= 31;
                     else flag = 0;
                     break;
        }
    }
    switch(--month)
    {
        case 1: printf("Jan"); break;
        case 2: printf("Feb"); break;
        case 3: printf("Mar"); break;
        case 4: printf("Apr"); break;
        case 5: printf("May"); break;
        case 6: printf("Jun"); break;
        case 7: printf("Jul"); break;
        case 8: printf("Aug"); break;
        case 9: printf("Sep"); break;
        case 10: printf("Oct"); break;
        case 11: printf("Nov"); break;
        case 12: printf("Dec"); break;
    }
    printf(" %d, ", mdays);
    switch(day)
    {
        case 0: printf("Sunday"); break;
        case 1: printf("Monday"); break;
        case 2: printf("Tuesday"); break;
        case 3: printf("Wednesday"); break;
        case 4: printf("Thursday"); break;
        case 5: printf("Friday"); break;
        case 6: printf("Saturday"); break;
    }
}
