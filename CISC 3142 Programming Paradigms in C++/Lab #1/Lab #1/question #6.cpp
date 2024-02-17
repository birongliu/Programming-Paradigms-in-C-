using namespace std;
#include <cmath>
#include <iostream>

int main() {
    int elapsed;
    cout << "Enter in seconds of elapsed time: " << endl;
    cin >> elapsed;
    int minutes = floor((elapsed % 3600) / 60);
    int hours = floor(elapsed / 3600);
    int second = elapsed % 60;
    
    cout << hours << ":" << minutes << ":" << second << "\n";
    
    return 0;
}