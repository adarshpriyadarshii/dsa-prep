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
Node *remove_duplicate(Node *head){
    set<int> vis;
    Node *cur=head,*pre=cur;
    while(cur){
        if(vis.count(cur->data)){
            pre->next=cur->next;
            delete cur;
        }
        else {
            vis.insert(cur->data);
            pre=cur;
        }
        cur=pre->next;
    }
    return head;
}

int main()
{
	Node* head = NULL;
	head=head->add(6,head);
	head=head->add(2,head);
	head=head->add(5,head);
	head=head->add(4,head);
    head=head->add(2,head);

	printList(head);
    head=remove_duplicate(head);
    printList(head);
	return 0;
}