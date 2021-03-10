def Fibo(n):
    if n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return Fibo(n-1) + Fibo(n-2)

for i in range(1, 15):
    print(Fibo(i), end=' ')
