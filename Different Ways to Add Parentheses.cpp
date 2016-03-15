class Solution {
public:
    vector<int> diffWaysToCompute2(vector<int>& nums,int beg,int end,vector<char>& opts) {
        vector<int> ans;
        if(beg==end){
            ans.push_back(nums[beg]);
            return ans;
        }
        for(int j=beg;j<end;j++){
            vector<int> a=diffWaysToCompute2(nums,beg,j,opts);
            vector<int> b=diffWaysToCompute2(nums,j+1,end,opts);
            for(int x=0;x<a.size();x++){
                for(int y=0;y<b.size();y++){
                    switch(opts[j]){
                    case '+':
                        ans.push_back(a[x]+b[y]);
                        break;
                    case '-':
                        ans.push_back(a[x]-b[y]);
                        break;
                    case '*':
                        ans.push_back(a[x]*b[y]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<int> ans;
        vector<char> opts;
        int i=0;
        while(1){
            int n=0;
            while(i<input.size()&&isdigit(input[i])){
                n=n*10+input[i]-'0';
                i++;
            }
            nums.push_back(n);
            if(i==input.size()){
                break;
            }
            opts.push_back(input[i++]);
        }
        ans=diffWaysToCompute2(nums,0,nums.size()-1,opts);
        return ans;
    }
};
