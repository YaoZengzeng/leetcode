class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hash;
        for(int i=0;i<nums.size();i++){
            hash.insert(nums[i]);
        }
        int max=1;
        for(int i=0;i<nums.size();i++){
            int len=1;
            int t=nums[i]-1;
            while(hash.find(t)!=hash.end()) {
                hash.erase(t);
                len++;
                t--;
            }
            t=nums[i]+1;
            while(hash.find(t)!=hash.end()) {
                hash.erase(t);
                len++;
                t++;
            }
            max = max>len ? max:len;
        }
        return max;
    }
};
