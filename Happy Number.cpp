class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int t,sum;
        
        while(1){
            if(s.find(n)!=s.end()){
                return false;
            }
            t=n;
            sum=0;
            while(t){
                sum+=(t%10)*(t%10);
                t/=10;
            }
            if(sum==1){
                return true;
            }
            s.insert(n);
            n=sum;
        }
    }
};
