class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        for(int boundary=2;boundary<nums.size();boundary++){
            int beg=0,end=boundary-1;
            while(beg<end){
                int sum=nums[beg]+nums[end]+nums[boundary];
                if(abs(sum-target)<abs(ans-target)){
                    ans=sum;
                }
                if(nums[beg]+nums[end]+nums[boundary]==target){
                    return target;
                }else if(nums[beg]+nums[end]+nums[boundary]<target){
                    beg++;
                }else{
                    end--;
                }
            }

        }
        return ans;
        
    }
};
