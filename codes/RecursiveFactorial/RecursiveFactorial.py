def Factorial(n):
    if n == 0:
        return 1
    else:
        return n * Factorial(n-1)

print("1! = {}".format(Factorial(1)))
print("2! = {}".format(Factorial(2)))
print("3! = {}".format(Factorial(3)))
print("4! = {}".format(Factorial(4)))
print("9! = {}".format(Factorial(9)))
