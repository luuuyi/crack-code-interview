class Count2 {
public:
    int countNumberOf2s(int n) {
        // write code here
        // 很有挑战的一题，具体的解题思路可以参考下面这篇博客
        // http://blog.csdn.net/sallyxyl1993/article/details/60882064
        // 数0和数1~9的情况还不太相同
        int sum = 0, divi = 1, total = n;
        while(n){
            if(n%10 == 2)   sum += n/10*divi + (total%divi+1);
            else if(n%10 > 2)   sum += (n/10+1)*divi;
            else    sum += n/10*divi;
            n /= 10; divi *= 10;
        } 
        return sum;
    }
};