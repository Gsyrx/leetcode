#include <bits/stdc++.h>
using namespace std;

// Balanced Parenthesis
bool isBalanced(string s)
{
  stack<char> ch;

  for (char c : s)
  {
    if (c == '(' || c == '[' || c == '{')
    {
      ch.push(c);
    }
    else
    {
      if (ch.empty())
      {
        return false;
      }
      else if (c == ')' and ch.top() != '(')
      {
        return false;
      }
      else if (c == ']' and ch.top() != '[')
      {
        return false;
      }
      else if (c == '}' and ch.top() != '{')
      {
        return false;
      }
      else
      {
        ch.pop();
      }
    }
  }

  return ch.empty();
}

// Stock span problem
vector<int> calculateStockSpan(vector<int> &prices)
{
  vector<int> spans;
  stack<int> indices;

  for (int i = 0; i < prices.size(); i++)
  {
    while (!indices.empty() && prices[i] >= prices[indices.top()])
    {
      indices.pop();
    }

    int span = indices.empty() ? i + 1 : i - indices.top();
    spans.push_back(span);
    indices.push(i);
  }

  return spans;
}

// Previous Greater Element
void printPrevGreater(const std::vector<int> &nums)
{

  stack<int> st;

  for (int i = 0; i < nums.size(); i++)
  {
    while (!st.empty() && nums[i] >= st.top())
    {
      st.pop();
    }

    if (st.empty())
    {
      cout << "-1 ";
    }
    else
    {
      cout << st.top() << " ";
    }
    st.push(nums[i]);
  }
}

vector<int> nextGreater(int arr[], int n)
{
  vector<int> v;
  stack<int> s;

  for (int i = n - 1; i >= 0; i--)
  {
    while (!s.empty() && s.top() <= arr[i])
      s.pop();
    int ng = s.empty() ? -1 : s.top();
    v.push_back(ng);
    s.push(arr[i]);
  }
  reverse(v.begin(), v.end());
  return v;
}

// Generate numbers with given digits
void printFirstN(int n)
{
  queue<string> q;

  q.push("5");
  q.push("6");

  for (int i = 0; i < n; i++)
  {
    string curr = q.front();

    cout << curr << " ";

    q.pop();

    q.push(curr + "5");
    q.push(curr + "6");
  }
}

// queue using linked list

struct Queue
{
  QNode *front, *rear;
  Queue()
  {
    front = rear = NULL;
  }

  void enQueue(int x)
  {

    QNode *temp = new QNode(x);

    if (rear == NULL)
    {
      front = rear = temp;
      return;
    }

    rear->next = temp;
    rear = temp;
  }

  void deQueue()
  {

    if (front == NULL)
      return;

    QNode *temp = front;
    front = front->next;

    if (front == NULL)
      rear = NULL;

    delete (temp);
  }
};

// deque

int main()
{
  std::deque<int> myDeque = {1, 2, 3, 4, 5};

  // Insert at the front and back
  myDeque.push_front(0);
  myDeque.push_back(6);

  // Display elements
  std::cout << "Deque elements: ";
  for (auto it = myDeque.begin(); it != myDeque.end(); ++it)
  {
    std::cout << *it << " ";
  }

  // Remove elements from the front and back
  myDeque.pop_front();
  myDeque.pop_back();

  // Display size and front element
  std::cout << "\nSize: " << myDeque.size();
  std::cout << "\nFront element: " << myDeque.front() << std::endl;

  return 0;
}