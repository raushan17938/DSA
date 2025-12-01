class Solution {
  private:
    struct TrieNode {
        TrieNode *child[2];
        int count;
        TrieNode() {
            child[0] = child[1] = nullptr;
            count = 0;
        }
    };

    void insert(TrieNode* root, int num) {
        TrieNode* curr = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!curr->child[bit]) {
                curr->child[bit] = new TrieNode();
            }
            curr = curr->child[bit];
            curr->count++;
        }
    }

    int query(TrieNode* root, int num, int k) {
        int pairs = 0;
        TrieNode* curr = root;
        
        for (int i = 30; i >= 0; i--) {
            if (!curr) break;
            
            int bit_num = (num >> i) & 1;
            int bit_k = (k >> i) & 1;

            if (bit_k == 1) {

                if (curr->child[bit_num]) {
                    pairs += curr->child[bit_num]->count;
                }
                

                curr = curr->child[1 - bit_num];
            } else {

                curr = curr->child[bit_num];
            }
        }
        return pairs;
    }

    void deleteTrie(TrieNode* root) {
        if (!root) return;
        deleteTrie(root->child[0]);
        deleteTrie(root->child[1]);
        delete root;
    }

  public:
    int cntPairs(vector<int>& arr, int k) {
        TrieNode* root = new TrieNode();
        long long count = 0;
        
        for (int num : arr) {
            count += query(root, num, k);
            insert(root, num);
        }
        
        deleteTrie(root);
        return (int)count;
    }
};