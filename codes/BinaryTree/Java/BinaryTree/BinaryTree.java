package BinaryTree;

public class BinaryTree<T> {
    private T data;
    private BinaryTree<T> left;
    private BinaryTree<T> right;

    public BinaryTree() {
        this.left = null;
        this.right = null;
    }

    public T GetData() {
        return this.data;
    }

    public void SetData(T data) {
        this.data = data;
    }

    public BinaryTree<T> GetLeftSubTree() {
        return this.left;
    }

    public BinaryTree<T> GetRightSubTree() {
        return this.right;
    }

    public void MakeLeftSubTree(BinaryTree<T> sub) {
        this.left = sub;
    }

    public void MakeRightSubTree(BinaryTree<T> sub) {
        this.right = sub;
    }
}
