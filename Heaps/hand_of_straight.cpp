846. Hand of Straights
Medium
Topics
Companies
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.




class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> mp;
        priority_queue<int, vector<int>, greater<int>> pq; // min heap initialization
        for(auto i : hand) {
            mp[i]++;
            pq.push(i);
        }

        while(!pq.empty()) {
            int start = pq.top(); // Start from the smallest card value
            pq.pop();

            if(mp[start] == 0) // If this card has already been used, continue to the next one
                continue;
            
            mp[start]--;

            for(int i=1;i<groupSize;i++)
            {
                
                int next = start + i;
                cout<<next;
                if(mp.find(next)==mp.end() || mp[next]==0)
                {
                    return false;
                }
                mp[next]--;
            }
        
        }
        return true;
    }
};

