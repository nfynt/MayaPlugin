//Tree traversal of Left(L), Right(R), and Parent(P) nodes
// DFS:
// In-order -> LPR
// Pre-order -> PLR
// Post-order -> LRP
// BFS height-wise traversal

#include <iostream>

using namespace std;

//Node of a binary tree
struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
    //Node(int data) : data(data), left(NULL), right(NULL) {}   Shorthand
};

void InorderTraversal(Node *n)
{
    if(n==NULL) return;
    InorderTraversal(n->left);
    cout<<n->data<<" ";
    InorderTraversal(n->right);
}

void PreorderTraversal(Node *n)
{
    if(n==NULL) return;
    cout<<n->data<<" ";
    PreorderTraversal(n->left);
    PreorderTraversal(n->right);
}

void PostorderTraversal(Node *n)
{
    if(n==NULL) return;
    PostorderTraversal(n->left);
    PostorderTraversal(n->right);
    cout<<n->data<<" ";
}

int HeightOfTree(Node *n)
{
    if(n==NULL) return 0;
    int left = HeightOfTree(n->left);
    int right = HeightOfTree(n->right);
    int h = (left>right)? left+1: right+1;
    return h;
}

void PrintTreeLevel(Node *n, int lvl);

void BFS(Node *n, int height)
{
    for(int i=1;i<=height;i++)
       { 
           cout<<"Level-"<<i<<" ";
           PrintTreeLevel(n,i);
           cout<<endl;
       }
}

void PrintTreeLevel(Node *n, int lvl)
{
    if(n==NULL) return;
    if(lvl==1) cout<<n->data<<" ";
    else{ PrintTreeLevel(n->left,lvl-1); PrintTreeLevel(n->right,lvl-1);}
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right=new Node(3);
    root->right->right = new Node(6);

    int h=HeightOfTree(root);
    cout<<"Height of tree: "<<h<<endl;
    cout<<"BFS:\n";BFS(root,h);
    cout<<"\nInorder: ";InorderTraversal(root);
    cout<<"\nPreorder: ";PreorderTraversal(root);
    cout<<"\nPostorder: ";PostorderTraversal(root);
    return 0;
}
