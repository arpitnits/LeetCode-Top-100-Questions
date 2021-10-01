/*
  4. MEDIAN OF TWO SORTED ARRAYS [HARD]
  
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example
----------------
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            nums1.swap(nums2);
        }
        int start = 0, end = nums1.size();
        while(start<=end){
            int i = (start+end)/2;
            int j = (nums1.size() + nums2.size() + 1)/2 - i;
            
            int max1 = (i==0 ? INT_MIN : nums1[i-1]);
            int max2 = (j==0 ? INT_MIN : nums2[j-1]);
            
            int min1 = (i==nums1.size() ? INT_MAX: nums1[i]);
            int min2 = (j==nums2.size() ? INT_MAX : nums2[j]);
            
            double max_left = max(max1, max2);
            double min_right = min(min1, min2);
            
            if(max_left <= min_right){
                if((nums1.size() + nums2.size())%2==0){
                    return (max_left + min_right)/2;
                }
                return max_left;
            }else if(max2 > min1){
                start = i+1;
            }else{
                end = i-1;
            }
        }
        return 0;
    }
};
