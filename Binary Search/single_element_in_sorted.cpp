You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1)
        {
            return nums[0];
        }
        if(nums[0]!=nums[1])
        {
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2])
        {
            return nums[n-1];
        }
        int l=1,r=n-2;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
            {
                return nums[mid];
            }
            else if((mid%2==0 && nums[mid+1]==nums[mid])||(mid%2!=0 && nums[mid-1]==nums[mid]))
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }


        }
        return -1;   


        
    }
};

// try 1123388 and 12233 to get the conditions right