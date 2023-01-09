#include "bits/stdc++.h"
using namespace std;
double stringToInt (string str)
{
    int index=str.find('.');
    double NewNumber=0;
    cout<<index<<endl;
    if(index!=string::npos)
    {

        for(int i=index-1;i>=0;--i)
        {
            int power=index-i-1;
            NewNumber+= (pow(10.0, power) * (str[i]-'0'));
        }
        int j=-1;
        double powerValue=0;
        for(int i=index+1;i<str.length();++i)
        {
             powerValue+=(pow(10.0, j) * (str[i]-'0'));
             cout<<powerValue<<endl;

            j--;
        }

         cout<<NewNumber<<" "<<powerValue<<endl;
         double value=NewNumber+powerValue;
         cout<<value<<endl;
         return value;


    }
    else
    {

        for(long long int i=str.length()-1;i>=0;--i)
        {
            int power=str.length()-i-1;
            NewNumber+= (pow(10.0, power) * (str[i]-'0'));
        }
        return NewNumber;

    }


}
int main()
{
    string str="111156.293";
    //double d= atof(str);
    cout<<fixed<<setprecision(3)<<stringToInt(str)<<endl;


}
