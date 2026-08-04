#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
	node(int value){
		data=value;
		next=NULL;
	}
};
class linkedlist{
	private:
		node* head;
	public:
		linkedlist(){
			head=NULL;
		}
		void insertatbegin(int value){
			node* newnode= new node(value);
			newnode->next=head;
			head=newnode;
		}
		void circularinsert(int value){
			node*newnode=new node(value);
			if(head==NULL){
				head=newnode;
				newnode->next=head;
				return;
			}
			node* temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			newnode->next=head;
			temp->next=newnode;
			head=newnode;
		}

   bool hascycle(){
	node* small=head;
	node*fast=head;
	while(fast !=NULL&&fast->next!= NULL){
		small=small->next;
		fast=fast->next->next;
		if(fast==small){
			return true;
		}
		}
		return false;
	}

};
int main(){
	linkedlist l1,l2;
	l1.insertatbegin(2);
	l1.insertatbegin(3);
	l1.insertatbegin(4);
	l1.insertatbegin(5);
	l1.insertatbegin(6);
	cout<<(l1.hascycle()?"true":"false");
	l2.circularinsert(2);
	l2.circularinsert(3);
	l2.circularinsert(4);
	l2.circularinsert(5);
	l2.circularinsert(6);
	cout<<(l2.hascycle()?"true":"false");
	return 0;
}
