#include<string>
#include<iostream>

using namespace std;

// Represents a single node in an arbitarary 
// tree structure
class TreeNode{

public:
 TreeNode(TreeNode* p, string k, int pwr)
   :parent{p}, key{k}, val_mw{pwr}
   {
     // set children nodes to nullptr
     childL= nullptr;
     childR= nullptr;
   }

  TreeNode* parent;
  string key; // the searchable value
  int val_mw; // the payload of the node
  TreeNode* childL;
  TreeNode* childR;
};

// store our tree simply by holding a 
// pointer to the root node
TreeNode*powerTree;

// An in-order recursive tree traversal algroithm
// See Section 12.1 in Cormen,Leiseron et. al "Introduction to Aglos"

void in_order_tree_walk(TreeNode* root){
  if(root != nullptr){
    // recusively call with this root's left child
    in_order_tree_walk(root->childL);
    cout << root->key << '\n';
    in_order_tree_walk(root->childR);
  }
}

int main(){
  TreeNode* node = new TreeNode(nullptr, "Fermi", 1098);
  // make our first node the root of the tree
  powerTree = node;
  // Holds a reference to what will become a parent
  TreeNode* tempParent = powerTree;

  node = new TreeNode(powerTree, "Blue castle project", 1500);
  // assigned our Blue Castle to the parent's left child  
  powerTree->childL = node;

  // insert Oconee
  node = new TreeNode(tempParent, "Oconee", 846);
  // point parent to child
  tempParent->childR = node;
  // make Oconee the parent we'll link Limerick to
  tempParent = node;
  
  node = new TreeNode(tempParent,"Limerick", 1134);
  // tell parent about its new child!
  tempParent->childL = node;
  // Walk our tree with an in-order recursive algo
  in_order_tree_walk(powerTree);
}