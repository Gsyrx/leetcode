#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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

// Binary Search
/*
Binary Search is a powerful and efficient algorithm for finding elements in sorted arrays.
*/

int binarySearchIterative(const vector<int> &arr, int target)
{
  int left = 0;
  int right = arr.size() - 1;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
      return mid; // Element found, return its index
    }
    else if (arr[mid] < target)
    {
      left = mid + 1; // Search the right half
    }
    else
    {
      right = mid - 1; // Search the left half
    }
  }

  return -1; // Element not found
}
// or
int binarySearchRecursive(const vector<int> &arr, int target, int left, int right)
{
  if (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
      return mid; // Element found, return its index
    }
    else if (arr[mid] < target)
    {
      return binarySearchRecursive(arr, target, mid + 1, right); // Search the right half
    }
    else
    {
      return binarySearchRecursive(arr, target, left, mid - 1); // Search the left half
    }
  }

  return -1; // Element not found
}

// Two Pointers Approach
/*

The Two Pointers technique is a useful approach in solving problems
where you need to iterate through the array with two pointers.
This technique is often used to solve problems involving
searching, sorting, or finding a pair of elements that meet certain conditions.

*/

bool isPairWithSum(const vector<int> &arr, int target)
{
  int left = 0;
  int right = arr.size() - 1;

  while (left < right)
  {
    int currentSum = arr[left] + arr[right];

    if (currentSum == target)
    {
      return true;
    }
    else if (currentSum < target)
    {
      left++; // Move the left pointer to increase the sum
    }
    else
    {
      right--; // Move the right pointer to decrease the sum
    }
  }
  return false;
}

// bubble sort

void bubbleSort(std::vector<int> &arr)
{
  int n = arr.size();
  bool swapped;

  for (int i = 0; i < n - 1; ++i)
  {
    swapped = false;

    for (int j = 0; j < n - i - 1; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        // Swap arr[j] and arr[j + 1]
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }

    // If no two elements were swapped in the inner loop, the array is sorted
    if (!swapped)
    {
      break;
    }
  }
}

// selection sort

void selectionSort(std::vector<int> &arr)
{
  int n = arr.size();

  for (int i = 0; i < n - 1; ++i)
  {
    // Find the minimum element in the unsorted part of the array
    int minIndex = i;
    for (int j = i + 1; j < n; ++j)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }

    // Swap the found minimum element with the first element
    std::swap(arr[i], arr[minIndex]);
  }
}

// insertion sort

void insertionSort(std::vector<int> &arr)
{
  int n = arr.size();

  for (int i = 1; i < n; ++i)
  {
    int key = arr[i];
    int j = i - 1;

    // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      --j;
    }

    arr[j + 1] = key;
  }
}

// merge two sorted arrays

void mergeSortedArrays(const std::vector<int> &arr1, const std::vector<int> &arr2, std::vector<int> &result)
{
  int i = 0; // Index for arr1
  int j = 0; // Index for arr2

  while (i < arr1.size() && j < arr2.size())
  {
    if (arr1[i] <= arr2[j])
    {
      result.push_back(arr1[i]);
      ++i;
    }
    else
    {
      result.push_back(arr2[j]);
      ++j;
    }
  }

  // If there are remaining elements in arr1, append them
  while (i < arr1.size())
  {
    result.push_back(arr1[i]);
    ++i;
  }

  // If there are remaining elements in arr2, append them
  while (j < arr2.size())
  {
    result.push_back(arr2[j]);
    ++j;
  }
}

// merge sort

