#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;
int main() {
    char wall = 186, up = 205, down = 205;
    int snakeLong = 5, runs = 0, stanga = 0, dreapta = 0;
    int extremitatiStanga[26] = {1, 100, 199, 298, 397, 496, 595, 694, 793, 892, 991, 1090, 1189, 1288, 1387, 1486, 1585, 1684, 1783, 1882, 1981, 2080, 2179, 2278, 2377, 2476};
    int extremitatiDreapta[26] = {99, 198, 297, 396, 495, 594, 693, 792, 891, 990, 1089, 1188, 1287, 1386, 1485, 1584, 1683, 1782, 1881, 1980, 2079, 2178, 2277, 2376, 2475, 2574};
    int i, contor = 1, score = 0, randPosition = 232;
    srand(time(NULL));
    bool full_runs = true, start = true, eated = false, w = false, a = false, s = false, d = false;
    char area[2575], answer;
    for(i = 1; i <= 2574; ++i) {
        area[i] = ' ';
    }
    char eatIt = 254;
    int snake[250] = {941, 1040, 1139, 1238, 1337};
    int copie_snake[250];
    int snakeElementsDiff, deleteElement, deleteElement2;
    while(start){
            ++runs;
            for(i = 0; i < snakeLong; ++i){
            copie_snake[i] = snake[i];
            }
            snakeElementsDiff = snake[snakeLong-2] - snake[snakeLong-1];

            if(snake[0] == randPosition) {
                area[randPosition] = ' ';
                score++;
                eated = true;
            }

            if(eated == true) {
                snakeLong++;
                if(snakeElementsDiff == 99 || snakeElementsDiff == -99) {
                    snake[snakeLong] = snake[snakeLong-1] + 99;
                }

                randPosition = rand()%2574;
                for(int r = 0;  r < snakeLong; ++r) {
                  if(snake[r] == randPosition) {
                  randPosition = rand()%2574;
                  r = 0;
                }
                }
                eated = false;
                char sound = 7;
                cout << sound;
             }

            if(snake[0] < 0 || snake[0] > 2574 || snake[0] == 0) {
                system("Color 02");
                cout  << "         The game is over, you were out of range" << endl;
                cout << "         You've obtained: " << score << " points, congrats!" << endl;
                cout << "         Thanks for playing, i hope you've enjoyed the game!" << endl;
                Sleep(10000);
                return 0;
            }
            if((snake[0] - snake[1] < 0) && (snake[0] - snake[1] == -1)) {
              stanga++;
            }
            else if((snake[0] - snake[1] > 0) && (snake[0] - snake[1] == 1)) {
              dreapta++;
            }
            if(runs > 30) {
                if(((snake[0] - snake[1]) < 0) && (stanga > dreapta)) {
                  for(i = 0; i <= 26; ++i) {
                    if(snake[0] == extremitatiStanga[i]-1 ){
                      system("Color 02");
                      cout  << "         The game is over, you were out of range" << endl;
                      cout << "         You've obtained: " << score << " points, congrats!" << endl;
                      cout << "         Thanks for playing, i hope you've enjoyed the game!" << endl;
                      Sleep(10000);
                      return 0;
                    }
                  }
                }
                else {
                if(((snake[0] - snake[1]) > 0) && (stanga < dreapta)) {
                  for(i = 0; i <= 26; ++i) {
                    if(snake[0] == extremitatiDreapta[i]+1) {
                      system("Color 02");
                      cout  << "         The game is over, you were out of range" << endl;
                      cout << "         You've obtained: " << score << " points, congrats!" << endl;
                      cout << "         Thanks for playing, i hope you've enjoyed the game!" << endl;
                      Sleep(10000);
                      return 0;
                    }
                }
              }
            }
          }
            for(i = 0; i < snakeLong; ++i) {
                for(int j = i + 1; j < snakeLong; ++j) {
                  if(snake[i] == snake[j]) {
                    system("Color 02");
                    cout << "         The game is over, you've hitten your body with the head" << endl;
                    cout << "         You've obtained: " << score << " points, congrats!" << endl;
                    cout << "         Thanks for playing, i hope you've enjoyed the game!" << endl;
                    Sleep(10000);
                    return 0;
                  }
                }
            }


            for(i = 1; i < snakeLong; ++i) {
                area[snake[0]]  = 176;
                area[snake[i]] = 219;

            }
              if(runs % 2 != 0) {
                area[deleteElement2] = 32;
                  deleteElement = snake[snakeLong-1];
              }
              if(runs % 2 == 0) {
                area[deleteElement] = 32;
                deleteElement2 = snake[snakeLong-1];
              }
             area[randPosition] = eatIt;
                    cout << "                                     Snake Game, v1.2 developed by Gog Andrew" << endl;
                       for(i = 1; i <= 101; ++i) {
                        cout << up;
                    }
                    cout << endl;
                        for(int z = 1; z <= 2574; ++z) {
                            if(full_runs) {
                                cout << wall;
                                full_runs = false;
                            }
                            cout << area[z];
                            contor++;
                            if(contor==100) {
                                cout << wall << endl;
                                contor = 1;
                                full_runs = true;
                            }
                    }

                    for(i = 1; i <= 101; ++i) {
                            cout << down;
                     }
            cout << endl;
            char input, copie_input;
            if(runs == 1) {
              system("Color 04");
              cout << "                                        - GAMEPLAY HELP - \n " << endl;
              cout << "[1] To move the snake, press next keys: W for up, A for left, S for down, D for right" << endl;
              cout << "[2] You have to eat the littles squares which appear on the game interface, you will earn 1 point for every eated square" << endl;
              cout << "[3] Try to don't hit your head of walls or of your body, if you did it, the game will end up" << endl;
              cout << "[4] If you're going in a direction, don't press the opposite direction key, if you did it, the game will end up" << endl;
              cout << "[Gog Andrew] - Enjoy the game, thanks for playing it." << endl << endl;
              cout << "                   -------------------- Press 'C' to start the game! -------------------- ";
              answer = _getch();

                while(answer != 'c' || answer != 'C') {
                answer = _getch();
                if(answer == 'c' || answer == 'C') {
                  break;
                }
              }
              system("Color 07");
              input = 'A';
            }
            if(kbhit()) {
            input = _getch();
            }
            if(runs % 2 != 0 && (input == 'w' || input == 'W' || input == 'a' || input == 'A' || input == 's' || input == 'S' || input == 'D' || input == 'd' )) {
              copie_input = input;
            }
            if(input != 'w' && input != 'W' && input != 'a' && input != 'A' && input != 's' && input != 'S' && input != 'D' && input != 'd') {
                input = copie_input;
            }
            if(input == 'W'|| input == 'w') {
                for(i = 0; i < snakeLong; ++i) {
                  if(i == 0) {
                  snake[0] -= 99;
                  }
                  else {
                  snake[snakeLong-i] = copie_snake[snakeLong-i-1];
                  }
                }
              w = true;
            }

            else if(input == 'A' || input == 'a') {
              for(i = 0; i < snakeLong; ++i) {
                if(i == 0) {
                snake[0] -= 1;
                }
                else {
                snake[snakeLong-i] = copie_snake[snakeLong-i-1];
                }
              }
                    a = true;
            }
            else if(input == 'S' || input == 's') {
              for(i = 0; i < snakeLong; ++i) {
                if(i == 0) {
                snake[0] += 99;
                }
                else {
              snake[snakeLong-i] = copie_snake[snakeLong-i-1];
                }
              }
                    s = true;
            }
            else if(input == 'D' || input == 'd') {
              for(i = 0; i < snakeLong; ++i) {
                if(i == 0) {
                snake[0] += 1;
                }
                else {
              snake[snakeLong-i] = copie_snake[snakeLong-i-1];
                }
              }
                    d  = true;
            }
          system("CLS");
    }
return 0;
}
