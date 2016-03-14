class Solution {
public:
    int maxProduct2(vector<int>& nums){
        int pos1=-1,pos2=-1;
        int neg1=1,neg2=1;
        int total=1;
        int i=0;
        if(nums.size()==1){
            return nums[0];
        }
        while(1) {
            int t=1;
            while(i<nums.size()&&nums[i]>0){
                t*=nums[i];
                total*=nums[i];
                i++;
            }
            if(pos1==-1){
                pos1=t;
            }else{
                pos2=t;
            }
            if(i==nums.size()){
                break;
            }
            total*=nums[i];
            if(neg1==1){
                neg1=neg2=nums[i];
            }else{
                neg2=nums[i];
            }
            i++;
        }
        if(total>0){
            return total;
        }else{
            int ans1=total/pos1/neg1;
            int ans2=total/pos2/neg2;
            return ans1>ans2 ? ans1 : ans2;
        }
        
    }
    int maxProduct(vector<int>& nums) {
        int i=0;
        int max=0x80000000;
        while(i<nums.size()){
            vector<int> t;
            while(i<nums.size()&&nums[i]!=0){
                t.push_back(nums[i]);
                i++;
            }
            if(t.size()>0){
                int ret=maxProduct2(t);
                max = ret>max ? ret:max;
            }
            while(i<nums.size()&&nums[i]==0){
                i++;
                max = max>0 ? max:0;
            }
        }
        return max;
    }
};