void merge(std::vector<int> &arr, int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temporary arrays
  std::vector<int> leftArray(n1);
  std::vector<int> rightArray(n2);

  // Copy data to temporary arrays leftArray[] and rightArray[]
  for (int i = 0; i < n1; ++i)
    leftArray[i] = arr[left + i];
  for (int j = 0; j < n2; ++j)
    rightArray[j] = arr[mid + 1 + j];

  // Merge the temporary arrays back into arr[left..right]
  int i = 0;    // Initial index of first subarray
  int j = 0;    // Initial index of second subarray
  int k = left; // Initial index of merged subarray

  while (i < n1 && j < n2)
  {
    if (leftArray[i] <= rightArray[j])
    {
      arr[k] = leftArray[i];
      ++i;
    }
    else
    {
      arr[k] = rightArray[j];
      ++j;
    }
    ++k;
  }

  // Copy the remaining elements of leftArray[], if there are any
  while (i < n1)
  {
    arr[k] = leftArray[i];
    ++i;
    ++k;
  }

  // Copy the remaining elements of rightArray[], if there are any
  while (j < n2)
  {
    arr[k] = rightArray[j];
    ++j;
    ++k;
  }
}

void mergeSort(std::vector<int> &arr, int left, int right)
{
  if (left < right)
  {
    // Same as (left + right) / 2, but avoids overflow for large left and right
    int mid = left + (right - left) / 2;

    // Sort first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

// lomuto partition (pivot element goes toits correct position)
/*
The pivot is chosen as the last element (arr[high]),
and elements are rearranged such that elements smaller than or equal to the pivot are on the left,
and elements greater than the pivot are on the right. The function returns the index of the pivot element after partitioning.

*/

int iPartition(int arr[], int l, int h)
{
  int pivot = arr[h];
  int i = l - 1;
  for (int j = l; j <= h - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[h]);
  return i + 1;
}

void qSort(int arr[], int l, int h)
{
  if (l < h)
  {
    int p = iPartition(arr, l, h);
    qSort(arr, l, p - 1);
    qSort(arr, p + 1, h);
  }
}

// hoarePartition
/*
The pivot is chosen as the first element .
 Elements are rearranged such that elements smaller than or equal to the pivot are on the left,
 and elements greater than or equal to the pivot are on the right.
 The function returns the index of the last element in the left partition.
 means all elements till jth index is smaller than pivot and on the right greater than pivot(including pivot)
 example:-
  Segregate negative and positive elements.
  Segregate even and odd elements.
  Sort a binary array.
 */
int partition(int arr[], int l, int h)
{
  int pivot = arr[l];
  int i = l - 1, j = h + 1;
  while (true)
  {
    do
    {
      i++;
    } while (arr[i] < pivot);
    do
    {
      j--;
    } while (arr[j] > pivot);
    if (i >= j)
      return j;
    swap(arr[i], arr[j]);
  }
}

void qSort(int arr[], int l, int h)
{
  if (l < h)
  {
    int p = partition(arr, l, h);
    qSort(arr, l, p);
    qSort(arr, p + 1, h);
  }
}

//  Floyd's cycle-finding algorithm

bool detectLoop(Node *head)
{
  // Initialize two pointers, slow and fast
  Node *slow = head;
  Node *fast = head;

  // Traverse the linked list
  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;       // Move slow pointer by one step
    fast = fast->next->next; // Move fast pointer by two steps

    // Check if the pointers meet (loop detected)
    if (slow == fast)
    {
      return true;
    }
  }

  // If the loop is not detected, return false
  return false;
}

// detact and remove loop
void detectRemoveLoop(Node *head)
{
  Node *slow = head, *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      break;
    }
  }
  if (slow != fast)
    return;
  slow = head;
  while (slow->next != fast->next)
  {
    slow = slow->next;
    fast = fast->next;
  }
  fast->next = NULL;
}

// Function to delete a node with only a pointer to it
void deleteNode(Node *nodeToDelete)
{
  if (nodeToDelete == nullptr || nodeToDelete->next == nullptr)
  {
    // Cannot delete the last node or a nullptr
    std::cerr << "Cannot delete the last node or a nullptr.\n";
    return;
  }

  Node *nextNode = nodeToDelete->next;

  // Copy data of the next node to the current node
  nodeToDelete->data = nextNode->data;

  // Update the next pointer of the current node to skip the next node
  nodeToDelete->next = nextNode->next;

  // Delete the next node
  delete nextNode;
}