#include <string>
#include <iostream>
using namespace std;

string exec(const char* cmd);

void computeKNNs(string filePath, const int N, const int Dim, const int K, float sampleRate, const int convThreshold, int** B_Index,double** B_Dist,double** dataPoints, ofstream& logFile);

