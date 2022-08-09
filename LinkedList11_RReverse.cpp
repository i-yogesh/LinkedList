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

int getLength(Node* head)
{
  int c = 0;
  while(head!=NULL)
  {
    head = head->next;
    c++;
  }
  return c;
}
Node* findMiddle(Node* head)
{
  int c = 0;
  int len = getLength(head);
  int ans = len/2;
 // cout<<ans<<endl;
  Node* temp = head;
  while(c<ans)
  {
    temp = temp->next;
    c++;
  }
  //cout<<"Ans "<<temp->data<<endl;
  return temp;
  
}

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

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    //print(head);
    
    insertAtTail(tail,15);
   // print(head);
    
    insertAtTail(tail,20);
    insertAtTail(tail,25);
    insertAtTail(tail,30);
    insertAtTail(tail,35);
    insertAtTail(tail,40);
    print(head);
    Node* ans = findMiddle(head);
    cout<<"Ans "<<ans->data<<endl;
}