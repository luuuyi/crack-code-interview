class Exchange {
public:
    int exchangeOddEven(int x) {
        // write code here
        // 分别获取奇位数和偶位数
        int p = x & 0xAAAAAAAA;
        int q = x & 0x55555555;
        // 将两个结果移位之后做一个或运算
        return (p>>1)|(q<<1);
    }
};