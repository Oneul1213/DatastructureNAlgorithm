package BinarySearchTree;

public class BinarySearchTreeMain {
    public static void main(String[] args) {
        BinarySearchTree<Integer> bstRoot = new BinarySearchTree<Integer>();
        BinaryTree3<Integer> sNode;

        bstRoot.BSTInsert(5); bstRoot.BSTInsert(8);
        bstRoot.BSTInsert(1); bstRoot.BSTInsert(6);
        bstRoot.BSTInsert(4); bstRoot.BSTInsert(9);
        bstRoot.BSTInsert(3); bstRoot.BSTInsert(2);
        bstRoot.BSTInsert(7);

        bstRoot.BSTShowAll(); System.out.println();
        sNode = bstRoot.BSTRemove(3);

        bstRoot.BSTShowAll(); System.out.println();
        sNode = bstRoot.BSTRemove(8);

        bstRoot.BSTShowAll(); System.out.println();
        sNode = bstRoot.BSTRemove(1);

        bstRoot.BSTShowAll(); System.out.println();
        sNode = bstRoot.BSTRemove(6);

        bstRoot.BSTShowAll(); System.out.println();
    }
}
