/**
 * @file 26_LRU_Cache_Implementation
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-24
 * @time 23:19
 * @link https://practice.geeksforgeeks.org/problems/lru-cache/1
 * @copyright Copyright (c) 2022
 */

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
private:
    list<pair<int, int>> dq;
    map<int, list<pair<int, int>>::iterator> mp;
    int c;

public:
    LRUCache(int cap) {
        c = cap;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end()) {
            int ans = (*mp[key]).second;
            dq.erase(mp[key]);
            dq.push_front(make_pair(key, ans));
            mp[key] = dq.begin();
            return ans;
        }
        return -1;
    }

    void set(int key, int value) {
        if(mp.find(key)!=mp.end()) {
            dq.push_front(make_pair(key, value));
            dq.erase(mp[key]);
            mp[key] = (dq.begin());
            return;
        } 
        if(c==dq.size()) {
            int i = dq.back().first;
            mp.erase(i);
            dq.pop_back();
        }
        dq.emplace_front(key, value);
        mp[key] = dq.begin();
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends