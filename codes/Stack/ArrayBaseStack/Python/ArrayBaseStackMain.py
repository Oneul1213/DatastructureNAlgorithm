import ArrayBaseStackModule as asm

stack = asm.ArrayStack()

for i in range(1, 6):
    stack.SPush(i)

if stack.SIsEmpty() is False:
    for i in range(3):
        print(stack.SPeek(), end=' ')
print()
print()

while stack.SIsEmpty() is False:
    print(stack.SPop(), end=' ')
print()
