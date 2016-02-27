class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> height;
        int ans=0;
        
        for(int i=0;i<matrix.size();i++){
            vector<int> v;
            for(int j=0;j<matrix[i].size();j++){
                if(i==0){
                    if(matrix[i][j]=='0'){
                        v.push_back(0);
                    }else{
                        v.push_back(1);
                    }
                }else{
                    if(matrix[i][j]=='0'){
                        v.push_back(0);
                    }else{
                        v.push_back(1+height[i-1][j]);
                    }
                }
            }
            height.push_back(v);
        }
        
        for(int i=0;i<height.size();i++){
            int ret=largestRectangleArea(height[i]);
            if(ret>ans){
                ans=ret;
            }
        }
        return ans;
        
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> idx,area;
        int max=0;
        
        idx.push(0);
        area.push(0);
        heights.push_back(0);
        for(int i=1;i<heights.size();i++){
            if(heights[i]>=heights[idx.top()]){
                idx.push(i);
                area.push(0);
            }else{
                while(heights[idx.top()]>heights[i]){
                    if(heights[idx.top()]*(i-idx.top())+area.top()>max){
                        max=heights[idx.top()]*(i-idx.top())+area.top();
                    }
                    idx.pop();
                    area.pop();
                    if(idx.empty()){
                        break;
                    }
                }
                if(idx.empty()){
                    area.push(i*heights[i]);
                }else{
                    area.push((i-idx.top()-1)*heights[i]);
                }
                idx.push(i);
            }
        }
        return max;
    }
};
