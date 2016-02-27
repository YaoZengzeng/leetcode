class Solution {
public:
    void combinationSum32(int k,int n,int pos,vector<int>&v,vector<vector<int>>& ans){
        if(k==0&&n==0){
            ans.push_back(v);
        }
        for(int i=pos;i<=9;i++){
            v.push_back(i);
            combinationSum32(k-1,n-i,i+1,v,ans);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        vector<vector<int>> ans;
        combinationSum32(k,n,1,v,ans);
        return ans;
    }
};
