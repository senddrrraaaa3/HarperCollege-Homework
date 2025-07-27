#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string normalize(const string& word) {
    string cleaned;
    for (char c : word) {
        if (isalnum(c) || c == '-') {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

bool isCommon(const string& word) {
    static unordered_set<string> common = {
        "a", "an", "and", "are", "as", "at", "be", "by", "for", "from",
        "has", "he", "in", "is", "it", "its", "of", "on", "that", "the",
        "to", "was", "were", "will", "with", "they", "you", "your"
    };
    return common.find(word) != common.end();
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("index.txt");

    vector<string> words;
    string line, word;

    while (getline(infile, line)) {
        istringstream iss(line);
        while (iss >> word) {
            words.push_back(normalize(word));
        }
    }

    map<string, vector<int>> invertedIndex;

    for (int i = 0; i < words.size(); ++i) {
        string w = words[i];
        if (!w.empty() && !isCommon(w)) {
            invertedIndex[w].push_back(i);
        }
    }

    outfile << "{\n";
    for (auto it = invertedIndex.begin(); it != invertedIndex.end(); ++it) {
        outfile << "  \"" << it->first << "\": [";
        for (size_t j = 0; j < it->second.size(); ++j) {
            outfile << it->second[j];
            if (j != it->second.size() - 1) outfile << ", ";
        }
        outfile << "]";
        if (next(it) != invertedIndex.end()) outfile << ",";
        outfile << "\n";
    }
    outfile << "}\n";

    infile.close();
    outfile.close();
    return 0;
}
