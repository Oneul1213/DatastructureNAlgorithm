package BinaryTree;

public class BinaryTreeMain {
    public static void main(String[] args) {
        BinaryTree<Integer> bt1 = new BinaryTree<Integer>();
        BinaryTree<Integer> bt2 = new BinaryTree<Integer>();
        BinaryTree<Integer> bt3 = new BinaryTree<Integer>();
        BinaryTree<Integer> bt4 = new BinaryTree<Integer>();

        bt1.SetData(1);
        bt2.SetData(2);
        bt3.SetData(3);
        bt4.SetData(4);

        bt1.MakeLeftSubTree(bt2);
        bt1.MakeRightSubTree(bt3);
        bt2.MakeLeftSubTree(bt4);

        System.out.println(bt1.GetLeftSubTree().GetData());
        System.out.println(bt1.GetLeftSubTree().GetLeftSubTree().GetData());
    }
}
