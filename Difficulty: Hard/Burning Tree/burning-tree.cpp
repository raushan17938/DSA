/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int ans;
    pair<int,int> dfs(Node* r,int t){
        if(!r) return {0,-1};
        auto l=dfs(r->left,t), ri=dfs(r->right,t);
        int h=max(l.first,ri.first)+1, d=-1;
        if(r->data==t) d=0, ans=max(ans,h-1);
        else if(l.second>=0) d=l.second+1, ans=max(ans,ri.first+d);
        else if(ri.second>=0) d=ri.second+1, ans=max(ans,l.first+d);
        return {h,d};
    }
    int minTime(Node* root,int target){
        ans=0;
        dfs(root,target);
        return ans;
    }
};