#include <bits/stdc++.h>
using namespace std;
class Node {
    //node have three things=> data and ref to next node and prev node.
public:
	int data;
	Node* next;
    Node* prev;
	Node(){
		this->next=NULL;
	}
	Node(int data){
		this->data=data;
		this->next=NULL;
        this->prev=NULL;
	}
	Node *add(int data,Node *head){
		if(head==NULL){
            
			Node *temp= new Node(data);
			temp->next=head;
            if(head!=NULL){ 
                head->prev=temp;
                }
            head=temp;
		}
		else{
            Node *n=new Node(data);
			Node *temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=n;
            n->prev=temp;
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
int main()
{
	Node* head = NULL;
	head=head->add(1,head);
	head=head->add(2,head);
	head=head->add(3,head);
	head=head->add(4,head);

	printList(head);

	return 0;
}