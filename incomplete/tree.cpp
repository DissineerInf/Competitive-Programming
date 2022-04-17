#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BTnode {
	int data;
	BTnode * left;
	BTnode * right;
	
	BTnode(int data) :data(data) {
		left = nullptr;
		right = nullptr;
	}
};
typedef struct BTnode node;

void pre_order_traversal(node *t)
{
	if(t==nullptr)return;
	cout<<t->data<<" ";
	pre_order_traversal(t->left);
	pre_order_traversal(t->right);
}

void in_order_traversal(node *t)
{
	if(t==nullptr)return;
	in_order_traversal(t->left);
	cout<<t->data<<" ";
	in_order_traversal(t->right);
}

void post_order_traversal(node *t)
{
	if(t==nullptr)return;
	post_order_traversal(t->left);
	post_order_traversal(t->right);
	cout<<t->data<<" ";
}






node* construct_from_preorder(vector<int> preorder, vector<int> inorder,vector<int>::iterator in_begin,
vector<int>::iterator in_end ){
	
	static int pre_start = 0;

	if (in_begin>in_end) return nullptr;

	if(pre_start>preorder.size()-1) return nullptr;

	node * root = new node(preorder[pre_start++]);

	if(in_begin==in_end) return root;

	auto it = find(in_begin,in_end,root->data);
	root->left = construct_from_preorder(preorder,inorder,in_begin,it-1);
	root->right = construct_from_preorder(preorder,inorder,it+1,in_end);
	
	return root;
}

node* construct_from_postorder(vector<int> postorder, vector<int> inorder,vector<int>::iterator in_begin,
vector<int>::iterator in_end ){
	
	static int post_end = postorder.size()-1;

	if (in_begin>in_end) return nullptr;

	if(post_end<0) return nullptr;

	node * root = new node(postorder[post_end--]);

	if(in_begin==in_end) return root;

	auto it = find(in_begin,in_end,root->data);
	root->right = construct_from_postorder(postorder,inorder,it+1,in_end);
	root->left = construct_from_postorder(postorder,inorder,in_begin,it-1);
	
	return root;
}

int main() {

	// Construction of tree from preorder and inorder traversal
	vector<int> preorder1{ 5,10,17,40,16,30,70,12,15 };
	vector<int> inorder1  { 17,10,16,40,5,70,12,30,15 };
	node * preorder_tree1 = construct_from_preorder(preorder1,inorder1,inorder1.begin(),inorder1.end());
	post_order_traversal(preorder_tree1);
	cout<<endl;

	// Construction of tree from postorder and inorder traversal
	vector<int> postorder2 {17,16,40,10,12,70,15,30,5};
	vector<int> inorder2  { 17,10,16,40,5,70,12,30,15 };
	node * postorder_tree2 = construct_from_postorder(postorder2,inorder2,inorder2.begin(),inorder2.end());
	pre_order_traversal(postorder_tree2);
	cout<<endl;
	in_order_traversal(postorder_tree2);
	cout<<endl;
	post_order_traversal(postorder_tree2);
	cout<<endl;

	
return 0;
}