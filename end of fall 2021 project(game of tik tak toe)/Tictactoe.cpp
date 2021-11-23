//
//  main.cpp
//  end of fall semester 2021 project(game of tik tak toe)
//
//  Created by MARTIN on 14/11/2021.
//

 


 

#include <iostream>
using namespace std;

void displayGrid(char[][3]);

void Play(char[][3], char);

bool isWon(char, char[][3]);

bool isDraw(char[][3]);

 
int main()
{
    
    
    char Grid[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };

     displayGrid(Grid);

     while (true) {

          // Allows player X to play

          Play(Grid, 'X');

         //displays the empty grid to the console
         
          displayGrid(Grid);

         //displays the winner
         
          if (isWon('X', Grid)) {

              cout << "X player won" << endl;

              exit(0);

          }

         //displays to the comsole if there is a draw
         
          else if (isDraw(Grid))
          {

              cout << "No winner" << endl;

              exit(0);

          }

          // Player O plays next

          Play(Grid, 'O');

          displayGrid(Grid);

          if (isWon('O', Grid)) {

              cout << "O player won" << endl;

              exit(0);

          }

          else if (isDraw(Grid)) {

              cout << "No winner" << endl;

              exit(0);

          }

     }

     return 0;

}

// function to display the emptygrid.

void displayGrid(char Grid[][3])

{

     cout << "-------------" << endl;

  

     for (int i = 0; i < 3; i++)

     {

          cout << "|";

          for (int j = 0; j < 3; j++)

          {

              cout << " " << Grid[i][j] << " |";

          }

          cout << endl;

     }

     cout << "-------------" << endl;

}

//Function to play the game

void Play(char Grid[][3], char Player)

{

     //Declaration of variables.

     int row;

     int column;

     //prompt user to enter the row of the player
    
     cout << "Enter a row for player "

          << Player << " : ";

     cin >> row;

     cout << "Enter a column for player "

          << Player << " : ";

     cin >> column;

      //checks if the user enter a valid value
    
     while (Grid[row][column] != ' ')

     {

          cout << "The cell is Filled !"

              << " Try a different cell" << endl;

          cout << "Enter a row for player "

              << Player << " : ";

          cin >> row;

          cout << "Enter a column for player "

              << Player << " : ";

          cin >> column;

     }

      //displays players character on the Grid

     Grid[row][column] = Player;

}

  
//function to check if there is a draw

bool isDraw(char Grid[][3])

{

     // loop to check the Grid.

     for (int i = 0; i < 3; i++)

     {

          for (int j = 0; j < 3; j++)

          {

              // return false If there is an empty space left on the Grid.

              if (Grid[i][j] == ' ')

              {

                   return false;

              }

          }

     }

     //returns true if there is a draw

     return true;

}

 

 
//function to check if player wins

bool isWon(char Player, char Grid[][3])

{

    //loop to check the rows and columns

    for (int i = 0; i < 3; i++)

    {

         //checks if the first character of the current row is the same as the character of the player
         
        if (Grid[i][0] == Player)

         {

             // checks if other chracters in the row are the same as the  player
             
             if (Grid[i][0] == Grid[i][1] && Grid[i][0] == Grid[i][2])

             {

                  //return true if a player wins the game

                  return true;

             }

         }

         //Check if the first character of the current column is the same as the character of the player

         if (Grid[0][i] == Player)

         {

             //Check if all the other characters in the column are the characters of the player

             if (Grid[0][i] == Grid[1][i] && Grid[0][i] == Grid[2][i])

             {

                   //returns true if the current player wins the game
                  return true;

             }

         }

    }

    //checks if characters are the same as the player

    if (Grid[1][1] == Player)

    {

         //Check the left diagonal of the Grid.

         if (Grid[0][0] == Grid[1][1] && Grid[0][0] == Grid[2][2])

         {

             //returns true If all the characters in the diagonal are the characters of the current player

             return true;

         }

         //Check the right diagonal of the Grid.

         if (Grid[0][2] == Grid[1][1] && Grid[0][2] == Grid[2][0])

         {

             //returns true If all the characters in the diagonal are the characters of the current player

              return true;

         }

    }

    //Check the left diagonal of the Grid.

    if (Grid[0][2] == Player)

    {

         if (Grid[0][2] == Grid[1][1] && Grid[0][2] == Grid[2][0])

         {

             return true;

         }

    }

    //Return false if the player hasn't won the game.

    return false;

}
