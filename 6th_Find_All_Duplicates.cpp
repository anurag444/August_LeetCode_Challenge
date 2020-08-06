/*  Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]    */

//SOLUTION

vector<int> findDuplicates(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<int> result;
        
        for(int i = 1 ; i< nums.size(); i++){
            if(nums[i] == nums[i-1]) result.push_back(nums[i]);
        }
    
        return result;
    }