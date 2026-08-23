class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        
        int n = aliceValues.size();

        priority_queue<pair<int,int> > pq;


        for(int i=0; i<n; i++) {

            int combine = aliceValues[i] + bobValues[i];
            pq.push({combine, i});

        }

        bool flag = true;
        int aliceGet = 0,
            bobGet   = 0;

        while(!pq.empty()) {

            pair<int,int> top = pq.top(); pq.pop();
            int val   = top.first;
            int index = top.second;

            if(flag == true) 
                aliceGet += aliceValues[index];
            else
                bobGet   += bobValues[index];

            flag = !flag;

                
        }

        if(aliceGet > bobGet) 
            return 1;
        else if(bobGet > aliceGet) 
            return -1;
        else
            return 0;



    }
};