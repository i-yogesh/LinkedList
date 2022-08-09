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

void insertAtTail(Node* &tail, int data)
{
  Node* temp = new Node(data);
  tail->next = temp;
  tail = temp;
  
}

void print(Node* &head)
{
   Node* temp = head;
   while(temp!=NULL)
   {
     cout<<temp->data<<" ";
     temp = temp->next;
   }
   cout<<endl;
}

bool isCircular(Node* head)
{
  if(head==NULL)
  return true;
  
  Node* temp = head->next;
  while(temp!=head && temp!=NULL)
  {
    temp = temp->next;
  }
  
    if(temp==NULL)
    return false;
    
    if(temp == head)
    return true;
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    print(head);
    
    insertAtTail(tail,15);
    print(head);
    
    insertAtTail(tail,20);
    print(head);
    
    if(isCircular(tail))
    printf("Circular\n");
    
    else
    printf("Not Circular\n");
}