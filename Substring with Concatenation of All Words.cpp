class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> m;
        vector<int> ans;
        for(int i=0; i<words.size(); i++) {
            if(m.find(words[i])==m.end()) {
                m.insert(pair<string,int>(words[i],1));
            } else {
                m[words[i]]++;
            }
        }
        
        for(int i=0; i<words[0].size(); i++) {
            map<string,int> cur;
            int left=i,cnt=0;
            for(int j=i; j+words[0].size()<=s.size(); j+=words[0].size()) {
                string word=s.substr(j,words[0].size());
                if(m.find(word)!=m.end()) {
                    if(cur.find(word)==cur.end()) {
                        cur.insert(pair<string,int>(word,1));
                    } else {
                        cur[word]++;
                    }
                    cnt++;
                    
                    if(cur[word]>m[word]) {
                        string s1=s.substr(left,words[0].size());
                        while(s1!=word) {
                            cnt--;
                            cur[s1]--;
                            left+=words[0].size();
                            s1=s.substr(left,words[0].size());
                        }
                        cur[s1]--;
                        left+=words[0].size();
                        cnt--;
                    }
                    if(cnt==words.size()) {
                        ans.push_back(left);
                        cur[s.substr(left,words[0].size())]--;
                        left+=words[0].size();
                        cnt--;
                    }
                } else {
                    cur.clear();
                    cnt=0;
                    left=j+words[0].size();
                }
            }
        }
        
        return ans;
    }
};
