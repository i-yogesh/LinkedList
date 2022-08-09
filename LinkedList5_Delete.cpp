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
    
    ~Node()
    {
      int value = this->data;
      if(this->next!=NULL)
      {
        delete next;
        this->next = NULL;
      }
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

void deleteAt(Node* &head, int pos)
{
  Node* temp = head;
  if(pos==1)
  {
    head = temp->next;
    //free memory
    temp->next =NULL;
    delete temp;
  }
  
  //deleting any middle or last node
  else
  {
    Node* curr = head;
    Node* prev = NULL;
    int cnt=1;
    while(cnt < pos)
    {
      prev = curr;
      curr = curr->next;
      cnt++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
  
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
    
    int pos = 3;
    deleteAt(head,pos);
    print(head);
}