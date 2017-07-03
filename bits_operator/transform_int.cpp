class Transform {
public:
    int calcCost(int A, int B) {
        // write code here
        // 根动态规划字符串变换的题还不一样
        // 此处只关注替换，不关注删除，增加
        int tmp_a = A, tmp_b = B;
        int ret = 0;
        // 判断每一次最后一位是否相同即可
        while(tmp_a!=0||tmp_b!=0){
            if((tmp_a&0x01)!=(tmp_b&0x01))  ++ret;
            tmp_a >>= 1; tmp_b >>= 1;
        }
        return ret;
    }
};