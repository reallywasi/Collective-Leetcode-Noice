/*
Question:
Given a sentence string and a searchWord string, determine if the searchWord is a prefix of any word in the sentence. 
Return the 1-based index of the first such word. If no such word exists, return -1.

Definitions:
- A word is defined as a substring of the sentence separated by spaces.
- A prefix means the searchWord must match the beginning of the word.

Approach:
1. Parse the sentence word by word, keeping track of the word index.
2. Check if the searchWord matches the beginning (prefix) of each word.
3. Use the `substr` function to extract the substring starting at the beginning of each word.
4. Return the 1-based word index if a match is found; otherwise, return -1.

Steps:
1. Handle the first word separately since it does not have a leading space.
2. Traverse the sentence and identify the start of each word by checking for spaces.
3. Increment the word index whenever a new word starts.
4. Compare the substring starting at the new word's index with the searchWord.
5. If a match is found, return the current word index.
6. If the traversal completes without finding a match, return -1.
*/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ns = sentence.size(); // Length of the sentence
        int ws = searchWord.size(); // Length of the searchWord
        int wordindex = 1; // 1-based index of the current word

        // Check if the first word starts with searchWord
        if (sentence.substr(0, ws) == searchWord) return wordindex;

        // Iterate through the rest of the sentence
        for (int i = ws; i < ns; i++) {
            // Check if a new word starts (indicated by a space before it)
            if (sentence[i - 1] == ' ') {
                wordindex++; // Increment the word index

                // Check if the new word starts with searchWord
                if (sentence.substr(i, ws) == searchWord) return wordindex;
            }
        }

        return -1; // Return -1 if no prefix match is found
    }
};
