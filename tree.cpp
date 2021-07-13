#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//----------------------------------------------
class Solution
{
public:
    Node* insert(Node* root, int data)
    {
        if(root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node* cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    void preOrder(Node *root);
    void postOrder(Node *root);
    void inOrder(Node *root);

    int height(Node* root);
    void levelOrder(Node * root);

}; //End of Solution

//---------------------------------------------------
void Solution::preOrder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    
    preOrder(root->left);
    preOrder(root->right);
}

//----------------------------------------------------
void Solution::inOrder(Node *root)
{
    if (root == nullptr)
        return;
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//-------------------------------------------------------
void Solution::postOrder(Node *root)
{
    if (root == nullptr)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

//------------------------------------------------------------
int Solution::height(Node* root)
{
    int leftHeight = -1; 
    int rightHeight = -1;
    
    if (root->left)
        leftHeight = height(root->left);
        
    if (root->right)
        rightHeight = height(root->right);
    
    return max(leftHeight, rightHeight) + 1;
}

//------------------------------------------------------------
// In level-order traversal, nodes are visited level by level from left to right
void Solution::levelOrder(Node * root)
{
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty())
    {
        Node *tmpRoot = q.front();
        cout << tmpRoot->data << " ";
        q.pop();
        
        if (tmpRoot->left != nullptr)
            q.push(tmpRoot->left);
        if (tmpRoot->right != nullptr)
            q.push(tmpRoot->right);            
    }   
}

//------------------------------------------------------------
int main()
{
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	// myTree.preOrder(root);

    int height = myTree.height(root);
    cout << "Height of tree: " << height << "\n";

    return 0;
}
