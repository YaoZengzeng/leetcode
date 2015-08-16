class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(int i=0;i<s.length();i++){

            if(S.empty()){
              S.push(s[i]);  
            } else{
              if(s[i]==')'||s[i]==']'||s[i]=='}'){
              	switch(s[i]){
              	case ')':
              		if(S.top()!='(') return false;
              		S.pop();
              		break;
              	case ']':
              		if(S.top()!='[') return false;
              		S.pop();
              		break; 
              	case '}':
              		if(S.top()!='{') return false;
              		S.pop();
              		break;             	
              	}
              }
              else{
                  S.push(s[i]);
              }
            }
            
        }
        if(S.empty()){
            return true;
        }else{
            return false;
        }
    }
};
