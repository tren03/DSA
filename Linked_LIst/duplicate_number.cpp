
// 287. Find the Duplicate Number
// Solved
// Medium
// Topics
// Companies
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [3,3,3,3,3]
// Output: 3
 

// Constraints:

// 1 <= n <= 105
// nums.length == n + 1
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

// Follow up:

// How can we prove that at least one duplicate number must exist in nums?
// Can you solve the problem in linear runtime complexity?




class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        // consider indexes as nodes and the values as pointers to the other index nodes
        // job is to detect there is a cycle and find the start of the cycle
        // that is the repeated element


        int slowp = arr[0];
        int fastp = arr[arr[0]];
        
        while(slowp!=fastp)
        {
            slowp = arr[slowp];
            fastp = arr[arr[fastp]];
            
        }
        slowp = 0;
        i=0;
        while(slowp!=fastp)
        {
            slowp = arr[slowp];
            fastp = arr[arr[fastp]];
            
        }


        return arr[slowp];

        

        
    }
};