#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node
{
public:
  int data;
  Node *left;
  Node *right;

  // Constructor to initialize a new node
  Node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

bool isLeaf(Node *root)
{
  return !root->left && !root->right;
}

void addLeftBoundary(Node *root, vector<int> &res)
{
  Node *curr = root->left;
  while (curr)
  {
    if (!isLeaf(curr))
      res.push_back(curr->data);
    if (curr->left)
      curr = curr->left;
    else
      curr = curr->right;
  }
}

void addLeafNodes(Node *root, vector<int> &res)
{
  if (isLeaf(root))
  {
    res.push_back(root->data);
    return;
  }
  if (root->left)
    addLeafNodes(root->left, res);
  if (root->right)
    addLeafNodes(root->right, res);
}

void addRightBoundary(Node *root, vector<int> &res)
{
  vector<int> arr;
  Node *curr = root->right;
  while (curr)
  {
    if (!isLeaf(curr))
      arr.push_back(curr->data);
    if (curr->right)
      curr = curr->right;
    else
      curr = curr->left;
  }
  for (int i = arr.size() - 1; i >= 0; i--)
  {
    res.push_back(arr[i]);
  }
}

vector<int> boundaryTraversal(Node *root)
{
  vector<int> res;
  if (root == NULL)
    return res;
  if (!isLeaf(root))
    res.push_back(root->data); // root is included only if not a leaf
  addLeftBoundary(root, res);
  addLeafNodes(root, res);
  addRightBoundary(root, res);
  return res;
}

int main()
{
  // Example tree:
  //         1
  //       /   \
    //      2     3
  //     / \   / \
    //    4   5 6   7
  //       / \
    //      8   9

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  root->left->right->left = new Node(8);
  root->left->right->right = new Node(9);

  vector<int> result = boundaryTraversal(root);

  cout << "Boundary Traversal: ";
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}
