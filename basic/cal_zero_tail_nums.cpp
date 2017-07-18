class Factor {
public:
    int getFactorSuffixZero(int n) {
        // write code here
        // 比较经典的一个题，其实就是寻找n！中n个数分解质因数之后
        // 有多少个5，可以用下列方法来计算
        int tmp = n, ret = 0;
        while(tmp){
            tmp /= 5; ret += tmp;
        }
        return ret;
    }
};