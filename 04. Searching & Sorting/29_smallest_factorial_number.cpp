/**
 * @file 29_smallest_factorial_number
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 01:43
 * @link https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1
 * @copyright Copyright (c) 2022
 */

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:

    bool check(int mid, int n) {
        int count = 0, f = 5;
        while(f<=mid) {
            count += mid/f;
            f *= 5;
        }
        return (count>=n);
    }

    int findNum(int n) {
        int i=0, j=5*n;
        while(i<j) {
            int mid = (i+j)/2;
            if(check(mid, n)) {
                j = mid;
            } else {
                i = mid+1;
            }
        }
        return i;
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends