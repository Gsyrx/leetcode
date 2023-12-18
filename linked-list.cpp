

#include <bits/stdc++.h>
using namespace std;

void printlist(Node *head)
{

  Node *curr = head;

  while (curr != NULL)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
}

// singly linked list

void insertAtBeginning(int data)
{
  // Node *newNode = new Node();
  // newNode->data = data;
  Node *newNode = new Node(data); // Step 1 same as above

  if (head != NULL)
  {
    newNode->next = head; // Step 2
  }

  head = newNode; // Step 3
}

Node *insertAtEnd(Node *head, int data)
{
  Node *temp = new Node(data);
  if (head == NULL)
    return temp;
  Node *curr = head;
  while (curr->next != NULL)
  {
    curr = curr->next;
  }
  curr->next = temp;
  return head;
}

Node *insertAtPos(Node *head, int x, int pos)
{
  Node *temp = new Node(x);
  if (head == NULL)
  {
    if (pos == 1)
      return temp;
    else
      return head;
  }
  if (pos == 1)
  {
    temp->next = head;
    return temp;
  }
  Node *curr = head;
  for (int i = 1; i < pos - 1; i++)
  {
    curr = curr->next;
    if (curr == NULL)
    {
      cout << "Position out of range" << endl;
      return head;
    }
  }
  temp->next = curr->next;
  curr->next = temp;
  return head;
}

Node *delHead(Node *head)
{
  if (head == NULL)
    return NULL;
  else
  {
    Node *temp = head->next;
    delete (head);
    return temp;
  }
}

Node *delTail(Node *head)
{
  if (head == NULL)
    return NULL;
  if (head->next == NULL)
  {
    delete head;
    return NULL;
  }
  Node *curr = head;
  while (curr->next->next != NULL)
    curr = curr->next;
  delete (curr->next);
  curr->next = NULL;
  return head;
}

int search(Node *head, int x)
{
  int pos = 1;
  Node *curr = head;
  while (curr != NULL)
  {
    if (curr->data == x)
      return pos;
    else
    {
      pos++;
      curr = curr->next;
    }
  }
  return -1;
}

// doubly linked list

Node *insertBegin(Node *head, int data)
{
  Node *temp = new Node(data);
  temp->next = head;
  if (head != NULL)
    head->prev = temp;
  return temp;
}

Node *insertEnd(Node *head, int data)
{
  Node *temp = new Node(data);
  if (head == NULL)
    return temp;
  Node *curr = head;
  while (curr->next != NULL)
  {
    curr = curr->next;
  }

  curr->next = temp;
  temp->prev = curr;
  return head;
}

Node *reverse(Node *head)
{
  Node *temp = NULL;
  Node *curr = head;
  while (curr != NULL)
  {
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;
    curr = curr->prev;
  }
  if (temp != NULL)
    head = temp->prev;
  return head;
}

Node *delHead(Node *head)
{
  if (head == NULL)
    return NULL;
  if (head->next == NULL)
  {
    delete head;
    return NULL;
  }
  else
  {
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
  }
}

Node *delLast(Node *head)
{
  if (head == NULL)
    return NULL;
  if (head->next == NULL)
  {
    delete head;
    return NULL;
  }
  Node *curr = head;
  while (curr->next != NULL)
    curr = curr->next;
  curr->prev->next = NULL;
  delete curr;
  return head;
}

// singly circular linked list

void printlist(Node *head)
{
  if (head == NULL)
    return;
  cout << head->data << " ";
  for (Node *p = head->next; p != head; p = p->next)
    cout << p->data << " ";
}

Node *insertBegin(Node *head, int x)
{
  Node *temp = new Node(x);
  if (head == NULL)
    temp->next = temp;
  else
  {
    Node *curr = head;
    while (curr->next != head)
      curr = curr->next;
    curr->next = temp;
    temp->next = head;
  }
  return temp;
}

// another efficient sol
Node *insertBegin(Node *head, int x)
{
  Node *temp = new Node(x);
  if (head == NULL)
  {
    temp->next = temp;
    return temp;
  }
  else
  {
    temp->next = head->next;
    head->next = temp;
    int t = head->data;
    head->data = temp->data;
    temp->data = t;
    return head;
  }
}

Node *insertEnd(Node *head, int x)
{
  Node *temp = new Node(x);
  if (head == NULL)
  {
    temp->next = temp;
    return temp;
  }
  else
  {
    Node *curr = head;
    while (curr->next != head)
      curr = curr->next;
    curr->next = temp;
    temp->next = head;
    return head;
  }
}

