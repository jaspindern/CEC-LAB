import numpy as np

P = float(input('Enter the value of system pressure in Pa: '))
comp1 = float(input('Enter composition: '))
comp2 = 1-comp1

# Antoine parameters for water
A1 = 8.140191
B1 = 1810.94
C1 = 244.485

# Anotine parameters for acetone
A2 = 4.42448
B2 = 1312.253
C2 = -32.445


def buble(f,Df,e,max_iter):
    y = ((comp1*((B1/(A1-np.log(P)))-C1))+(comp2*((B2/(A2-np.log(P)))-C2)))
    x = (np.abs(y))**0.5
    for n in range(0,max_iter):
        fx = f(x)
        if abs(fx) < e:
            print('Found solution after',n,'iterations.')
        Dfx = Df(x)
        if Dfx == 0:
            print('No solution found, zero derivative')
            return None
        x = x - fx/Dfx
    print(' No solution found,Exceeded maximum iterations.')
    print("Bubble Point Temperature = ",x)
    return None

f =  lambda x: P-(comp1*np.exp(A1 - (B1/(x+C1))))-(comp2*np.exp(A2 - (B2/(x+C2))))
Df = lambda x: (comp1 * np.exp(A1 - (B1/(x+C1))) * B1)/((x+C1)**2)-(comp2 * np.exp(A2 - (B2/(x+C2))) * B2)/((x+C2)**2)

Value = buble(f, Df, 1e-4, 300)
print(Value)