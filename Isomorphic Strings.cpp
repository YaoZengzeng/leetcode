class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m1,m2;
        if(s.size()!=t.size()) {
            return false;
        }
        
        for(int i=0;i<s.size();i++) {
            map<char,char>::iterator iter;
            iter=m1.find(s[i]);
            if(iter==m1.end()) {
                m1.insert(pair<char,char>(s[i],t[i]));
            } else if(iter->second!=t[i]) {
                return false;
            }
            iter=m2.find(t[i]);
            if(iter==m2.end()) {
                m2.insert(pair<char,char>(t[i],s[i]));
            } else if(iter->second!=s[i]) {
                return false;
            }
        }
        
        return true;
    }
};
