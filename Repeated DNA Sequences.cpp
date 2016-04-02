class Solution {
public:
    int getVal(char c) {
        switch (c) {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
        }
    }
    vector<string> findRepeatedDnaSequences(string s) {
        int mask=0x3ffff;
        map<int,int> m;
        vector<string> ans;
        int val=0;
        for(int i=0;i<10;i++) {
            val=val*4+getVal(s[i]);
        }
        m.insert(pair<int,int>(val,1));
        for(int i=10;i<s.size();i++) {
            val &=mask;
            val=val*4+getVal(s[i]);
            if(m.find(val)==m.end()) {
                m.insert(pair<int,int>(val,1));
            } else if(m[val]==1) {
                ans.push_back(s.substr(i-9,10));
                m[val]=2;
            }
        }
        
        return ans;
    }
};
