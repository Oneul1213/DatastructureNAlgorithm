package InterpolationSearch;

public class InterpolationSearchMain {
    public static void main(String[] args) {
        int[] arr = { 1, 3, 5, 7, 9 };
        int idx;

        idx = InterpolationiSearch.Search(arr, 0, arr.length-1, 7);
        if (idx == -1)
            System.out.println("탐색 실패");
        else
            System.out.println("타겟 저장 인덱스: "+idx);

        idx = InterpolationiSearch.Search(arr, 0, arr.length-1, 10);
        if (idx == -1)
            System.out.println("탐색 실패");
        else
            System.out.println("타겟 저장 인덱스: "+idx);

        idx = InterpolationiSearch.Search(arr, 1, 4, 2);
        if (idx == -1)
            System.out.println("탐색 실패");
        else
            System.out.println("타겟 저장 인덱스: "+idx);
    }
}
