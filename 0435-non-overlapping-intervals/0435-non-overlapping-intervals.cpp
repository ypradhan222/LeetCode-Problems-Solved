class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //O(nlogn)  sc-O(1)
        sort(intervals.begin(),intervals.end());
        //Approach 1

        int n= intervals.size();
        int count=0;
        /*
        int i=0,j=1;
        while(j<n){
            vector<int> curr= intervals[i];
            vector<int> next= intervals[j];
            int currstart= curr[0];
            int currend = curr[1];
            int nextstart = next[0];
            int nextend= next[1];

            //No overlap
            if(currend<=nextstart){
                i=j;
            }
            else if(currend<=nextend){ //Overlap
                 count++;
            }
            else if(currend>nextend){ //Overlap
                i=j;
                count++;
                
            }
            j++;
        }
        */

        //Approach 2
        int i=1;
        vector<int> lastinterval= intervals[0];
        while(i<n){
            int currstart=intervals[i][0];
            int currend=intervals[i][1];
            int lastend= lastinterval[1];
            if(currstart>=lastend){
                lastinterval= intervals[i];
            }
            else if(currend>=lastend){
                count++;
            }
            else if(currend<lastend){
                lastinterval= intervals[i];
                count++;
            }
            i++;

        }
        return count;
    }
};