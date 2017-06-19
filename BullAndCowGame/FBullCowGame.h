#pragma once
#include <string>

using FString = std::string;
using int32 = int;


struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


enum class EGuessStatus
{
	INVALID,
	OK, 
	NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWERCASE
};


class FBullCowGame
{
public:
	FBullCowGame();
	~FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	
	EGuessStatus CheckGuessValidity(FString) const;
	
	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool MyIsGameWon;
};
