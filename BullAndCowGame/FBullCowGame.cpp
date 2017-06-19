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
	return MyIsGameWon;
}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "planet";

	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyIsGameWon = false;

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


FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) 
{
	MyCurrentTry++;
	int32 WordLength = GetHiddenWordLength();
	FBullCowCount BullCowCount;

	for (int32 g = 0; g < WordLength; g++)
	{
		for (int32 h = 0; h < WordLength; h++)
		{
			if (Guess[g] == MyHiddenWord[h])
			{
				if (g == h)
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

	MyIsGameWon = (BullCowCount.Bulls == WordLength);

	return BullCowCount;
}
