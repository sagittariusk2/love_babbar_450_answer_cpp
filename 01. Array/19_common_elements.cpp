/* 
    Question Link :- (https://practice.geeksforgeeks.org/problems/common-elements1132/1#)
    Common elements
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

// Brute Force :- Time complexity :- O(n1*n2*n3), Space Complexity :- O(1)

// 3 pointer approach

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {
    int i=0, j=0, k=0;
    vector<int> ans;

    while(i<n1 && j<n2 && k<n3) {
        if(A[i]==B[j] && B[j]==C[k]) {
            if(ans.size()==0 || ans[ans.size()-1]!=C[k])
                ans.push_back(A[i]);
            i++, j++, k++;
        }
        else if(A[i]<=B[j] && A[i]<=C[k]) i++;
        else if(B[j]<=A[i] && B[j]<=C[k]) j++;
        else k++;
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n1, n2, n3;
        cin>>n1>>n2>>n3;
        int A[n1], B[n2], C[n3];
        for(int i=0; i<n1; i++) {
            cin>>A[i];
        }

        for(int i=0; i<n2; i++) {
            cin>>B[i];
        }

        for(int i=0; i<n2; i++) {
            cin>>C[i];
        }

        vector<int> ans = commonElements(A, B, C, n1, n2, n3);

        for(auto i:ans) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n1+n2+n3)
    Space Complexity :- O(1)
*/
