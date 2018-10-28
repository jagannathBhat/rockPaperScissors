/*
Rock, paper, scissors game

This project is licensed under the terms of the GNU GPLv3 license.
A copy of the lisence will be found in the root directory of the project as "LICENSE.txt"
*/
#include<conio.h> //Defining Headers
#include<iostream.h>
#include<stdlib.h>
#include<time.h>

char* choice[] = {"Rock          ", "Paper         ", "Scissor       "};

int getUserChoice() {
	int i = 0, userChoice = 0;
	cout<<"\n\nYour choice:               ";
	while(i != 13) {
		i = int(getch());
		if(i == 8) {
			cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b              ";
		}
		else if(i - 48 >= 1 && i - 48 <= 3) {
			cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<<choice[i - 49];
			userChoice = i - 48;
		}
		else if(i == 13) {
			continue;
		}
		else {
			cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\bInvalid Choice";
		}
	}
	return userChoice;
}

void main() {
	char key = 'y';
	int Algorithm, computerChoice, computerScore = 0, flag = 1, userChoice, userScore = 0;
	srand(time(NULL));
	while(key == 'y' || key == 'Y') {
		computerScore = userScore = 0;
		clrscr();
		cout<<"Instructions\n1.You will plays against the computer.\n2.You get 10 tries.\n3.Press 1 for Rock, 2 for Paper and 3 for Scissor.\nLet's start!";
		for(int i = 0; i < 10; i++) {
			flag = 1;
			userChoice = getUserChoice();
			if(userChoice < 1 || userChoice > 3) {
				flag = 0;
				i--;
			}
			if(flag) {
				computerChoice = rand() % 3 + 1;
				cout<<"\nComputer's choice: "<<choice[computerChoice - 1];
				Algorithm = (2 * computerChoice + userChoice - 2) % 3;
				switch(Algorithm) {
					case 0:
						cout<<"\nComputer gets a point";
						computerScore++;
						break;
					case 1:
						cout<<"\nDraw";
						break;
					case 2:
						cout<<"\nUser gets a point";
						userScore++;
						break;
				}
			}
		}
		cout<<"\n\nGame over\n---------\nUser: "<<userScore<<"\nComputer: "<<computerScore;
		if(userScore > computerScore) {
			cout<<"\n\nUser wins! Congrats.";
		}
		else if(userScore < computerScore) {
			cout<<"\nComputer wins. Better luck next time.";
		}
		else {
			cout<<"\nGame is a draw";
		}
		cout<<"\n\nPress y to try again. Press any other key to exit";
		key = getch();
		cout<<"\n\n";
	}
}
