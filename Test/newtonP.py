def newton(x, y, t):
    value = 0
    norm = 1
    for i in range(len(y)):
        for j in range(i):
            norm *= (t - x[j])
        value += (coef(x, y, i) * norm)
        norm = 1
    return value

def coef(x, y, n):
    denom = 1
    num = y[n]
    norm = 1
    
    if(n == 0):
        return num
    
    for i in range(n):
        for j in range(i):
            norm *= (x[n] - x[j])
        denom *= (x[n]-x[i])
        num -= (coef(x, y, i) * norm)
        norm = 1
    
    return (num/denom)
