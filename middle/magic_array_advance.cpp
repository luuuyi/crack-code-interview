class MagicIndex {
private:
    bool binarySearch(vector<int>& A, int l, int r){
        if(l <= r){
            int mid = l+(r-l)/2;
            if(A[mid] == mid)   return true;
            // 画图会发现，两边都要查找，但是可以排除掉一些不可能的情况
            // 优化查找事件
            else    return binarySearch(A, l, min(A[mid], mid-1)) || binarySearch(A, max(mid+1, A[mid]), r);
        }
        else    return false;
    }
public:
    bool findMagicIndex(vector<int> A, int n) {
        // write code here
        // 改进版二分查找
        return binarySearch(A, 0, n-1);
    }
};