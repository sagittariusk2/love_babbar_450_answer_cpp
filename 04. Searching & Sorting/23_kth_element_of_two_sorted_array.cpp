/**
 * @file 23_kth_element_of_two_sorted_array
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 01:40
 * @link https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
 * @copyright Copyright (c) 2022
 */

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        if(n>m) {
            return kthElement(arr2, arr1, m, n, k);
        }
        int i=0, j=n;
        while(i<=j) {
            int mid1 = (i+j)/2;
            int mid2 = k-mid1;
            if(mid2<0) j=mid1;
            else if(mid2>m) i=mid1+1;
            else {
                int a1 = (mid1==0)?INT_MIN:arr1[mid1-1];
                int a2 = (mid1==n)?INT_MAX:arr1[mid1];
                int b1 = (mid2==0)?INT_MIN:arr2[mid2-1];
                int b2 = (mid2==m)?INT_MAX:arr2[mid2];
                if(a1<=b2 and b1<=a2) return max(a1, b1);
                else if(a1>b2) {
                    j=mid1;
                } else {
                    i=mid1+1;
                }
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends