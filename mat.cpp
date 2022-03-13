#include "mat.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
namespace ariel{
string mat(int col, int row, char c1, char c2)
{
    if (col < 0 || row < 0)
        throw invalid_argument("inputs should be positive");
    
    if (col % 2 == 0 || row % 2 == 0)
        throw invalid_argument("both inputs should be odd");
    
    string mat = "a";
    return mat;
}}