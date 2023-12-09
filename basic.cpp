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
// bool visit[n];
// memset(visit, false, sizeof(visit));

int main()
{

  unordered_set<int> s;
  s.insert(10);
  s.insert(5);
  s.insert(15);
  s.insert(20);
  for (int x : s)
    cout << x << " ";

  cout << endl;
  for (auto it = s.begin(); it != s.end(); it++)
    cout << *it << " ";
  cout << endl;
  cout << s.size() << endl;
  s.clear();
  cout << s.size() << endl;

  s.insert(10);
  s.insert(5);
  s.insert(15);
  s.insert(20);
  cout << s.size() << endl;

  if (s.find(15) == s.end())
    cout << "Not Found";
  else
    cout << "Found " << (*s.find(15));

  cout << endl;
  if (s.count(15))
    cout << "Found";
  else
    cout << "Not Found";
  cout << endl;

  cout << s.size() << endl;
  s.erase(15);
  cout << s.size() << endl;
  auto it = s.find(10);
  s.erase(it);
  cout << s.size() << endl;

  s.erase(s.begin(), s.end());

  return 0;
}
