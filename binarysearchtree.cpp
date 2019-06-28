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
Node *root = root;
while(root -> right != NULL){
	root = root->right;
}
return root->item;
}
int HEIGHT(Node * root){
	int height = 0;
	if (root == NULL)
	{
		return -1;
	}
	else{
	int lheight = HEIGHT(root->left);
	int rheight = HEIGHT(root->right);
    height = max(lheight, rheight) + 1;
	}
	return height;
}
int PrintLevel(Node * root,int level){
if(root == NULL){
	return -1;

}
if(level == 1){
	return root->item;
}
else{
	PrintLevel(root->left, level);
	PrintLevel(root->right, level);
}

}

int PrintLevelNode(Node * root ){
	int h = HEIGHT(root);
	for (int i = 0; i < h; i++){
		cout << PrintLevel(root, i);
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

    Search(root, 110) == true ? cout << "Elem Found"<<endl : cout << "Sorry Elem Not found" << endl; 

}