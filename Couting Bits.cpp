class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        if(num==0) {
            return ans;
        }
        ans.push_back(1);
        if(num==1) {
            return ans;
        }
        int cnt=2;
        while(1) {
            int size=ans.size();
            for(int i=0;i<size;i++) {
                ans.push_back(1+ans[i]);
                if(cnt++==num) {
                    return ans;
                }
            }
        }
    }
};
