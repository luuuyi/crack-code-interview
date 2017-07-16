class AntiOrder {
private:
    int _ret;
    void mergeArray(vector<int>& A, int s, int mid, int e, vector<int>& help){
        int x = mid, y = e, z = 0;
        // 这里有别于一般的归并排序框架，从后往前计算，并不是从前往后计算
        while(x>=s&&y>=mid+1){
            if(A[x]<=A[y])   help[z++] = A[y--];
            else{    help[z++] = A[x--]; _ret += y-mid;}
        }
        while(x>=s)   help[z++] = A[x--];
        while(y>=mid+1) help[z++] = A[y--];
        for(int i=s;i<=e;i++)   A[i] = help[--z];
    }
    void mergeSort(vector<int>& A, int s, int e, vector<int>& help){
        // 归并排序这个位置要选择小于才符合条件，不用等于
        if(s < e){
            int mid = s+(e-s)/2;
            mergeSort(A, s, mid, help);
            mergeSort(A, mid+1, e, help);
            mergeArray(A, s, mid, e, help);
        }
        return;
    }
public:
    int count(vector<int> A, int n) {
        // write code here
        vector<int> help(n); _ret = 0;
        mergeSort(A, 0, n-1, help);
        return _ret;
    }
};