#include<iostream>

struct mylist{
        int value;
        mylist *next;
        mylist(int v=0, mylist* p=nullptr):
                value(v),next(p){}
};

mylist* remove(mylist *head,int n){
	mylist* end=head;
	while(n>0 && end!=nullptr){
		--n;
		end=end->next;
	}
	if(end==nullptr){
		if(n>0) return head;
		else return head->next;
	}
	mylist* pre=head;
	end = end->next;
	while(end!=nullptr){
		pre=pre->next;
		end=end->next;
	}
	pre->next=pre->next->next;
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
        for(int i=16;i>0;--i){
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
        head = remove(head,5);
        print_list(head);
        head = remove(head,15);
        print_list(head);
        return 0;
}

