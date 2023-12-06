#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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

/*   <<<<<--------------------------  Reverse Words in a String  -------------------------------------------->>>>>

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

*/

class Solution
{
public:
  string reverseWords(string s)
  {

    vector<string> v;
    stringstream ss(s);

    string word;

    while (ss >> word)
    {
      v.push_back(word);
    }

    string res = "";

    for (int i = v.size() - 1; i > 0; i--)
    {
      res += v[i] + " ";
    }

    return res + v[0];
  }
};

/*   <<<<<-------------------------- Minimum Equal Sum of Two Arrays After Replacing Zeros  -------------------------------------------->>>>>

Example 1:

Input: nums1 = [3,2,0,1,0], nums2 = [6,5,0]
Output: 12
Explanation: We can replace 0's in the following way:
- Replace the two 0's in nums1 with the values 2 and 4. The resulting array is nums1 = [3,2,2,1,4].
- Replace the 0 in nums2 with the value 1. The resulting array is nums2 = [6,5,1].
Both arrays have an equal sum of 12. It can be shown that it is the minimum sum we can obtain.
Example 2:

Input: nums1 = [2,0,2,0], nums2 = [1,4]
Output: -1
Explanation: It is impossible to make the sum of both arrays equal.

*/

class Solution
{
public:
  long long minSum(vector<int> &nums1, vector<int> &nums2)
  {
    long long sum1 = 0, sum2 = 0;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < nums1.size(); i++)
    {
      sum1 += nums1[i];
      if (nums1[i] == 0)
      {
        count1++;
      }
    }

    for (int i = 0; i < nums2.size(); i++)
    {
      sum2 += nums2[i];
      if (nums2[i] == 0)
      {
        count2++;
      }
    }

    if ((count1 == 0 && sum2 + count2 > sum1) || (count2 == 0 && sum1 + count1 > sum2))
    {
      return -1;
    }
    else
    {
      return max(sum1 + count1, sum2 + count2);
    }
  }
};

/*   <<<<<-------------------------- Product of Array Except Self  -------------------------------------------->>>>>

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

*/

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();

    vector<int> output(n, 1);

    int left_product = 1;
    for (int i = 0; i < n; ++i)
    {
      output[i] *= left_product;
      left_product *= nums[i];
    }

    int right_product = 1;
    for (int i = n - 1; i >= 0; --i)
    {
      output[i] *= right_product;
      right_product *= nums[i];
    }

    return output;
  }
};

/*   <<<<<-------------------------- Max Number of K-Sum Pairs  -------------------------------------------->>>>>

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.

*/

class Solution
{
public:
  int maxOperations(vector<int> &nums, int k)
  {
    sort(nums.begin(), nums.end());

    int count = 0, start = 0, end = nums.size() - 1;
    while (start < end)
    {
      int sum = nums[start] + nums[end];

      if (sum == k)
      {
        count++;
        start++;
        end--;
      }
      else if (sum < k)
      {
        start++;
      }
      else
      {
        end--;
      }
    }

    return count;
  }
};

/*   <<<<<-------------------------- Maximum Average Subarray I  -------------------------------------------->>>>>

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000

*/

class Solution
{
public:
  double findMaxAverage(vector<int> &nums, int k)
  {
    int windowSum = 0;
    for (int i = 0; i < k; i++)
    {
      windowSum += nums[i];
    }

    double maxAvg = (double)windowSum / k;
    for (int i = k; i < nums.size(); i++)
    {
      windowSum += nums[i] - nums[i - k];
      maxAvg = max(maxAvg, (double)windowSum / k);
    }

    return maxAvg;
  }
};

/*   <<<<<-------------------------- Maximum Number of Vowels in a Substring of Given Length  -------------------------------------------->>>>>

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

*/

class Solution
{
public:
  bool isVowel(char ch)
  {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
  }

  int maxVowels(string s, int k)
  {
    int n = s.length();
    int count = 0;

    for (int i = 0; i < k; i++)
    {
      if (isVowel(s[i]))
      {
        count++;
      }
    }
    int maxCount = count;

    for (int i = k; i < n; i++)
    {
      if (isVowel(s[i]))
      {
        count++;
      }
      if (isVowel(s[i - k]))
      {
        count--;
      }
      maxCount = max(maxCount, count);
    }

    return maxCount;
  }
};

/*   <<<<<-------------------------- Find Words That Can Be Formed by Characters  -------------------------------------------->>>>>

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

*/

class Solution
{
public:
  bool canForm(string word, string chars)
  {
    unordered_map<char, int> charCount;
    for (char c : chars)
    {
      charCount[c]++;
    }

    for (char c : word)
    {
      if (charCount[c] == 0)
      {
        return false;
      }
      charCount[c]--;
    }

    return true;
  }

  int countCharacters(vector<string> &words, string chars)
  {
    int totalCount = 0;

    for (int i = 0; i < words.size(); i++)
    {
      if (canForm(words[i], chars))
      {
        totalCount += words[i].length();
      }
    }

    return totalCount;
  }
};

/*   <<<<<--------------------------  Largest 3-Same-Digit Number in String -------------------------------------------->>>>>

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".

*/

class Solution
{
public:
  string largestGoodInteger(string nums)
  {
    string maxSubstring = "";
    for (int i = 0; i < nums.size() - 2; i++)
    {
      string currentSubstring = "";
      if (nums[i] == nums[i + 1] && nums[i] == nums[i + 2])
      {
        currentSubstring = nums.substr(i, 3);
        maxSubstring = max(maxSubstring, currentSubstring);
      }
    }
    return maxSubstring;
  }
};
