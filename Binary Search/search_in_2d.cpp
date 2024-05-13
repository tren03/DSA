74. Search a 2D Matrix
Solved
Medium
Topics
Companies
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.




class Solution {
public: 
    int od(int i,int j,int n)
    {
        return (i*(n)+j);
    }
    pair<int,int> td(int x,int n)
    {
        return {x/n,x%n};   
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //1d -> 2d => x/n,x%n;
        //2d -> 1d => x = i(n) + j;
        
        int m = matrix.size();
        int n = matrix[0].size();

        int l = od(0,0,n);
        int r = od(m-1,n-1,n);

        while(r>=l)
        {
            int mid = (l+r)/2;
            pair<int,int> m_2d = td(mid,n);
            cout<<"l = "<<l;
            cout<<"r = "<<r;
            cout<<endl;
            if(matrix[m_2d.first][m_2d.second] == target)
            {
                return true;
            }
            else if(matrix[m_2d.first][m_2d.second]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
            
        }
        return false;


        
        
    }
    
};