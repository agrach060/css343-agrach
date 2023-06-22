#include <iostream>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

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

int main(){
    string userInput;
    int shuffles;
    cout << "Please input 9 digits to be randomly shuffled: " << endl;
    cin >> userInput;
    cout << "Please enter the number of shuffles: " << endl;
    cin >> shuffles;
    for (int i = 1; i <= shuffles; i++) {
        string shuffleLabel;
        if (i == 1) {
            shuffleLabel = "first";
        } else if (i == 2) {
            shuffleLabel = "second";
        } else if (i == 3) {
            shuffleLabel = "third";
        } else {
            shuffleLabel = to_string(i) + "th";
        }
        cout << "The " << shuffleLabel << " shuffled output is: " << endl;
        shuffleDigits(userInput);
    }
    
    return 0;
}