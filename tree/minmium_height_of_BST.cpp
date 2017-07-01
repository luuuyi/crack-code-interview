class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        // write code here
        int lens = vals.size();
        return ceil(log2(lens+1));
    }
};