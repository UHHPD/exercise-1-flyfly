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

    std::ofstream meanFile("mittelwerte.txt");
    std::ofstream varianceFile("varianzen.txt");

    if(!meanFile || !varianceFile) {
        std::cerr << "Error opening output files!" << std::endl;
        return 1;
    }

    double overall_mean_sum = 0.0;
    double overall_variance_sum = 0.0;
    int group_size = 9;
    int num_groups = N / group_size;

    for (int i = 0; i < num_groups; i++) {
        double group_mean_sum = 0.0;
        double group_variance_sum = 0.0;

        for (int j = 0; j < group_size; j++ ) {
            group_mean_sum += numbers[i * group_size + j];
        }
        double group_mean = group_mean_sum / group_size;
        overall_mean_sum += group_mean;
        meanFile << group_mean << std::endl;

        for (int j = 0; j < group_size; j++) {
            group_variance_sum += pow(numbers[i * group_size + j] - group_mean, 2);
        }
        double group_variance = group_variance_sum / group_size;
        overall_variance_sum += group_variance;
        varianceFile << group_variance << std::endl;
    }

    meanFile.close();
    varianceFile.close();

    double mean_of_means = overall_mean_sum / num_groups;
    double mean_of_variances = overall_variance_sum / num_groups;

    std::cout << "Mean of Means: " << mean_of_means << std::endl;
    std::cout << "Mean of Variances: " << mean_of_variances << std::endl;

    return 0;
}