#include <bits/stdc++.h>
using namespace std;

// ----------------- Tree Node Definition -----------------
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ----------------- Your Function -----------------
bool getPath(TreeNode *root, int target, vector<int> &path)
{
  if (!root)
    return false;
  path.push_back(root->val);
  if (root->val == target)
    return true;
  if (getPath(root->left, target, path) || getPath(root->right, target, path))
    return true;
  path.pop_back();
  return false;
}

// ----------------- Main Function -----------------
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Build your test tree here
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);

  int target = 5;
  vector<int> path;

  if (getPath(root, target, path))
  {
    for (int i = 0; i < path.size(); i++)
    {
      cout << path[i] << " ";
    }
  }
  else
  {
    cout << "Target not found\n";
  }

  return 0;
}
