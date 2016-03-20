class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0) {
            return ans;
        }
        int i=0;
        int start=i;
        while(1) {
            while(i==0||i<nums.size()&&nums[i]==nums[i-1]+1) {
                i++;
            }
            int end=i-1;
            if(start==end) {
                char s1[20];
                sprintf(s1,"%d",nums[start]);
                string s(s1);
                ans.push_back(s);
            } else {
                char s1[20];
                sprintf(s1,"%d->%d",nums[start],nums[end]);
                string s(s1);
                ans.push_back(s);
            }
            if(i==nums.size()) {
                break;
            } else {
                start=i;
                i++;
            }
        }
        return ans;
    }
};
