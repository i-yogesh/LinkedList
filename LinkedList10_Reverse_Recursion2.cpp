#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    
    Node(int data)
    {
      this->data = data;
      this->next = NULL;
    }
};

Node* reverseLL(Node* &head)
{
  if(head == NULL || head-> next == NULL)
  {
    return head;
  }
  
  Node* chotaHead = reverseLL(head->next);
  head->next->next = head;
  head->next = NULL;
  
  return chotaHead;
  
}
void insert(Node* &head, int data)
{
  Node* temp = new Node(data);
  temp->next = head;
  head = temp;
  
}

void print(Node* &head)
{
   Node* temp = head;
   while(temp!=NULL)
   {
     cout<<temp->data<<endl;
     temp = temp->next;
   }
   
}

int main()
{
    Node* node1 = new Node(5);
    
    Node* head = node1;
   // cout<<head->data<<endl;
    insert(head, 10);
    insert(head,20);
    insert(head,30);
    Node* curr = head;
    Node* prev = NULL;
    head = reverseLL(head);
    print(head);
}