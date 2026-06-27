/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        if(intervals.empty()) return 0;

        vector<int> starts;
        vector<int> ends;

        for(auto &interval: intervals){
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int overlaps = 0;
        int max_overlaps = INT_MIN;
        
        int end = 0;
        int start = 0;

        while(end < ends.size()){
            while(start < starts.size() && starts[start] < ends[end]){
                start++;
                overlaps++;
            }

            max_overlaps = max(overlaps, max_overlaps);

            end++;
            overlaps--;
        }

        return max_overlaps; 
    }
};
