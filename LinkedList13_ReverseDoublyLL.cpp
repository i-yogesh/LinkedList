#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int d)
    {
      this->data = d;
      this->prev = NULL;
      this-> next = NULL;
    }
    
    ~Node()
    {
      int val = this->data;
      if(next!=NULL)
      {
        delete next;
        next = NULL;
      }
      cout<<"memory released for "<<val<<endl;
    }
};

Node* reverse(Node* &head)
{
  Node* prev = NULL;
  Node* curr = head;
  Node* forward = NULL;
  
  if(head == NULL || head->next == NULL)
  return head;
  
  while(curr!=NULL)
  {
    forward = curr->next;
    curr->next = prev;
    curr->prev = forward;
    prev = curr;
    curr = forward;
  }
  return prev;
}
void print(Node* head)
{
  Node* temp = head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

int getLength(Node* head)
{
  Node* temp = head;
  int len = 0;
  while(temp!=NULL)
  {
    len++;
    temp = temp->next;
  }
  return len;
}

void insertAtHead(Node* &head,Node* &tail, int d)
{
  
  Node* temp = new Node(d);
  if(head==NULL)
  {
    head = temp;
    tail = temp;
  }
  else
  {
  temp->next = head;
  head->prev = temp;
  head = temp;
  }
  
}

void insertAtTail(Node* &head, Node* &tail, int d)
{
  Node* temp = new Node(d);
 
  if(head==NULL)
  {
    head = temp;
    tail = temp;
  }
  
  tail->next = temp;
  temp->prev = tail;
  
  tail = temp;
}

void insertAt(Node* &head, Node* &tail, int pos, int d)
{
  Node* newNode = new Node(d);
  Node* temp = head;
  int count = 0;
  
  if(pos == 0)
  {
    insertAtHead(head,tail,d);
    return;
  }
  
  //Going to one place before required position
  while(count<pos-1)
  {
    temp = temp->next;
    count++;
  }
  
  //last position
  if(temp->next == NULL)
  {
    insertAtTail(head,tail,d);
    return;
  }
  
  //any middle position
  newNode-> next = temp->next;  
  temp->next = newNode;
  newNode->prev = temp;
  temp->next->prev = newNode;
  
}

void deleteNode(Node* &head, int pos)
{
  Node* curr = head;
  Node* prev = NULL;
  
  if(pos == 0)
  {
    Node* temp = head;
    
    temp->next->prev = NULL;
    head = head->next;
    temp->next = NULL;
    delete temp;
    return;
  }
  
  int cnt = 1;
  while(cnt<pos)
  {
    prev = curr;
    curr = curr->next;
    cnt++;
  }
  
  //prev->next = curr->next;
  //curr->next = NULL;
  
  curr->prev = NULL;
  prev->next = curr->next;
  curr->next = NULL;
  delete curr;
  
}

int main()
{
   // Node* node1 = new Node(5);
   // Node* head = node1;
   // Node* tail = node1;
    //print(head);
    
    Node* head = NULL;
    Node* tail = NULL;
    cout<<"Length is "<<getLength(head)<<endl;
    cout<<"Insert At Head\n";
    insertAtHead(head,tail,10);
    print(head);
    cout<<"Insert At Tail\n";
    insertAtTail(head, tail,15);
    print(head);
    cout<<"Insert At A Particular Position\n";
    insertAt(head,tail,2,8);
    print(head);
    
    cout<<"Insert At Head\n";
    insertAtHead(head,tail,100);
    print(head);
    
    cout<<"Delete at\n";
    deleteNode(head, 0);
    print(head);
    
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    
    head = reverse(head);
    print(head);
}