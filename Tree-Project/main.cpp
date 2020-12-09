#include <iostream>
#include<string>

using namespace std;
// Represents a single node in an arbitarary 
// tree structure
struct TreeNode
{
   string gems;
   struct TreeNode* left;
   struct TreeNode* right;

 TreeNode(string g)
    {
        gems = g;
        left = nullptr;
        right = nullptr;
    }
};

// An in-order recursive tree traversal algroithm

void in_order_tree_walk(TreeNode* root){
  if(root != nullptr){
    // recusively call with this root's left child
    in_order_tree_walk(root->left);
    cout << root->gems << '\n';
    in_order_tree_walk(root->right);
  }
}

TreeNode* insertValue(TreeNode* root, string newValue) // method for insertion
{
    if (root == nullptr)
    {
        root = new TreeNode(newValue);
        return root;
    }
    if (root->gems > newValue)
    {
        root->left = insertValue(root->left, newValue);
    }
    else {
        root->right = insertValue(root->right, newValue);
    }
    return root;
}
string leftTraversal(TreeNode* root) // method for traversing left
{

    root = root->left;
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->gems;
}

string rightTraversal(TreeNode* root) // method for traversing right
{

    root = root->right;
    while (root->left != nullptr)
    {
        root = root->left;
    }

    return root->gems;
}

TreeNode* deleteValue(TreeNode* root, string value)
{
   if(root == nullptr)
   {
     return root;
   }
    if(root->gems > value)
   {
     root->left = deleteValue(root->left,value);
   }
   else if(root->gems < value)
   {
     root->right = deleteValue(root->right,value);
   }
   else{
     if(root->left == nullptr && root->right ==nullptr)
     {
       root = nullptr;
     }
     else if(root->left != nullptr)
     {
      root->gems = leftTraversal(root);
      root->left = deleteValue(root->left, root->gems);
     }
     else{
        root->gems = rightTraversal(root);
       root->right = deleteValue(root->right, root->gems);
     }
   }
   return root;
}

int main() {

struct TreeNode* root = new TreeNode("Beritoite");
 root->left = new TreeNode("Red Beryl");
 root->right = new TreeNode("Tanzanite");
 root->left->left = new TreeNode("Taaffeite");
 root->left->right = new TreeNode("Painite");
 root->right->left = new TreeNode("Larimar");
 root->right->left->left = new TreeNode("Gradiderite");
 root->right->left->right = new TreeNode("Black Opal");
 root->right->left->left->left = new TreeNode("Alexandrite");
 root->right->left->left->right = new TreeNode("Paraiba Tourmaine");

  // Walk our tree with an in-order recursive algo
  in_order_tree_walk(root);
  cout <<'\n';
insertValue(root, "Diamond");
insertValue(root, "Emerald");
cout << "Succesfully inserted Diamond and Emerald. The final tree structure is: " << '\n';
in_order_tree_walk(root);
 cout <<'\n';
deleteValue(root, "Larimar");
cout << "Succesfully deleted Larimar. The final tree structure is: " << '\n';
in_order_tree_walk(root);
}