#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// Function to remove punctuation from a word
string removePunctuation(const string& word) {
    string result;
    for (char c : word) {
        if (isalpha(c) || isdigit(c) || c == '\'') {
            result += c;
        }
    }
    return result;
}

int main() {
    ifstream file;
    file.open("Hi my name is Jesse.txt");

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    int wordCount = 0;
    int sentenceCount = 0;
    vector<string> words;
    map<string, int> wordFrequency;  // Map to store word frequencies

    while (getline(file, line)) {
        cout << line << endl;

        stringstream ss(line);
        string word;

        while (ss >> word) {
            wordCount++;
            words.push_back(word);

            // Remove punctuation and convert to lowercase for consistency
            string cleanedWord = removePunctuation(word);
            (cleanedWord.begin(), cleanedWord.end(), cleanedWord.begin(), ::tolower);

            // Update word frequency map
            wordFrequency[cleanedWord]++;
        }

        for (char c : line) {
            if (c == '.' || c == '!' || c == '?') {
                sentenceCount++;
            }
        }
    }

    file.close();

    cout << "Total Words: " << wordCount << endl;
    cout << "Total Sentences: " << sentenceCount << endl;

    // Output each word from the vector after removing punctuation
    cout << "Words in the file:" << endl;
    for (const string& word : words) {
        string wordWithoutPunctuation = removePunctuation(word);
        cout << wordWithoutPunctuation << endl;
    }

    // Output word frequencies
    cout << "Word Frequencies:" << endl;
    for (const auto& pair : wordFrequency) {
        cout << pair.first << ": " << pair.second  << endl;
    }

    return 0;
}
