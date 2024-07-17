//subsets wihtout duplicates

class Solution {
public:
    void rec(int ind,vector<int> &nums,vector<vector<int>> &ans,vector<int> temp)
    {
        if(ind >= nums.size())
        {
            ans.push_back(temp);
            return;
        }
        

        // include ele
        temp.push_back(nums[ind]);
        rec(ind+1,nums,ans,temp);
        


        // exclude element 
        temp.pop_back();
        while(ind+1<nums.size() && nums[ind] == nums[ind+1]) // run loop till we do not rech duplicate element as they are in ordeer
        {
            ind=ind+1;
        }
        
        rec(ind+1,nums,ans,temp);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        rec(0,nums,ans,temp);
        return ans;

        
        
    }
};