#pragma once
#include <string>

//To make the code unreal friendly
using FString = std::string;
using int32 = int;


struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;

};


enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Nothing_entered,
	Wrong_Length,
	Guess_Incorrect,
	Not_Lowercase
};


class FBullCowGame {
public:

	FBullCowGame();		// Constructor >> Look at constructor code in CPP
	
	int32  GetMaxTries() const;
	int32  GetCurrentTry() const;
	bool IsGameWon() const;
	int32  GetHiddenWordLength() const;

	EGuessStatus CheckGuessValidity(FString)const;

	FBullCowCount SubmitValidGuess(FString);
	FString GetHiddenWord();
	FString GetPVPWord();
	int32 AskGameType() const;
	FString PrintGameSummary();
	void Reset();

private:
	// I have moved the initialization of these variables to the Constructor in the CPP
	int32  MyCurrentTry;
	int32  MyMaxTries;
	FString MyHiddenWord;
	FString PVPWord;
	bool bFinalStatus;

};