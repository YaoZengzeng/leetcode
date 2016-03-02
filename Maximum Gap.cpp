class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        
        int min=nums[0],max=nums[0];
        for(int i=1;i<nums.size();i++){
            min = nums[i]<min ? nums[i]:min;
            max = nums[i]>max ? nums[i]:max;
        }
        
        if(min==max){
            return 0;
        }
        
        int len;
        if((max-min)%(nums.size()-1)==0){
            len=(max-min)/(nums.size()-1);
        }else{
            len=(max-min)/(nums.size()-1)+1;
        }
        
        int* bMin=new int[nums.size()];
        int* bMax=new int[nums.size()];
        
        for(int i=0;i<nums.size();i++){
            bMax[i]=0x80000000;
        }
        
        for(int i=0;i<nums.size();i++){
            int p=(nums[i]-min)/len;
            if(bMax[p]==0x80000000){
                bMax[p]=bMin[p]=(nums[i]-min);
            }else{
                bMax[p] = bMax[p]>(nums[i]-min) ? bMax[p]:(nums[i]-min);
                bMin[p] = bMin[p]<(nums[i]-min) ? bMin[p]:(nums[i]-min);
            }
        }
        
        int pre=0;
        int cur=1;
        int ans=0x80000000;
        while(cur<nums.size()){
            while(cur<nums.size()&&bMax[cur]==0x80000000){
                cur++;
            }
            if(cur==nums.size()){
                break;
            }
            ans = ans>(bMin[cur]-bMax[pre]) ? ans:(bMin[cur]-bMax[pre]);
            pre=cur;
            cur++;
        }
        
        return ans;
    }
};
