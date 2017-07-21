class FindPair {
public:
    int countPairs(vector<int> A, int n, int sum) {
        // write code here
        // 经典的k-sum题目，这个k取2的情况是最简单的情况
        sort(A.begin(), A.end());
        int ret = 0;
        for(int i=0;i<n;i++){
            // 固定一边夹逼就好了
            int right = n - 1;
            while(i < right){
                if(A[i] + A[right] == sum){  ret++; right--;}
                else if(A[i] + A[right] > sum)  right--;
                else    break;
            }
        }
        return ret;
    }
};