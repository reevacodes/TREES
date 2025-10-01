#include <iostream>
using namespace std;

// TreeNode structure
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  void changeTree(TreeNode *root)
  {
    if (root == nullptr)
      return;

    // Calculate sum of children
    int childSum = 0;
    if (root->left)
      childSum += root->left->val;
    if (root->right)
      childSum += root->right->val;

    // If root is greater than sum of children, push value down to BOTH children
    if (childSum < root->val)
    {
      if (root->left)
        root->left->val = root->val;
      if (root->right)
        root->right->val = root->val;
    }

    // Recurse on children
    changeTree(root->left);
    changeTree(root->right);

    // Update current node after recursion
    int total = 0;
    if (root->left)
      total += root->left->val;
    if (root->right)
      total += root->right->val;
    if (root->left || root->right)
      root->val = total;
  }
};

// Inorder traversal to print tree
void inorderTraversal(TreeNode *root)
{
  if (!root)
    return;
  inorderTraversal(root->left);
  cout << root->val << " ";
  inorderTraversal(root->right);
}

int main()
{
  // Build sample tree
  TreeNode *root = new TreeNode(40);
  root->left = new TreeNode(10);
  root->right = new TreeNode(20);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(30);
  root->right->right = new TreeNode(40);

  Solution sol;

  cout << "Binary Tree before modification: ";
  inorderTraversal(root);
  cout << endl;

  sol.changeTree(root);

  cout << "Binary Tree after Children Sum Property: ";
  inorderTraversal(root);
  cout << endl;

  return 0;
}
