class GoUpstairs {
public:
    int countWays(int n) {
        // write code here
        const int MOD = 1000000007;
        // 经典的爬楼梯题目，没啥好说的，主要注意
        // 1）因为n比较大，会出现很大的数，就算取模，也要注意使用long long
        // 2）一定要注意任何一个可能会溢出的情况
        int a = 1, b = 2, c = 4;
        if(n == 1)  return a;
        else if(n == 2) return b;
        else if(n == 3) return c;
        else{
            long long ret = 0;
            for(int i=4;i<=n;i++){
                // 比如说下面这种写法，在括号里面三个数就算取模之后相加依然会出现溢出的情况
                // ret = (a%MOD + b%MOD + c%MOD)%MOD;
                ret = ((a%MOD + b%MOD)%MOD + c%MOD)%MOD;
                a = b; b = c; c = (int)ret;
            }
            return int((ret+MOD)%MOD);
        }
    }
};