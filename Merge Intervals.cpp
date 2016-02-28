/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    struct compInterval {
        bool operator()(const Interval &a, const Interval &b) const {
            return a.start<b.start;
        }
    };
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.size()==0){
            return ans;
        }
        sort(intervals.begin(),intervals.end(),compInterval());
        
        Interval t=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start>t.end){
                ans.push_back(t);
                t=intervals[i];
            }else if(intervals[i].end>t.end){
                t.end=intervals[i].end;
            }
        }
        ans.push_back(t);
        
        return ans;
    }
};
