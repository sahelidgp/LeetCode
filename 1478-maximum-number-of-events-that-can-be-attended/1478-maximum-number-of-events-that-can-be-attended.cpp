class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(begin(events),end(events)); // nlogn

        priority_queue<int,vector<int>,greater<int>>pq; //min-heap

        int day = events[0][0];
        int i = 0;
        int count = 0;//result number of events attended 
        
        //push and pop for every events attended
        //push pop
        //n*logn
        while(!pq.empty() || i < n){

            if(pq.empty())
            day = events[i][0];
            while(i<n && events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }
        
        if(!pq.empty()){
        pq.pop(); // 1 event attended on this day
        count++; // counting the result
        }
        day++;

        //skip those events whose endDay < day
        while(!pq.empty() && pq.top()<day){
            pq.pop();
        }
        }
        return count;
    }
};
/*
for any day if I have an option to select among events ,I will choose the one that ends earlier

skip the events whose endday < day
*/