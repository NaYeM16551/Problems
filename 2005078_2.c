#include<stdio.h>
int calender(int m, int y)
{
    int q=1,x,h,week_day=1,i,startDay,j,mday;

    printf("    Calender for:  \n");
    printf("  \n");
    if(m==1 || m==2)
    {
        m=m+12;
        y=y-1;
    }
    x=q+(26*(m+1))/10+y+y/4+6*(y/100)+y/400;
    startDay=x%7;
    if(m==13)
    {
        printf("    January,");
        y=y+1;
        m=m-12;

    }
    else if(m==14)
    {
        printf("    February,");
        y=y+1;
        m=m-12;
    }
    else if(m==3)
    {
        printf("    March,");
    }
    else if(m==4)
    {
        printf("    April,");
    }
    else if(m==5)
    {
        printf("    May,");
    }
    else if(m==6)
    {
        printf("    June,");
    }
    else if(m==7)
    {
        printf("    July,");
    }
    else if(m==8)
    {
        printf("    August,");
    }
    else if(m==9)
    {
        printf("    September,");
    }
    else if(m==10)
    {
        printf("    October,");
    }
    else if(m==11)
    {
        printf("    November, ");
    }
    else if(m==12)
    {
        printf("    December, ");
    }
    printf("%d\n",y);
    printf("  \n");
    printf("    SUN     MON      TUE      WED      THU      FRI      SAT  \n");
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        mday=31;
    }
   else if(m==4 || m==6 || m==9|| m==7 || m==9 || m==11)
    {
        mday=30;
    }
   else if (y % 400 == 0
            || (y % 4 == 0
                && y % 100 != 0))
            mday=29;
        else
            mday=28;
    if(startDay==0)
    {
        printf("                                                      ");
        week_day=7;

    }
    for (j=1; j<startDay; j++)
    {
        printf("         ");
        week_day++;
    }

    for (i=1; i<=mday; i++)
    {
        if(i<10)
        {
            printf("    %d    ",i);
            week_day++;
        }

        if(i>9)
        {
            printf("   %d    ",i);
            week_day++;
        }

        if(week_day>7)
        {
            printf("\n");
            week_day=1;

        }
    }
}
    int main()
{
	int m, y, e;
    printf("Enter year\n:");
    scanf("%d",&y);
    printf("Enter month(1-12)\n:");
    scanf("%d",&m);
    calender(m, y);

    while(1)
    {
        printf("  \n");
        printf("  \n");
        printf("Do you want to explore more?\nIf yes,press 1\nIf not,press 2\n");
        scanf("%d",&e);
        if(e==1)
        {
            printf("\n");
    		printf("Enter year\n:");
    		scanf("%d",&y);
    		printf("Enter month(1-12)\n:");
    		scanf("%d",&m);
    		printf("  \n");
            calender(m, y);
            continue;
        }
        else
        {
            break;
        }

    }
    return 0;
}





