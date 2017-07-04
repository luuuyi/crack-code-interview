

在二维平面上，有两个正方形，请找出一条直线，能够将这两个正方形对半分。假定正方形的上下两条边与x轴平行。

给定两个vecotrA和B，分别为两个正方形的四个顶点。请返回一个vector，代表所求的平分直线的斜率和截距，保证斜率存在。
测试样例：

[(0,0),(0,1),(1,1),(1,0)],[(1,0),(1,1),(2,0),(2,1)]

返回：[0.0，0.5]

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
        //
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
        double k = double(A_y - B_y) / (A_x - B_x);
        double b = double(A_y*B_x - B_y*A_x) / (B_x - A_x);
        return vector<double>({k, b});
    }
};