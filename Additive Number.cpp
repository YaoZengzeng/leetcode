class Solution {
public:
    bool isAdditiveNumber3(string num,int pos,long long sum,long long a,int cnt) {
        long long b=0,times=1,flag=0;
        if(pos==-1&&cnt) {
            return true;
        }
        while(pos>=0 && b<=sum) {
            b=(num[pos]-'0')*times+b;
            pos--;
            times*=10;
            if(b+a==sum && (num[pos+1]!='0' || num[pos+1]=='0' && b==0)) {
                flag=1;
                break;
            } 
        }
        if(flag) {
            return isAdditiveNumber3(num,pos,a,b,cnt+1);
        } else {
            return false;
        }
        
    }
    bool isAdditiveNumber2(string num,int pos,long long sum) {
        long long a=0,times=1;
        while(pos>=0 && a<=sum) {
            a=(num[pos]-'0')*times+a;
            pos--;
            times*=10;
            if((num[pos+1]!='0' || num[pos+1]=='0' && a==0) && isAdditiveNumber3(num,pos,sum,a,0)) {
                return true;
            }
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        int pos=num.size()-1;
        long long sum=0,times=1;
        while(pos>=0) {
            sum=(num[pos]-'0')*times+sum;
            pos--;
            times*=10;
            if((num[pos+1]!='0'||num[pos+1]=='0' && sum==0 )&& isAdditiveNumber2(num,pos,sum)) {
                return true;
            }
        }
        
        return false;
    }
};
