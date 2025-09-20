#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

class Solution
{
public:
  // Function to return bottom view of the binary tree
  vector<int> bottomView(Node *root)
  {
    vector<int> ans;
    if (root == NULL)
      return ans;

    map<int, int> mpp; // line -> node->data
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
      auto it = q.front();
      q.pop();

      Node *node = it.first;
      int line = it.second;

      // Always update -> last node seen at this line will be bottom view
      mpp[line] = node->data;

      if (node->left)
        q.push({node->left, line - 1});
      if (node->right)
        q.push({node->right, line + 1});
    }

    // Collect results from left to right
    for (auto it : mpp)
    {
      ans.push_back(it.second);
    }
    return ans;
  }
};

// ---------- Helper to Build Tree ----------
Node *buildTree(vector<int> arr)
{
  // arr contains level-order values, -1 means NULL
  if (arr.empty() || arr[0] == -1)
    return NULL;

  Node *root = new Node(arr[0]);
  queue<Node *> q;
  q.push(root);

  int i = 1;
  while (!q.empty() && i < arr.size())
  {
    Node *curr = q.front();
    q.pop();

    // left child
    if (arr[i] != -1)
    {
      curr->left = new Node(arr[i]);
      q.push(curr->left);
    }
    i++;

    if (i >= arr.size())
      break;

    // right child
    if (arr[i] != -1)
    {
      curr->right = new Node(arr[i]);
      q.push(curr->right);
    }
    i++;
  }
  return root;
}

// ------------------ MAIN ------------------
int main()
{
  // Example: Tree = [1,2,3,4,5,-1,6]
  // Structure:
  //         1
  //       /   \
    //      2     3
  //     / \     \
    //    4   5     6
  vector<int> arr = {1, 2, 3, 4, 5, -1, 6};

  Node *root = buildTree(arr);

  Solution sol;
  vector<int> ans = sol.bottomView(root);

  cout << "Bottom View: ";
  for (int x : ans)
    cout << x << " ";
  cout << endl;

  return 0;
}
