// 2nd largest element in an array
// sort the array
// sort(arr, arr + arr_size);

// only for non repeating numbers
// int findSecondLargest(int arr[], int n)

// {
//   int max1 = arr[0];
//   int max2 = INT_MIN;

//   for (int i = 0; i < n; i++)
//   {
//     if (arr[i] > max1)
//     {
//       max1 = arr[i];
//     }
//   }

//   for (int i = 0; i < n; i++)
//   {
//     if (arr[i] > max2 && arr[i] < max1)
//     {
//       max2 = arr[i];
//     }
//   }

//   return max2;
// }

int findSecondLargest(int arr[], int n)
{
  int firstLargest = INT_MIN;
  int secondLargest = INT_MIN;

  for (int i = 0; i < size; ++i)
  {
    if (arr[i] > firstLargest)
    {
      secondLargest = firstLargest;
      firstLargest = arr[i];
    }
    else if (arr[i] > secondLargest && arr[i] != firstLargest)
    {
      secondLargest = arr[i];
    }
  }
  if (secondLargest == INT_MIN)
  {
    cout << "There is no second largest element in the array." << endl;
  }
  else
  {
    cout << "The second largest element in the array is: " << secondLargest << endl;
  }

  return secondLargest;
}

// reverse array
void reverse(int arr[], int n)
{
  int low = 0, high = n - 1;

  while (low < high)
  {
    int temp = arr[low];

    arr[low] = arr[high];

    arr[high] = temp;

    low++;
    high--;
  }
}

// remove duplicates
int removeDuplicates(int arr[], int size)
{
  if (size == 0 || size == 1)
  {
    return size;
  }

  int index = 0; // Index to keep track of the unique elements

  for (int i = 1; i < size; i++)
  {
    if (arr[i] != arr[index])
    {
      // If the current element is not equal to the previous unique element,
      // update the unique element and copy the current element to the next position.
      index++;
      arr[index] = arr[i];
    }
  }

  return index + 1; // Size of the modified array without duplicates
}

// move zeros to end
// Input: arr[]  = {1, 2, 0, 0, 0, 3, 6}
// Output: 1 2 3 6 0 0 0

// Input: arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9}
// Output: 1 9 8 4 2 7 6 9 0 0 0 0 0

void moveZerosToEnd(int arr[], int size)
{
  int nonZeroIndex = 0;

  // Traverse the array and move non-zero elements to the front
  for (int i = 0; i < size; i++)
  {
    if (arr[i] != 0)
    {
      arr[nonZeroIndex] = arr[i];
      nonZeroIndex++;
    }
  }

  // Fill the remaining positions with zeros
  while (nonZeroIndex < size)
  {
    arr[nonZeroIndex] = 0;
    nonZeroIndex++;
  }
}

// left rotate by one place
// Input:  arr[] = {1,2,3,4,5}
// Output: arr[] = {2,3,4,5,1}

