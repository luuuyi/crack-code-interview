class CloseNumber {
public:
    vector<int> getCloseNumber(int x) {
        // write code here
        if(x <= 1)  return vector<int>({-1, -1});
        int c00 = 0, c01 = 0, c10 = 0, c11 = 0;
        int p = x, q = x;
        // 根据书上的方法
        // 寻找下一个数，需要明确有多少个拖尾0，和拖尾0左边的1的个数
        while((p&0x01) == 0 && p!=0){
            c00++; p >>= 1;
        }
        while(p&0x01){
            c01++; p >>= 1;
        }
        if(c00+c01==32 || c00+c01 == 0) return vector<int>({-1, -1});
        // 需要明确有多少个拖尾1，和拖尾1左边的0的个数
        while(q&0x01){
            c11++; q >>= 1;
        }
        while((q&0x01) == 0 && q!=0){
            c10++; q >>= 1;
        }
        if(c10 == 0) return vector<int>({-1, -1});
        // 通过书上算术方法求得最终的结果，注意-1的操作
        int next = x + (1<<(c01-1)) + (1<<c00) - 1;
        int pre = x - (1<<c11) - (1<<(c10-1)) + 1;
        return vector<int>({pre, next});
    }
};