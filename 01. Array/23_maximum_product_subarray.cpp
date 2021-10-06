/*
    Question link :- (https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1)
    Question :- find maximum product subarray
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

long long maxProduct(vector<int> arr, int n) {
	// code here
    long long max_product=arr[0], min_product=arr[0], ans=arr[0];
	for(int i=1; i<n; i++) {
        long long x=max_product, y=min_product;
	    max_product = max((long long)arr[i], (long long)x*arr[i]);
	    max_product = max(max_product, (long long)y*arr[i]);

	    min_product = min((long long)arr[i], (long long)x*arr[i]);
	    min_product = min(min_product, (long long)y*arr[i]);

	    ans=max(ans, max_product);
	}
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<int> arr(n);

        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<maxProduct(arr, n)<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/