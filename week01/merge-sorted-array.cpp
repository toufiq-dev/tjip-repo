#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == 0) {
                nums1[i] = nums2[j];
                j++;
            }

            i++;
        }

        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    vector<int> arr1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> arr2 = {2, 5, 6};
    int n = 3;

    Solution sln;

    sln.merge(arr1, m, arr2, n);

    for(int x : arr1) {
        cout << x << " ";
    }

    return 0;
}