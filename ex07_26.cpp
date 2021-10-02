/*ex07_26.cpp*/

#include <iostream>
using std::cout;
//using std::cin;
using std::endl;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include <iomanip>
using std::setw;

bool correctness_of_the_course(int [][8], int, int);
void make_move(int [][8], int, int);
void show_board(int [][8], int, int);

int main()
{
   srand(time(0));
   int move_r, move_c;
   int number_move = 0;
   int attempt_counter = 0;
   int board[8][8] = {0};
   int start_r = rand() % 8;
   int start_c = rand() % 8;
   move_r = start_r;
   move_c = start_c;    

   while(true)
   {
      if(correctness_of_the_course(board, move_r, move_c))
      {
         number_move++;
	 board[move_r][move_c] = number_move;
         make_move(board, move_r, move_c);
         attempt_counter = 0;
      }
      else
      {
	 attempt_counter++;
         if(attempt_counter > 100)
            break;
      }

      move_r = rand() % 8;
      move_c = rand() % 8;
   }

   show_board(board, start_r, start_c);

   return 0;
}

bool correctness_of_the_course(int B[][8], int current_R, int current_C)
{
   if(B[current_R][current_C] != 0)
      return false;
   else
      return true;
}

void make_move(int B[][8], int current_R, int current_C)
{
   int filler = 10;
   int r_temp = current_R;
   int c_temp = current_C;

   while(true)
   {
      if((c_temp - 1) >= 0)
      {
         c_temp--;
         B[r_temp][c_temp] = filler;
      }
      else
	 break;
   }

   r_temp = current_R;
   c_temp = current_C;

   while(true)
   {
      if((c_temp + 1) < 8)
      {
         c_temp++;
	 B[r_temp][c_temp] = filler;
      }
      else
         break;
   }

   r_temp = current_R;
   c_temp = current_C;

   while(true)
   {
      if((r_temp - 1) >= 0)
      {
         r_temp--;
	 B[r_temp][c_temp] = filler;
      }
      else
         break;
   }

   r_temp = current_R;
   c_temp = current_C;

   while(true)
   {
      if((r_temp + 1) < 8)
      {
         r_temp++;
	 B[r_temp][c_temp] = filler;
      }
      else
         break;
   }

   r_temp = current_R;
   c_temp = current_C;

   while(true)
   {
      if((r_temp - 1) >= 0 && (c_temp - 1) >= 0)
      {
         r_temp--;
         c_temp--;
         B[r_temp][c_temp] = filler;
      }
      else
         break;
   }
   
   r_temp = current_R;
   c_temp = current_C;

   while(true)
   {
      if((r_temp + 1) < 8 && (c_temp + 1) < 8)
      {
         r_temp++;
	 c_temp++;
	 B[r_temp][c_temp] = filler;
      }
      else
	 break;
   }
   
   r_temp = current_R;
   c_temp = current_C;

   while(true)
   {
      if((r_temp + 1) < 8 && (c_temp - 1) >= 0)
      {
         r_temp++;
	 c_temp--;
	 B[r_temp][c_temp] = filler;
      }
      else
	 break;
   }

   r_temp = current_R;
   c_temp = current_C;

   while(true)
   {
      if((r_temp - 1) >= 0 && (c_temp + 1) < 8)
      {
         r_temp--; 
         c_temp++;
	 B[r_temp][c_temp] = filler;
      }
      else
	 break;   
   }
}

void show_board(int B[][8], int sCR, int sCC)
{
   cout << "\n      0   1   2   3   4   5   6   7   \n" ;
   cout << "                                   \n";
   for(int i = 0; i < 8; i++)
   {
       cout << "    |---|---|---|---|---|---|---|---|\n";
       cout << i << "   |";
       for (int j = 0; j < 8; j++)
       {
           if (i == sCR && j == sCC)
               cout << " Q " << "|";
           else if (B[i][j] == 0)
               cout << "   |";
           else    
               cout << setw(3) << B[i][j] << "|";
       }
       cout << endl;
   }
   cout << "    |---|---|---|---|---|---|---|---|\n";
}
