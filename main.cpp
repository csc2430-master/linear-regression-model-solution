#include <iostream>
#include <fstream>
#include <vector>
#include "point.h"
#include "model.h"


int main() {
    std::ifstream file("data.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    Model model(file);
    std::cout << "Model: " << model.ToString() << std::endl;
    std::cout << "R^2: " << model.R2() << std::endl;
    std::cout << "Pearson correlation: " << model.PearsonCorrelation() << std::endl;

    return 0;
}