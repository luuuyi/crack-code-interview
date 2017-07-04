/*
struct Point {
    int x;
    int y;
    Point() :
            x(0), y(0) {
    }
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};*/
class Bipartition {
public:
    vector<double> getBipartition(vector<Point> A, vector<Point> B) {
        // write code here
        // 由于一条线把两个正方形都平均分开
        // 所以这条线肯定过两个正方形的中点，计算中点以后连城线即为所求
        int A_x = 0, A_y = 0;
        for(int i=0;i<4;i++){
            A_x += A[i].x;
            A_y += A[i].y;
        }
        A_x /= 4; A_y /= 4;
        int B_x = 0, B_y = 0;
        for(int i=0;i<4;i++){
            B_x += B[i].x;
            B_y += B[i].y;
        }
        B_x /= 4; B_y /= 4;
        // 根据两点计算通过两点的直线
        double k = double(A_y - B_y) / (A_x - B_x);
        double b = double(A_y*B_x - B_y*A_x) / (B_x - A_x);
        return vector<double>({k, b});
    }
};