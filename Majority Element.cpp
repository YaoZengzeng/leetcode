class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        map<int,int>::iterator iter;
        int count=nums.size();
        for(int i=0;i<count;i++){
            if((iter=m.find(nums[i]))==m.end()){
                m.insert(std::make_pair(nums[i],1));
            }else{
                iter->second=iter->second+1;
                if(iter->second>nums.size()/2){
                    return nums[i];
                }
            }
        }
    }
};
