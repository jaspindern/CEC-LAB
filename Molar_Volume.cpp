#include<iostream>
#include<cmath>
    using namespace std;

float f(float x,float y, float z, float r,float t,float p){
  return (pow(x,3)-z*pow(x,2)-(r*t*pow(x,2)/p)+(y*x)/p-(y*z)/p);
}
// Derivative value of f will be given by below fun
float Df(float x,float y, float z, float r,float t,float p){
  return (3*pow(x,2)-2*z*pow(x,1)-(2*r*t*pow(x,1)/p)+y/p);
}
 int main()
{
   int phase;
   cout<<"Enter 1 for finding volume of Liquid and 0 for vapor: "<<endl;
   cin>>phase;
   float Tc;
   cout<<"Enter Critical temperature in K: "<<endl;
   cin>>Tc;
   float Pc;
   cout<<"Enter Critical Pressure in Pa: "<<endl;
   cin>>Pc;
   float P;
   cout<<"Enter Value of Pressure in Pa: "<<endl;
   cin>>P;
   float T;
   cout<<"Enter Value of temperature in K: "<<endl;
   cin>>T;
  float R=8.31446261815324;
  float a=(27*(Tc*2)*(R*2))/(64*(Pc*2));
  float b=(R*Tc)/(8*Pc);
  float V,V1;

  if(phase==1){
    V=b;
  }else{
    V=(R*T)/P;
  }

while(true){
  V1=V-f(V,a,b,R,T,P)/Df(V,a,b,R,T,P);
  if(V==V1){
    break;
  }
  V=V1;
}
cout<<"Molar Volume is: "<<V1;
    return 0;
}