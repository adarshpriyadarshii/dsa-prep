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
Node* reverse_ll(Node* head){
        Node *cur=head,*n=head,*pre=NULL;
        while(cur){
            n=cur->next;
            cur->next=pre;
            pre=cur;
            cur=n;
        }
        return pre;
    }
Node* middle_element(Node *head){
    auto sp=head,fp=head;
    while(fp!=NULL && fp->next!=NULL){
        sp=sp->next;
        fp=fp->next->next;
    }
    return sp;
}
bool is_palindrome(Node *head){
    if(head==NULL)return true;
    Node* mid=middle_element(head);
    Node* curr=head;
    Node* last=reverse_ll(mid->next);
    while(last!=NULL){
        if(last->data!=curr->data)return false;
        last=last->next;
        curr=curr->next;
    }
    return true;
}
int main()
{
	Node* head = NULL;
	head=head->add(1,head);
	head=head->add(2,head);
	head=head->add(2,head);
	head=head->add(1,head);
    is_palindrome(head)?cout<<"YES":cout<<"NO";

   
	return 0;
}