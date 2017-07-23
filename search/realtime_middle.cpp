// 实时找出数组的中位数，使用插入排序来做
class Middle {
public:
    vector<int> getMiddle(vector<int> A, int n) {
        // write code here
        if(n <= 0)  return vector<int>();
        vector<int> ret;
        // 插入排序的经典结构
        for(int i=0;i<n;i++){
            int j = i-1, tmp = A[i];
            while(j>=0 && A[j] > tmp){
                A[j+1] = A[j]; j--;
            }
            A[j+1] = tmp;
            ret.push_back(A[i/2]);
        }
        return ret;
    }
};

class Middle {
public:
    vector<int> getMiddle(vector<int> A, int n) {
        // write code here
    }
};