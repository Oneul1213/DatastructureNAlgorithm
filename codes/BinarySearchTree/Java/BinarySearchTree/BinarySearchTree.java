package BinarySearchTree;

public class BinarySearchTree<T extends Comparable<T>> {
    private BinaryTree3<T> root;

    private void ShowData(T data) {
        System.out.print(data+" ");
    }

    public BinarySearchTree() {
        root = null;
    }

    public T BSTGetNodeData() {
        return this.root.GetData();
    }

    public void BSTInsert(T data) {
        BinaryTree3<T> pNode = null;
        BinaryTree3<T> cNode = this.root;

        // 단말 노드가 될 때까지 반복
        while (cNode != null) {
            // 키의 중복 방지
            if (data == cNode.GetData())
                return;

            pNode = cNode;

            if (cNode.GetData().compareTo(data) > 0)
                cNode = cNode.GetLeftSubTree();
            else
                cNode = cNode.GetRightSubTree();
        }

        BinaryTree3<T> nNode = new BinaryTree3<T>();
        nNode.SetData(data);

        if (pNode != null) {    // 루트 노드가 아닐 경우
            if (data.compareTo(pNode.GetData()) < 0)
                pNode.MakeLeftSubTree(nNode);
            else
                pNode.MakeRightSubTree(nNode);
        } else {    // 루트 노드일 경우
            this.root = nNode;
        }
    }

    public BinaryTree3<T> BSTSearch(T target) {
        BinaryTree3<T> cNode = this.root;

        while (cNode != null) {
            T cData = cNode.GetData();

            if (target.compareTo(cNode.GetData()) == 0)
                return cNode;
            else if (target.compareTo(cNode.GetData()) < 0)
                cNode = cNode.GetLeftSubTree();
            else
                cNode = cNode.GetRightSubTree();
        }

        // target을 찾지 못한 경우
        return null;
    }

    public BinaryTree3<T> BSTRemove(T target) {
        BinaryTree3<T> pVRoot = new BinaryTree3<T>();   // 가상 루트 노드(코드의 일관성을 위함)
        BinaryTree3<T> pNode = pVRoot;                  // 부모 노드
        BinaryTree3<T> cNode = this.root;               // 자식 노드
        BinaryTree3<T> dNode;                           // 삭제 대상 노드

        pVRoot.ChangeRightSubTree(this.root);

        // pNode, cNode를 갱신하며 target 찾기
        while (cNode != null && !cNode.GetData().equals(target)) {
            pNode = cNode;

            if(target.compareTo(cNode.GetData()) < 0)
                cNode = cNode.GetLeftSubTree();
            else
                cNode = cNode.GetRightSubTree();
        }

        // target을 찾지 못한 경우
        if (cNode == null)
            return null;

        dNode = cNode;

        // 삭제할 노드가 단말 노드인 경우
        if (dNode.GetLeftSubTree() == null && dNode.GetRightSubTree() == null) {
            if (pNode.GetLeftSubTree().equals(dNode))
                pNode.RemoveLeftSubTree();
            else
                pNode.RemoveRightSubTree();
        }

        // 삭제할 노드가 자식 노드 하나를 갖는 경우
        else if (dNode.GetLeftSubTree() == null || dNode.GetRightSubTree() == null) {
            BinaryTree3<T> dcNode;

            if (dNode.GetLeftSubTree() != null)   // 왼쪽 자식을 갖는 경우
                dcNode = dNode.GetLeftSubTree();
            else                                        // 오른쪽 자식을 갖는 경우
                dcNode = dNode.GetRightSubTree();

            // 자식 노드를 삭제할 노드의 부모 노드에 연결
            if (pNode.GetLeftSubTree().equals(dNode))
                pNode.ChangeLeftSubTree(dcNode);
            else
                pNode.ChangeRightSubTree(dcNode);
        }

        // 삭제할 노드가 여러 자식을 갖는 경우
        else {
            BinaryTree3<T> mNode = dNode.GetRightSubTree();     // 삭제할 노드를 대체할 노드
            BinaryTree3<T> mpNode = dNode;                      // mNode의 부모 노드
            T delData;

            // 삭제할 노드를 대체할 노드는 오른쪽 서브 트리 중 가장 작은 값을 갖는 것
            while (mNode.GetLeftSubTree() != null) {
                mpNode = mNode;
                mNode = mNode.GetLeftSubTree();
            }

            delData = dNode.GetData();
            dNode.SetData(mNode.GetData());     // 삭제 노드 대체

            // mNode의 자식 노드를 부모 노드와 연결
            if (mpNode.GetLeftSubTree().equals(mNode))
                mpNode.ChangeLeftSubTree(mNode.GetRightSubTree());
            else
                mpNode.ChangeRightSubTree(mNode.GetRightSubTree());

            // 대체가 끝난 mNode를 삭제 대상으로 지정
            dNode = mNode;
            dNode.SetData(delData);
        }

        // 루트 노드가 변경되었을 경우 root가 루트 노드를 가리키도록
        if (!pVRoot.GetRightSubTree().equals(this.root))
            this.root = pVRoot.GetRightSubTree();

        return dNode;
    }

    void BSTShowAll() {
        this.root.InorderTraverse(this::ShowData);
    }
}
