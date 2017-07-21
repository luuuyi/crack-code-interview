// 只要改变区间中的值就使得整个数组有序了,并不是计算不同的区间中,哪一个最小
// 简单的做法,排序以后对比,但是时间复杂度为排序的复杂度
class Rearrange {
public:
    vector<int> findSegment(vector<int> A, int n) {
        // write code here
        if(n <= 0)  return vector<int>({-1, -1});
        vector<int> tmp(A);
        sort(tmp.begin(), tmp.end());
        int start = 0, end = 0;
        for(int i=0;i<n;i++){
            if(A[i] != tmp[i]){  start = i; break;}
        }
        for(int i=n-1;i>=0;i--){
            if(A[i] != tmp[i]){  end = i; break;}
        }
        return vector<int>({start, end});
    }
};

// 快速做法
class Rearrange {
public:
    vector<int> findSegment(vector<int> A, int n) {
        int max_val = INT_MIN, min_val = INT_MAX;
        int begin = 0, end = 0;
        for(int i=0;i<n;i++){
            if(A[i] >= max_val) max_val = A[i];
            else    end = i;
        }
        for(int i=n-1;i>=0;i--){
            if(A[i] <= min_val) min_val = A[i];
            else    begin = i;
        }
        return vector<int>({begin, end});
    }
};