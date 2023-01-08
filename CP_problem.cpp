//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// Driver program to test above functions
int main() {
   /* long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }*/
   int arr[]={-8 ,2, 3 ,-6, 10};
    int size=sizeof (arr)/sizeof (arr[0]);
    vector<int> ans;
    ans= printFirstNegativeInteg(arr,size,2);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
