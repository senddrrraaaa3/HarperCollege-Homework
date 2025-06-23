#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
    
    srand(time(0));

    
    int stepOptions[] = {10, 50, 100, 500, 1000};
    int numStepOptions = 5;

   
    int M = 10;

    
    cout << "Number of Steps (N)\tTrial Number (M)\tFinal Position (D)" << endl;

    
    for (int i = 0; i < numStepOptions; i++) {
        int N = stepOptions[i];

        
        for (int trial = 1; trial <= M; trial++) {
            int position = 0;  

            
            for (int step = 0; step < N; step++) {
                int flip = rand() % 2;  
                if (flip == 0) {
                    position--;  
                } else {
                    position++;  
                }
            }

            
            cout << N << "\t\t\t" << trial << "\t\t" << position << endl;
        }
    }

    return 0;
}

