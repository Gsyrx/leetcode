
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// // distinct elements
// int countDistinct(int arr[], int n)
// {
//   unordered_set<int> uniqueElements;
//   for (int i = 0; i < n; i++)
//     uniqueElements.insert(arr[i]);

//   return uniqueElements.size();

//   // unordered_set<int> uniqueElements(nums.begin(), nums.end());
//   // return uniqueElements.size();
// }

// // frequency
// std::unordered_map<int, int> countFrequencies(const std::vector<int> &nums)
// {
//   std::unordered_map<int, int> frequencyMap;

//   for (int num : nums)
//   {
//     // Increment the frequency of the current element
//     frequencyMap[num]++;
//   }

//   return frequencyMap;
// }

// Intersection of two unsorted arrays

vector<int> findIntersection(int num1[], int n, int num2[], int m)
{
  unordered_set<int> set1(num1, num1 + n);
  vector<int> intersection;
  for (int i = 0; i < m; i++)
  {
    if (set1.find(num2[i]) != set1.end())
    {
      intersection.push_back(num2[i]);
      set1.erase(num2[i]); // to avoid duplicates
    }
  }

  return intersection;
}

// union of two unsorted arrays

int findUnion(int num1[], int n, int num2[], int m)
{
  unordered_set<int> unionSet(num1, num1 + n);

  for (int i = 0; i < m; i++)
  {
    unionSet.insert(num2[i]);
  }

  return unionSet.size();
}

// Pair with given sum in unsorted array

bool findPairWithSum(int arr[], int n, int target)
{
  unordered_set<int> present;

  for (int i = 0; i < n; i++)
  {
    if (present.find(target - arr[i]) != present.end())
    {
      return true;
    }
    present.insert(arr[i]);
  }

  return false;
}

// subarray with zero sum

bool hasZeroSumSubarray(int arr[], int n)
{
  unordered_set<int> found;

  int prefixSum = 0;

  for (int i = 0; i < n; i++)
  {
    prefixSum += arr[i];
    if (found.find(prefixSum) != found.end() || prefixSum == 0)
    {
      return true;
    }
    found.insert(prefixSum);
  }

  return false;
}

// subarray with given sum
bool hasSubarrayWithSum(int arr[], int n, int targetSum)
{
  unordered_set<int> sumSet;
  int currentSum = 0;

  for (int i = 0; i < n; i++)
  {
    currentSum += arr[i];

    if (currentSum == targetSum || sumSet.find(currentSum - targetSum) != sumSet.end())
    {
      return true; // Subarray with the target sum found
    }

    sumSet.insert(currentSum);
  }

  return false; // No subarray with the target sum found
}

// largest subarray with given sum

int largestSubarrayWithSumX(int arr[], int n, int sum)
{
  int prefix_sum = 0, res = 0;
  unordered_map<int, int> m;
  for (int i = 0; i < n; i++)
  {
    prefix_sum += arr[i];
    if (prefix_sum == sum)
      res = i + 1;
    if (m.find(prefix_sum) == m.end())
      m.insert({prefix_sum, i});
    if (m.find(prefix_sum - sum) != m.end())
      res = max(res, i - m[prefix_sum - sum]);
  }
  return res;
}

// Longest Consecutive Subsequence
int findLongest(int arr[], int n)
{
  unordered_set<int> s;
  int res = 0;

  for (int i = 0; i < n; i++)
    s.insert(arr[i]);

  for (int i = 0; i < n; i++)
  {
    if (s.find(arr[i] - 1) == s.end())
    {
      int curr = 1;
      while (s.find(curr + arr[i]) != s.end())
        curr++;

      res = max(res, curr);
    }
  }
  return res;
}

// More than n/k Occurences

void printNByK(int arr[], int n, int k)
{
  unordered_map<int, int> m;

  for (int i = 0; i < n; i++)
    m[arr[i]]++;
  for (auto e : m)
    if (e.second > n / k)
      cout << e.first << " ";
}