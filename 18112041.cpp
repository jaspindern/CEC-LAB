#include<iostream>
#include<math.h>
using namespace std;
float f(float v,float a,float b,float r,float t,float p)
{
return(v*v*v-(b+(r*t/p))*v*v+(a*v)/p-(a*b)/p);
}
float f1(float v,float a,float b,float r,float t,float p)
{
return(3*v*v-2*(b+(r*t/p))*v+(a/p));
}
int main(){
int z;
float v,v1,T,P,Tc,Pc,R;
cout<<"Enter Temperature: "<<endl;
cin>>T;
cout<<"Enter Pressure: "<<endl;
cin>>P;
cout<<"Enter Tc: "<<endl;
cin>>Tc;
cout<<"Enter Pc: "<<endl;
cin>>Pc;
cout<<"Enter R: "<<endl;
cin>>R;
float a = (27*R*R*Tc*Tc)/(64*Pc);
float b = (R*Tc)/(8*Pc);
cout<<"Enter initial guess:1 for b or 2 for RT/P or any other number for own guess"<<endl;
cin>>z;
if(z==1)
{
    v = b;
}
else
    if(z==2)
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
    v1 = v-f(v,a,b,R,T,P)/f1(v,a,b,R,T,P);
    if(v1-v<pow(10,-6)&&v1-v>-pow(10,-6))
    {
        break;
    }
    v=v1;
}
cout<<"Molar Volume is "<<v1;
return 0;
}
