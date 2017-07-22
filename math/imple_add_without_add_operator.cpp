class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        // 比较经典常见的题了
        while(B){
            int num1 = A ^ B;
            int num2 = (A & B) << 1;
            A = num1; B = num2;
        }
        return A;
    }
};