class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        // sorting the vector , because sorting is a prerequisite for applying two pointer approach
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        // here the loop will traverse only upto last second element
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || i>0 && (nums[i]!=nums[i-1]))   // this check is basically done to avoid duplicacy in answer
            {
                int low=i+1;                          // low pointer
                int high=nums.size()-1;               // high pointer
                int sum=0-nums[i];                    // actual sum that needs to be find after subtracting nums[i] from 0
                
                while(low<high)
                {
                    // if we get the required sum , then push all these elements into a vector and then push that vector into ans vector
                    if(nums[low]+nums[high]==sum)
                    {
                        vector<int> v1;
                        v1.push_back(nums[i]);
                        v1.push_back(nums[low]);
                        v1.push_back(nums[high]);
                        ans.push_back(v1);
                        // the below two while loop are to avoid the duplicate answers
                        while(low<high && nums[low]==nums[low+1])
                        {
                           low++;
                        }
                        while(low<high && nums[high]==nums[high-1])
                        {
                           high--;
                        }
                        // updating the low and the high pointer
                        low++;
                        high--;
                    }
                    // if we get the value less than required sum , then simply update low pointer
                    else if(nums[low]+nums[high]<sum)
                    {
                        low++;
                    }
                    // if we get the value greater than required sum, then update high pointer
                    else
                    {
                        high--;
                    }
                    
                    
                }
            }
        }
        return ans;
        
    }
};