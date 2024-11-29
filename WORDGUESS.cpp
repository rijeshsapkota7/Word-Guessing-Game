#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// function prototypes
string ChooseRandomWord();
string HideAlphabets(string word);
bool checkChar(string real, string hidden, string word);
bool AllSolved(string OrignalW, string guessWord);

int main()
{
    srand(time(0));
    string Word = ChooseRandomWord();
    string guessWord = HideAlphabets(Word);
    bool solve = false;
    int i = 20;
    system("cls");
    cout << "Welcome To Word Guessing Game" << endl
         << endl;
    while (solve != true)
    {
        for (i = 20; i > 0; i--)
        {
            cout << endl;
            for (char ch : guessWord)
            {
                cout << "| " << ch << " ";
            }
            cout << endl
                 << endl;
            string Try;
            cout << "Lives: " << i;
            cout << endl;
            cout << "Guess the whole word or character: ";
            cin >> Try;
            if (checkChar(Word, guessWord, Try))
            {
                for (int j = 0; j < Word.length(); j++)
                {
                    if(Try == Word){
                        guessWord = Try;
                        break;
                    }
                    else{
                        if (Word[j] == Try[0])
                    {
                        guessWord[j] = Try[0];
                        break;
                    }
                    }
                }
            }
            if (AllSolved(Word, guessWord))
            {
                solve = true;
                break;
            }
        }
        break;
    }
    if (solve == true)
    {
        cout << endl
             << "Congratulations You won the game!!!";
    }
    else
    {
        cout << endl
             << "Better Luck Next time You Loose The game!!";
        cout << endl
             << "The Hidden Word Was " << Word;
    }
}

string ChooseRandomWord()
{
    string Randomword, word;
    int randomWordPosition = rand() % 67;
    ifstream file("words.txt");
    int currentPosition = 0;
    while (file >> word)
    {
        currentPosition++;
        if (currentPosition == randomWordPosition)
        {
            Randomword = word;
            file.close();
            break;
        }
    }
    transform(Randomword.begin(), Randomword.end(), Randomword.begin(), ::tolower);
    return Randomword;
}

string HideAlphabets(string word)
{
    int WordLen = word.length();
    int hiddenChar = WordLen / 2;
    string BackupWord = word;
    bool replaced = false;

    int randomIndex;
    do
    {
        randomIndex = rand() % WordLen;
        if (word[randomIndex] != '?')
        {
            word[randomIndex] = '?';
            hiddenChar--;
        }
    } while (hiddenChar != 0);
    return word;
}

bool checkChar(string real, string hidden, string word)
{
    int i;
    for (i = 0; i < real.length(); i++)
    {
        if (real[i] == word[0])
        {
            return true;
        }
    }
    return false;
}

bool AllSolved(string OrignalW, string guessWord)
{
    int result = OrignalW.compare(guessWord);
    if(result ==0){
        return true;
    }
    return false;
}