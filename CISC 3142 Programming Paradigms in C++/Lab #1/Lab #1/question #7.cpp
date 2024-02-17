using namespace std;
#include <cmath>
#include <iostream>

int main() {
    double totalMilk;
    cout << "Enter the total amount of milk produced in morning: " << endl;
    cin >> totalMilk;
    double capacityLiters = 3.78;
    int numberOfCartons = static_cast<int>(round(totalMilk / capacityLiters));
    
    double costPerLiter = 0.38;
    double cost = totalMilk * costPerLiter;
    
    double profitPerCarton = 0.27;
    double profit = numberOfCartons * profitPerCarton;
    
    cout << "milk cartons holds milk: " << numberOfCartons << " cost of milk production: " << cost << " profit of milks: " << profit << endl;
}
