https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])==s.end())
            {
                s.insert(nums[i]);
            }
            
        }

        int temp = 0;
        int ans = 0;

        for(auto i: nums)
        {
            temp = 1;
            int t = i;
            if(s.find(t-1)==s.end()) // if no previous element exists, that means that it may be start of the seq, helps reduce time taken
            {
                while(s.find(t+1)!=s.end())
                {
                    temp++;
                    t++;
                }
            }
            ans = max(temp,ans);
        }
        return ans;

        
        
    }
};

/* How to identify if a number can be the starting number for a sequence:

First, we will put all the array elements into the set data structure.
If a number, num, is a starting number, ideally, num-1 should not exist. So, for every element, x, in the set, we will check if x-1 exists inside the set. :
If x-1 exists: This means x cannot be a starting number and we will move on to the next element in the set.
If x-1 does not exist: This means x is a starting number of a sequence. So, for number, x, we will start finding the consecutive elements.
How to search for consecutive elements for a number, x:

Instead of using linear search, we will use the set data structure itself to search for the elements x+1, x+2, x+3, and so on.
Thus, using this method we can narrow down the search and optimize the approach.

*/