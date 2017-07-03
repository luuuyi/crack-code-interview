class Finder {
public:
    int findMissing(vector<vector<int> > numbers, int n) {
        // write code here
        if(n <= 0)  return 0;
        // 题目规定了是0到n的数按升序排好了，所以只要判断跟i相不相似就好了
        // 类似于在一个0到n的乱序序列中找到第一个缺失的值
        for(int i=0;i<n;i++){
            if((i&0x01) != numbers[i][0])   return i;
        }
        return n;
    }
};