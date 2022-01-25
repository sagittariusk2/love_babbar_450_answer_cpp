/**
 * @file 19_expression_contains_redundant_bracket_or_not
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-25
 * @time 15:20
 * @link https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

#include<stack>
bool findRedundantBrackets(string &s) {
    // Write your code here.
    stack<char> brackets;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            brackets.push(s[i]);
        }
        else if (s[i] == ')'){
            bool isRedundant = true;
            while (brackets.top() != '(') {
                if (brackets.top() == '+' || brackets.top() == '-' || brackets.top() == '*' || brackets.top() == '/') {
                    isRedundant = false;
                }
                brackets.pop();
            }
            brackets.pop();
            if (isRedundant == true){
                return true;
            }
        }
    }
    return false;
}


signed main() {
    //code here
}