#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();


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
	std::cout << std::endl << std::endl;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
}


void PlayGame()
{
	BCGame.Reset();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries())
	{
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << ".";
		std::cout << std::endl << std::endl;
	}

	PrintGameSummary();
}


FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::INVALID;
	do
	{
		std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
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
		default: // assume the guess is valid
			break;
		}
		std::cout << std::endl;
	} 
	while (Status != EGuessStatus::OK);

	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	
	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintGameSummary()
{
	std::cout << (BCGame.IsGameWon() ? "WELL DONE - YOU WIN!" : "Better luck next time!") << std::endl;
}
