#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Helper function: compute height & update diameter
int height(TreeNode *root, int &diameter)
{
  if (root == NULL)
    return 0;

  int lh = height(root->left, diameter);
  int rh = height(root->right, diameter);

  diameter = max(diameter, lh + rh); // update diameter
  return 1 + max(lh, rh);
}

// Main function: diameter of binary tree
int diameterOfBinaryTree(TreeNode *root)
{
  int diameter = 0;
  height(root, diameter);
  return diameter;
}

int main()
{
  // Example tree:
  //       1
  //      / \
    //     2   3
  //    / \
    //   4   5
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  cout << "Diameter of tree: " << diameterOfBinaryTree(root) << endl;

  return 0;
}
