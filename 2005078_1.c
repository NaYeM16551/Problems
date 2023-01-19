#include<stdio.h>
int calender(int m,int y,int q)
{
    int x,h;

    if(m==1 || m==2)
    {
        m=m+12;
        y=y-1;
    }

    x=q+(26*(m+1))/10+y+y/4+6*(y/100)+y/400;
    h=x%7;
    printf("\n");


    if(m==13)
    {
        printf("January");
        y=y+1;
        m=m-12;

    }
    else if(m==14)
    {
        printf("February");
        y=y+1;
        m=m-12;
    }
    else if(m==3)
    {
        printf("March");
    }
    else if(m==4)
    {
        printf("April");
    }
    else if(m==5)
    {
        printf("May");
    }
    else if(m==6)
    {
        printf("June");
    }
    else if(m==7)
    {
        printf("July");
    }
    else if(m==8)
    {
        printf("August");
    }
    else if(m==9)
    {
        printf("September");
    }
    else if(m==10)
    {
        printf("October");
    }
    else if(m==11)
    {
        printf("November");
    }
    else if(m==12)
    {
        printf("December");
    }
    printf(" %d,",q);
    printf(" %d",y);
    if(h==0)
    {
        printf(" is Saturday\n");

    }
    else if(h==1)
    {
        printf(" is Sunday\n");
    }
    else if(h==2)
    {
        printf(" is Monday\n");
    }
    else if(h==3)
    {
        printf(" is Tuesday\n");
    }
    else if(h==4)
    {
        printf(" is wednesday\n");
    }
    else if(h==5)
    {
        printf(" is Thrusday\n");
    }
    else if(h==6)
    {
        printf(" is Friday\n");
    }
    printf("\n");


}
int main()
{

    int m,y,q,e;
    while(1)
    {
        printf("Enter year\n:");
        scanf("%d",&y);
        printf("Enter month(1-12)\n:");
        scanf("%d",&m);
        printf("Enter day:");
        scanf("%d",&q);

        calender(m,y,q);
        printf("Do you want to explore more?\nIf yes,press 1\nIf not,press 2\n");
        scanf("%d",&e);
        if(e==1)
        {
            printf("\n");
            continue;
        }
        else
        {
            break;
        }

    }
    return 0;
}
