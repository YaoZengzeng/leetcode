class Solution {
public:
    int hIndex(vector<int>& citations) {
        int* p=new int[citations.size()+1];
        
        for(int i=1;i<=citations.size();i++){
            p[i]=0;
        }
        for(int i=0;i<citations.size();i++){
            if(citations[i]>citations.size()){
                p[citations.size()]++;
            }else{
                p[citations[i]]++;
            }
        }
        
        int sum=0;
        for(int i=citations.size();i>0;i--){
            sum+=p[i];
            if(sum>=i){
                return i;
            }
        }
        
        return 0;
    }
};
