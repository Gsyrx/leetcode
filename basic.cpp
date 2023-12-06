#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// <----------array-------------->

int main()
{

  int arr[] = {10, 20, 5, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort(arr, arr + n);

  for (int x : arr)
    cout << x << " ";

  sort(arr, arr + n, greater<int>());

  cout << endl;
  for (int x : arr)
    cout << x << " ";
}

// <----------vector-------------->
int main()
{

  vector<int> v = {10, 20, 5, 7};

  sort(v.begin(), v.end());

  for (int x : v)
    cout << x << " ";

  sort(v.begin(), v.end(), greater<int>());

  cout << endl;
  for (int x : v)
    cout << x << " ";
}

// <--------------------------->
bool visit[n];
memset(visit, false, sizeof(visit));
