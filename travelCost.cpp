/*
	983. https://leetcode.com/problems/minimum-cost-for-tickets/
*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int totalDays = days.size();
        
        vector<int> itenerary(366,0);
        
        for(int i = 0; i<totalDays; i++)
        {
            itenerary[days[i]] = 1;
        }
        
        // cost cannot be greater than 400*1000
        vector<int> travelCost(366, 400*1000);
        
        travelCost[0] = 0; //travelCost for 0th day is 0
        
        int pre = 0;
        
        for(int day = 1; day<=365; day+=1)
        {
            if(itenerary[day])
            {
                if(day-30>=0)
                {
                    travelCost[day] = min(travelCost[day], travelCost[day-30]+costs[2]);
                }
                else
                {
                    travelCost[day] = min(travelCost[day], costs[2]);
                }
                
                if(day-7>=0)
                {
                    travelCost[day] = min(travelCost[day], travelCost[day-7]+costs[1]);
                }
                else
                {
                    travelCost[day] = min(travelCost[day], costs[1]);
                }
                
                if(day-1>=0)
                {
                    travelCost[day] = min(travelCost[day], travelCost[day-1]+costs[0]);
                }
                else
                {
                    travelCost[day] = min(travelCost[day], costs[0]);
                }
                
                pre = travelCost[day];
                
            }
            else
            {
                travelCost[day] = pre;
            }
        }
        
        return pre;
    }
};
