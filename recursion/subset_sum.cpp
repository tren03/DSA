// return vector with all the sums of the subsets
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    // void rec(int,vector<int>&,vector<int>&,int);
    vector<int> ans;
    vector<int> subsetSums(vector<int> arr, int n) {
        
        rec(0,arr,ans,0);
        return ans;
        
    }
    void rec(int ind,vector<int>& arr,vector<int>& ans,int sum)
    {
        if(ind>=arr.size())
        {
            ans.push_back(sum);
            return;
        }
        
        //include ele
        sum += arr[ind];
        rec(ind+1,arr,ans,sum);

        //exclude ele
        sum -= arr[ind];
        rec(ind+1,arr,ans,sum);
    }
};


// arroach - same as subset gen, choose one element for sum, and do recursion, exclude element for sum and do recursion

