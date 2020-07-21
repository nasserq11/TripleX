#include <iostream>
#include <ctime>

void PrintIntro(int Difficulty)
{
    //Print welcome messages to the terminal
    std::cout << "\nYou'r a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room \nEnter the correct code to continue..\n\n";
}

bool PlayGame(int Difficulty)
{  
    PrintIntro(Difficulty);
    //Declaring our varuble, 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA+CodeB+CodeC;
    const int CodeProduct = CodeA*CodeB*CodeC;

    //print sum and product to the terminal
    std::cout << "+ There are 3 number in the code" << std::endl;
    std::cout << "+ The codes add up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiple to: " << CodeProduct << std::endl;

    //store players guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check if player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou have won this level Congratlations";
        return true;
    }
    else
    {
        std::cout << "\nYou entered the wrong code please try again";
        return false;
    }

}

int main()
{
    srand(time(NULL));//creat a new random sequence based on time of day
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty)// will loop the game while all levels are complated
    {
        bool bLevelComplete = PlayGame(LevelDifficulty); //store if succfully completed the level or not
        std::cin.clear();//Clear any errors
        std::cin.ignore();//Discards the buffer

        if (bLevelComplete)// if player completed the level, increase the level diffuclty before code loops again
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\nCongrlations you have succfully unlocked the vault now run away";
    return 0;
}