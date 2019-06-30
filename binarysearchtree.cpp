#include<iostream>
using namespace std;

struct Node {
	int item; 
	Node* left;
	Node* right;
};

Node* createNode(int item) {
	Node* newNode = new Node();
	newNode->item = item;
	newNode->left = newNode->right = NULL;
	return newNode;
}


Node* Insert(Node* root,int item) {
	if(root == NULL) { 
		root = createNode(item);
    }

	else if(item <= root->item) {
		root->left = Insert(root->left,item);
	}

	else {
		root->right = Insert(root->right,item);
	}
	return root;
}
void del(){


}
int MIN(Node * root){
if(root == NULL){
	cout << "Tree Underflow" << endl;
}

while(root -> left != NULL){
	root = root ->left;
}
return root->item;
}

int MAX(Node * root){
if(root == NULL){
	cout << "Tree Underflow" << endl;
}

while(root -> right != NULL){
	root = root->right;
}
return root->item;
}
int HEIGHT(Node * root){
	int height = 0;
	if (root == NULL)
	{
		height = 0;
		
	}
	else{
	int lheight = HEIGHT(root->left);
	int rheight = HEIGHT(root->right);
    height = max(lheight, rheight) + 1;
	}
	return height;
}
void PrintLevel(Node * root,int level){
if(root == NULL){
	cout << "Root is NULL" << endl;


}
if(level == 1){
cout<< root->item<<endl;
}
else{
	PrintLevel(root->left, level);
	PrintLevel(root->right, level);
}

}

void Preorder(Node * root){
	
	if (root != NULL)
	{
		cout << root->item << endl;
		Preorder(root->left);
		Preorder(root->right);
}
}

void Inorder(Node *root){
if(root != NULL){
	Inorder(root->left);
	cout << root->item;
	Inorder(root->right);
	

}

}

int PrintLevelNode(Node * root ){
	int h = HEIGHT(root);
	for (int i = 0; i < h; i++){
		PrintLevel(root, i);
	}
}


bool Search(Node* root,int item) {
    bool isPresent = false;
    if (root == NULL)
    {
        isPresent = false;
    }
    else if(root->item == item) {
        isPresent = true;
    
    }
    else if(item <= root->item) {
		return Search(root->left,item);
	}
	else {
		return Search(root->right,item);
	}
    return isPresent;
}

int main() {
	Node* root = NULL;  
	
	root = Insert(root,110);	
	root = Insert(root,100);	
	root = Insert(root,40);
	root = Insert(root, 1000);

	Search(root, 110) == true ? cout << "Elem Found"<<endl : cout << "Sorry Elem Not found" << endl;
	cout << "Preorder Traversal"<<endl;
	Preorder(root);
}