#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> DividSentences(const string& paragraph) {
    vector<string> sentences;
    stringstream ss(paragraph);
    string sentence;  

    while (getline(ss, sentence, '.')) {
        if (!sentence.empty()) { 
            sentences.push_back(sentence);
        }
    }

    return sentences;
}

void checkPlagiarismmINCode(const string& paragraph1, const string& paragraph2) {
    vector<string> sentences1 = DividSentences(paragraph1);
    vector<string> sentences2 = DividSentences(paragraph2);

    bool matchFound = false;

    for (const string& sentence1 : sentences1) {
        for (const string& sentence2 : sentences2) {
            if (sentence1 == sentence2) {
                cout << "Matching sentence found: " << sentence1 << endl;
                matchFound = true;
            }
        }
    }

    if (!matchFound) {
        cout << "No matching sentences found." << endl;
    }
}

int main() {
    string paragraph1 = "DAA is very interesting subject. It is used in many real life applications.";
    string paragraph2 = "DAA is very interesting subject. They are used in various applications.";

    checkPlagiarismmINCode(paragraph1, paragraph2);

    return 0;
}

