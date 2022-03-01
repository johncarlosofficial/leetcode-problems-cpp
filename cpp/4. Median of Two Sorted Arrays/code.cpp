class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i=0;i<nums2.size();i++)
        {
            nums1.push_back(nums2[i]);
        }
        
        sort(nums1.begin(),nums1.end());
        double median=0.0;
        int len=nums1.size();
        int pointer;
            if(len%2==0)
            {
                pointer=len/2;
                median=(nums1[pointer-1]+nums1[pointer])/2.0;               
            }
            else
            {
                pointer=(len+1)/2;
                median=nums1[pointer-1];
            }
        
        return median;
    }
};