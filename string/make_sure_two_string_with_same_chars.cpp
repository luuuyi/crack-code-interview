#include <unordered_map>
//使用一个hash表来维护字符即可
class Same {
public:
    bool checkSam(string stringA, string stringB) {
        // write code here
        if(stringA.size() != stringB.size())    return false;
        unordered_map<char, int> table;
        for(int i=0;i<(int)stringA.size();i++){
            table[stringA[i]]++;
        }
        for(int i=0;i<(int)stringB.size();i++){
            table[stringB[i]]--;
            if(table[stringB[i]] < 0)   return false;
        }
        return true;
    }
};