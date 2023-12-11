

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