class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        // 保证位数从j到i，n二进制上都是0，所以直接将m左移做一个或运算就好
        return (n|(m<<j));
    }
};