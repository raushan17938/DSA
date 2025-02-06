//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<int, int> idxMap;
    int preIndex = 0;

    Node* build(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;
        Node* root = new Node(preorder[preIndex++]);
        int mid = idxMap[root->data];
        root->left = build(inorder, preorder, inStart, mid - 1);
        root->right = build(inorder, preorder, mid + 1, inEnd);
        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        for (int i = 0; i < inorder.size(); i++) idxMap[inorder[i]] = i;
        return build(inorder, preorder, 0, inorder.size() - 1);
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends