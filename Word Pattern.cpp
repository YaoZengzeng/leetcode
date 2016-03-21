class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> m1;
        map<string,char> m2;
        int i=0,j=0;
        while(i<pattern.size()&&j<str.size()) {
            char c=pattern[i++];
            char t[100];
            int p=0;
            while(j<str.size()&&str[j]!=' '){
                t[p++]=str[j++];
            }
            j++;
            t[p]='\0';
            string s=t;
            
            map<char,string>::iterator iter1;
            iter1=m1.find(c);
            if(iter1==m1.end()) {
                m1.insert(pair<char,string>(c,s));
            } else if(m1[c]!=s){
                return false;
            }
            
            map<string,char>::iterator iter2;
            iter2=m2.find(s);
            if(iter2==m2.end()) {
                m2.insert(pair<string,char>(s,c));
            } else if(m2[s]!=c) {
                return false;
            }
        }
        
        if(i<pattern.size()||j<str.size()) {
            return false;
        }
        
        return true;
    }
};
