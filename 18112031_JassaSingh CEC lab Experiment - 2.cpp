#include<iostream>
#include<math.h>
using namespace std;
float fun1(float V,float a,float b,float R,float T,float P)
{
    return(pow(V,3)-R*T*pow(V,2)/P-V*(pow(b,2)+b*R*T/P-a/(pow(T,0.5)*P))-a*b/(pow(T,0.5)*P));
}
float fun2(float V,float a,float b,float R,float T,float P)
{
    return(3*pow(V,2)-(2*V*R*T)/P-pow(b,2)-(b*R*T)/P+a/(P*pow(T,0.5)));
}
int main()
{
    float v,v1,T,P,Tc,Pc,R;
    cout<<"Enter the Temperature in Kelvin: "<<'\n';
    cin>>T;
    cout<<"Enter the Pressure in Pa: "<<'\n';
    cin>>P;
    cout<<"Enter Tc in Kelvin: "<<'\n';
    cin>>Tc;
    cout<<"Enter Pc in Pa: "<<'\n';
    cin>>Pc;
    R=8.314;
    float a = (0.42748*pow(R,2)*pow(Tc,2.5))/Pc;
    float b = (0.08664*R*Tc/Pc);
    v = b;
    while(1)
    {
        v1 = v-fun1(v,a,b,R,T,P)/fun2(v,a,b,R,T,P);
        if(v1-v<pow(10,-6)&&v1-v>-pow(10,-6))
        {
            break;
        }
        v=v1;
    }
    cout<<"Molar Volume of saturated liquid water is: "<<v1;
    v = R*T/P;
    while(1)
    {
        v1 = v-fun1(v,a,b,R,T,P)/fun2(v,a,b,R,T,P);
        if(v1-v<pow(10,-6)&&v1-v>-pow(10,-6))
        {
            break;
        }
        v=v1;
    }
    cout<<"\nMolar Volume of saturated water vapour is: "<<v1;
    return 0;
}

