package ListBaseStack;

import ArrayBaseStack.ArrayStack;

public class ListStackMain {
    public static void main(String[] args) {
        ListStack<Integer> stack = new ListStack<>();

        stack.SPush(1); stack.SPush(2);
        stack.SPush(3); stack.SPush(4);
        stack.SPush(5);

        if (!stack.SIsEmpty()) {
            for (int i = 0; i < 3; i++)
                System.out.print(stack.SPeek()+" ");
        }
        System.out.println("\n");

        while (!stack.SIsEmpty())
            System.out.print(stack.SPop()+" ");
        System.out.println();
    }
}
