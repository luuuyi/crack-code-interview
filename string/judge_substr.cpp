class Substr {
public:
    vector<bool> chkSubStr(vector<string> p, int n, string s) {
        // write code here
        if(n <= 0)  return vector<bool>();
        vector<bool> ret;
        for(int i=0;i<n;i++){
            if(s.find(p[i]) != string::npos)    ret.push_back(true);
            else    ret.push_back(false);
        }
        return ret;
    }
};