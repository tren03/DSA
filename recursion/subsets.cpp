//generation of all subsets

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
void rec(int,vector<int>,vector<int>);
int main() {
    // Write C++ code here
    
    vector<int> arr = {1,2,3,5};
    vector<int> temp;
    rec(0,arr,temp);

    return 0;
}
void rec(int ind,vector<int> arr,vector<int> temp)
{
    if(ind>=arr.size())
    {
        for(auto i : temp)
        {
            cout<<i;
        }
        cout<<endl;
        return;
    }
    // include ele
    temp.push_back(arr[ind]);
    rec(ind+1,arr,temp);

    // exclude ele
    temp.pop_back();
    rec(ind+1,arr,temp);
}
 // approach - include element and do recursion, then do  not include element and do recursion

