#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to encode a message using a substitution cipher
string encodeMessage(const string& message, const unordered_map<char, char>& key) {
    string encodedMessage;
    for (char c : message) {
        if (key.find(c) != key.end()) {
            encodedMessage += key.at(c);
        } else {
            encodedMessage += c; // Keep non-alphabetic characters unchanged
        }
    }
    return encodedMessage;
}

// Function to decode a message using a substitution cipher
string decodeMessage(const string& encodedMessage, const unordered_map<char, char>& key) {
    unordered_map<char, char> reverseKey;
    for (const auto& entry : key) {
        reverseKey[entry.second] = entry.first; // Reverse the key for decoding
    }
    string decodedMessage = encodeMessage(encodedMessage, reverseKey);
    return decodedMessage;
}

int main() {
    // Define substitution keys
    unordered_map<char, char> key1 = {
        {'a', 'x'}, {'b', 'y'}, {'c', 'z'}, {'d', 'a'}, {'e', 'b'},
        {'f', 'c'}, {'g', 'd'}, {'h', 'e'}, {'i', 'f'}, {'j', 'g'},
        {'k', 'h'}, {'l', 'i'}, {'m', 'j'}, {'n', 'k'}, {'o', 'l'},
        {'p', 'm'}, {'q', 'n'}, {'r', 'o'}, {'s', 'p'}, {'t', 'q'},
        {'u', 'r'}, {'v', 's'}, {'w', 't'}, {'x', 'u'}, {'y', 'v'},
        {'z', 'w'}
    };

    unordered_map<char, char> key2 = {
        {'a', 'z'}, {'b', 'y'}, {'c', 'x'}, {'d', 'w'}, {'e', 'v'},
        {'f', 'u'}, {'g', 't'}, {'h', 's'}, {'i', 'r'}, {'j', 'q'},
        {'k', 'p'}, {'l', 'o'}, {'m', 'n'}, {'n', 'm'}, {'o', 'l'},
        {'p', 'k'}, {'q', 'j'}, {'r', 'i'}, {'s', 'h'}, {'t', 'g'},
        {'u', 'f'}, {'v', 'e'}, {'w', 'd'}, {'x', 'c'}, {'y', 'b'},
        {'z', 'a'}
    };

    unordered_map<char, char> key3 = {
        {'a', 'm'}, {'b', 'n'}, {'c', 'o'}, {'d', 'p'}, {'e', 'q'},
        {'f', 'r'}, {'g', 's'}, {'h', 't'}, {'i', 'u'}, {'j', 'v'},
        {'k', 'w'}, {'l', 'x'}, {'m', 'y'}, {'n', 'z'}, {'o', 'a'},
        {'p', 'b'}, {'q', 'c'}, {'r', 'd'}, {'s', 'e'}, {'t', 'f'},
        {'u', 'g'}, {'v', 'h'}, {'w', 'i'}, {'x', 'j'}, {'y', 'k'},
        {'z', 'l'}
    };

    unordered_map<char, char> key4 = {
        {'a', 'f'}, {'b', 'g'}, {'c', 'h'}, {'d', 'i'}, {'e', 'j'},
        {'f', 'k'}, {'g', 'l'}, {'h', 'm'}, {'i', 'n'}, {'j', 'o'},
        {'k', 'p'}, {'l', 'q'}, {'m', 'r'}, {'n', 's'}, {'o', 't'},
        {'p', 'u'}, {'q', 'v'}, {'r', 'w'}, {'s', 'x'}, {'t', 'y'},
        {'u', 'z'}, {'v', 'a'}, {'w', 'b'}, {'x', 'c'}, {'y', 'd'},
        {'z', 'e'}
    };
    unordered_map<char, char> key5 = {
    {'a', 'x'}, {'b', '1'}, {'c', '#'}, {'d', 'z'}, {'e', '9'},
    {'f', '!'}, {'g', '8'}, {'h', '@'}, {'i', '7'}, {'j', '^'},
    {'k', '6'}, {'l', '*'}, {'m', '5'}, {'n', '%'}, {'o', '4'},
    {'p', '$'}, {'q', '3'}, {'r', '&'}, {'s', '2'}, {'t', '{'},
    {'u', '0'}, {'v', ')'}, {'w', '('}, {'x', 'k'}, {'y', 'l'},
    {'z', 'm'}, {'1', 'n'}, {'2', 'o'}, {'3', 'p'}, {'4', 'q'},
    {'5', 'r'}, {'6', 's'}, {'7', 't'}, {'8', 'u'}, {'9', 'v'},
    {'0', 'w'}, {' ', '}'}, {'.', 'a'}, {'!', 'b'}, {'?', 'c'},
    {'@', 'd'}, {'$', 'e'}, {'%', 'f'}, {'^', 'g'}, {'&', 'h'},
    {'*', 'i'}, {'(', 'j'}
};

unordered_map<char, char> key6 = {
    {'a', '#'}, {'b', '$'}, {'c', '%'}, {'d', '&'}, {'e', '*'},
    {'f', '!'}, {'g', '?'}, {'h', '@'}, {'i', '^'}, {'j', '('},
    {'k', ')'}, {'l', '-'}, {'m', '_'}, {'n', '='}, {'o', '+'},
    {'p', '['}, {'q', ']'}, {'r', '{'}, {'s', '}'}, {'t', '/'},
    {'u', '\\'}, {'v', '|'}, {'w', '.'}, {'x', ','}, {'y', ';'},
    {'z', ':'}
};

unordered_map<char, char> key7 = {
    {'a', 'x'}, {'b', '1'}, {'c', '#'}, {'d', 'x'}, {'e', 'y'},
    {'f', '2'}, {'g', 'z'}, {'h', '3'}, {'i', '!'}, {'j', '4'},
    {'k', 'w'}, {'l', '@'}, {'m', '5'}, {'n', 'v'}, {'o', '6'},
    {'p', '$'}, {'q', 'u'}, {'r', '7'}, {'s', '%'}, {'t', 't'},
    {'u', '8'}, {'v', '^'}, {'w', 's'}, {'x', '9'}, {'y', '&'},
    {'z', 'r'}, {'1', '0'}, {'2', 'p'}, {'3', '*'}, {'4', 'q'},
    {'5', '('}, {'6', 'o'}, {'7', ')'}, {'8', 'i'}, {'9', 'n'},
    {'0', '_'}, {' ', '+'}, {'.', '{'}, {'!', '}'}, {'?', '|'},
    {'@', ';'}, {'$', ':'}, {'%', ','}, {'^', '.'}, {'&', '<'},
    {'*', '>'}
};
    char repeatChoice;
    do {
    // Prompt user to enter a message
    string message;
    cout << "Enter a message: ";
    getline(cin, message);

    // Prompt user to choose encode or decode
    char choice;
    cout << "Do you want to encode or decode the message? (e/d): ";
    cin >> choice;

    if (choice == 'e') {
        // Prompt user to choose a key for encoding
        int keyChoice;
        cout << "Choose a key for encoding (1/2/3/4/5/6/7): ";
        cin >> keyChoice;

        // Encode the message using the chosen key
        string encodedMessage;
        switch (keyChoice) {
            case 1:
                encodedMessage = encodeMessage(message, key1);
                break;
            case 2:
                encodedMessage = encodeMessage(message, key2);
                break;
            case 3:
                encodedMessage = encodeMessage(message, key3);
                break;
            case 4:
                encodedMessage = encodeMessage(message, key4);
                break;
            case 5:
                encodedMessage = encodeMessage(message, key5);
                break;
            case 6:
                encodedMessage = encodeMessage(message, key6);
                break;
            case 7:
                encodedMessage = encodeMessage(message, key7);
                break;            
            default:
                cout << "Invalid key choice!" << endl;
                return 1;
        }
        cout << "Encoded Message: " << encodedMessage << endl;
    } else if (choice == 'd') {
        // Prompt user to choose a key for decoding
        int keyChoice;
        cout << "Choose a key for decoding (1/2/3/4/5/6/7): ";
        cin >> keyChoice;

        // Decode the message using the chosen key
        string decodedMessage;
        switch (keyChoice) {
            case 1:
                decodedMessage = decodeMessage(message, key1);
                break;
            case 2:
                decodedMessage = decodeMessage(message, key2);
                break;
            case 3:
                decodedMessage = decodeMessage(message, key3);
                break;
            case 4:
                decodedMessage = decodeMessage(message, key4);
                break;
            case 5:
                decodedMessage = decodeMessage(message, key5);
                break;
            case 6:
                decodedMessage = decodeMessage(message, key6);
                break;
            case 7:
                decodedMessage = decodeMessage(message, key7);
                break;     
            default:
                cout << "Invalid key choice!" << endl;
                return 1;
        }
        cout << "Decoded Message: " << decodedMessage << endl;
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    cout << "Do you want to repeat the process? (y/n): ";
        cin >> repeatChoice;
        cin.ignore(); // Clear the input buffer

    } while (repeatChoice == 'y' || repeatChoice == 'Y');

    return 0;
}
