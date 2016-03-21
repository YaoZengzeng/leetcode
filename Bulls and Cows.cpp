class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> m;
        vector<char> tag(secret.size(),false);
        int bow=0,cow=0;
        for(int i=0;i<secret.size();i++) {
            if(secret[i]==guess[i]) {
                bow++;
                tag[i]=true;
            } else {
                m[secret[i]]++;
            }
        }
        for(int i=0;i<guess.size();i++) {
            if(tag[i]==false && m[guess[i]]>0) {
                cow++;
                m[guess[i]]--;
            }
        }
        char ans[20];
        sprintf(ans,"%dA%dB",bow,cow);
        return ans;
    }
};
