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

void deleting(Node* &head, int key)
{
  Node* temp = head;
  Node* deleteN = NULL;
  if(head->data == key)
  {
    head = head->next;
    delete(temp);
    return;
  }

  while(temp->next->data != key)
  temp = temp->next;

  deleteN = temp;
  temp->next = temp->next->next;
  // delete(deleteN);
}
int main()
{
    Node* node1 = new Node(5);
    
    Node* head = node1;
   // cout<<head->data<<endl;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    deleting(head,10);
    print(head);
}