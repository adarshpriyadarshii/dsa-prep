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
Node* merge(Node* h1,Node* h2){
		if(h1==NULL or h2==NULL){
			return (h1==NULL)?h2:h1;
		}
		if(h1->data<h2->data){
			h1->next=merge(h1->next,h2);
			return h1;
		}
		else{
			h2->next=merge(h1,h2->next);
			return h2;
		}
	}
Node* mergesort(Node* head){
		if(head==NULL or head->next==NULL)return head;
		Node *sp=head,*fp=head,*pre=sp;
		while(fp and fp->next){
			pre=sp;
			sp=sp->next;
			fp=fp->next->next;
		}
		pre->next=NULL;
		Node* h1=mergesort(head);
		Node* h2=mergesort(sp);
		return merge(h1,h2);
	}
void printList(Node* head){
	Node *n=head;
	while (n != NULL) {
		cout << n->data << "->";
		n = n->next;
	}
	cout<<"NULL"<<endl;
}
int main()
{
	Node* head = NULL;
	head=head->add(2,head);
	head=head->add(4,head);
	head=head->add(3,head);
	head=head->add(1,head);

	printList(head);
    head=mergesort(head);
    printList(head);


	return 0;
}