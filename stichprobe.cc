#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>

int main(){
    std::ifstream inputFile("datensumme.txt");
    if(!inputFile){
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }
    std::vector<double> numbers;
    double number;
    int N = 0;

    while(inputFile >> number){
        numbers.push_back(number);
        N++;
    }
    inputFile.close();

    double sum = 0;
    for (double num : numbers) {
        sum += num;
    }
    double mean = sum / N;
    std::cout << "Mean(ā): " << mean << std::endl;

    double variance_sum = 0.0;
    for (double num : numbers) {
        variance_sum += pow(num - mean, 2);
    }
    double variance = variance_sum / N;
    std::cout << "Variance(V): " << variance << std::endl;

    double std_deviation = std::sqrt(variance);
    std::cout << "Standard Deviation(σ): " << std_deviation << std::endl;

    return 0;
}