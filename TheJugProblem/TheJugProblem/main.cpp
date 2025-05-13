#include "Graph.h"  
#include "Printer.h"  
#include <iostream>  

using namespace std;  

int main()  
{  
   int smallJugSize, largeJugSize, targetSize, method, runningTimeFlag, numOp;  
   cout << "Do you want to see the running time?\n  pick: 0 - No\n 1 - Yes";  
   cin >> runningTimeFlag;  
   cout << "Enter method to be used\n  pick: 1 or 2\n";  
   cin >> method;  
   cout << "Enter size of Large jug\n";  
   cin >> largeJugSize;  
   cout << "Enter size of Small jug\n";  
   cin >> smallJugSize;  
   cout << "Enter target sizn\n";  
   cin >> targetSize;  

   if (targetSize > largeJugSize)  
   {  
       cout << "Target size is larger than the large jug size\n";  
       return 0;  
   }  

   Printer printer;
   printer.printInstructions(numOp);
}
