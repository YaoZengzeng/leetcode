/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
	static char map[10][4]={
	{},
	{},
	{'a','b','c'},
	{'d','e','f'},
	{'g','h','i'},
	{'j','k','l'},
	{'m','n','o'},
	{'p','q','r','s'},
	{'t','u','v'},
	{'w','x','y','z'}
	};
	int i,j,t,k,tmp,Size;
	static int pos=0,len;
	static char** ret;
	static char* ans;
	
	if(strlen(digits)==0){
	    *returnSize=0;
	    return NULL;
	}
	
	if(pos==0){
		len=strlen(digits);
		*returnSize=0;
		Size=1;
		for(i=0;i<len;i++){
	   		 if(digits[i]=='7'||digits[i]=='9'){
	       	 	Size*=4;
	   	 	}else{
	        	Size*=3;
	   	 	}
		}		
		ret=(char**)malloc(Size*sizeof(char*));
		ans=(char*)malloc(len+1);
		ans[len]='\0';
	}else if(pos==len){
		ret[*returnSize]=(char*)malloc(len+1);
		strcpy(ret[*returnSize],ans);
		(*returnSize)++;
		return ret;
	}
	
	if(digits[pos]=='7'||digits[pos]=='9'){
		t=4;
	}else{
		t=3;
	}
	
	for(i=0;i<t;i++){
		ans[pos]=map[digits[pos]-'0'][i];
		tmp=pos;
		pos++;
		letterCombinations(digits,returnSize);
		pos=tmp;
	}
	

	return ret;
}

