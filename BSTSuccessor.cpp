// BST Successor Search

// In a Binary Search Tree (BST), an Inorder Successor of a node is defined as the node with the smallest key greater 
// than the key of the input node (see examples below). Given a node inputNode in a BST, you’re asked to write a function 
// findInOrderSuccessor that returns the Inorder Successor of inputNode. If inputNode has no Inorder Successor, return null.

// Explain your solution and analyze its time and space complexities.

Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

Node* findInOrderSuccessor( Node *inputNode )
{
   // your code goes here
   // if right is present left most child of the right is my in-order successor.
   // no-op if have left child.
   // no right child - if node == node->parent->left -- node->parent
   //                  if node == node->parent->right -- got to parent's parent. repeat logic.
    if (inputNode->right != nullptr) { 
      Node * curr = inputNode->right;
        while (curr->left != nullptr) {
          curr = curr->left;
          
        }
      return curr;
    }
   
   while (inputNode != NULL) {
      if (inputNode->parent == nullptr) return nullptr;
      if (inputNode->parent->left == inputNode) {
            return inputNode->parent;
      } else {
           inputNode = inputNode->parent;        
      }
   }
  return inputNode;
}
