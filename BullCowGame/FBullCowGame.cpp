#include "FBullCowGame.h"
#include <iostream>
#include <string>

//To make the code unreal friendly
using FString = std::string;
using int32 = int;



void FBullCowGame::Reset() // This is the Reset Code. I moved the Reset function to the constructor :-)
{
	MyCurrentTry = 1;
	bFinalStatus = false;
	const FString HIDDEN_WORD = MyHiddenWord;
	MyHiddenWord = GetHiddenWord();
	const int32  MAX_TRIES = GetHiddenWordLength();
	MyMaxTries = 5;
}

FString FBullCowGame::PrintGameSummary()
{
	if (IsGameWon() == true)
	{
		std::cout << "Well done bitch!!!! Type y if you would like to play again" << std::endl;
	}
	else
	{
		std::cout << "Shame man, you lost!!!! Type y if you would like to play again. But just type n to quit now" << std::endl;;
	}
	return FString();
}

FBullCowGame::FBullCowGame() 
{
	Reset();
}

int32  FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32  FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return bFinalStatus;
}

int32  FBullCowGame::GetHiddenWordLength() const
{

	return MyHiddenWord.length();

}

FString FBullCowGame::GetHiddenWord()
{
	{

		FString SECRET_WORD;
		std::cout << "Enter your Secret word: ";
		getline(std::cin, SECRET_WORD);
		return SECRET_WORD;

	}
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();//this will always only submit a valid guess anyways as CheckGuessValidity is filtering out the crap guesses before even sending submit guess.
	//Loop through all letters in the hiddenword

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) 
	{
		// compare letters against the hidden guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) 
		{
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{
				if (MHWChar == GChar) 
				{ // if they're in the same place
					BullCowCount.Bulls++; // incriment bulls
				}
				else 
				{
					BullCowCount.Cows++; // must be a cow
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bFinalStatus = true;
	}
	else
	{
		bFinalStatus = false;
	}

	return BullCowCount;
}






