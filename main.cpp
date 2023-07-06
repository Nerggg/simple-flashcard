#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream cards("cards.txt");
    if (!cards) {
        ofstream createFile("cards.txt", ios::app);
        createFile << "QUESTIONS\n";
        createFile << "ANSWERS\n";
        createFile.close();
        cards.open("cards.txt");
    }
    
    int size=0;
    
    string line;
    
    if (getline(cards,line) && line == "QUESTIONS"){
        while (getline(cards, line)) {
            if (line == "ANSWERS"){
                break;
            }
            size++;
        }
    }

    string questions[size], answers[size];
    int index = 0;

    cards.clear(); 
    cards.seekg(0, ios::beg);

    if (getline(cards,line) && line == "QUESTIONS"){
        while (getline(cards, line)) {
            if (line == "ANSWERS"){
                break;
            }
            questions[index] = line;
            index++;
        }
    }

    index = 0;

    while (getline(cards, line)) {
            answers[index] = line;
            index++;
        }

    int opt = 10;

    while (opt <1 || opt >3){
        system("cls");
        cout << "Welcome to Simple Flashcard!" << endl;
        cout << "[1] Question me" << endl;
        cout << "[2] Edit flashcards" << endl;
        cout << "[3] Exit" << endl;
        cin >> opt;
    }

    return 0;
}
