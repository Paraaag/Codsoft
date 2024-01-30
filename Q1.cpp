#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    srand(time(0));
    
    
    int secretNumber = rand() % 300 + 1;
    int guess;
    int cnt = 0;
    
    cout << "Welcome to the Guess the Number game!\n";
    cout << "I have selected a number between 1 and 300. Can you guess it?\n";
    
    
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        cnt++;
        
        
        if (guess > secretNumber) {
            cout << "Too high! Try again.\n";
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You've guessed the number " << secretNumber << " correctly!\n";
            cout << "Number of attempts: " << cnt << endl;
        }
    } while (guess != secretNumber);
    
    return 0;
}
