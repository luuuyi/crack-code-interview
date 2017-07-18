class Max {
public:
    int getMax(int a, int b) {
        // write code here
        // 快速写法
        return a-b>0?a:b;
        // 正常做法
        // return ((a+b+abs(a-b))/2);
    }
};