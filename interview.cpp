/*   <<<<<--------------------------------------------------------------------->>>>>
Given an integer array nums sorted in non-decreasing order,
remove some duplicates in-place such that each unique element appears at most twice.
The relative order of the elements should be kept the same.

Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

*/

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    // int i = 0;
    // for(auto n : nums){
    //     if(i == 0 || i == 1 || nums[i-2]!=n){
    //         nums[i] = n;
    //         i++;
    //     }
    // }

    // return i;

    if (nums.size() < 2)
    {
      return nums.size();
    }
    int slow = 2, fast = 2;
    while (fast < nums.size())
    {
      if (nums[slow - 2] != nums[fast])
      {
        nums[slow] = nums[fast];
        slow += 1;
      }
      fast += 1;
    }
    return slow;
  }
};