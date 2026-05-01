/**
 * @file main.cpp
 * @author Akshith
 * @date 15-Dec-2025
 *
 * Contains the entry point of the Battleship application and
 * coordinates testing, initialization, and game execution flow.
 */
#include <iostream>
#include <cstdlib>

#include "GridPosition.h"
#include "Board.h"
#include "ConsoleView.h"
#include "Ship.h"
#include "OpponentGrid.h"
#include "OwnGrid.h"
#include <string.h>
#include <map>

#include "TestUtils.h"

extern int mysunkCount;
extern int oppsunkCount;
extern const int NumberOfShips;

/**
 * @brief Entry point of the Battleship application.
 *
 * Initializes the game environment, allows selection between
 * automated tests and manual gameplay, and controls game flow.
 *
 * @return Program exit status.
 */
int main ()
{
	std::cout << "Welcome to BattleShip Game..!" << std::endl ;

	int select_testing = 0;
	std::cout << "Enter 1 for tests using Part tests.........!" << std::endl;
	std::cout << "Enter 2 tor test manually(via playing game)!" << std::endl;
	std::cin >> select_testing;
	switch(select_testing)
	{
	case 1:
		/**
		 * @brief Executes automated test cases.
		 *
		 * Runs predefined unit tests for different parts of
		 * the application to verify correctness.
		 */
		part1tests();
		part2tests();
		part3tests();
		return 0;

	case 2:
	{
		/**
		 * @brief Initializes manual game components.
		 *
		 * Creates grids, board, console view, and ship limits
		 * required for interactive gameplay.
		 */
		char rowChar;
		int  colInt;
		OwnGrid myGrid(10,10);
		OpponentGrid oppGrid(10,10);
		Board B1(10,10);
		ConsoleView C1(&B1);
		std::map<int,int> shipLimits;
		shipLimits[5] = 1;
		shipLimits[4] = 2;
		shipLimits[3] = 3;
		shipLimits[2] = 4;

		int playerId;
		bool myTurn;

		std::cout << "Enter your player number (1 or 2): ";
		std::cin >> playerId;
		while (playerId != 1 && playerId != 2) {
			if (std::cin.fail()) {         // check if input is not a number
				std::cin.clear();          // clear the error flag
				std::cin.ignore(1000, '\n');  // discard invalid input
			}
			std::cout << "Invalid input. Enter 1 or 2: ";
			std::cin >> playerId;
		}


		/**
		 * @brief Determines starting player.
		 *
		 * Player one begins the game, while player two waits
		 * for the opponent's initial move.
		 */

		if (playerId == 1)
		{
			myTurn = true;   // Player 1 shoots first
			std::cout << "You start the game!\n";
		}
		else
		{
			myTurn = false;  // Player 2 waits
			std::cout << "Opponent starts. Waiting for shot...\n";
		}

		/**
		 * @brief Handles ship placement phase.
		 *
		 * Allows the player to place ships based on length
		 * constraints until all ships are positioned.
		 */
		int shipCount = 0,L=0;
		while(shipCount < NumberOfShips)

		{
			std::cout << "Enter the Length of ship to be placed"<<std::endl;
			std::cin >> L;

			if (std::cin.fail())
			{
				std::cin.clear();              // clear error state
				std::cin.ignore(1000, '\n');   // discard bad input
				std::cout << "Alphabets not allowed. "
						"only 2 - 5" << std::endl;
				continue;
			}

			if(L< 2 || L >5 )
			{
				std::cout<<"Please Enter the "
						"length between 2 and 5"<<std::endl;
				continue;
			}
			else
			{
				if(shipLimits[L]>0)

				{
					std::cout << "you can place "
							"more: "<<shipLimits[L]<<" ships "<<std::endl;
					std::cout << "======================"
							"================"<<std::endl;
					std::cout << "Enter the "
							"Bow and  Stern placing ship"<<std::endl;
					std::cout <<"Enter the "
							"rows and columns for Bow "<<std::endl;
					std::cin >> rowChar >> colInt;
					std::cout << "==========="
							"==========================="<<std::endl;
					GridPosition bow(rowChar,colInt);
					if(bow.isValid())
					{
						std::cout<<"Valid Positions"<<std::endl;
					}
					else
					{
						std::cout<<"InValid Positions "
								"please repeat"<<std::endl;
					}

					std::cout << "=============="
							"========================"<<std::endl;
					std::cout <<"Enter the "
							"rows and columns for Stern "<<std::endl;
					std::cin >> rowChar >> colInt;
					std::cout << "==============="
							"======================="<<std::endl;
					GridPosition stern(rowChar,colInt);
					if(stern.isValid())
					{
						std::cout<<"Valid Positions"<<std::endl;
					}
					else
					{
						std::cout<<"InValid Positions "
								"please repeat"<<std::endl;
					}

					std::cout << "================="
							"====================="<<std::endl;

					Ship myShip(bow,stern);
					if(myShip.isValid() &&  myShip.length() == L )
					{

						if(B1.getOwnGrid().placeShip(myShip))
						{
							std::cout << "Placement done" << std::endl ;

							std::cout << "================"
									"======================"<<std::endl;


							shipLimits[L]--;
							shipCount++;
						}
						else
						{
							std::cout << "Placement Failed" << std::endl ;
						}
					}

					else
					{
						std::cout << "Invalid position" << std::endl ;
					}
					std::cout << "========= CURRENT BOARD =======\n";
												C1.print();


				}
				else
				{
					std::cout << "The length of ship is already placed and "
							"cannot add more ships "
							"of this length"<<std::endl;
					std::cout << "============"
							"=========================="<<std::endl;
				}

			}
		}



		/**
		 * @brief Executes the main game loop.
		 *
		 * Alternates turns between the player and opponent
		 * until all ships of one side are sunk.
		 */
		bool gameOver = false;

		while (!gameOver)
		{
			if (!myTurn)
			{
				// ================= OPPONENT TURN =================
				std::cout << "\nOpponent fired.\n";
				std::cout << "Enter row and column opponent fired at: ";
				std::cin >> rowChar >> colInt;

				Shot opponentShot(GridPosition(rowChar, colInt));
				B1.getOwnGrid().takeBlow(opponentShot);

				std::cout << "\n===== YOUR GRID AFTER OPPONENT SHOT =====\n";
				C1.printOwngrid();
				std::cout << "========================================\n";

				if (mysunkCount == NumberOfShips)
				{
					std::cout << "All your ships are sunk. You lost.\n";
					gameOver = true;
				}
				else
				{
					myTurn = true;
				}

			}
			else
			{
				// ================= YOUR TURN =================
				std::cout << "\nYour turn to fire.\n";
				std::cout << "Enter row and column: ";
				std::cin >> rowChar >> colInt;

				Shot myShot(GridPosition(rowChar, colInt));

				int opp_result;
				std::cout << "Opponent result (MISS=0, HIT=1, SUNKEN=2): ";
				std::cin >> opp_result;

				if (opp_result == 1)
					B1.getOpponentGrid().
					shotResult(myShot, Shot::Impact::HIT);
				else if (opp_result == 2)
					B1.getOpponentGrid().
					shotResult(myShot, Shot::Impact::SUNKEN);
				else
					B1.getOpponentGrid().
					shotResult(myShot, Shot::Impact::None);

				std::cout << "\n===== OPPONENT BOARD "
						"AFTER YOUR SHOT =====\n";
				C1.printOpponentgrid();
				std::cout << "=========================="
						"==================\n";

				if (oppsunkCount == NumberOfShips)
				{
					std::cout << "All opponent ships are sunk. You win!\n";
					gameOver = true;
				}
				else
				{
					myTurn = false;
				}
			}
		}
		return 0;
	}
	default:
		std::cout << "Invalid option entered" <<std::endl;
		break;
	}
}













