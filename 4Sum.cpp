class Solution {
public:
    vector<vector<int>> twoSum(vector<int>&nums,int pos,int target) {
        vector<vector<int>> ans;
        int start=pos,end=nums.size()-1;
        while(start<end) {
            if(nums[start]+nums[end]==target) {
                vector<int> t;
                t.push_back(nums[start]);
                t.push_back(nums[end]);
                ans.push_back(t);
                start++;
            } else if(nums[start]+nums[end]<target) {
                start++;
            } else {
                end--;
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<string> check;
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                vector<vector<int>> ret=twoSum(nums,j+1,target-nums[i]-nums[j]);
                for(int k=0;k<ret.size();k++) {
                    char s[30];
                    sprintf(s,"%d%d%d%d",nums[i],nums[j],ret[k][0],ret[k][1]);
                    if(check.find(s)==check.end()) {
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(ret[k][0]);
                        t.push_back(ret[k][1]);
                        ans.push_back(t);
                        check.insert(s);
                    }
                }
            }
        }
        return ans;
    }
};
