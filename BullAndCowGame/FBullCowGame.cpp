#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}


FBullCowGame::~FBullCowGame()
{
}


int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}


int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}


int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) 
	{
		return EGuessStatus::NOT_ISOGRAM;
	}
	else if (false) 
	{
		return EGuessStatus::NOT_LOWERCASE;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::WRONG_LENGTH;
	}
	else
	{
		return EGuessStatus::OK;
	}
}


FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	
	FBullCowCount BullCowCount;
	int32 MyHiddenWordLength = GetHiddenWordLength();

	for (int32 i = 0; i < MyHiddenWordLength; i++)
	{
		for (int32 j = 0; j < MyHiddenWordLength; j++)
		{
			if (MyHiddenWord[i] == Guess[j])
			{
				if (i == j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}
