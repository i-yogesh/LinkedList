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

void insertAtHead(Node* &head, int data)
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
     cout<<temp->data<<" ";
     temp = temp->next;
   }
   cout<<endl;
}

void insertAtPos(Node* &head, Node* &tail, int pos, int data)
{
  
  if(pos == 0)
  {
    cout<<"pos "<<pos<<endl;
    insertAtHead(head,data);
    return;
  }
  
  Node* temp = head;
  int i=0;
  while(i<pos-1)
  {
    temp = temp->next;
    i++;
  }
  
  //last position
  if(temp->next == NULL)
  {
    insertAtTail(tail, data);
    return;
  }
  
  Node* nodeToInsert = new Node(data);
  
  nodeToInsert->next = temp->next;
  temp->next = nodeToInsert;
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
    
    int pos = 4;
    insertAtPos(head,tail,pos-1,99);
    print(head);
}