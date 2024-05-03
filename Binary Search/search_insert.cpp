//You are given a sorted array 'arr' of distinct values and a target value 'm'.
// You need to search for the index of the target value in the array.
// Note:
// If the value is present in the array, return its index.
// If the value is absent, determine the index where it would be inserted in the array while maintaining the sorted order. 

#include<bits/stdc++.h>
int searchInsert(vector<int>& arr, int m)
{
	int l=0,r=arr.size()-1;
	int ans;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(arr[mid]==m)
		{
			return mid;
		}
		else if(arr[mid]<m)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	ans = upper_bound(arr.begin(),arr.end(),m) - arr.begin();
	return ans;
}
