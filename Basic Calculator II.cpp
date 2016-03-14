class Solution {
public:
    int calculate(string s) {
        stack<long long> nums;
        stack<char> opts;
        
        int i=0;
        while(i<s.size()) {
            if(s[i]==' '){
                i++;
            }else if(s[i]=='+'||s[i]=='-'){
                if(opts.size()!=0){
                    int t1=nums.top();
                    nums.pop();
                    int t2=nums.top();
                    nums.pop();
                    char c=opts.top();
                    opts.pop();
                    if(c=='+'){
                        nums.push(t1+t2);
                    }else{
                        nums.push(t2-t1);
                    }
                }
                opts.push(s[i]);
                i++;
            }else if(s[i]=='/'||s[i]=='*'){
                opts.push(s[i]);
                i++;
            }else {
                long long t=0;
                while(i<s.size()&&(s[i]==' '||isdigit(s[i]))){
                    if(isdigit(s[i])){
                        t=t*10+s[i]-'0';
                    }
                    i++;
                }
                if(nums.size()==0){
                    nums.push(t);
                }else if(opts.top()=='/'||opts.top()=='*'){
                    long long top=nums.top();
                    nums.pop();
                    if(opts.top()=='/'){
                        top/=t;
                    }else{
                        top*=t;
                    }
                    nums.push(top);
                    opts.pop();
                }else{
                    nums.push(t);
                }
            }
        }
        if(opts.size()!=0){
            long long t1=nums.top();
            nums.pop();
            long long t2=nums.top();
            nums.pop();
            switch(opts.top()){
                case '+':
                    return t1+t2;
                case '-':
                    return t2-t1;
            }
        }else{
            return nums.top();
        }
    }
};
