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

    string questions[size], answers[size], quest, ans;
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

    // Actual Code

    int opt = 10;

    while (opt <1 || opt >3){
        system("clear");
        cout << "Welcome to Simple Flashcard!" << endl;
        cout << "[1] Question me" << endl;
        cout << "[2] Edit flashcards" << endl;
        cout << "[3] Exit" << endl;
        cin >> opt;
    }

    switch(opt){

        case 1:
            cout << "1";
            break;
        case 2:
            edit:
            system("clear");
            for(int i=0; i<size; i++){
                printf("[%d]\n", i+1);
                cout << "Q: " << questions[i] << endl;
                cout << "A: " << answers[i] << endl << endl;
            }
        
            opt = 10;

            while (opt <1 || opt >3){
                cout << "[1] Add flashcard" << endl;
                cout << "[2] Delete flashcard" << endl;
                cout << "[3] Back" << endl;
                cin >> opt;
            }

            switch(opt){
                
                case 1:
                    cout << "Enter the question:" << endl;
                    cin >> quest;
                    cout << "Enter the answer:" << endl;
                    cin >> ans;
                    // make here so that "quest" and "ans" will be entered into "cards.txt"
                    cout << "Flashcard added!" << endl;
                    // make here so that the user need to press enter to procced 
                    goto edit;
                case 2:
                    cout << "Enter the index of the flashcard you want to delete:" << endl;
                    cin >> index;
                    printf("Are you sure? Flashcard with the index %d will be deleted (Y/N)\n", index+1);
            }

        case 3:
            cout << "3";
            break;

    }

    return 0;
}
