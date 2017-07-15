// 和约瑟夫问题一比较像，通过递归函数找到相互队列间的映射
class Joseph {
private:
    int getIndex(int n, int m){
        int tmp = n%m==0?n/m:n/m+1;
        // 当发现下一次队列中数值的个数小于跳跃距离，直接返回最后一个
        if(tmp <= m+1)  return (tmp-1)*m+1;
        // 找到下一个队列的结果的位置
        int index = getIndex(tmp, m+1);
        // 具体实例分析解释可以参考牛客网链接：
        // https://www.nowcoder.com/questionTerminal/ff063da83b1a4d91913dd1b1e8b01466
        // 因为上一次把最后一位移到当前位的前面，所以相对位置要考虑到前两个位置才行
        return (index-2)*m+1;
    }
public:
    int getResult(int n) {
        // write code here
        return getIndex(n, 2);
    }
};