class Solution {
public:
    int findMaxSquare(vector<int>& a){
        stack<int> val,idx;
        int max=0;
        for(int i=0;i<a.size();i++){
            if(val.size()==0||a[i]>=val.top()){
                val.push(a[i]);
                idx.push(i);
            }else{
                while(val.size()>0&&val.top()>a[i]){
                    int value;
                    value=val.top();
                    val.pop();
                    idx.pop();
                    if(val.size()){
                        if(value<=(i-idx.top()-1)&&value*value>max){
                            max=value*value;
                        }
                    }else{
                        if(value<=i&&value*value>max){
                            max=value*value;
                        }
                    }
                }
                val.push(a[i]);
                idx.push(i);
            }
        }
    
        return max;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> a;
        vector<int> v;
        if(matrix.size()==0){
            return 0;
        }
        for(int i=0;i<matrix[0].size();i++){
            v.push_back(matrix[0][i]-'0');
        }
        v.push_back(0);
        a.push_back(v);
        for(int i=1;i<matrix.size();i++){
            vector<int> v;
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='0'){
                    v.push_back(0);
                }else{
                    v.push_back(1+a[i-1][j]);
                }
            }
            v.push_back(0);
            a.push_back(v);
        }
        
        int max=0;
        for(int i=0;i<a.size();i++){
            int ret=findMaxSquare(a[i]);
            if(max<ret){
                max=ret;
            }
        }
        
        return max;
    }
};
