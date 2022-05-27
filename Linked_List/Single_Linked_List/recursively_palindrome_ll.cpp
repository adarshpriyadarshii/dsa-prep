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
bool is_palindrome(Node* &left,Node* right){
    if(right==NULL)return true;
    bool first=is_palindrome(left,right->next);
    if(first==false)return false;
    bool second=(right->data == left->data);
    left=left->next;
    return second;
}
int main()
{
	Node* head = NULL;
	head=head->add(1,head);
	head=head->add(2,head);
	head=head->add(2,head);
	head=head->add(1,head);

	int ans=is_palindrome(head,head);
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

	return 0;
}