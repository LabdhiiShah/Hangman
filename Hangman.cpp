#include<iostream>
#include<string>
#include<vector>
#include<ctime>
using namespace std;

void guide();
void display_fail_attempt(int fail_attempt);
void display_status(std::vector<char>incorrect_guesses,string answer);
void end_game(string answer,string codeword);

int main(){
    string words[]={"Study","Computer","Chocolate","Forest","Hand","Eyes","God","Easy","Good"};
    srand(time(NULL));
    int word_num = rand()%9;
    string codeword = words[word_num];
    string answer(codeword.length(),'_');
    int fail_attempt=0;
    bool guess=false;
    char letter;
    vector<char>incorrect_guesses;

    while((answer != codeword) && (fail_attempt < 7)){
        system("cls");
        for(int i=0;i<=0;i++){
            guide();
        }
        display_fail_attempt(fail_attempt);
        display_status(incorrect_guesses,answer);

        cout << "\n\nEnter your guess: ";
        cin >> letter;

        guess = false;

    for(int i=0;i<codeword.length();i++){
    if(letter==codeword[i]){
        answer[i]=letter;
        guess = true;
        }
    }
    if(guess){
        cout<<"\nCORRECT!\n";
    }
    else{
        cout<<"\nINCORRECT!\n";
        incorrect_guesses.push_back(letter);
        fail_attempt++;
    }
}
end_game(answer,codeword);
return 0;
}


void guide(){
cout<<"=============== HANGMAN =============== \n";
cout<<"Try to save the man by guessing the correct word\n";
}


void display_fail_attempt(int fail_attempt){
    if(fail_attempt==0){
        cout<<"+----+ \n";
        cout<<" |   | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"====== \n";
    }
    else if(fail_attempt==1){
        cout<<"+----+ \n";
        cout<<" |   | \n";
        cout<<" o   | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"====== \n";
    }
    else if(fail_attempt==2){
        cout<<"+----+ \n";
        cout<<" |   | \n";
        cout<<" o   | \n";
        cout<<" |   | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"====== \n";
    }
    else if(fail_attempt==3){
        cout<<"+----+ \n";
        cout<<" |   | \n";
        cout<<" o   | \n";
        cout<<"/|   | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"====== \n";
    }
    else if(fail_attempt==4){
        cout<<"+----+ \n";
        cout<<" |   | \n";
        cout<<" o   | \n";
        cout<<"/|\\  | \n";
        cout<<"     | \n";
        cout<<"     | \n";
        cout<<"====== \n";
    }
    else if(fail_attempt==5){
        cout<<"+----+ \n";
        cout<<" |   | \n";
        cout<<" o   | \n";
        cout<<"/|\\  | \n";
        cout<<"/    | \n";
        cout<<"     | \n";
        cout<<"====== \n";
    }
    else if(fail_attempt==6){
        cout<<"+----+ \n";
        cout<<" |   | \n";
        cout<<" o   | \n";
        cout<<"/|\\  | \n";
        cout<<"/ \\  | \n";
        cout<<"     | \n";
        cout<<"====== \n";
    }
}

void display_status(vector<char>incorrect_guesses,string answer){

cout<<"Incorrect Guesses: \n";
for(int i=0;i<incorrect_guesses.size();i++){
    cout<<incorrect_guesses[i]<<"   ";
}
cout<<"\nCODEWORD: ";
for(int i=0;i<answer.size();i++){
    cout<<answer[i]<<"  ";
}
}

void end_game(string answer,string codeword){
if(answer==codeword){
    cout<<"Hooray! You saved the person from being hanged \n";
    cout<<"CONGRATULATIONSSS!!!";
}
else{
    cout<<"Oh no! The man is hanged!\n";
    cout<<"The Codeword is: "<<codeword;
}
}
