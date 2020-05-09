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

void view_my_list(int grid_size, string ** mywordlist){
  int largestlength = mywordlist[0][0].length();
  for (int m = 0; m < grid_size; m++){
    for (int n = 0; n<grid_size; n++){
      if (mywordlist[m][n].length()>largestlength)
        largestlength = mywordlist[m][n].length();
    }
  }
 for (int i = 0; i<grid_size; i++){
    for (int j = 0; j<grid_size; j++){
      cout << left << setw(largestlength)<< mywordlist[i][j] <<" ";
    }
    cout << endl;
  }
}
