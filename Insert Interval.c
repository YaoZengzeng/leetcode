/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    int i,beg,end;
    struct Interval* ans;
    
    ans=(struct Interval*)malloc((intervalsSize+1)*sizeof(struct Interval));
    
    *returnSize=0;
    if(intervalsSize==0){
        ans[*returnSize].start=newInterval.start;
        ans[*returnSize].end=newInterval.end;
        (*returnSize)++;
        return ans;
    }
    
    beg=end=0;
    for(i=0;i<intervalsSize;i++){
        if(newInterval.start<=intervals[i].end){
            beg=i;
            break;
        }
    }
    if(i==intervalsSize){
        beg=intervalsSize;
    }
    
    for(i=beg;i<intervalsSize;i++){
        if(newInterval.end<intervals[i].start){
            end=i;
            break;
        }
    }
    if(i==intervalsSize){
        end=intervalsSize;
    }
    
    if(beg<intervalsSize && intervals[beg].start<newInterval.start){
        newInterval.start=intervals[beg].start;
    }
    if(end>0 && intervals[end-1].end>newInterval.end){
        newInterval.end=intervals[end-1].end;
    }
    
    for(i=0;i<intervalsSize;i++){
        if(i==beg){
            ans[*returnSize].start=newInterval.start;
            ans[*returnSize].end=newInterval.end;
            (*returnSize)++;
        }
        if(i>=beg&&i<end){
            continue;
        }
        ans[*returnSize].start=intervals[i].start;
        ans[*returnSize].end=intervals[i].end;
        (*returnSize)++;
    }
    
    if(beg==intervalsSize){
        ans[*returnSize].start=newInterval.start;
        ans[*returnSize].end=newInterval.end;
        (*returnSize)++;    
    }
    
    return ans;
}
