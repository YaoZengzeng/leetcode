class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies;
        candies.push_back(1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                candies.push_back(candies[candies.size()-1]+1);
            } else {
                candies.push_back(1);
            }
        }
        for(int i=ratings.size()-2;i>=0;i--) {
            if(ratings[i]>ratings[i+1]&&candies[i]<candies[i+1]+1) {
                candies[i]=candies[i+1]+1;
            }
        }
        
        int ans=0;
        for(int i=0;i<candies.size();i++) {
            ans+=candies[i];
        }
        
        return ans;
    }
};
