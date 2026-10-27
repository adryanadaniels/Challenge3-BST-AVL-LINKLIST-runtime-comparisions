#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip> 
#include <algorithm>
#include <bits/stdc++.h>

//headers
#include "BST.h"
#include "AVL.h"
#include "LinkedList.h"

std::vector<int> GenerateRand(size_t size);
std::vector<int> GenerateASC(size_t size);
std::vector<int> GenerateDESC(size_t size);

int main()
{
    

    return 0;
}

std::vector<int> GenerateRand(size_t size)
{
    std::vector<int> data;
    data.reserve(size); // pre allocate memory

    //using a seed to generate random numbers 
    std::mt19937 rng(47); 
    std::uniform_int_distribution <int> dist(1,10000000);
    
    for (int i = 1; i <= size; ++i)
    {
        data.push_back(dist(rng));
    }
    return data;
}
std::vector<int> GenerateASC(size_t size)
{

    std::vector<int> ASC_Sequence;
    ASC_Sequence.reserve(size);
    int N = size; 
    
  

  for (int i = 1; i <= N; ++i)
  {
    ASC_Sequence.push_back(i);
  }
  return ASC_Sequence;
}

std::vector<int> GenerateDESC(size_t size)
{
    std::vector<int> DESC_Sequence; 
    DESC_Sequence.reserve(size);
    int N = size;
    for (int i = N; i >= 1; --i)
    {
        DESC_Sequence.push_back(i);
    }
    reutrn DESC_Sequence;
}