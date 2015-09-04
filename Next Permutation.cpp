class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j,t;
        int min,flag,pos;
        if(nums.size()==1){
            return ;
        }
    
    for(i=nums.size()-2;i>=0;i--){
        flag=0;
        for(j=i+1;j<nums.size();j++){
            if(flag==0&&nums[j]>nums[i]){
                flag=1;
                min=nums[j],pos=j;
            }else if(flag==1&&nums[j]>nums[i]&&nums[j]<min){
                min=nums[j],pos=j;
            }
        }
        if(flag){
            t=nums[i];
            nums[i]=nums[pos];
            nums[pos]=t;
            sort(nums.begin()+i+1,nums.end());
            return;
        }
    }
    
    for(i=0;i<nums.size()/2;i++){
        t=nums[i];
        nums[i]=nums[nums.size()-1-i];
        nums[nums.size()-1-i]=t;
    }
    return;
    }
};
