class Solution {
public:
    int isValid(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]!='('&&s[i]!=')') {
                continue;
            }else if(s[i]==')') {
                cnt--;
            }else {
                cnt++;
            }
            if(cnt<0) {
                return cnt;
            }
        }
        return cnt;
    }
    void dfs(string s,string re,int pos,set<string>& m) {
        if(pos==s.size()) {
            if(isValid(re)==0&&m.find(re)==m.end()) {
                m.insert(re);
            }
            return;
        } 
        if(s[pos]!='(' && s[pos]!=')') {
            re=re+s[pos];
            dfs(s,re,pos+1,m);
        } else {
            dfs(s,re,pos+1,m);
            re=re+s[pos];
            if(isValid(re)>=0) {
                dfs(s,re,pos+1,m);
            }
        }
        return;
        
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        set<string> m;
        string re;
        dfs(s,re,0,m);
        set<string>::iterator iter;
        int max=0;
        for(iter=m.begin();iter!=m.end();iter++) {
            max= max>(*iter).size() ? max:(*iter).size();
        }
        for(iter=m.begin();iter!=m.end();iter++) {
            if((*iter).size()==max) {
                ans.push_back(*iter);
            }
        }
        return ans;
    }
};
