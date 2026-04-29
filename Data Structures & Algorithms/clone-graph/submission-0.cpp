/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node *node)
    {
        if (!node)
            return node;
        
        auto it = myMap.find(node->val);
        if (it != myMap.end())
        {
            return it->second;
        }

        myMap[node->val] = new Node(node->val);

        vector<Node*> neighbors;
        for (auto n : node->neighbors)
        {
            neighbors.push_back(dfs(n));
        }

        myMap[node->val]->neighbors = neighbors;

        return myMap[node->val];
    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }

private:
    unordered_map<int, Node*> myMap;
};
