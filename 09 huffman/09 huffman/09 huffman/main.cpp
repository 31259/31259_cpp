#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Step 1: Build frequency map
unordered_map<char, int> buildFrequencyMap(const string& text) {
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;
    return freq;
}

// Step 2a: Create priority queue from frequency map
priority_queue<Node*, vector<Node*>, Compare> buildPriorityQueue(const unordered_map<char, int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (const auto& pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }
    return pq;
}

// Step 2b: Build tree from priority queue
Node* buildTreeFromQueue(priority_queue<Node*, vector<Node*>, Compare>& pq) {
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }
    return pq.top();
}

// Step 3: Build Huffman Tree using modular functions
Node* buildHuffmanTree(const unordered_map<char, int>& freq) {
    auto pq = buildPriorityQueue(freq);
    return buildTreeFromQueue(pq);
}

// Step 4-5-6: Generate Huffman Codes
void generateCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Step 5b: Count total bits
int calculateEncodedSize(const string& text, const unordered_map<char, string>& huffmanCode) {
    int total = 0;
    for (char ch : text) {
        total += static_cast<int>(huffmanCode.at(ch).size());
    }
    return total;
}

// Step 6-7: Display codes sorted by frequency
void displayHuffmanCodes(const unordered_map<char, string>& huffmanCode,
    const unordered_map<char, int>& freq) {
    vector<pair<char, int>> sorted;
    for (auto& p : freq) sorted.push_back(p);
    sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    cout << left << setw(10) << "Char" << setw(10) << "Freq" << "Code" << endl;
    for (auto& p : sorted) {
        cout << left << setw(10) << p.first << setw(10) << p.second << huffmanCode.at(p.first) << endl;
    }
}


int main() {
    // Step 1: Read input text from .txt
    ifstream file("input.txt");
    if (!file) {
        cerr << "Error: input.txt not found!" << endl;
        return 1;
    }

    string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // Step 2: Frequency map
    unordered_map<char, int> freqMap = buildFrequencyMap(text);

    // Step 3: Build Huffman Tree
    Node* root = buildHuffmanTree(freqMap);

    // Step 4-6: Generate Codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // Step 5a: Original ASCII size
    int originalBits = static_cast<int>(text.size()) * 8;
    // Step 5b: Huffman size
    int huffmanBits = calculateEncodedSize(text, huffmanCode);

    // Step 5c: Compression ratio
    double compression = (double)huffmanBits / originalBits;

    // Step 6-7: Show Huffman codes with frequencies sorted
    cout << "\nHuffman Codes:\n";
    displayHuffmanCodes(huffmanCode, freqMap);

    // Step 5: Summary
    cout << "\nOriginal size (ASCII): " << originalBits << " bits" << endl;
    cout << "Compressed size (Huffman): " << huffmanBits << " bits" << endl;
    cout << "Compression ratio: " << fixed << setprecision(2) << compression << endl;

    return 0;
}
