package BinaryTree3;

public class BinaryTree3<T> {
    private T data;
    private BinaryTree3<T> left;
    private BinaryTree3<T> right;

    public BinaryTree3() {
        this.left = null;
        this.right = null;
    }

    public T GetData() {
        return this.data;
    }

    public void SetData(T data) {
        this.data = data;
    }

    public BinaryTree3<T> GetLeftSubTree() {
        return this.left;
    }

    public BinaryTree3<T> GetRightSubTree() {
        return this.right;
    }

    public void MakeLeftSubTree(BinaryTree3<T> sub) {
        this.left = sub;
    }

    public void MakeRightSubTree(BinaryTree3<T> sub) {
        this.right = sub;
    }

    public void PreorderTraverse(VisitFunction<T> action) {
        action.VisitFunction(this.data);
        if (this.left != null)
         this.left.PreorderTraverse(action);
        if (this.right != null)
            this.right.PreorderTraverse(action);
    }

    public void InorderTraverse(VisitFunction<T> action) {
        if (this.left != null)
            this.left.InorderTraverse(action);
        action.VisitFunction(this.data);
        if (this.right != null)
            this.right.InorderTraverse(action);
    }

    public void PostorderTraverse(VisitFunction<T> action) {
        if (this.left != null)
            this.left.PostorderTraverse(action);
        if (this.right != null)
            this.right.PostorderTraverse(action);
        action.VisitFunction(this.data);
    }

    public BinaryTree3<T> RemoveLeftSubTree() {
        BinaryTree3<T> delNode = this.left;
        this.left = null;

        return delNode;
    }

    public BinaryTree3<T> RemoveRightSubTree() {
        BinaryTree3<T> delNode = this.right;
        this.right = null;

        return delNode;
    }

    public void ChangeLeftSubTree(BinaryTree3<T> sub) {
        this.left = sub;
    }

    public void ChangeRightSubTree(BinaryTree3<T> sub) {
        this.right = sub;
    }
}
