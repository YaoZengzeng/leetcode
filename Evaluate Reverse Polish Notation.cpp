class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(!isdigit(tokens[i][0])&&tokens[i].size()==1){
                int t2=s.top();
                s.pop();
                int t1=s.top();
                s.pop();
                switch(tokens[i][0]){
                    case '/':
                        s.push(t1/t2);
                        break;
                    case '*':
                        s.push(t1*t2);
                        break;
                    case '-':
                        s.push(t1-t2);
                        break;
                    case '+':
                        s.push(t1+t2);
                        break;
                }
            }else{
                int t=0;
                int p=0;
                if(!isdigit(tokens[i][0])){
                    p=1;
                }
                for(int j=p;j<tokens[i].size();j++){
                    t = t*10+tokens[i][j]-'0';
                }
                if(p==0){
                    s.push(t);
                }else{
                    s.push(-t);
                }
            }
        }
        
        return s.top();
    }
};
