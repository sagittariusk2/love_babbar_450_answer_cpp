/**
 * @file 01_building_heap_from_array
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-29
 * @time 23:59
 * @link https://www.geeksforgeeks.org/building-heap-from-array/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
#define int long long
using namespace std;

class myHeap {
private:
    vector<int> nums;

    int parent(int i) {
        return (i-1)/2;
    }

public:
    myHeap() {}

    myHeap(vector<int> v1) {
        nums=v1;
        for(int i=(nums.size()/2)-1; i>=0; i--) {
            heapify(i);
        }
    }

    myHeap(int a[], int n) {}

    void insert(int val) {
        nums.push_back(val);
        int i=nums.size()-1;
        while(i!=0 and nums[parent(i)]<nums[i]) {
            swap(nums[parent(i)], nums[i]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int x = i;
        int l = 2*i+1;
        int r = 2*i+2;

        if(l<nums.size() and nums[l]>nums[x]) {
            x = l;
        }
        if(r<nums.size() and nums[r]>nums[x]) {
            x = r;
        }
        if(x != i) {
            swap(nums[i], nums[x]);
            heapify(x);
        }
    }

    void print() {
        for(auto i:nums) cout << i << " ";
        cout << endl;
    }

    int getMax() {
        return nums[0];
    }

    int extractMax() {
        if(nums.empty()) {
            cerr << "No element found\n";
            return INT_MIN;
        }
        int ans = nums[0];
        nums[0] = nums[nums.size()-1];
        nums.resize(nums.size()-1);
        if(!nums.empty())
            heapify(0);
        return ans;
    }

    void decreaseKey() {}

    void deleteKey() {}

};

signed main() {
    //code here
    myHeap hp({1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17});
    hp.insert(100);
    hp.print();
}