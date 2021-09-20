#include<iostream>
#include<conio.h>
#include<math.h>
 using namespace std;
 int main()
{
   float  p,p1sat,p2sat,p1satn,t1sat,t2sat,t,tn,x1,x2,f,f1;
   float a1=14.39155,b1=2795.317,c1=230.002,a2=16.26205,b2=3799.887,c2=226.346;
   cout<<"Enter pressure in KPa: "<<endl;
   cin>>p;
   cout<<"Enter mole fraction of component 1:"<<endl;
   cin>>x1;
   x2=1-x1;
   t1sat=(b1/(a1-log(p)))-c1;
   t2sat=(b2/(a2-log(p)))-c2;
   tn=x1*t1sat+x2*t2sat;
   do{
       t=tn;
       p1sat=exp(a1-b1/(t+c1));
       p2sat=exp(a2-b2/(t+c2));
       f=p-x1*p1sat-x2*p2sat;
       f1=-(x1*p1sat*b1/((t+c1)*(t+c1)))-(x2*p2sat*b2/((t+c2)*(t+c2)));
       tn=t-f/f1;
   }while(fabs(tn-t)>1e-6);

   cout<<"The bubble point is: "<<tn;
  

    return 0;
}