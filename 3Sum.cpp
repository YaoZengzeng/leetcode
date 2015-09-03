class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        bool zeroIncluded;
        
        if(nums.size()<3){
            return ans;
        }
        
        if(nums[0]==0&&nums[1]==0&&nums[2]==0){
            zeroIncluded=true;
        }else{
            zeroIncluded=false;
        }
        for(int boundary=2;boundary<nums.size();boundary++){
            int type;
            if(boundary>2&&nums[boundary]==nums[boundary-1]&&nums[boundary-1]==nums[boundary-2]){
                if(nums[boundary]==0&&!zeroIncluded){
                    vector<int> t(3,0);
                    ans.push_back(t);
                    zeroIncluded=true;
                }
                continue;
            }else if (boundary>2&&nums[boundary]==nums[boundary-1]){
                type=1;
            }else{
                type=0;
            }
            
            int beg=0,end=boundary-1;
            switch(type){
            case 0:
                while(beg<end){
                    if(nums[beg]+nums[end]+nums[boundary]==0){
                        vector<int> t;
                        t.push_back(nums[beg]);
                        t.push_back(nums[end]);
                        t.push_back(nums[boundary]);
                        ans.push_back(t);
                        beg++;
                        while(beg<boundary&&nums[beg]==nums[beg-1]){
                            beg++;
                        }
                        end--;
                        while(end>=0&&nums[end]==nums[end+1]){
                            end--;
                        }
                    }else if(nums[beg]+nums[end]+nums[boundary]<0){
                        beg++;
                    }else{
                        end--;
                    }
                }
                break;
            case 1:
                while(beg<end){
                    if(nums[beg]+nums[end]+nums[boundary]==0){
                        vector<int> t;
                        t.push_back(nums[beg]);
                        t.push_back(nums[end]);
                        t.push_back(nums[boundary]);
                        ans.push_back(t);
                        break;
                    }else if(nums[beg]+nums[end]+nums[boundary]<0){
                        beg++;
                    }else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
