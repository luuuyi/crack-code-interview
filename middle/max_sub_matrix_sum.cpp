class SubMatrix {
private:
    // 经典题目中的求一位数组最大连续子数组和
    int getMaxSubSum(vector<int> &nums, int n){
        int ret_val = INT_MIN, sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum < 0){ ret_val = max(ret_val, sum); sum = 0;}
            else    ret_val = max(ret_val, sum);
        }
        return ret_val;
    }
public:
    // 基本思路就是不论是什么矩形,都可以压缩到一维向量上,所以求最大和子矩形转换为求一维数组最大子序列问题
    // 从第一行开始向后枚举,每一次用一个外部变量来维护最大值
    int sumOfSubMatrix(vector<vector<int> > mat, int n) {
        // write code here
        if(n <= 0)  return 0;
        int ret_val = INT_MIN;
        for(int i=0;i<n;i++){
            vector<int> tmp(n, 0);
            for(int j=i;j<n;j++){
                for(int k=0;k<n;k++){
                    tmp[k] += mat[j][k];
                }
                ret_val = max(ret_val, getMaxSubSum(tmp, n));
            }
        }
        return ret_val;
    }
};