// another efficient sol
Node *insertEnd(Node *head, int x)
{
  Node *temp = new Node(x);
  if (head == NULL)
  {
    temp->next = temp;
    return temp;
  }
  else
  {
    temp->next = head->next;
    head->next = temp;
    int t = head->data;
    head->data = temp->data;
    temp->data = t;
    return temp;
  }
}

Node *delHead(Node *head)
{
  if (head == NULL)
    return NULL;
  if (head->next == head)
  {
    delete head;
    return NULL;
  }
  Node *curr = head;
  while (curr->next != head)
    curr = curr->next;
  curr->next = head->next;
  delete head;
  return (curr->next);
}

// another efficient sol
Node *delHead(Node *head)
{
  if (head == NULL)
    return NULL;
  if (head->next == head)
  {
    delete head;
    return NULL;
  }
  head->data = head->next->data;
  Node *temp = head->next;
  head->next = head->next->next;
  delete temp;
  return head;
}

// delete kth in circular linked list

Node *deleteHead(Node *head)
{
  if (head == NULL)
    return NULL;
  if (head->next == head)
  {
    delete head;
    return NULL;
  }
  head->data = head->next->data;
  Node *temp = head->next;
  head->next = head->next->next;
  delete temp;
  return head;
}

Node *deleteKth(Node *head, int k)
{
  if (head == NULL)
    return head;
  if (k == 1)
    return deleteHead(head);
  Node *curr = head;
  for (int i = 0; i < k - 2; i++)
    curr = curr->next;
  Node *temp = curr->next;
  curr->next = curr->next->next;
  delete temp;
  return head;
}

// circular doubly linked list
Node *insertAtHead(Node *head, int x)
{
  Node *temp = new Node(x);
  if (head == NULL)
  {
    temp->next = temp;
    temp->prev = temp;
    return temp;
  }
  temp->prev = head->prev;
  temp->next = head;
  head->prev->next = temp;
  head->prev = temp;
  return temp;
}

