// 理解错了题意，写成了局部排序
class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        // write code here
        for(int i=0;i<n;i++){
            while(A[i] < n && A[A[i]] != A[i])  swap(A[A[i]], A[i]);
        }
        for(int i=0;i<n;i++){
            if(A[i] != i)   return false;
        }
        return true;
    }
};

// 找到其中是否存在a[i] == i
// 要求复杂度低于O(n)
class MagicIndex {
public:
    bool findMagicIndex(vector<int> A, int n) {
        // write code here
        // 考虑使用二分查找来做
        int l = 0, r = n-1;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(A[mid] == mid)    return true;
            else if(A[mid] > mid)   r = mid - 1;
            else    l = mid + 1;
        }
        return false;
    }
};