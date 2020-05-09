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

//function to print the pool of words
void show_pool(vector<string> pool){
  for (int i = 0; i<pool.size();i++)
    cout << pool[i]<<endl;
}
