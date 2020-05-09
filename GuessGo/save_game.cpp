#include <iostream>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<ctime>
#include <fstream>
#include<sstream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include "guessgo.h"
using namespace std;

void save_game(int grid_size, int pool_size, vector<string> pool, string** userwordlist, string** computerwordlist){
  ofstream fout;
  string path = "txt_files/save_picked_words.txt";
  fout.open(path.c_str());

  if (fout.fail()){
    cout << "Sorry an error occurred";
    exit(0);
  }
  else{
    for (int i=0;i<grid_size;i++){
      for (int j=0; j<grid_size; j++){
        fout << userwordlist[i][j]<<" ";
      }
    }
  }

  fout.close();

  path = "txt_files/save_computer_wordlist.txt";
  fout.open(path.c_str());
  if (fout.fail()){
    cout << "Sorry an error occurred" <<endl;
    exit(0);
  }
  else{
    for (int k=0;k<grid_size;k++){
      for (int l=0;l<grid_size;l++){
        fout << computerwordlist[k][l] <<" ";
      }
    }
  }
  fout.close();

  fout.open("txt_files/save_pool.txt");
  if (fout.fail()){
    cout << "Sorry an error occurred" <<endl;
    exit(0);
  }
  else{
    for (int p = 0;p<pool_size;p++){
      fout << pool[p] <<" ";
    }
  }

  fout.close();

  path = "txt_file/sizes";
  fout.open(path.c_str());
  if (fout.fail()){
    cout << "Sorry an error occurred"<<endl;
    exit(0);
  }
  else{
    fout << grid_size << " " <<pool_size <<endl;
  }

}
