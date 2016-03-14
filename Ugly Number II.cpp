    class Solution {
    public:
        int nthUglyNumber(int n) {
            deque<int> q1,q2,q3;
            int num=1;
            for(int i=1;i<=n;i++){
                if(i==n){
                    return num;
                }
                q1.push_back(num*2);
                q2.push_back(num*3);
                q3.push_back(num*5);
                
                int t1=q1.front();
                int t2=q2.front();
                int t3=q3.front();
                if(t1<=t2&&t1<=t3){
                    num=q1.front();
                    q1.pop_front();
                }
                if(t2<=t1&&t2<=t3){
                    num=q2.front();
                    q2.pop_front();
                }
                if(t3<=t1&&t3<=t2){
                    num=q3.front();
                    q3.pop_front();
                }
            }
        }
    };
