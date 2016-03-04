class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> partSum;
        partSum.push_back(0);
        int sum;
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            partSum.push_back(sum);
        }
        
        int min=0x7fffffff;
        for(int i=0;i<partSum.size();i++){
            for(int j=i+1;j<partSum.size();j++){
                if(partSum[j]-partSum[i]>=s&&min>(j-i)){
                    min=j-i;                    
                    break;
                }
                if(j-i>=min){
                    break;
                }
            }
        }
        if(min==0x7fffffff){
            return 0;
        }else{
            return min;
        }
    }
};
