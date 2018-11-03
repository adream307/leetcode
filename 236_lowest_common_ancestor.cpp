#include<iostream>
#include<list>
#include<utility>

using namespace std;

struct mynode{
	int val;
	mynode *left;
	mynode *right;
	mynode(int v=0, mynode *l=nullptr, mynode *r=nullptr):
		val(v),left(l),right(r){}
};

mynode* gen_tree(int n){
	int cnt=0;
	list<mynode*> parents;
	list<mynode*> children;
	mynode* root = new mynode(cnt++);
	parents.push_back(root);
	bool set_left = true;
	while(cnt < n){
		if(parents.empty()){
			parents = std::move(children);
			children.clear();
		}
		auto node = new mynode(cnt++);
		auto &p = parents.front();
		if(set_left){
			p->left = node;
			set_left = false;		
		}else{
			p->right = node;
			set_left=true;
			parents.pop_front();
		}	
		children.push_back(node);
	}
	return root;	
}

mynode *lowest_common_ancestor(mynode* root, int p, int q){
	if(root==nullptr) return root;
	if(root->val == p) return root;
	if(root->val == q) return root;
	auto left = lowest_common_ancestor(root->left,p,q);
	auto right = lowest_common_ancestor(root->right,p,q);
	if(left!=nullptr && right!=nullptr) return root;
	if(left!=nullptr) return left; 
	if(right!=nullptr) return right;
	return nullptr;
}

void print_tree(mynode *root){
	if(root==nullptr) return;
	cout << root->val << " ";
	print_tree(root->left);
	print_tree(root->right);
}

int main(){
	auto root = gen_tree(16);
	print_tree(root);
	cout << endl;
	auto ancestor = lowest_common_ancestor(root,7,8);
	if(ancestor!=nullptr){
		cout << ancestor->val << std::endl;
	}	
	return 0;
}
