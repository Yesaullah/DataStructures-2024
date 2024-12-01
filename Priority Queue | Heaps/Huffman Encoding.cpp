#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

// Node structure for the Huffman tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to generate Huffman codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // Leaf node
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to build Huffman tree and generate codes
unordered_map<char, string> buildHuffmanTree(const string& text) {
    unordered_map<char, int> freqMap;
    for (char ch : text) freqMap[ch]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    unordered_map<char, string> huffmanCodes;
    generateCodes(pq.top(), "", huffmanCodes);

    return huffmanCodes;
}

// Function to encode the string
string encode(const string& text, const unordered_map<char, string>& huffmanCodes) {
    string encodedStr;
    for (char ch : text) {
        encodedStr += huffmanCodes.at(ch);
    }
    return encodedStr;
}

// Main function
int main() {
    string text;
    cout << "Enter a string to encode: ";
    cin >> text;

    // Build Huffman tree and get codes
    unordered_map<char, string> huffmanCodes = buildHuffmanTree(text);

    // Display Huffman codes
    cout << "\nHuffman Codes:\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Encode the input text
    string encodedStr = encode(text, huffmanCodes);
    cout << "\nEncoded String: " << encodedStr << endl;

    return 0;
}
