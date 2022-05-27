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
bool detect_loop(Node *head){
   Node *sp=head,*fp=head;
   while(fp && fp->next){
       sp=sp->next;
       fp=fp->next->next;
       if(sp==fp)return true;
   }
   return false;
}
Node *remove_loop(Node *head){
    Node *sp=head,*fp=head;
     while(fp && fp->next){
        sp=sp->next;
        fp=fp->next->next;
        if(sp==fp)break;
    }
    if(sp==fp){
        sp=head;
        while(sp->next!=fp->next){
            sp=sp->next;
            fp=fp->next;
        }
        fp->next=NULL;
    }
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
    head=head->add(6,head);
	printList(head);
    //creating loop
    auto cur=head,temp=head;
    while(cur->next)cur=cur->next;
    while(temp->data!=2)temp=temp->next;
    cur->next=temp;//loop created
    cout<<(detect_loop(head)?"True":"False")<<endl;
    head=remove_loop(head);
    cout<<(detect_loop(head)?"True":"False");
	return 0;
}