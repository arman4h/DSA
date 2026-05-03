#include<iostream> 
#include<vector>
using namespace std ; 

class Node{
public:
    int data; 
    Node* left; 
    Node* right; 

    Node(int val) {
        data = val;
        left = right = NULL ;
    }
};

static int idx = -1 ;
Node* buildTree(vector<int> preorder) {
    idx++ ; 
    if (idx >= static_cast<int>(preorder.size()) || preorder[idx] == -1) return nullptr;

    Node* root = new Node(preorder[idx]) ; 
    root->left = buildTree(preorder) ; 
    root->right = buildTree(preorder) ;
    return root ; 
}


int main() {
    vector<int> preorder = {1, 2, -1, -1 ,3, 4 , - 1,-1, 5 ,-1, -1} ;

    Node* root = buildTree(preorder) ;

    cout << root-> data << endl ; 
    cout << root->right->right-> data << endl ; 


    return 0 ;

}