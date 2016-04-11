// Random.cpp 
 
#include "Random.h" 
#include <cstdlib> 
 
// Returns a random number in r. 
int Random(Range r) 
{ 
  return r.Low + rand() % ((r.High + 1) - r.Low); 
} 
 
// Returns a random number in [low, high]. 
int Random(int low, int high) 
{ 
  return low + rand() % ((high + 1) - low); 
}

