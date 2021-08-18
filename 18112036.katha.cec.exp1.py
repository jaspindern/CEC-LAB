phase = float(input('if liquid phase enter 1 else 0 '))
Tc = float(input('enter critical tempearture in kelvin '))
Pc = float(input('enter critical Pressure in Pa '))
P = float(input('enter presure in Pa '))
T = float(input('enter tempearture in kelvin '))
R = 8.314
a = (27*(Tc**2)*(R**2))/(64*(Pc**2))
b = (R*Tc)/(8*Pc)

def vand(f,Df,e,max):
    if phase==1:
        x0 = b
    else:
        x0 = ((R*T/P))
    xn = x0
    for n in range(0,max):
        fxn = f(xn)
        if abs(fxn) < e:
            print('Found solution after',n,'iterations')
        Dfxn = Df(xn)
        if Dfxn == 0:
            print('no solution found zero derivative')
            return None
        xn = xn -fxn/Dfxn
    print('no solution found exceed maximum iterations')
    print('molar volume = ',xn)
    print('compressibility Factor Z =', (P*xn)/(R*T))
    return None

p = (b+((R*T)/P))
q = a/P
r = (a*b)/P
f = lambda x: x**3 - (p*(x**2)) + q*x - r #cubic vanderwaal equation
Df = lambda x: 3*(x**2) - (2*p*x) + q
Value = vand(f,Df,1e-6,10)
print(Value)
