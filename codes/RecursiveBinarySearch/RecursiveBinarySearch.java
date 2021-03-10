class BSearchRecur{
    public int BSearchRecur(int[] ar, int first, int last, int target){
        int mid;
        if (first > last)
            return -1;
        mid = (first + last) / 2;

        if (ar[mid] == target)
            return mid;
        else if (target < ar[mid])
            return BSearchRecur(ar, first, mid-1, target);
        else
            return BSearchRecur(ar, mid+1, last, target);
    }
}

public class RecursiveBinarySearch {
    public static void main(String[] args){
        BSearchRecur bs = new BSearchRecur();
        int[] arr = {1, 3, 5, 7, 9};
        int idx;

        idx = bs.BSearchRecur(arr, 0, arr.length-1, 7);
        if(idx == -1)
            System.out.println("탐색 실패");
        else
            System.out.println("타겟 저장 인덱스: "+idx);

        idx = bs.BSearchRecur(arr, 0, arr.length-1, 4);
        if(idx == -1)
            System.out.println("탐색 실패");
        else
            System.out.println("타겟 저장 인덱스: "+idx);
    }
}
