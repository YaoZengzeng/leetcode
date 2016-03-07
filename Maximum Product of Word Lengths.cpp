class Solution {
public:
    int maxProduct(vector<string>& words) {
        int* mask= new int[words.size()];
        
        for(int i=0;i<words.size();i++){
            mask[i]=0;
            for(int j=0;j<words[i].size();j++){
                mask[i]|=(1<<(words[i][j]-'a'));
            }
        }
        
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(mask[i]&mask[j]){
                    continue;
                }else{
                    ans = words[i].size()*words[j].size()>ans ? words[i].size()*words[j].size() : ans;
                }
            }
        }
        return ans;
    }
};
