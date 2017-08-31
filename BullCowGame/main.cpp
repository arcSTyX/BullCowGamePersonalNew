//This is the console executable that uses the BUllCow Class. 
//It acts as the vie for the MVC patter and is responsible for all user interaction.
// For game logic see the FBullCow class

#include <iostream>
#include <string>
#include "FBullCowGame.h"

//To make the code unreal friendly
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;
//Instantiate a new Game!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



// the entry point for our application
int main()
{
	bool bPlayAgain = false;
	do {
		BCGame.Reset();
		PrintIntro();
		PlayGame();
		//TODO add a game summary after completion. Can come after Play Game function no problem.=
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0; // exit the application
}


// introduce the game
void PrintIntro()
{
	int32  WORD_LENGTH = BCGame.GetHiddenWordLength();

std::cout<< 
			" _______________________ _______ _          _______         _______ _______  _______ _       _______         \n"
			"(  ____ \__   __/  ___  )  ____ \ \    /\  (  ___  )\     /|  ____ \  ____ )(  ____ \ \     (  ___  )\     /|\n"
			"| (    \/  ) (  | (   ) | (    \/  \  / /  | (   ) | )   ( | (    \/ (    )|| (    \/ (     | (   ) | )   ( |\n"
			"| (_____   | |  | (___) | |     |  (_/ /   | |   | | |   | | (__   | (____)|| (__   | |     | |   | | | _ | |\n"
			"(_____  )  | |  |  ___  | |     |   _ (    | |   | | (   ) )  __)  |     __)|  __)  | |     | |   | | |( )| |\n"
			"      ) |  | |  | (   ) | |     |  ( \ \   | |   | |\ \_/ /| (     | (\ (   | (     | |     | |   | | || || |\n"
			"/\____) |  | |  | )   ( | (____/\  /  \ \  | (___) | \   / | (____/\ ) \ \__| )     | (____/\ (___) | () () |\n"
			"\_______)  )_(  |/     \|_______/_/    \/  (_______)  \_/  (_______//   \__/|/      (_______/_______)_______)\n";

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	int32  MaxTries = BCGame.GetMaxTries();
	std::cout << "Total Number of tries allowed is " << MaxTries << std::endl;
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
	}
	BCGame.PrintGameSummary();
}

//Loop continously until user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do	{
		int32  WORD_LENGTH = BCGame.GetHiddenWordLength();
		int32  CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try number " << CurrentTry << " of " << BCGame.GetMaxTries () << std::endl;
		std::cout << "Enter your guess: ";
		getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::OK:
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Your Guess was not an isogram.";
			break;
		case EGuessStatus::Nothing_entered:
			std::cout << "You did not enter anything, Please enter a " << WORD_LENGTH << "letter word." << std::endl;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << WORD_LENGTH << " letter word." << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all letters in lower Case";
			break;
		default:
			break;

		} 
	} while (Status != EGuessStatus::OK);//keep looping until we get no errors
	return Guess;
}



bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}