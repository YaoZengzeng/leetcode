class Solution {
public:
    static bool cmp(vector<string> &v1,vector<string> &v2) {
        return v2.size()>v1.size();
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int cnt=0;
        string s;
        map<string,int> m;
        map<string,int>::iterator iter;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            s=strs[i];
            sort(s.begin(),s.end());            
            if((iter=m.find(s))==m.end()){
                m.insert(pair<string,int>(s,cnt++));
                vector<string> v;
                v.push_back(strs[i]);
                ans.push_back(v);
            }else{
                ans[iter->second].push_back(strs[i]);
            }
        }
        for(int i=0;i<cnt;i++){
            sort(ans[i].begin(),ans[i].end());
        }
        sort(ans.begin(),ans.end(),cmp);
        
        return ans;
    }
};
