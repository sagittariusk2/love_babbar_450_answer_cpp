/**
 * @file 07_reverse_a_string_using_stack
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-23
 * @time 02:22
 * @link https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1
 * @copyright Copyright (c) 2022
 */

#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}

// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
    stack<char> s1;
    for(int i=0; i<len; i++) {
        s1.push(S[i]);
    }
    int i=0;
    while(!s1.empty()) {
        S[i++]=s1.top();
        s1.pop();
    }
    return S;
}