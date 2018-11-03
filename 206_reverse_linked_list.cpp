#include<iostream>

struct mylist{
	int value;
	mylist *next;
	mylist(int v=0, mylist* p=nullptr):
		value(v),next(p){}
};

mylist* revert(mylist *head){
	mylist *pre = nullptr;
	while(head->next!=nullptr){
		mylist *tmp = head->next;
		head->next = pre;
		pre = head;
		head = tmp;	
	}
	head->next=pre;
	return head;	
}

void print_list(mylist* head){
	while(head!=nullptr){
		std::cout << head->value << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

int main()
{
	mylist *head=nullptr;
	mylist *current=nullptr;
	for(int i=0;i<16;++i){
		auto val = new mylist(i);
		if(head==nullptr){
			head = val;
			current = val;
		}else{
			current->next=val;
			current=val;
		}
	}
	print_list(head);
	head = revert(head);
	print_list(head);
	return 0;
}

