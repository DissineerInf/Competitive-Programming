#include <iostream>
#include <vector>

using namespace std;

struct BSTnode {
	int data;
	BSTnode * left;
	BSTnode *right;
	
	BSTnode(int data): data(data){
		left=nullptr;
		right=nullptr;
	}
};
typedef struct BSTnode node;

node * insert_node (node * root, int data)
{
	if ( root == nullptr) 
	{
		root = new node(data);
		return root;
	}

	if (data <= root-> data) root->left = insert_node(root->left,data);
	if(data > root->data) root->right = insert_node(root->right,data);

	return root;
} 
int number_of_leaf(node * t)
{
	if(t == nullptr) return  0;
	if (t->left == nullptr && t->right==nullptr) return 1;
	else return(number_of_leaf(t->left)+number_of_leaf(t->right));
}

int number_of_internal(node * t)
{
	if(t == nullptr) return  0;
	if (t->left == nullptr && t->right==nullptr) return 0;
	else return(number_of_internal(t->left)+number_of_internal(t->right)+1);
}

int total_nodes(node * t)
{	
	if(t == nullptr) return  0;
	if (t->left == nullptr && t->right==nullptr) return 1;
	else return(total_nodes(t->left)+total_nodes(t->right)+1);
}

int height(node *t)
{
	if (t==nullptr) return 0;
	if (t->left == nullptr && t->right==nullptr) return 0;
	else return( 1+ max(height(t->left),height(t->right)));
}


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

node * search_BST(node * root, int key)
{
	if (root==nullptr) return nullptr;
	if(key == root->data ) return root;
	if(key < root->data) return (search_BST(root->left, key));
	else return (search_BST(root->right,key));
	
}

int main() {
	node * root = nullptr;

	vector<int> v {20,10,15,30,35,27,5,2,1,29};

	for (auto it = v.begin(); it!= v.end();it++)
	root = insert_node(root,*it);

	// Preorder traversal
	pre_order_traversal(root);
	cout<<endl;
	// Inorder traversal
	in_order_traversal(root);
	cout<<endl;
	// Postorder traversal
	post_order_traversal(root);
	cout<<endl;

	// Number of leaf nodes
	cout<<number_of_leaf(root)<<endl;
	// Number of internal nodes
	cout<<number_of_internal(root)<<endl;
	// Total number of nodes
	cout<<total_nodes(root)<<endl;

	// Height of the tree
	cout<<height(root)<<endl;

	// Search element
	int key = 30;
	node * res = search_BST(root,key);
	if(res==nullptr) cout<<"NOT FOUND"<<endl;
	else cout<<res->data<<endl;

return 0;
}