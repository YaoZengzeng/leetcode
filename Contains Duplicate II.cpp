class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;
        map<int,int>::iterator iter;
        
        for(int i=0;i<nums.size();i++){
            iter=m.find(nums[i]);
            if(iter==m.end()){
                m.insert(pair<int,int>(nums[i],i));
            }else if(i-iter->second<=k){
                return true;
            }else{
                iter->second=i;
            }
        }
        
        return false;
    }
};
