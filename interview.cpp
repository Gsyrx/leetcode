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

/*   <<<<<--------------------------  Minimum Size Subarray Sum -------------------------------------------->>>>>

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

*/

class Solution
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int curr_sum = 0;
    int sum = INT_MAX;
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      curr_sum += nums[i];
      while (curr_sum >= target)
      {
        curr_sum -= nums[j];
        sum = min(sum, i - j + 1);
        j++;
      }
    }

    return sum == INT_MAX ? 0 : sum;
  }
};

/*   <<<<<--------------------------  Two Sum II - Input Array Is Sorted -------------------------------------------->>>>>

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

*/

class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {

    int i = 0, j = numbers.size() - 1;
    int a, b;

    while (i < j)
    {
      int sum = numbers[i] + numbers[j];
      if (sum == target)
      {
        a = i + 1;
        b = j + 1;
        break;
      }
      else if (sum < target)
      {
        i++;
      }
      else
      {
        j--;
      }
    }
    return {a, b};
  }
};

/*   <<<<<--------------------------  Reverse Vowels of a String -------------------------------------------->>>>>

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.



Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"

*/

class Solution
{
public:
  bool isvowel(char ch)
  {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u';
  }
  string reverseVowels(string s)
  {
    int n = s.length();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
      if (!isvowel(s[i]))
        i++;
      else if (!isvowel(s[j]))
        j--;
      else if (i < j)
      {
        swap(s[i], s[j]);
        i++;
        j--;
      }
    }
    return s;
  }
};

// 2nd soln.
class Solution
{
public:
  string reverseVowels(string s)
  {
    unordered_set<char> ch = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
      // while(!ch.count(s[i])&&i<j){
      //     i++;
      // }
      // while(!ch.count(s[j])&&i<j){
      //     j--;
      // }
      // swap(s[i],s[j]);
      // i++;
      // j--;

      if (!ch.count(s[i]))
      {
        i++;
      }
      else if (!ch.count(s[j]))
      {
        j--;
      }
      else if (i < j)
      {
        swap(s[i], s[j]);
        i++;
        j--;
      }
    }

    return s;
  }
};