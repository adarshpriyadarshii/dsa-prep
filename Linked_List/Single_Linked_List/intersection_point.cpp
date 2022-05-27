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
int intersection_point(Node* head1,Node*head2){
        Node *cur1=head1,*cur2=head2;
        while(cur1!=cur2){
            if(cur1==NULL)cur1=head2;
            else cur1=cur1->next;
            if(cur2==NULL)cur2=head1;
            else cur2=cur2->next;
        }
        return cur1->data;
    }

int main(){
	Node *head1 = NULL,*head2 = NULL;
    //Linked list 1
	head1=head1->add(1,head1);
	head1=head1->add(2,head1);
	head1=head1->add(3,head1);
	head1=head1->add(4,head1);
    head1=head1->add(5,head1);
    //Linked list 2
	head2=head2->add(8,head2);
    head2=head2->add(6,head2);
	
    //Connecting LL1 and LL2
   auto cur=head2,temp=head1;
    while(cur->next)cur=cur->next;
    while(temp->data!=2)temp=temp->next;
    cur->next=temp;
    //Printing Lists
    cout<<"Linked List 1 :"<<endl;
	printList(head1);
    cout<<"Linked List 2 :"<<endl;
    printList(head2);
    //Intersection point
    cout<<"The intersection point is: "<<intersection_point(head1,head2);
    
	return 0;
}