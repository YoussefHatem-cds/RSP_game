#include <iostream>


enum Enchoices {
    paper = 1,
    scissors = 2,
    rock = 3
};

struct stScore
{

    //int Player_score = 0; int PC_score = 0; int Ties = 0; int rounds = 0; int r;

    int Player_score=0;
    int PC_score=0;
    int ties=0;
    

};
using namespace std;

int readposstive(string messege,int start,int limit) {
    int num; 
    cout << messege << endl;
    cin >> num;

    while (cin.fail() || (num<start||num>limit)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Invalid input please try again\n\n";
        cout << messege;
        cin >> num;
    }

    return num;
}

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int ReadRounds() {
    cout << "How many rounds do u want to play [1-10]\n";
    int rounds = readposstive("Rounds:",1,10);
    return rounds;
}

int pc() {return  RandomNumber(0, 3);}

int logic(Enchoices player, Enchoices pc) {
    if (player == pc) { return 2; }

    if (player == Enchoices::paper && pc == Enchoices::rock) { return 1; }

    if (player == Enchoices::scissors && pc == Enchoices::paper) { return 1; }

    if (player == Enchoices::rock && pc == Enchoices::scissors) { return 1; }

    return 0;


}

int checkWinner(int result) {
    int winner = 0;

    switch (result)
    {
    case 0:
        system("Color 47");
        cout << "========PC Won this round GOOD LUCK========\n ";
        winner = 0;
        break;

    case 1:
        cout << "\a";
        system("Color 20");
        cout << "========player Won this round good job========\n";
        winner = 1;
        break;

    case 2:
        system("Color 80");
        cout << "========Its a Tie!========\n";
        winner = 2;
        break;

    default:
        winner = 0;
    }
    cout << "\n";
    return winner;
}

void printElemtns() {

    cout << "Pick number [1,2,3] to select your choice.\n\n";
    cout << "Paper   : 1\n";
    cout << "Scissors: 2\n";
    cout << "Rock    : 3\n\n";


}

string getChoice(int choice) {
    switch (choice)
    {
    case 1:
        return "paper";
        break;

    case 2:
        return "scissors";
        break;

    case 3:
        return "rock";
        break;

    default:
        return "paper";
        break;

    }



}

void printChoice(string player, string PC) {
    cout << "Your choice :" << player << endl;
    cout << "PC choice   :" << PC << endl;

}

void Scores(int Winner, int& Player_score, int& PC_score, int& Ties) {
    switch (Winner)
    {
    case 0:  ++PC_score; break;
    case 1:  ++Player_score; break;
    case 2:  ++Ties; break;
    }

}

void PrintSummery(int& Player_score, int& PC_score, int& Ties, int rounds) {
    cout << "-------------------------------------------\n";
    cout << "---------------summery---------------------\n";
    cout << "---------------       ---------------------\n";
    cout << "----------Game rounds    : " << rounds << "---------------" << endl;
    cout << "----------Player Won time: " << Player_score << "---------------" << endl;
    cout << "----------PC Won time    : " << PC_score << "---------------" << endl;
    cout << "----------Draw Won time  : " << Ties << "---------------" << endl;
    cout << "-------------------------------------------\n";
    cout << "-------------------------------------------\n";
    cout << "-------------------------------------------\n";
    cout << "\t";
    if (Player_score > PC_score) 
    {system("Color 20"); cout << "FINAL WINNER: Player" << endl;}
    else if(PC_score>Player_score)
    {system("Color 47"); cout << "FINAL WINNER : PC" << endl;}
    else{ system("Color 0f"); cout << "its a tie there is no winner" << endl; }
    cout << endl;
}

void startgame() {
    int cont = 0; int rounds = 0;
    do {
        //clear all text in pervoius round and rest color to black
        system("cls");
        system("Color 0f");

        //reset scores to zero
        stScore scores;
        
        //read rounds from user
        int rounds = ReadRounds();
        int round = 1;  //counter

        while (round <= rounds) {

            cout << "Round [" << round << "] begins\n";
            printElemtns();                         //print the choices to user
            int target = readposstive("Enter a number: ",1,3);
            int PCtarget = pc();                    //generate random choice to pc
            Enchoices choice = (Enchoices)(target);
            Enchoices PCchoice = (Enchoices)(PCtarget);

            int result = logic(choice, PCchoice);   //check the winner 0:pc,1:player,2:tie

            string player = getChoice(target);      //get player,pc choice to string
            string PC = getChoice(PCtarget);

            printChoice(player, PC);                //print both player and pc choice 

            int Winner = checkWinner(result);       //check the winner and print 
            Scores(Winner, scores.Player_score, scores.PC_score, scores.ties);                                                //increase the winner score
            round++;                                //increment to next round

        }

        //print the rounds summery after all rounds finished 
        PrintSummery(scores.Player_score, scores.PC_score, scores.ties, rounds);
        cont=readposstive("Play again ? ? ? 0 for no, 1 for yes\n",0,1);

    } while (cont == 1);

}

int main()
{
    srand((unsigned)time(NULL));

    startgame();

}
