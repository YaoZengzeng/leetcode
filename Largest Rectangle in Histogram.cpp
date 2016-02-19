class Solution {
public:
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
