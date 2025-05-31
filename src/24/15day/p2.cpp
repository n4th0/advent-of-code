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
      if (matrix[pos_i][pos_j] == '[') {
        return can_move(matrix, pos_i+1, pos_j, mov) && can_move(matrix, pos_i+1, pos_j+1, mov);
      }else if (matrix[pos_i][pos_j] == ']') {
        return can_move(matrix, pos_i+1, pos_j, mov) && can_move(matrix, pos_i+1, pos_j-1, mov);
      }

      return can_move(matrix, pos_i+1, pos_j, mov);
    case '^':
      if (matrix[pos_i][pos_j] == '[') {
        return can_move(matrix, pos_i-1, pos_j, mov) && can_move(matrix, pos_i-1, pos_j+1, mov);
      }else if (matrix[pos_i][pos_j] == ']') {
        return can_move(matrix, pos_i-1, pos_j, mov) && can_move(matrix, pos_i-1, pos_j-1, mov);
      }
      return can_move(matrix, pos_i-1, pos_j, mov);

    case '<':
      return can_move(matrix, pos_i, pos_j-1, mov);
    case '>':
      return can_move(matrix, pos_i, pos_j+1, mov);
    default:
      return false;
  }
}


void move_rl(vector<string> & matrix, int pos_i, int pos_j, char mov, char last){

  if (matrix[pos_i][pos_j] == '.') {
    matrix[pos_i][pos_j] = last;
    return;
  }

  char aux = matrix[pos_i][pos_j];
  matrix[pos_i][pos_j] = last;

  switch (mov) {

      break;
    case '<':
      move_rl(matrix, pos_i, pos_j-1, mov, aux);
      break;
    case '>':
      move_rl(matrix, pos_i, pos_j+1, mov, aux);
      break;
  }
}

void move_d(vector<string> & matrix, int pos_i, int pos_j, char last){

  if (matrix[pos_i+1][pos_j] == '#') {
    matrix[pos_i][pos_j] = last;
    return;
  }

  if (matrix[pos_i][pos_j] == '.') {
    matrix[pos_i][pos_j] = last;
    return;
  }
  
  if (matrix[pos_i+1][pos_j] == '[') {
    move_d(matrix, pos_i+1, pos_j+1, '.');
  }else if (matrix[pos_i+1][pos_j] == ']') {
    move_d(matrix, pos_i+1, pos_j-1, '.');
  }

  move_d(matrix, pos_i+1, pos_j, matrix[pos_i][pos_j]);
  matrix[pos_i][pos_j] = last;
}

void move_u(vector<string> & matrix, int pos_i, int pos_j, char last){
  if (matrix[pos_i-1][pos_j] == '#') {
    matrix[pos_i][pos_j] = last;
    return;
  }

  if (matrix[pos_i][pos_j] == '.') {
    matrix[pos_i][pos_j] = last;
    return;
  }
  
  if (matrix[pos_i-1][pos_j] == '[') {
    move_u(matrix, pos_i-1, pos_j+1, '.');
  }else if (matrix[pos_i-1][pos_j] == ']') {
    move_u(matrix, pos_i-1, pos_j-1, '.');
  }

  move_u(matrix, pos_i-1, pos_j, matrix[pos_i][pos_j]);
  matrix[pos_i][pos_j] = last;

}

void move(vector<string> & matrix, int pos_i, int pos_j, char mov){

  if (mov == '<' || mov == '>') {
    move_rl(matrix, pos_i, pos_j, mov, '.');
    return;
  }


  if (mov == '^' ) {
    move_u(matrix, pos_i, pos_j, '.');
    return;
  }



  /*
  if (mov == 'v' && matrix[pos_i+1][pos_j] == ']') {
    // move_ud(matrix, pos_i, pos_j,  mov, '.');
    // move_ud(matrix, pos_i+1, pos_j-1,  mov, '.');
    return;
  }

  if (mov == 'v' && matrix[pos_i+1][pos_j] == '[') {
    // move_ud(matrix, pos_i, pos_j,  mov, '.');
    // move_ud(matrix, pos_i, pos_j+1,  mov, '.');
    return;
  }
  if (mov == 'v' ) {
    // move_ud(matrix, pos_i, pos_j,  mov, '.');
    return;
  }*/
  
  if (mov == '^') {
    move_u(matrix, pos_i, pos_j, '.');
    return;
  }
  else {
    move_d(matrix, pos_i, pos_j, '.');
    return;
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
      string s = "";
      for (auto c : line) {
        if (c == '#') {
          s += "##";
        }else if (c == 'O') {
          s += "[]";
        }else if (c == '.') {
          s += "..";
        }else if (c == '@') {
          s += "@.";
          pos_i = matrix.size();
          pos_j = s.size()-2;
        }
      }


      matrix.push_back(s);
      continue;
    }

    movs += line;

  }

  // for (unsigned i = 0; i< matrix.size(); i++) {
  //   cout << matrix[i]<<endl;
  // }

  // cout << "pos_i " << pos_i << " | pos_j " << pos_j << endl;

  // cout << "movs:"<<endl;
  // cout <<movs <<endl;



  while (!movs.empty()) {

    char mov = movs[0];

    if (can_move(matrix, pos_i, pos_j, mov)) {
      // cout << "true"<<endl;
      move(matrix, pos_i, pos_j, mov);
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

      // for (unsigned i = 0; i< matrix.size(); i++) {
      //   cout << matrix[i]<<endl;
      // }

    }


    movs.erase(0, 1);
  }

  unsigned long long result = 0;

  for (unsigned i = 0; i< matrix.size(); i++) {
    for (unsigned j = 0; j< matrix[0].size(); j++) {
      if (matrix[i][j] == '[') {
        result += i*100 + j;
      }
    }
  }

  // for (unsigned i = 0; i< matrix.size(); i++) {
  //   cout << matrix[i]<<endl;
  // }


  cout << result<<endl;;

}
