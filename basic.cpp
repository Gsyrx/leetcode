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

  // store unique elements.
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

// unordered_set<int> uniqueElements(nums.begin(), nums.end()); // vector sort
// unordered_set<int> uniqueElements(nums, nums+n); // array sort

// Unordered_map in C++ STL

int main()
{
  //  Create an unordered_map with keys as strings and values as integers
  unordered_map<string, int> myMap;

  // Insert key-value pairs into the unordered_map
  myMap["one"] = 1;
  myMap["two"] = 2;
  myMap["three"] = 3;

  myMap.erase("two");

  for (const auto &pair : myMap)
  {
    std::cout << " {" << pair.first << ": " << pair.second << "}";
  }
}

// string

int main()
{
  string str = "geeksforgeeks";
  int count[26] = {0};

  for (int i = 0; i < str.length(); i++)
  {
    count[str[i]]++;
  }

  for (int i = 0; i < 26; i++)
  {
    if (count[i] > 0)
    {
      cout << char(i + 'a') << " " << count << endl;
    }
  }
}

// bool visited[256];
// fill(visited, visited + 256, false);

// std::string firstName = "Gaurav";
// std::string lastName = "Verma";
// std::string fullName = firstName + " " + lastName;
// int length = fullName.length(); // or fullName.size();
// char firstChar = fullName[0];
// std::string sub = fullName.substr(0, 4); // Extracts characters from index 0 to 3
// size_t pos = fullName.find("Doe");       // Returns the position of the first occurrence of "Doe"
// fullName.replace(pos, 3, "Smith");       // Replaces "Doe" with "Smith"
// std::string str1 = "apple";
// std::string str2 = "banana";

// if (str1 == str2)
// {
//   std::cout << "Strings are equal." << std::endl;
// }
// else
// {
//   std::cout << "Strings are not equal." << std::endl;
// }
// for (char c : fullName)
// {
//   std::cout << c << " ";
// }

// linked list
struct Node
{
  int data;
  Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

void printlist(Node *head)
{
  Node *curr = head;
  while (curr != NULL)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
}

int main()
{
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(40);
  printlist(head);
  return 0;
}

// stack

int main()
{
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  cout << s.size() << endl;
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  s.push(5);
  cout << s.top() << endl;

  while (s.empty() == false)
  {
    cout << s.top() << endl;
    s.pop();
  }
  return 0;
}

// using array
struct MyStack
{
  int *arr;
  int cap;
  int top;
  MyStack(int c)
  {
    cap = c;
    arr = new int[cap];
    top = -1;
  }

  void push(int x)
  {
    if (top == cap - 1)
    {
      cout << "Stack is full" << endl;
      return;
    }
    top++;
    arr[top] = x;
  }

  int pop()
  {
    if (top == -1)
    {
      cout << "Stack is Empty" << endl;
      return INT_MIN;
    }
    int res = arr[top];
    top--;
    return res;
  }

  int peek()
  {
    if (top == -1)
    {
      cout << "Stack is Empty" << endl;
      return INT_MIN;
    }
    return arr[top];
  }

  int size()
  {
    return (top + 1);
  }

  bool isEmpty()
  {
    return top == -1;
  }
};

int main()
{
  MyStack s(5);
  s.push(5);
  s.push(10);
  s.push(20);
  cout << s.pop() << endl;
  cout << s.size() << endl;
  cout << s.peek() << endl;
  cout << s.isEmpty() << endl;

  return 0;
}

// using vector
struct MyStack
{
  vector<int> v;

  void push(int x)
  {
    v.push_back(x);
  }

  int pop()
  {
    int res = v.back();
    v.pop_back();
    return res;
  }

  int peek()
  {
    return v.back();
  }

  int size()
  {
    return v.size();
  }

  bool isEmpty()
  {
    return v.empty();
  }
};

// linked list
struct MyStack
{
  Node *head;
  int sz;
  MyStack()
  {
    head = NULL;
    sz = 0;
  }

  void push(int x)
  {
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
    sz++;
  }

  int pop()
  {
    if (head == NULL)
    {
      cout << "Stack is Empty" << endl;
      return INT_MAX;
    }
    int res = head->data;
    Node *temp = head;
    head = head->next;
    delete (temp);
    sz--;
    return res;
  }

  int peek()
  {
    if (head == NULL)
    {
      cout << "Stack is Empty" << endl;
      return INT_MAX;
    }
    return head->data;
  }

  int size()
  {
    return sz;
  }

  bool isEmpty()
  {
    return head == NULL;
  }
};

// queue

int main()
{
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  cout << q.size();

  while (q.empty() == false)
  {
    cout << q.front() << " " << q.back() << endl;
    q.pop();
  }

  return 0;
}