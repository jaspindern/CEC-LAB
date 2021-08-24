phase = float(input('If the volume for liquid phase enter 1 else 0 : '))
Tc = float(input('Enter critical temperature in Kelvin:'))
Pc = float(input('Enter critical pressure in Pa:'))
P = float(input('Enter pressure in Pa:'))
T = float(input('Enter temperature in Kelvin:'))
R = 8.31446261815324
a = (0.42748*(Tc**2.5)*(R**2))/(Pc)
b = (0.08664*R*Tc)/(Pc)

def vand(f,Df,e,max):
    if phase == 1:
        x0 = b
    else:
        x0 = ((R*T)/P)
    xn = x0
    for n in range(0,max):
        fxn = f(xn)
        if abs(fxn) < e:
            print('Found solution after',n,'iterations.')
        Dfxn = Df(xn)
        if Dfxn == 0:
            print('No solution found, zero derivative')
            return None
        xn = xn - fxn/Dfxn
    print(' No solution found,Exceeded maximum iterations.')
    print("Molar Volume = ",xn)
    print("Compressibility factor Z = ", (P*xn)/(R*T))
    return None


p = (R*T)/P
r = (a*b)/((T**0.5)*P)
q = ((b**2)+(b*p)-(r/b))
f =  lambda x: x**3 - (p*(x**2)) - q*x - r #Cubic form of Van der waal equation
Df = lambda x: 3*(x**2) - (2*p*x) - q

Value = vand(f, Df, 1e-6, 10)
print(Value)
