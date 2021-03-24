#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
	Stack stack;
	int i;

	StackInit(&stack);

	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);

	if (!SIsEmpty(&stack))
		for (i = 0; i < 3; i++)
			printf("%d ", SPeek(&stack));
	printf("\n\n");

	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));
	printf("\n");
	
	return 0;
}