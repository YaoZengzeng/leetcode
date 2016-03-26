class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> m;
        vector<pair<int,char>> v;
        for(int i=0;i<t.size();i++) {
            if(m.find(t[i])==m.end()) {
                m.insert(pair<char,int>(t[i],1));
            } else {
                m[t[i]]++;
            }
        }
        for(int i=0;i<s.size();i++) {
            if(m.find(s[i])!=m.end()) {
                v.push_back(pair<int,char>(i,s[i]));
            }
        }
        
        map<char,int> cur;
        int left=0,cnt=0;
        int ans=-1,len=0x78888888;
        for(int i=0;i<v.size();i++) {
            if(cur.find(v[i].second)==cur.end()) {
                cur.insert(pair<char,int>(v[i].second,1));
                cnt++;
            } else {
                cur[v[i].second]++;
                if(cur[v[i].second]<=m[v[i].second]) {
                    cnt++;
                }
            }
            while(cur[v[left].second]>m[v[left].second]) {
                cur[v[left].second]--;
                left++;
            }
            if(cnt==t.size()) {
                if(v[i].first-v[left].first+1<len) {
                    ans=v[left].first;
                    len=v[i].first-v[left].first+1;
                }
                cur[v[left].second]--;
                left++;
                cnt--;
            }
        }
        
        if(ans==-1) {
            return "";
        } else {
            return s.substr(ans,len);
        }
    }
};
