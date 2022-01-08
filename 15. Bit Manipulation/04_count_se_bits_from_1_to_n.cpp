/**
 * @file 04_count_se_bits_from_1_to_n
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-08
 * @time 02:00
 * @link https://practice.geeksforgeeks.org/problems/count-total-set-bits/0
 * @copyright Copyright (c) 2022
 */


//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n) {
        n++;
        int x=2, ans=0, y=32, f=n-1;
        while(f) {
            int r = max(0, n%x-x/2);
            int t = n-n%x;
            ans += (t/2)+r;
            // cout << ans << " ";
            x *= 2;
            
            f/=2;
        }
        return ans;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends