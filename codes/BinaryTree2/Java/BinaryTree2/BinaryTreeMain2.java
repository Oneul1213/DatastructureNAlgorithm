package BinaryTree2;

public class BinaryTreeMain2 {
    public static void main(String[] args) {
        BinaryTree2<Integer> bt1 = new BinaryTree2<Integer>();
        BinaryTree2<Integer> bt2 = new BinaryTree2<Integer>();
        BinaryTree2<Integer> bt3 = new BinaryTree2<Integer>();
        BinaryTree2<Integer> bt4 = new BinaryTree2<Integer>();
        BinaryTree2<Integer> bt5 = new BinaryTree2<Integer>();
        BinaryTree2<Integer> bt6 = new BinaryTree2<Integer>();

        bt1.SetData(1);
        bt2.SetData(2);
        bt3.SetData(3);
        bt4.SetData(4);
        bt5.SetData(5);
        bt6.SetData(6);

        bt1.MakeLeftSubTree(bt2);
        bt1.MakeRightSubTree(bt3);
        bt2.MakeLeftSubTree(bt4);
        bt2.MakeRightSubTree(bt5);
        bt3.MakeRightSubTree(bt6);

        bt1.PreorderTraverse((a)->System.out.print(a+" "));
        System.out.println();
        bt1.InorderTraverse((a)->System.out.print(a+" "));
        System.out.println();
        bt1.PostorderTraverse((a)->System.out.print(a+" "));
        System.out.println();
    }
}
