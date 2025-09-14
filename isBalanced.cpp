#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check height and balance together
int dfsHeight(TreeNode *root)
{
  if (root == NULL)
    return 0;

  int lh = dfsHeight(root->left);
  if (lh == -1)
    return -1;

  int rh = dfsHeight(root->right);
  if (rh == -1)
    return -1;

  if (abs(lh - rh) > 1)
    return -1; // unbalanced
  return 1 + max(lh, rh);
}

// Main function to check balance
bool isBalanced(TreeNode *root)
{
  return dfsHeight(root) != -1;
}

int main()
{
  // Example 1: Balanced tree
  //      1
  //     / \
    //    2   3
  //   / \
    //  4   5
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  root1->left->left = new TreeNode(4);
  root1->left->right = new TreeNode(5);

  cout << "Tree 1 Balanced? " << (isBalanced(root1) ? "Yes" : "No") << endl;

  // Example 2: Unbalanced tree
  //      1
  //     /
  //    2
  //   /
  //  3
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->left->left = new TreeNode(3);

  cout << "Tree 2 Balanced? " << (isBalanced(root2) ? "Yes" : "No") << endl;

  return 0;
}
