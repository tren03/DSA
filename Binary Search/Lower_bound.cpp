
#include<bits/stdc++.h>
#include <vector>
int lowerBound(vector<int> arr, int n, int x) {
	int l=0,r=n-1;
	int ans = n;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(arr[mid]<x)
		{
			l=mid+1;
		}
		else
		{
			
			r=mid-1;
			ans = mid;
			
		}
	}
	return ans;
};
