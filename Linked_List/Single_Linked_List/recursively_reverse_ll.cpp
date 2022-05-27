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
void reverse_printList(Node* head){
	if(head==NULL)return;
    reverse_printList(head->next);//recursion.
    cout<<head->data<<" ";//printing when backtracking.
}
int main(){
	Node* head = NULL;
	head=head->add(1,head);
	head=head->add(2,head);
	head=head->add(3,head);
	head=head->add(4,head);

	reverse_printList(head);

	return 0;
}