// Sorted Insert in a Singly Linked List
void sortedInsert(Node **head_ref,
                  Node *new_node)
{
  Node *current;
  /* Special case for the head end */
  if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
  {
    new_node->next = *head_ref;
    *head_ref = new_node;
  }
  else
  {
    /* Locate the node before the
point of insertion */
    current = *head_ref;
    while (current->next != NULL && current->next->data < new_node->data)
    {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

// twice traversal (middle of linked list)
void printMiddle(Node *head)
{
  if (head == NULL)
    return;
  int count = 0;
  Node *curr;
  for (curr = head; curr != NULL; curr = curr->next)
    count++;
  curr = head;
  for (int i = 0; i < count / 2; i++)
    curr = curr->next;
  cout << curr->data;
}

// one traversal
void printMiddle(Node *head)
{
  if (head == NULL)
    return;
  Node *slow = head, *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  cout << slow->data;
}

// Using length of Linked List
void printNthFromEnd(Node *head, int n)
{
  int len = 0;
  for (Node *curr = head; curr != NULL; curr = curr->next)
    len++;
  if (len < n)
    return;
  Node *curr = head;
  for (int i = 1; i < len - n + 1; i++)
    curr = curr->next;
  cout << (curr->data) << " ";
}

// Using Two Pointers/References
void printNthFromEnd(Node *head, int n)
{
  if (head == NULL)
    return;
  Node *first = head;
  for (int i = 0; i < n; i++)
  {
    if (first == NULL)
      return;
    first = first->next;
  }
  Node *second = head;
  while (first != NULL)
  {
    second = second->next;
    first = first->next;
  }
  cout << (second->data);
}

Node *revList(Node *head)
{
  vector<int> arr;
  for (Node *curr = head; curr != NULL; curr = curr->next)
  {
    arr.push_back(curr->data);
  }
  for (Node *curr = head; curr != NULL; curr = curr->next)
  {
    curr->data = arr.back();
    arr.pop_back();
  }
  return head;
}

Node *reverse(Node *head)
{
  Node *curr = head;
  Node *prev = NULL;
  while (curr != NULL)
  {
    Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

// Remove duplicates from a sorted Singly Linked List

void removeDuplicates(Node *head)
{
  Node *current = head;

  while (current != NULL && current->next != NULL)
  {
    if (current->data == current->next->data)
    {
      Node *duplicate = current->next;
      current->next = current->next->next;
      delete duplicate;
    }
    else
    {
      current = current->next;
    }
  }
}

// reverse in size of k
// recursive
Node *reverseK(Node *head, int k)
{

  Node *curr = head, *prev = NULL, *next = NULL;
  int count = 0;

  while (curr != NULL && count < k)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  if (next != NULL)
  {
    Node *rest_head = reverseK(next, k);
    head->next = rest_head;
  }

  return prev;
}

// iterative
Node *reverseK(Node *head, int k)
{

  Node *curr = head, *prevFirst = NULL;
  bool isFirstPass = true;
  while (curr != NULL)
  {
    Node *first = curr, *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
      Node *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      count++;
    }
    if (isFirstPass)
    {
      head = prev;
      isFirstPass = false;
    }
    else
    {
      prevFirst->next = prev;
    }
    prevFirst = first;
  }
  return head;
}

// detact loop
// method 1

bool isLoop(Node *head)
{
  Node *temp = new Node(0);
  Node *curr = head;
  while (curr != NULL)
  {
    if (curr->next == NULL)
      return false;
    if (curr->next == temp)
      return true;
    Node *curr_next = curr->next;
    curr->next = temp;
    curr = curr_next;
  }
  return false;
}

// method 2

bool isLoop(Node *head)
{
  unordered_set<Node *> s;
  for (Node *curr = head; curr != NULL; curr = curr->next)
  {
    if (s.find(curr) != s.end())
      return true;
    s.insert(curr);
  }
  return false;
  // unordered_set<Node *> visited;
  // while (head != NULL)
  // {
  //   // If the current node is already in the set, a loop is detected
  //   if (visited.find(head) != visited.end())
  //   {
  //     return true;
  //   }

  //   // Add the current node to the set
  //   visited.insert(head);

  //   // Move to the next node
  //   head = head->next;
  // }
  // return false;
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

// Function to insert a node in the middle of a linked list
void insertInMiddle(Node *&head, int value)
{
  Node *slow = head;
  Node *fast = head;
  Node *newNode = new Node(value);

  // Find the middle of the linked list using the slow and fast pointers
  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  // Insert the new node after the middle node
  newNode->next = slow->next;
  slow->next = newNode;
}

int getIntersection(Node *head1, Node *head2)
{
  unordered_set<Node *> s;
  Node *curr = head1;
  while (curr != NULL)
  {
    s.insert(curr);
    curr = curr->next;
  }
  curr = head2;
  while (curr != NULL)
  {
    if (s.find(curr) != s.end())
      return curr->data;
    curr = curr->next;
  }
  return -1;
}

// Function to perform pairwise swapping of nodes
Node *pairwiseSwap(Node *head)
{
  // If the list is empty or has only one node, no swapping is needed
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  // Initialize pointers for swapping
  Node *prev = nullptr;
  Node *current = head;
  Node *nextNode = nullptr;

  // Traverse the list and swap adjacent nodes
  while (current != nullptr && current->next != nullptr)
  {
    nextNode = current->next;
    current->next = nextNode->next;
    nextNode->next = current;

    // Update the head if the swap involves the first node
    if (prev == nullptr)
    {
      head = nextNode;
    }
    else
    {
      prev->next = nextNode;
    }

    // Move to the next pair
    prev = current;
    current = current->next;
  }

  return head;
}

// another sol (we can also use reverse the linked list of size k and in place of size k we can pass 2)

// 2nd sol but not used because we are swapping the data (may be the node contains the large amount of data)
void pairwiseSwap(Node *head)
{
  Node *curr = head;
  while (curr != NULL && curr->next != NULL)
  {
    swap(curr->data, curr->next->data);
    curr = curr->next->next;
  }
}

// Function to merge two sorted linked lists
Node *mergeSortedLists(Node *list1, Node *list2)
{
  // Create a dummy node to simplify code
  Node *dummy = new Node(0);
  Node *current = dummy;

  // Traverse both lists and compare nodes
  while (list1 != nullptr && list2 != nullptr)
  {
    if (list1->data < list2->data)
    {
      current->next = list1;
      list1 = list1->next;
    }
    else
    {
      current->next = list2;
      list2 = list2->next;
    }
    current = current->next;
  }

  // If one list is not empty, append the remaining nodes
  if (list1 != nullptr)
  {
    current->next = list1;
  }
  else
  {
    current->next = list2;
  }

  // Save the merged list, excluding the dummy node
  Node *mergedList = dummy->next;

  // Delete the dummy node to avoid memory leaks
  delete dummy;

  return mergedList;
}

// Palindrome Linked List

bool isPalindrome(Node *head)
{
  stack<char> st;
  for (Node *curr = head; curr != NULL; curr = curr->next)
    st.push(curr->data);
  for (Node *curr = head; curr != NULL; curr = curr->next)
  {
    if (st.top() != curr->data)
      return false;
    st.pop();
  }
  return true;
}

// 2nd sol
Node *reverseList(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  Node *rest_head = reverseList(head->next);
  Node *rest_tail = head->next;
  rest_tail->next = head;
  head->next = NULL;
  return rest_head;
}

bool isPalindrome(Node *head)
{
  if (head == NULL)
    return true;
  Node *slow = head, *fast = head;
  while (fast->next != NULL && fast->next->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  Node *rev = reverseList(slow->next);
  Node *curr = head;
  while (rev != NULL)
  {
    if (rev->data != curr->data)
      return false;
    rev = rev->next;
    curr = curr->next;
  }
  return true;
}

// Function to detect and find the length of a loop in a linked list
int findLoopLength(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  // Detect the loop using Floyd's cycle-finding algorithm
  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      // Loop detected, find the length of the loop
      int length = 1;
      slow = slow->next;

      while (slow != fast)
      {
        slow = slow->next;
        length++;
      }

      return length;
    }
  }

  // No loop detected
  return 0;
}

// add two numbers represented by linked lists
//  Function to reverse a linked list
Node *reverseList(Node *head)
{
  Node *prev = nullptr;
  Node *current = head;
  Node *nextNode = nullptr;

  while (current != nullptr)
  {
    nextNode = current->next;
    current->next = prev;
    prev = current;
    current = nextNode;
  }

  return prev;
}

// Function to add two numbers represented by linked lists
Node *addNumbers(Node *l1, Node *l2)
{
  // Reverse the input lists to simplify addition
  l1 = reverseList(l1);
  l2 = reverseList(l2);

  Node *dummy = new Node(0); // Dummy node to simplify code
  Node *current = dummy;
  int carry = 0;

  while (l1 != nullptr || l2 != nullptr || carry != 0)
  {
    int sum = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry;
    carry = sum / 10;

    current->next = new Node(sum % 10);
    current = current->next;

    if (l1)
      l1 = l1->next;
    if (l2)
      l2 = l2->next;
  }

  // Reverse the result list before returning
  Node *result = reverseList(dummy->next);

  // Free the memory allocated for the dummy node
  delete dummy;

  return result;
}

// Function to sort a linked list containing 0s, 1s, and 2s
Node *sortLinkedList(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *dummyZero = new Node(0);
  Node *dummyOne = new Node(0);
  Node *dummyTwo = new Node(0);

  Node *zero = dummyZero;
  Node *one = dummyOne;
  Node *two = dummyTwo;

  Node *current = head;

  // Traverse the list and partition nodes based on their values
  while (current != nullptr)
  {
    if (current->data == 0)
    {
      zero->next = current;
      zero = zero->next;
    }
    else if (current->data == 1)
    {
      one->next = current;
      one = one->next;
    }
    else
    {
      two->next = current;
      two = two->next;
    }

    current = current->next;
  }

  // Combine the three partitions
  zero->next = dummyOne->next ? dummyOne->next : dummyTwo->next;
  one->next = dummyTwo->next;

  // Update the next pointer of the last node to nullptr
  two->next = nullptr;

  // Save the new head
  Node *sortedList = dummyZero->next;

  // Free the memory allocated for dummy nodes
  delete dummyZero;
  delete dummyOne;
  delete dummyTwo;

  return sortedList;
}

// Function to remove duplicates from an unsorted linked list
void removeDuplicates(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return;
  }

  std::unordered_set<int> uniqueValues;
  Node *current = head;
  Node *previous = nullptr;

  while (current != nullptr)
  {
    // If the current value is already in the set, remove the current node
    if (uniqueValues.count(current->data))
    {
      previous->next = current->next;
      delete current;
      current = previous->next;
    }
    else
    {
      // Add the current value to the set and move to the next node
      uniqueValues.insert(current->data);
      previous = current;
      current = current->next;
    }
  }
}