#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

// takes a string of digits and shuffles them randomly 
void shuffleDigits(string digits){
    random_device rd;
    mt19937 rng(rd());
    shuffle(digits.begin(), digits.end(), rng);
    cout << "+-------+" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << digits[i * 3 + j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "+-------+" << endl;
}

// checks if a given string contains any non-digit characters
bool containsNonDigits(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return true;
        }
    }
    return false;
}

// handles the user input and shuffling process
int main(int argc, char* argv[]){
    // prompt the user to input 9 digits
    string userInput;
    cout << "Please input 9 digits to be randomly shuffled: " << endl;
    cin >> userInput;
    // check if the input is valid
    if (userInput.length() != 9 || containsNonDigits(userInput)) {
        cout << "Invalid input. Please enter a string of 9 digits only." << endl;
        return 1;
    }
    // retrieve the number of shuffles (assuming it's <= 10) from the command line argument 
    int shuffles = atoi(argv[1]);
    // iterate through the shuffles and print out the grid
    for (int i = 1; i <= shuffles; i++) {
        string shuffleLabel;
        if (i == 1) {
            shuffleLabel = "first";
        } else if (i == 2) {
            shuffleLabel = "second";
        } else if (i == 3) {
            shuffleLabel = "third";
        } else if (i == 4) {
            shuffleLabel = "fourth";
        } else if (i == 5) {
            shuffleLabel = "fifth";
        } else if (i == 6) {
            shuffleLabel = "sixth";
        } else if (i == 7) {
            shuffleLabel = "seventh";
        } else if (i == 8) {
            shuffleLabel = "eighth";
        } else if (i == 9) {
            shuffleLabel = "ninth";
        } else if (i == 10) {
            shuffleLabel = "tenth";
        }
        cout << "The " << shuffleLabel << " shuffled output is: " << endl;
        shuffleDigits(userInput);
    }
    
    return 0;
}