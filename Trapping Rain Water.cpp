class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> idx;
        
        if(height.size()<3){

            return 0;

        }

	int l=0;
	while(l<height.size()-1 && height[l]==height[l+1]){
		l++;
	}

	if(l==(height.size()-1)){
		return 0;
	}

        if(height[l]>height[l+1]){

            idx.push_back(l);

        }

	int i=l+1;
	while(i<height.size()-1){
		if(height[i]>height[i-1]){
			while(i<height.size()-1 && height[i]==height[i+1]){
				i++;
			}
			if(i==height.size()-1 || height[i]>height[i+1]){
				int max;
				int j=idx.size()-1;
				if(j<=0){
				    goto L1;
				}
				while(j>0&&height[idx[j-1]]>=height[idx[j]]){
					j--;
				}
				max=height[idx[j]];
				j=idx.size()-1;
				while(height[idx[j]]<height[i] && height[idx[j]]<max) {
					idx.pop_back();
					j--;
				}
			L1:	idx.push_back(i);
			}
				
		}
		i++;
	}

	if(height[height.size()-1]>height[height.size()-2]){
		int max;
                int j=idx.size()-1;
                if(j<=0){
                    goto L2;
                }
                while(j>0&&height[idx[j-1]]>=height[idx[j]]){
                        j--;
                }
                max=height[idx[j]];
                j=idx.size()-1;
                while(height[idx[j]]<height[height.size()-1] && height[idx[j]]<max) {
                        idx.pop_back();
			            j--;
                }
	
		        L2: idx.push_back(height.size()-1);
	}

    int sum=0;

	int len=idx.size();
    for(int i=0;i<len-1;i++){
        int min=height[idx[i]]<height[idx[i+1]] ? height[idx[i]] : height[idx[i+1]];
        for(int j=idx[i]+1;j<idx[i+1];j++){
            if(height[j]<min){
                sum += (min-height[j]);
            }
        }
    }

        
        return sum;

    }
};