void leftRotateByOne(int arr[], int size)
{
  // Store the first element of the array
  int temp = arr[0];

  // Shift each element to the left by one position
  for (int i = 0; i < size - 1; i++)
  {
    arr[i] = arr[i + 1];
  }

  // Place the first element at the end of the array
  arr[size - 1] = temp;

  // left rotate by d place
  void leftRotateByD(int arr[], int size, int d)
  {

    // Create a temporary array to store the rotated elements
    int temp[d];

    // Copy the first 'd' elements to the temporary array
    for (int i = 0; i < d; i++)
    {
      temp[i] = arr[i];
    }

    // Shift the remaining elements to the left by 'd' positions
    for (int i = d; i < size; i++)
    {
      arr[i - d] = arr[i];
    }

    // Copy the elements from the temporary array to the end of the original array
    for (int i = 0; i < d; i++)
    {
      arr[size - d + i] = temp[i];
    }
  }

  // 2nd soln.
  void reverse(int arr[], int low, int high)
  {
    while (low < high)
    {
      swap(arr[high], arr[low]);

      low++;
      high--;
    }
  }

  void leftRotate(int arr[], int d, int n)
  {
    reverse(arr, 0, d - 1);

    reverse(arr, d, n - 1);

    reverse(arr, 0, n - 1);
  }

  // leader element
  // An element is a leader if it is greater than all the elements to its right side.
  // And the rightmost element is always a leader.

  void findLeaders(const vector<int> &arr)
  {
    int n = arr.size();
    int leader = arr[n - 1];

    // The last element is always a leader
    cout << "Leaders in the array: " << leader << " ";

    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; i--)
    {
      if (arr[i] > leader)
      {
        // If the current element is greater than the leader, update the leader
        leader = arr[i];
        cout << leader << " ";
      }
    }
  }

  // Maximum Difference Problem with Order
  //   Input : arr = {2, 3, 10, 6, 4, 8, 1}
  // Output : 8
  // Explanation : The maximum difference is between 10 and 2.

  // Input : arr = {7, 9, 5, 6, 3, 2}
  // Output : 2
  // Explanation : The maximum difference is between 9 and 7.

  // o(n)
  int maxDiff(int arr[], int n)
  {
    int res = arr[1] - arr[0], minVal = arr[0];

    for (int i = 1; i < n; i++)
    {

      res = max(res, arr[i] - minVal);

      minVal = min(minVal, arr[i]);
    }

    return res;
  }

  // o(n*2)
  int maxDiff(int arr[], int n)
  {
    int res = arr[1] - arr[0];

    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        res = max(res, arr[j] - arr[i]);
      }
    }

    return res;
  }

  // frequency in a sorted array
  //   Input: arr[] = {1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10}
  // Output:       Frequency of 1 is: 3
  //               Frequency of 2 is: 1
  //               Frequency of 3 is: 2
  //               Frequency of 5 is: 2
  //               Frequency of 8 is: 3
  //               Frequency of 9 is: 2
  //               Frequency of 10 is: 1

  void printFreq(int arr[], int n)
  {
    int currElement = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++)
    {
      if (arr[i] == currElement)
      {
        count++;
      }
      else
      {
        cout << "Element " << currentElement << ": " << count << " times" << endl;
        currElement = arr[i];
        count = 1;
      }
    }
    cout << "Element " << currentElement << ": " << count << " times" << endl; // for last element
  }

  // stock buy and sell problem
  //   Input: arr[] = {100, 180, 260, 310, 40, 535, 695}
  // Output: 865
  // Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210
  //                        Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655
  //                        Maximum Profit  = 210 + 655 = 865

  int maxProfit(int price[], int n)
  {
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
      if (price[i] > price[i - 1])
      {
        profit += price[i] - price[i - 1];
      }
    }

    return profit;
  }

  // Trapping Rain Water
  // Input: arr[]   = {3, 0, 2, 0, 4}
  // Output: 7
  // Explanation: Structure is like below.
  // We can trap “3 units” of water between 3 and 2,
  // “1 unit” on top of bar 2 and “3 units” between 2 and 4.

  // n*2
  int getWater(int arr[], int n)
  {
    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {
      int lMax = arr[i];
      for (int j = 0; j < i; j++)
      {
        lMax = max(lMax, arr[j]);
      }

      int rMax = arr[i];
      for (int j = i + 1; j < n; j++)
      {
        rMax = max(rMax, arr[j]);
      }

      res = res + (min(lMax, rMax) - arr[i]);
    }

    return res;
  }

  // efficient
  int getWater(int arr[], int n)
  {
    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {
      int res = 0;

      int lMax[n];
      int rMax[n];

      lMax[0] = arr[0];
      for (int i = 1; i < n; i++)
        lMax[i] = max(arr[i], lMax[i - 1]);

      rMax[n - 1] = arr[n - 1];
      for (int i = n - 2; i >= 0; i--)
        rMax[i] = max(arr[i], rMax[i + 1]);

      for (int i = 1; i < n - 1; i++)
        res = res + (min(lMax[i], rMax[i]) - arr[i]);

      return res;
    }

    return res;
  }

  // maximum cons. ones
  //   Input: arr[] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1}
  // Output: 4

  int maxConsecutiveOnes(int arr[], int n)
  {
    int res = 0, curr = 0;

    for (int i = 0; i < n; i++)
    {
      if (arr[i] == 0)
        curr = 0;
      else
      {
        curr++;

        res = max(res, curr);
      }
    }

    return res;
  }
  // 2nd sol.

  int findMaxConsecutiveOnes(int arr[], int n)
  {
    int maxConsecutive = 0;
    int currentConsecutive = 0;

    for (int i = 0; i < n; i++)
    {
      if (arr[i] == 1)
      {

        currentConsecutive++;
      }
      else
      {

        maxConsecutive = max(maxConsecutive, currentConsecutive);
        currentConsecutive = 0;
      }
    }

    // Update the maximum consecutive count after the loop (in case the last element is 1).
    maxConsecutive = max(maxConsecutive, currentConsecutive);

    return maxConsecutive;
  }

  // longest even odd subarray
  //   Input: a[] = {1, 2, 3, 4, 5, 7, 9}
  // Output: 5
  // Explanation:
  // The subarray {1, 2, 3, 4, 5} has alternating even and odd elements.

  int longestEvenOddSubarray(int arr[], int n)
  {

    int maxLength = 1;
    int currentLength = 1;

    for (int i = 1; i < n; ++i)
    {
      if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
      {
        currentLength++;
        maxLength = max(maxLength, currentLength);
      }
      else
      {
        currentLength = 1;
      }
    }

    return maxLength;
  }

  // Maximum subarray sum (kadane algorithm)
  //   Input: arr = [-2, -3, 4, -1, -2, 1, 5, -3]
  // Output: [4, -1, -2, 1, 5]
  // Explanation:
  // In the above input, the maximum contiguous subarray sum is 7 and the elements of the subarray are [4, -1, -2, 1, 5]

  // efficient (kadane algorithm)
  int maxSubArraySum(int arr[], int n)
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

  // naive
  int maxSum(int arr[], int n)
  {
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
      int curr = 0;
      for (int j = i + 1; j < n; j++)
      {
        curr += arr[j];
        res = max(res, curr);
      }
    }

    return res;
  }

  // Maximum Circular Sum Subarray

  //   Input: arr[] = {8, -8, 9, -9, 10, -11, 12}
  // Output: 22
  // Explanation: Subarray 12, 8, -8, 9, -9, 10 gives the maximum sum, that is 22.

  // Input: arr[] = {10, -3, -4, 7, 6, 5, -4, -1}
  // Output:  23
  // Explanation: Subarray 7, 6, 5, -4, -1, 10 gives the maximum sum, that is 23.

  // Input: arr[] = {-1, 40, -14, 7, 6, 5, -4, -1}
  // Output: 52
  // Explanation: Subarray 7, 6, 5, -4, -1, -1, 40 gives the maximum sum, that is 52.

  int normalMaxSum(int arr[], int n)
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

  int overallMaxSum(int arr[], int n)
  {
    int max_normal = normalMaxSum(arr, n);

    if (max_normal < 0) // it means all elements in the array are negative
      return max_normal;

    int arr_sum = 0;

    for (int i = 0; i < n; i++)
    {
      arr_sum += arr[i];

      arr[i] = -arr[i];
    }

    int max_circular = arr_sum + normalMaxSum(arr, n);

    return max(max_circular, max_normal);
  }