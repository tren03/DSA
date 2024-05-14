


// still need to strenghten logic on this one

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (auto i : tasks) {
            mp[i]++;
        }
        priority_queue<int> pq;
        for (auto i : mp) {
            pq.push(i.second);
        }

        queue<pair<int, int>> q;
        int time = 0;

        while (!q.empty() || !pq.empty()) {


            time++;
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            } 

            if (!pq.empty()) {
                int temp = pq.top();
                pq.pop();
                if (temp > 1) { // we should not push 0 to que 
                    q.push({temp - 1, time + n+1});
                }
            }
        }
        return time;
    }
};