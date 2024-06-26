// smallest number >= x - ceil
// largest number <= x - floor

#include<bits/stdc++.h>

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	pair<int,int> ans;
	int l=0,r=n-1;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(arr[mid]==x)
		{
			ans.first = x;
			ans.second = x;
			return ans;
		}
		else if (arr[mid]>x)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	ans.first = (r >= 0) ? arr[r] : -1;     // Set floor to arr[r] or -1 if r is out of bounds
    ans.second = (l < n) ? arr[l] : -1;
	return ans;
}
