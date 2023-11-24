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