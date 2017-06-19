#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();


FBullCowGame BCGame;


int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	} 
	while (AskToPlayAgain());

	return 0;
}


void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();

	for (int32 count = 1; count <= BCGame.GetMaxTries(); count++)
	{
		FText Guess = GetValidGuess();
		
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl << std::endl;
	}

	return;
}


FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::INVALID;
	do
	{
		std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "Please enter a word without repeating letters." << std::endl;
			break;
		case EGuessStatus::WRONG_LENGTH:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength();
			std::cout << " letter word." << std::endl;
			break;
		case EGuessStatus::NOT_LOWERCASE:
			std::cout << "Please enter all lowercase letters." << std::endl;
			break;
		default:
			return Guess;
			break;
		}
		std::cout << std::endl;
	} 
	while (Status != EGuessStatus::OK);
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	
	return (Response[0] == 'y' || Response[0] == 'Y');
}
