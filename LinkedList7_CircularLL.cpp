#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node* next;
    
    Node(int d)
    {
      this->data = d;
      this->next = NULL;
    }
    
    ~Node()
    {
      if(this->next!=NULL)
      {
        delete next;
        next = NULL;
      }
    }
};


void insert(Node* &tail,int element, int d)
{
  if(tail == NULL)
  {
    Node* temp = new Node(d);
    temp->data = d;
    temp->next = temp;
    tail = temp;
    return;
  }
  
  
  
  else
  {
    Node* curr = tail;
    while(curr->data!=element)
    {
      curr = curr->next;
    }
    Node* temp = new Node(d);
    temp->data = d;
    temp->next = curr->next;
    curr->next = temp;
  }
  
  
}

void print(Node* tail)
{
  Node* temp = tail;
  if(tail == NULL)
  {
    cout<<"List is empty\n";
    return;
  }
  do{
      cout<<temp->data<<" ";
      temp = temp->next;
    }while(tail!=temp);
    
    cout<<endl;
}

void deleteAt(Node* &tail, int value)
{
  Node* prev = tail;
  Node* curr = prev->next;
  
  while(curr->data != value)
  {
    prev = curr;
    curr = curr->next;
  }
  
  prev->next = curr->next;
  
  if(curr == prev)
  {
    tail = NULL;
  }
  
  else if(tail == curr)
  {
    tail = prev;
  }
  curr->next = NULL;
  
  delete curr;
}


int main()
{
    Node* tail = NULL;
    insert(tail,2,5);
    
    insert(tail,5,8);
    insert(tail,8,15);
    print(tail);
    insert(tail,5,6);
    print(tail);
    deleteAt(tail,6);
    print(tail);
    cout<<"\nTail is "<<tail->data<<endl;
    
}