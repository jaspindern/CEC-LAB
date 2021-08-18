#include<iostream>
#include<math.h>
using namespace std;
float fun1(float v,float a,float b,float r,float t,float p)
{
    return(v*v*v-(b+(r*t/p))*v*v+(a*v)/p-(a*b)/p);
}
float fun2(float v,float a,float b,float r,float t,float p)
{
    return(3*v*v-2*(b+(r*t/p))*v+(a/p));
}
int main()
{
    int guess;
    float v,v1,T,P,Tc,Pc,R;
    cout<<"Enter the Temperature in Kelvin: \n";
    cin>>T;
    cout<<"Enter the Pressure Pa: \n";
    cin>>P;
    cout<<"Enter Tc in Kelvin: \n";
    cin>>Tc;
    cout<<"Enter Pc in Pa: \n";
    cin>>Pc;
    R=8.314;
    float a = (27*R*R*Tc*Tc)/(64*Pc);
    float b = (R*Tc)/(8*Pc);
    cout<<"For initial guess for liquid phase enter 1, for vapour phase enter 2 and for any other guess enter any number\n";
    cin>>guess;
    if(guess==1)
    {
        v = b;
    }
    else
        if(guess==2)
        {
            v = R*T/P;
        }

    else
    {
            cout<<"Enter guess: ";
            cin>>v;
    }
    while(1)
    {
        v1 = v-fun1(v,a,b,R,T,P)/fun2(v,a,b,R,T,P);
        if(v1-v<pow(10,-6)&&v1-v>-pow(10,-6))
        {
            break;
        }
        v=v1;
    }
    cout<<"The Molar Volume is "<<v1;
    return 0;
}
