class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<bool> opts;
        int num1;
        bool exist;
        bool opt;
        exist=false;
        int p=0;
        while(p<s.size()){
            if(s[p]==' '){
                p++;
                continue;
            }
            if(s[p]=='('&&exist){
                nums.push(num1);
                opts.push(opt);
                exist=false;
                p++;
                continue;
            }
            if(s[p]==')'&&nums.size()>0){
                opt=opts.top();
                opts.pop();
                if(opt){
                    num1=nums.top()+num1;
                }else{
                    num1=nums.top()-num1;
                }
                nums.pop();
                p++;
                continue;
            }
            if(s[p]=='+'){
                opt=true;
                p++;
                continue;
            }
            if(s[p]=='-'){
                opt=false;
                p++;
                continue;
            }
            int t=0;
            while(isdigit(s[p])||s[p]==' '){
                if(s[p]==' '){
                    p++;
                }else{
                    t=t*10+s[p]-'0';
                    p++;
                }
            }
            if(exist){
                if(opt){
                    num1+=t;
                }else{
                    num1-=t;
                }
            }else{
                exist=1;
                num1=t;
            }
        }
        return num1;
    }
};
