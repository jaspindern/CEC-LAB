#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    float p, p1Sat, p2Sat, t1Sat, t2Sat;
    float T1, T2, x1, x2, y1, y2, z1, a1, b1, c1, a2, b2, c2;
    float f,f1;
    cout<<"\nEnter the mole fraction of acetone : ";
    cin>>z1;
    cout<<"\nEnter the pressure in kPa : ";
    cin>>p;

    a1=14.39155;
    b1=2795.317;
    c1=230.002;
    a2=16.26205;
    b2=3799.887;
    c2=226.346;

    x1=z1;
    x2=1-z1;
    t1Sat=b1/(a1-log(p))-c1;
    t2Sat=b2/(a2-log(p))-c2;
    T2=x1*t1Sat+x2*t2Sat;
    do
    {
        T1=T2;
        p1Sat=exp(a1-b1/(T1+c1));
        p2Sat=exp(a2-b2/(T1+c2));
        f=p-x1*p1Sat-x2*p2Sat;
        f1=-x1*p1Sat*b1/((T1+c1)*(T1+c1))-x2*p2Sat*b2/((T1+c2)*(T1+c2));
        T2=T1-f/f1;

    }
    while(fabs(T2-T1)>1e-4);
    cout<<"\nThe bubble point temperature is : "<<T2;
}
