class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ans;
        string a;
        if(path.size()==1){
            return path;
        }
        a="";
        for(int i=1;i<=path.size();i++){
            if(i==path.size()||path[i]=='/'){
                if(a=="."||a==""){
                    a="";
                    continue;
                }else if(a==".."){
                    if(ans.size()!=0){
                        ans.pop_back();
                    }
                }else{
                    ans.push_back(a);
                }
                a="";
            }else{
                a+=path[i];
            }
        }
        
        
        a="";
        if(ans.size()==0){
            return "/";
        }
        for(int i=0;i<ans.size();i++){
            a=a+"/"+ans[i];
        }
        return a;
    }
};
