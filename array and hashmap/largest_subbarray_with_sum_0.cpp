https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int sum  = 0;
        int len,ans=0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<arr.size();i++)
        {
            sum += arr[i];
            if(sum == 0)
            {
            
                ans = max(i+1,ans);
            }
            if(mp.find(sum) != mp.end())
            {
                auto it = mp.find(sum);
                ans = max(ans,i - it->second);
            }
            else
            {
                mp.insert({sum,i});
            }
            
            
            
        }
        return ans;
        
    }
};

// approach = we keep calculating sum till current element and store in hashmap with index.
// if sum is equal to previous sum again, then we calculate difference between indexes
// is sum calculated == 0 , update ans with max(ans,i+1)