class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> mp;
        int l=0,r=0;
        int ans = 0;
        while(r<s.size())
        {
            auto it = mp.find(s[r]);

            if(it != mp.end())
            {
                l = max(l,it->second+1); //to see why we need max, check testcase abba
                // we need max as we want our left pointer to only move front, not back
    
            }

            mp[s[r]] = r;
            r++;
            ans = max(ans,r-l);

        }
        return ans;


        
    }
};


// didnt follow strive3rs,followed neetcode for this
// check test case abba
// keep incrementing r pointer and adding elemtnt with index to map, if we get duplicate, increment l to index after duplicate