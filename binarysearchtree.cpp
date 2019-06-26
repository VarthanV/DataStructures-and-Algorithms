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