class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> ans;
        if(nums.size()==0) {
            return ans;
        }
        d.push_front(0);
        for(int i=1;i<k;i++) {
            while(!d.empty()&&nums[d.back()]<nums[i]) {
                d.pop_back();
            }
            d.push_back(i);
        }
        ans.push_back(nums[d.front()]);
        for(int i=k;i<nums.size();i++) {
            while(!d.empty()&&nums[d.back()]<nums[i]) {
                d.pop_back();
            }
            d.push_back(i);
            while(d.front()<=i-k) {
                d.pop_front();
            }
            ans.push_back(nums[d.front()]);
        }
        
        return ans;
    }
};
