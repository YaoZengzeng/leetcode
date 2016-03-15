class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m,n,cm,cn;
        m=n=cm=cn=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==m){
                cm++;
            }else if(nums[i]==n){
                cn++;
            }else if(cm==0){
                cm++;
                m=nums[i];
            }else if(cn==0){
                cn++;
                n=nums[i];
            }else {
                cm--,cn--;
            }
        }
        
        cm=cn=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==m){
                cm++;
            }else if(nums[i]==n){
                cn++;
            }
        }
        vector<int> ans;
        if(cm>nums.size()/3){
            ans.push_back(m);
        }
        if(cn>nums.size()/3){
            ans.push_back(n);
        }
        return ans;
    }
};
