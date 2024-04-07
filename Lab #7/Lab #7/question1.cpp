//
//  main.cpp
//  Lab #7
//
//  Created by Bi Rong Liu on 4/5/24.
//

#include <iostream>
#include <fstream>
using namespace std;


const int MAX_SALESPEOPLE = 6;
const int MAX_QUARTER = 4;

struct salesPerson {
    string id;
    double quarter[MAX_QUARTER];
    double totalSales;
};

void initialize(ifstream& indata, salesPerson list[], int listSize);
void getData(ifstream& infile, salesPerson list[], int listSize);
void saleByQuarter(salesPerson list[], int listSize, double totalByQuarter[]);
void totalSaleByPerson(salesPerson list[], int listSize);
void printReport(ofstream& outfile, salesPerson list[], int listSize, double saleByQuarter[]);
void maxSaleByPerson(ofstream& outData, salesPerson list[], int listSize);
void maxSaleByQuarter(ofstream& outData, double saleByQuarter[]);
int sequentialSearch(salesPerson list[], int listSize, string search);
int getMonthIndex(int month);


int main(int argc, const char * argv[]) {
    string salespersonFileName;
    ifstream salespersonFile;
    cout << "Enter the salesperson ID data file: ";
    cin >> salespersonFileName;
    
    salespersonFile.open(salespersonFileName);
    
    if(!salespersonFile) {
        cout << "Invalid file name provided... exit";
        return 1;
    }
    
    double salesQuarter[MAX_QUARTER] = {0};
    salesPerson salesPersonList[MAX_SALESPEOPLE];
    initialize(salespersonFile, salesPersonList, MAX_SALESPEOPLE);
    salespersonFile.close();
    salespersonFile.clear();
    
    string salesDataFileName;
    ifstream salesDataFile;
    cout << "Enter the sales data file name: ";
    cin >> salesDataFileName;
    
    salesDataFile.open(salesDataFileName);
    
    if(!salesDataFile) {
        cout << "Invalid file provided... exit";
        return 1;
    }
    
    string outputFileName;
    ofstream outputFile;
    cout << "Enter the output file name: ";
    cin >> outputFileName;
    
    outputFile.open(outputFileName);
        
    getData(salesDataFile, salesPersonList, MAX_SALESPEOPLE);
    
    saleByQuarter(salesPersonList, MAX_SALESPEOPLE, salesQuarter);
            
    printReport(outputFile, salesPersonList, MAX_SALESPEOPLE, salesQuarter);

    maxSaleByPerson(outputFile, salesPersonList, MAX_SALESPEOPLE);
    
    maxSaleByQuarter(outputFile, salesQuarter);

    
    salesDataFile.close();
    outputFile.close();
    
    return 0;
}


void initialize(ifstream& indata, salesPerson list[], int listSize) {
    int currentIndex = 0;
    while((indata && !indata.eof()) && (currentIndex < listSize)) {
        indata >> list[currentIndex].id;
        list[currentIndex].totalSales = 0;
        for(int i = 0; i < MAX_QUARTER; i++) list[currentIndex].quarter[i] = 0;
        currentIndex++;
    }
}

void getData(ifstream& infile, salesPerson list[], int listSize) {
    string id;
    int month;
    double sales;
    while(infile >> id >> month >> sales) {
        int query = sequentialSearch(list, listSize, id);
        if(query == -1) continue;
        list[query].quarter[getMonthIndex(month)] += sales;
        list[query].totalSales += sales;
    }
}

int getMonthIndex(int month) {
    switch (month) {
        case 1:
        case 2:
        case 3: return 0;
        case 4:
        case 5:
        case 6: return 1;
        case 7:
        case 8:
        case 9: return 2;
        default: return 3;
    }
}

void saleByQuarter(salesPerson list[], int listSize, double totalByQuarter[]) {
    for(int i = 0; i < listSize; i++) {
        for(int j = 0; j < MAX_QUARTER; j++) {
           totalByQuarter[j] += list[i].quarter[j];
        }
    }
}

void printReport(ofstream& outfile, salesPerson list[], int listSize, double saleByQuarter[]){
    outfile << "-----------------------------Annual Report-----------------------------\n";
    outfile << "ID\t\t\tQT1\t\t\tQT2\t\t\tQ3\t\t\tQ4\t\t\tTotal\n";
    outfile << "-----------------------------------------------------------------------\n";
    for(int i = 0; i < MAX_SALESPEOPLE; i++) {
        outfile << list[i].id << "\t\t";
        for(int j = 0; j < MAX_QUARTER; j++) {
            outfile << fixed << showpoint << setprecision(2) << list[i].quarter[j] << "\t\t";
        }
        outfile << list[i].totalSales << "\n";
    }
    outfile << "Total\t";
    for(int i = 0; i < MAX_QUARTER; i++) {
        outfile << fixed << showpoint << setprecision(2) << saleByQuarter[i] << "\t\t";
    }
    outfile << "\n\n";
}

void maxSaleByPerson(ofstream& outData, salesPerson list[], int listSize) {
    int maxSaleByPerson = 0;
    for(int i = 0; i < listSize; i++) {
        if(list[i].totalSales > list[maxSaleByPerson].totalSales) {
            maxSaleByPerson = i;
        };
    }
    outData << "Max Sale by SalesPerson: ID = " << list[maxSaleByPerson].id << ", Amount = $" << list[maxSaleByPerson].totalSales << "\n";
}

void maxSaleByQuarter(ofstream& outData, double saleByQuarter[]) {
    int quarterIndex = 0;
    for(int i = 0; i < MAX_QUARTER; i++) {
        if(saleByQuarter[i] > saleByQuarter[quarterIndex]) {
            quarterIndex = i;
        }
    }
    outData << "Max Sale by Quarter: Quater = " << quarterIndex << ", Amount = $" << saleByQuarter[quarterIndex];
}

int sequentialSearch(salesPerson list[], int listSize, string search) {
    int currentIndex = -1;
    for(int i = 0; i < listSize; i++) {
        if(list[i].id == search) {
            currentIndex = i;
            break;
        }
    }
    return currentIndex;
}
