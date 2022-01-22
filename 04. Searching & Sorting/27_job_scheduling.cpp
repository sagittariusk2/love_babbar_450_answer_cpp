/**
 * @file 27_job_scheduling
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 00:27
 * @link https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1/
 * @copyright Copyright (c) 2022
 */

// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool comp(Job &a, Job &b) {
    return a.profit>b.profit;
}

class Solution {
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        // your code here
        sort(arr, arr+n, comp);
        // for(int i=0; i<n; i++) {
        //     cout << arr[i].profit << " " << arr[i].dead << endl;
        // }
        vector<int> de(101, 0);
        for(int i=0; i<n; i++) {
            for(int j=arr[i].dead; j>=1; j--) {
                if(de[j]==0) {
                    de[j]=arr[i].profit;
                    break;
                }
            }
        }
        int j=0, ans=0;
        for(int i=0; i<=100; i++) {
            if(de[i]!=0) {
                j++;
                ans += de[i];
            }
        }
        return vector<int>({j, ans});
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends