#include <iostream>
#include <random>
#include <iomanip>
#include <vector>
#include <functional>
#include <ctime>
#include <string>

using namespace std;

bool check_board(vector<vector<bool> > b);

int main(){
  // int m = stoi(argv[1]);
  // long long int n = stoi(argv[2]);
  // CLAs

  int m = 5;
  long long int n = 10000000;

  random_device rd;
  int seed = rd();
  mt19937 generator(seed);

  uniform_int_distribution<int> dist(0, (m-1)*2);

  auto draw_move = bind(dist, generator);

  int move;

  long long int total_Moves;
  double approx_Moves;

  for(long long int i = 0; i<n; i++){
    int x = 0;
    int y = 0;

    vector<vector<bool> > board(m, vector<bool>(m,false));
    board[0][0] = true;

    long long int num_Moves= 0;

    while(!check_board(board)){
      move = draw_move();

      if(move<=(n-1)/2){
        if(move>x){
          x = move+1;
        }
        else{
          x = move;
        }
      }
      else{
        if(move-(m-1)>y){
          y = (move-(m-1))+1;
        }
        else{
          y = move-(m-1);
        }
      }
      board[x][y] = true;
      num_Moves++;
    }
    total_Moves+= num_Moves;
  }

  approx_Moves = total_Moves/n;

  cout<<"The expected number of moves is: "<<approx_Moves;
  return 0;
}

bool check_board(vector<vector<bool> > b){
  for(int i =0; i<b.size(); i++){
    for(int j = 0; j<b[i].size(); j++){
      if(!b[i][j]){
        return false;
      }
    }
  }
  return true;
}
