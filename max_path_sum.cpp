#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function
int maxPathDown(TreeNode *node, int &maxi)
{
  if (node == NULL)
    return 0;

  int left = max(0, maxPathDown(node->left, maxi));
  int right = max(0, maxPathDown(node->right, maxi));

  maxi = max(maxi, left + right + node->val);

  return max(left, right) + node->val;
}

// Main function
int maxPathSum(TreeNode *root)
{
  int maxi = INT_MIN;
  maxPathDown(root, maxi);
  return maxi;
}

// Example usage
int main()
{
  /*
       10
      /  \
     2   10
    / \    \
   20  1    -25
             /  \
            3    4
  */

  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(2);
  root->right = new TreeNode(10);
  root->left->left = new TreeNode(20);
  root->left->right = new TreeNode(1);
  root->right->right = new TreeNode(-25);
  root->right->right->left = new TreeNode(3);
  root->right->right->right = new TreeNode(4);

  cout << "Maximum Path Sum: " << maxPathSum(root) << endl;

  return 0;
}
