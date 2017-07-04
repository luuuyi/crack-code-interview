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
// 不能用unordered_map
// #include <unordered_map>
class DenseLine {
private:
    // 计算两个点的斜率和截距
    pair<double, double> cal(Point &A, Point &B){
        int A_x = A.x, A_y = A.y;
        int B_x = B.x, B_y = B.y;
        double k = double(A_y - B_y) / (A_x - B_x);
        double b = double(A_y*B_x - B_y*A_x) / (B_x - A_x);
        return pair<double, double>({k, b});
    }
public:
    vector<double> getLine(vector<Point> p, int n) {
        // write code here
        // 只能通过暴力法枚举任意两个点的截距和斜率，用一个map来保存
        // 最后遍历map查找到斜率，截距对最多的那一对返回
        if(n <= 1)  return vector<double>({0, 0});
        map<pair<double, double>, int> table;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                table[cal(p[i], p[j])]++;
            }
        }
        pair<double, double> ret;
        int max_val = INT_MIN;
        for(auto k=table.begin();k!=table.end();k++){
            if(k->second > max_val){
                max_val = k->second;
                ret = k->first;
            }
        }
        return vector<double>({ret.first, ret.second});
    }
};