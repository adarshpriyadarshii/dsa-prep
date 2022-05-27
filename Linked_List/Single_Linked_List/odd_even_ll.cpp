#include <bits/stdc++.h>
using namespace std;
class Node {
    //node have two things=> data and ref to next node.
public:
	int data;
	Node* next;
	Node(){
		this->next=NULL;
	}
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
	Node *add(int data,Node *head){
		if(head==NULL){
			Node *temp= new Node(data);
			head=temp;
		}
		else{
			Node *temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=new Node(data);
		}
		return head;
	}
};
void printList(Node* head)
{
	Node *n=head;
	while (n != NULL) {
		cout << n->data << "->";
		n = n->next;
	}
	cout<<"NULL"<<endl;
}
Node *odd_even(Node *head){
    Node *o=head,*e=o->next,*temp=e;
    while(e!=NULL && e->next!=NULL){
        o->next=e->next;
        o=o->next;
        e->next=o->next;
        e=e->next;
    }
    o->next=temp;
    return head;
}
int main()
{
	Node* head = NULL;
	head=head->add(1,head);
	head=head->add(2,head);
	head=head->add(3,head);
	head=head->add(4,head);
    head=head->add(5,head);

	printList(head);
    head=odd_even(head);
    printList(head);
	return 0;
}