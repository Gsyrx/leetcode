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

/*   <<<<<--------------------------  Rotate Array  ------------------------------------------->>>>>

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.



Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

*/

class Solution
{
public:
  void reverse(vector<int> &nums, int start, int end)
  {
    while (start < end)
    {
      int temp = nums[start];
      nums[start] = nums[end];
      nums[end] = temp;
      start++;
      end--;
    }
  }
  void rotate(vector<int> &nums, int k)
  {

    int n = k % nums.size();

    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, n - 1);
    reverse(nums, n, nums.size() - 1);
  }
};