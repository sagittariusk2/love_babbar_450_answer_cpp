/*
    Question link :- (https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/)
    Question :- Program to generate all possible valid IP addresses from given string
*/

/*
    ----@sagittarius_k2-----
    Created by Ritesh Ranjan
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define M 1000000007

vector<string> IPaddress(string str) {
    int n=str.size();
    vector<string> ans;
    for(int i=0; i<n; i++) {
        string x = str.substr(0, i+1);
        bool check1=true;
        int x1;
        if((x[0]=='0' and x!="0") or x.length()>3 or x.length()<=0) check1=false;
        else {
            x1 = stoi(x);
            if(x1>255) check1=false;
        }
        if(check1) {
            for(int j=i+1; j<n; j++) {
                string y = str.substr(i+1, j-i);
                bool check2=true;
                int y1;
                if((y[0]=='0' and y!="0") or y.length()>3 or y.length()<=0) check2=false;
                else {
                    y1 = stoi(y);
                    if(y1>255) check2=false;
                }
                if(check2) {
                    for(int k=j+1; k<n; k++) {
                        string z = str.substr(j+1, k-j);
                        if((z[0]=='0' and z!="0") or (z.length()>3 or z.length()<=0)) ;
                        else {
                            int z1 = stoi(z);
                            if(z1<256) {
                                string a = str.substr(k+1);
                                if((a[0]=='0' and a!="0") or (a.length()>3 or a.length()<=0)) ;
                                else {
                                    int a1 = stoi(a);
                                    if(a1<256) {
                                        ans.push_back(to_string(x1)+'.'+to_string(y1)+'.'+to_string(z1)+'.'+to_string(a1));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin >> str;
        vector<string> ans = IPaddress(str);
        for(auto i:ans) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}

/*
    Time Complexity :- O(n)
    Space Complexity :- O(1)
*/