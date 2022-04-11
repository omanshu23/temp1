// Linked List basic operation

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

node* reverseRecursive(node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node* newhead = reverse_iterator(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

void deleteAtHead(node* &head)
{
    node* todelete = head;
    head = head->next;

    delete todelete;
}


void deletion1(node* &head, int val)
{
    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void deletion(node* &head, int val)
{
    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

bool search(node* &head, int key)
{
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* &head)
{
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverse(node* &head)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    display(head);
    cout<<endl;
    insertAtHead(head, 11);
    display(head);
    cout<<endl;
    cout<<search(head, 5);
    cout<<endl;
    deletion(head, 3);
    display(head);
    deleteAtHead(head);
    cout<<endl;
    display(head);
    cout<<endl;
    node* newhead = reverse(head);
    display(head);
    cout<<endl;
    node* newhead = reverseRecursive(head);
    display(newhead);

    return 0;
}
