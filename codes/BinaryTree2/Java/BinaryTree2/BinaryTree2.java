package BinaryTree2;

public class BinaryTree2<T> {
    private T data;
    private BinaryTree2<T> left;
    private BinaryTree2<T> right;

    public BinaryTree2() {
        this.left = null;
        this.right = null;
    }

    public T GetData() {
        return this.data;
    }

    public void SetData(T data) {
        this.data = data;
    }

    public BinaryTree2<T> GetLeftSubTree() {
        return this.left;
    }

    public BinaryTree2<T> GetRightSubTree() {
        return this.right;
    }

    public void MakeLeftSubTree(BinaryTree2<T> sub) {
        this.left = sub;
    }

    public void MakeRightSubTree(BinaryTree2<T> sub) {
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
}
