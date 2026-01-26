#include<iostream>
#include<vector> 
using namespace std ;

class Node{
public:
    int data ; 
    Node* left ; 
    Node* right ; 

    Node(int val) {
        data = val ; 
        left = right = NULL ;
    }
} ;

static int idx = -1 ; 

Node* buildTree(vector<int> preorder){
    idx++ ; 
    if (idx >= static_cast<int>(preorder.size()) || preorder[idx] == -1) return NULL ; 

    Node* root = new Node(preorder[idx]) ;
    root->left = buildTree(preorder);
    root->right = buildTree(preorder) ;

    return root ;
}

int height(Node* root) {
    if(root == NULL) return 0 ; 

    int leftH = height(root-> left) ; 
    int rightH = height(root-> right) ; 

    return max(leftH, rightH)+1 ;
}


int main() {
    vector<int> newarray = {1,2,4,-1,4,-1,-1,3,3,-1,-1,5,-1,-1} ;

    Node* root = buildTree(newarray) ; 

    cout << root->data << endl ;

    cout << "Height: " << height(root) << endl ;

    return 0 ;
}