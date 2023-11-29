// kadane algorithm
/*
Kadane's algorithm is a well-known algorithm for finding the maximum subarray sum in a given array of integers.
The algorithm is efficient and has a time complexity of O(n), where n is the number of elements in the array.

Here's the pseudocode for Kadane's algorithm:

Initialize:
  maxEndingHere = nums[0]
  maxSoFar = nums[0]

Loop from i = 1 to n - 1:
  maxEndingHere = max(nums[i], maxEndingHere + nums[i])
  maxSoFar = max(maxSoFar, maxEndingHere)

Return maxSoFar

*/

int kadane(int arr[], int n)
{

  int currentSum = arr[0];
  int maxSum = arr[0];

  for (int i = 1; i < n; i++)
  {

    currentSum = max(arr[i], currentSum + arr[i]);

    maxSum = max(maxSum, currentSum);
  }

  return maxSum;
}

// Moore’s Voting Algorithm

/*
This is a two-step process:-

The first step gives the element that may be the majority element in the array. If there is a majority element in an array, then this step will definitely return majority element, otherwise, it will return candidate for majority element.
Check if the element obtained from the above step is the majority element. This step is necessary as there might be no majority element.
Time Complexity: O(n), As two traversal of the array, is needed, so the time complexity is linear.
Auxiliary Space: O(1), As no extra space is required.

*/

int findMajority(int arr[], int n)
{
  int res = 0, count = 1;

  for (int i = 1; i < n; i++)
  {
    if (arr[res] == arr[i])
      count++;
    else
      count--;

    if (count == 0)
    {
      res = i; // here it's not necessary to get the index of first occurrence of majority element.
      count = 1;
    }
  }

  count = 0;

  for (int i = 0; i < n; i++)
    if (arr[res] == arr[i])
      count++;

  if (count <= n / 2)
    res = -1;

  return res;
}

// Sliding Window Technique
/*
The sliding window technique is especially useful for solving problems
where you need to find a subarray, substring, or any contiguous segment of elements
that satisfies specific conditions (e.g., maximum sum, minimum size, etc.).

*/

int maxSubarraySum(int arr[], int n, int k)
{
  int windowSum = 0;
  int maxSum = 0;

  // Calculate the initial sum of the first 'k' elements
  for (int i = 0; i < k; ++i)
  {
    windowSum += arr[i];
  }

  maxSum = windowSum;
  // Slide the window through the array
  for (int i = k; i < n; ++i)
  {
    windowSum = windowSum - arr[i - k] + arr[i]; // Slide the window

    // Update the maximum sum if the current window sum is greater
    maxSum = max(maxSum, windowSum);
  }

  return maxSum;
}
