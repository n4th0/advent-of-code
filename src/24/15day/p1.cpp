
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;


bool can_move(const vector<string> & matrix, int pos_i, int pos_j, char mov){
  if (matrix[pos_i][pos_j] == '.') {
    return true;
  }
  if (matrix[pos_i][pos_j] == '#') {
    return false;
  }


  switch (mov) {
    case 'v':
      return can_move(matrix, pos_i+1, pos_j, mov);
    case '<':
      return can_move(matrix, pos_i, pos_j-1, mov);
    case '>':
      return can_move(matrix, pos_i, pos_j+1, mov);
    case '^':
      return can_move(matrix, pos_i-1, pos_j, mov);
    default:
      return false;
  }
}


void move(vector<string> & matrix, int pos_i, int pos_j, char mov, char last){

  if (matrix[pos_i][pos_j] == '.') {
    matrix[pos_i][pos_j] = last;
    return;
  }

  char aux = matrix[pos_i][pos_j];
  matrix[pos_i][pos_j] = last;

  switch (mov) {
    case 'v':
      move(matrix, pos_i+1, pos_j, mov, aux);
      break;
    case '<':
      move(matrix, pos_i, pos_j-1, mov, aux);
      break;
    case '>':
      move(matrix, pos_i, pos_j+1, mov, aux);
      break;
    case '^':
      move(matrix, pos_i-1, pos_j, mov, aux);
      break;
  }


}


int main(){
  fstream f("input.txt");
  string line;
  bool b = true;

  vector<string> matrix;
  int pos_i, pos_j;

  string movs = "";

  while (getline(f, line)) {
    if (line.empty()) {
      b = false;
      continue;
    }

    if (b) {
      matrix.push_back(line);
      if (line.find("@") != string::npos) {
        pos_i = matrix.size()-1;
        pos_j = line.find("@");
      }
      continue;
    }

    movs += line;

  }

  // for (unsigned i = 0; i< matrix.size(); i++) {
  //   cout << matrix[i]<<endl;
  // }

  // cout << "movs:"<<endl;
  // cout <<movs <<endl;



  while (!movs.empty()) {

    char mov = movs[0];

    if (can_move(matrix, pos_i, pos_j, mov)) {
      move(matrix, pos_i, pos_j, mov, '.');
      switch (mov) {
        case 'v':
          pos_i++;;
          break;
        case '<':
          pos_j--;
          break;
        case '>':
          pos_j++;
          break;
        case '^':
          pos_i--;
          break;
      }
    }


    movs.erase(0, 1);
  }

  unsigned long long result = 0;

  for (unsigned i = 0; i< matrix.size(); i++) {
    for (unsigned j = 0; j< matrix[0].size(); j++) {
      if (matrix[i][j] == 'O') {
        result += i*100 + j;
      }
    }
  }


  cout << result<<endl;;

}
