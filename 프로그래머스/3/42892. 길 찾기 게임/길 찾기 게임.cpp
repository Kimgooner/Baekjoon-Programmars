#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int id;
    int depth;
    int data; // x값
    Node* left = nullptr;
    Node* right = nullptr;
    
    Node(int id, int y, int x) : id(id), depth(y), data(x) {}
};

Node* insertNode(Node* root, int id, int y, int x){
    if(root == nullptr) return new Node(id, y, x);
    if(x < root->data){
        root->left = insertNode(root->left, id, y, x);
    }
    else{
        root->right = insertNode(root->right, id, y, x);
    }
    return root;
}

void preOrder(Node* root, vector<int>& res){
    if(root == nullptr) return;
    res.push_back(root->id);
    preOrder(root->left, res);
    preOrder(root->right, res);
}

void postOrder(Node* root, vector<int>& res){
    if(root == nullptr) return;
    postOrder(root->left, res);
    postOrder(root->right, res);
    res.push_back(root->id);
}

bool cmp(Node* n1, Node* n2){
    if(n1->depth == n2->depth) return n1->data < n2->data;
    return n1->depth > n2->depth;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node*> nodes;
    for(int i = 0; i < nodeinfo.size(); i++){
        nodes.push_back(new Node(i+1, nodeinfo[i][1], nodeinfo[i][0]));
    }
    sort(nodes.begin(), nodes.end(), cmp);
    
    Node* root = nodes[0];
    for(int i = 1; i < nodes.size(); i++){
        insertNode(root, nodes[i]->id, nodes[i]->depth, nodes[i]->data);
    }
    
    vector<int> pre, post;
    preOrder(root, pre);
    postOrder(root, post);
    
    vector<vector<int>> answer;
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}