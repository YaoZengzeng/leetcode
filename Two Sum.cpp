class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mapper;
        
        vector<int> ans;
        
        for(int i=0;i!=nums.size();i++){
            if(mapper.find(target-nums[i])!=mapper.end()){
                ans.push_back(mapper.find(target-nums[i])->second);
                ans.push_back(i+1);
                return ans;
            }else {
                mapper.insert(pair<int,int>(nums[i],i+1));   
            }
        }
        
    }
};
