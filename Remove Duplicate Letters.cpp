class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26];
        vector<char> stk;
        for(int i=0;i<26;i++){
            cnt[i]=0;
        }
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']--;
            if(stk.empty()){
                stk.push_back(s[i]);
            }else {
                int j;
                for(j=0;j<stk.size();j++){
                    if(stk[j]==s[i]){
                        break;
                    }
                }
                if(j!=stk.size()){
                    continue;
                }
                while(!stk.empty()&&stk[stk.size()-1]>s[i]&&cnt[stk[stk.size()-1]-'a']>0){
                    stk.pop_back();
                }
                stk.push_back(s[i]);
            }
        }
        string ans;
        while(!stk.empty()){
            ans=stk[stk.size()-1]+ans;
            stk.pop_back();
        }
        
        return ans;
    }
};
