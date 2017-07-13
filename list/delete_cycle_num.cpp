class Joseph {
public:
    int getResult(int n, int m) {
        // write code here
        if(n == 1)  return 1;
        int a = 0;
        for(int i=2;i<=n;i++){
            a = (a + m) % i;
        }
        return a+1;
    }
};