#include <iostream>
using namespace std;

enum Enchoices {
    paper = 1,
    scissors = 2,
    rock = 3
};

int readposstive(string messege) {
    int num;

    cout << messege << endl;
    cin >> num;

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
    int rounds = readposstive("Rounds:");
    return rounds;
}

int pc() {
    int choice = RandomNumber(0, 3);
    return choice;
}

int logic(Enchoices player, Enchoices pc) {
    if (player == pc) { return 2; }

    if (player == Enchoices::paper && pc == Enchoices::rock) { return 1; }

    if (player == Enchoices::scissors && pc == Enchoices::paper) { return 1; }

    if (player == Enchoices::rock && pc == Enchoices::scissors) { return 1; }

    return 0;


}

Enchoices ReadChoice(int choice) {


    return (Enchoices)choice;

}

int checkWinner(int result) {
    int winner = 0;

    switch (result)
    {
    case 0:
        system("Color 47");
        cout << "========PC win this round GOOD LUCK========\n ";
        winner = 0;
        break;

    case 1:
        cout << "\a";
        system("Color 20");
        cout << "========You Won BUT dont get too excited========\n";
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

void printResult(string player, string PC) {
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

    if (Player_score > PC_score) {
        system("Color 20");
        cout << "Final winner : Player" << endl;
    }
    else {
        system("Color 47");
        cout << "Final winner : PC" << endl;
    }

}

void startgame() {
    int cont = 0;
    int Player_score = 0; int PC_score = 0; int Ties = 0; int rounds = 0; int r;
    do {
        system("cls");
        system("Color 0f");

        Player_score = 0;  PC_score = 0;  Ties = 0;

        int rounds = ReadRounds();
        r = rounds;
        int round = 1;
        while (round <= rounds) {

            cout << "Round [" << round << "] begins\n";
            printElemtns();
            int target = readposstive("Enter a number:  ");
            int PCtarget = pc();
            Enchoices choice = ReadChoice(target);
            Enchoices PCchoice = ReadChoice(PCtarget);

            int result = logic(choice, PCchoice);

            string player = getChoice(target);
            string PC = getChoice(PCtarget);

            printResult(player, PC);

            int Winner = checkWinner(result);

            Scores(Winner, Player_score, PC_score, Ties);

            round++;


        }

        PrintSummery(Player_score, PC_score, Ties, r);


        cout << "Play again??? 0 for no , 1 for yes\n";
        cin >> cont;

    } while (cont == 1);


}

int main()
{
    srand((unsigned)time(NULL));

    startgame();

}
