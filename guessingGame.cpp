#include <iostream>
#include <vector>
using namespace std;

//normal level for number guessing mode
void normalNumberGuessingGame() {
  bool correct = false;
  int guess;
  int num = rand()%10;

  cout << "Guess a number between 1 and 10! ";
  cin >> guess;
  if(guess == num) {
    correct = true;
  }
  
  //checks if correct answer guessed each time input is received
  while(!correct) {
    cout << "The number you have guessed is incorrect. Please enter a different number." << endl;
    cout << endl << "-------------------------------------------------------------" << endl;
    cout << "Guess a number between 1 and 10! ";
    cin >> guess;
    
    if(guess == num) {
    correct = true;
    }
  }
  cout << "Congratulations! You have guessed the correct number. ";
}

//easy level for number guessing mode
void easyNumberGuessingGame() {
  bool correct = false;
  int guess;
  int num = rand()%10;
  vector<int> guesses;

  cout << "Guess a number between 1 and 10! ";
  cin >> guess;
  if(guess == num) {
    correct = true;
  }
  
  //checks if correct answer guessed each time input is received
  while(!correct) {
    guesses.push_back(guess);
    cout << "The number you have guessed is incorrect. Please enter a different number." << endl;
    if(abs(num-guess) < 5) {
      cout << "You are close to the correct number.";
    }
    else {
      cout << "Try again. You are a little far from the number.";
    }
    cout << endl << "-------------------------------------------------------------" << endl;
    cout << "Guess a number between 1 and 10! ";

    string guessesS = "";
    for(int i = 0; i < guesses.size(); i++) {
      guessesS += to_string(guesses[i]) +" ";
    }
    cout << "Numbers guessed so far: " << guessesS << endl;
    cin >> guess;
    if(guess == num) {
      correct = true;
    }
  }
  cout << "Congratulations! You have guessed the correct number. ";
}

//hard level for number guessing mode
void hardNumberGuessingGame() {
  bool correct = false;
  int guess;
  int num = rand()%10;
  int guesses = 1;

  cout << "Guess a number between 1 and 10! " ;
  cin >> guess;
  if(guess == num) {
    correct = true;
  }
  
  //checks if correct answer guessed each time input is received
  while(!correct && guesses < 5) {
    cout << "The number you have guessed is incorrect. Please enter a different number." << endl;
    cout << endl << "-------------------------------------------------------------" << endl;
    cout << "Guess a number between 1 and 10! ";
    guesses++;
    cin >> guess;
    if(guess == num) {
      correct = true;
    }
  }
  cout << "Congratulations! You have guessed the correct number. ";
} 


string wordBank[10] = {"apple", "banana", "corn", "carrot", "ear", "fridge", "grass", "blue", "brown", "lemon"};

//easy level for word guessing mode
void easyWordGuessingGame() {
  int idx = rand()%10;
  string correctWord = wordBank[idx];
  bool correct = false;
  string guess;
  vector<string> guesses;

  string words = "";
  for(int i = 0; i < 10; i++) {
    words += wordBank[i] + ", ";
  }

  cout << "Word bank: " << words << endl;
  cout << "Enter a guess: ";
  cin >> guess;
  guesses.push_back(guess);
  if(guess == correctWord) {
    correct = true;
  }

  //checks if correct answer guessed each time input is received
  while(!correct) {
    cout << "The word you have guessed is incorrect. Please enter a different number." << endl;
    cout << endl << "-------------------------------------------------------------" << endl;
    cout << "Word bank: " << words << endl;

    string guessedWords = "";
    for(int i = 0; i < guesses.size(); i++) {
      guessedWords += guesses[i] + " ";
    }
    cout << "Words guessed so far: " << guessedWords << endl;
    cout << "Enter a guess: ";
    cin >> guess;
    guesses.push_back(guess);
    if(guess == correctWord) {
      correct = true;
    }
  }
  cout << "Congratulations! You have guessed the correct word. ";
}

//normal level for word guessing mode
void normalWordGuessingGame() {
  int idx = rand()%10;
  string correctWord = wordBank[idx];
  bool correct = false;
  string guess;

  string words = "";
  for(int i = 0; i < 10; i++) {
    words += wordBank[i] + ", ";
  }

  cout << "Word bank: " << words << endl;
  cout << "Enter a guess: ";
  cin >> guess;
  if(guess == correctWord) {
    correct = true;
  }

  //checks if correct answer guessed each time input is received
  while(!correct) {
    cout << "The word you have guessed is incorrect. Please enter a different number." << endl;
    cout << endl << "-------------------------------------------------------------" << endl;
    cout << "Word bank: " << words << endl;
    cout << "Enter a guess: ";
    cin >> guess;
    if(guess == correctWord) {
      correct = true;
    }
  }
  cout << "Congratulations! You have guessed the correct word. ";
}

//hard level for word guessing mode
void hardWordGuessingGame() {
  int idx = rand()%10;
  string correctWord = wordBank[idx];
  bool correct = false;
  string guess;

  string words = "";
  for(int i = 0; i < 10; i++) {
    words += wordBank[i] + ", ";
  }

  int count = 5;
  cout << "Word bank: " << words << endl;
  cout << "Enter a guess: ";
  cin >> guess;
  count--;
  if(guess == correctWord) {
    correct = true;
  }

  //checks if correct answer guessed each time input is received
  while(!correct && count > 0) {
    cout << "The word you have guessed is incorrect. Please enter a different number." << endl;
    cout << "You have " << count << " guesses left. " << endl;
    cout << endl << "-------------------------------------------------------------" << endl;
    cout << "Word bank: " << words << endl;
    cout << "Enter a guess: ";
    cin >> guess;
    count--;
    if(guess == correctWord) {
      correct = true;
    }
  }
  if(count < 0) {
    cout << "Congratulations! You have guessed the correct word. ";
  }
  else {
    cout << "You have no more guesses left.";
  }
}



int main() {
  //choosing the mode
  cout << "Choose a game - type 'number' OR 'word': ";
  string game;
  cin >> game;

  //choosing the level
  cout << "Choose a level - type 'easy' OR 'normal' OR 'hard': ";
  string level;
  cin >> level;

  //different difficulties for number guessing game
  if(game == "number") {
    if(level == "easy") {
      easyNumberGuessingGame();
    }
    else if(level == "normal") {
      normalNumberGuessingGame();
    }
    else if(level == "hard") {
      hardNumberGuessingGame();
    }
    else {
      cout << "Error! You have entered an invalid input. Please run again.";
    }
  }
  
  //different difficulties for word guessing game
  if(game == "word") {
    if(level == "easy") {
      easyWordGuessingGame();
    }
    else if(level == "normal") {
      normalWordGuessingGame();
    }
    else if(level == "hard") {
      hardWordGuessingGame();
    }
    else {
      cout << "Error! You have entered an invalid input. Please run again.";
    }
  }
}
