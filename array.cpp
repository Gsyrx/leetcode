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