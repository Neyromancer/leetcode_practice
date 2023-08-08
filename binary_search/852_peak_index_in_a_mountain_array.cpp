/*
Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

An array arr is a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.

Example:
1/
Input: arr = [0,1,0]
Output: 1

2/
Input: arr = [0,2,1,0]
Output: 1

3/
Input: arr = [0,10,5,2]
Output: 1
*/

class Solution {
public:
    /*
        TC: O(log N), where N == len(arr)
        SC: O(1)
    */
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size();

        while (r - l > 1) {
            int m = l + (r - l) / 2;

            if (m > 0 && m < arr.size() && arr[m - 1] < arr[m] && arr[m + 1] < arr[m])
                return m;

            if (m > 0 && arr[m - 1] < arr[m])
                l = m;
            else if (m < arr.size() && arr[m + 1] < arr[m])
                r = m;
        }

        if (l > 0 && l < arr.size() && arr[l - 1] < arr[l] && arr[l + 1] < arr[l])
            return l;       
        return -1;
    }
};
