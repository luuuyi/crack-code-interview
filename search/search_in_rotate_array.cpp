// 二分查找的高级应用，在旋转数组里面查找
class Finder {
private:
    int binarySearchInRotate(vector<int>& A, int s, int e, int t){
        while(s <= e){
            // 一样的先找到中点
            int mid = s+(e-s)/2;
            if(A[mid] == t) return mid;
            // 由于每个值是互异的，所以二分之后只有两种情况，一种是两端增序，一种是倒序，那么针对
            // 不同的两种情况来判断是否在这一半即可得到动态规划的边界值
            else if(t>=A[s]&&t<A[mid] || A[mid]<A[s]&&(A[mid]>t||A[s]<=t))  e = mid - 1;
            else    s = mid + 1;
        }
        return -1;
    }
public:
    int findElement(vector<int> A, int n, int x) {
        // write code here
        return binarySearchInRotate(A, 0, n-1, x);
    }
};