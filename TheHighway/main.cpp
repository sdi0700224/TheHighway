#include <iostream>
#include <string>
#include <vector>
#include "highway.h"
#include "debug.h"

using namespace std;


int main(int argc, char* argv[])
{
    #ifdef _DEBUG
        _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    #endif

    if (argc != 5)
    {
        cout << "Error! Wrong number of arguments!\n";
        exit(-1);
    }
    const int N = atoi(argv[1]);
    if (N < 1)
    {
        cout << "Error! N must be possitive!\n";
        exit(-1);
    }
    const int NSegs = atoi(argv[2]);
    if (NSegs < 1)
    {
        cout << "Error! NSegs must be possitive!\n";
        exit(-1);
    }
    const int K = atoi(argv[3]);
    if (K < 1)
    {
        cout << "Error! K must be possitive!\n";
        exit(-1);
    }
    const int Percent = atoi(argv[4]);
    if (Percent < 1 || Percent > 100)
    {
        cout << "Error! K must be possitive and not more than 100!\n";
        exit(-1);
    }

    int SegmentCapacity;

    cout << "Plese enter Maximum Segment Capacity: ";
    cin >> SegmentCapacity;
    cout << endl << endl;

    highway AttikiOdos(NSegs, K, Percent, SegmentCapacity);

    for (int i = 0; i < N; i++)
    {
        cout << "\n\nAttiki Odos is operating..\n" << endl;
        AttikiOdos.operate();
    }

    return 0;
}

