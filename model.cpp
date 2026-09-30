#include "model.h"

Model::Model() : _slope(0.0), _intercept(0.0), _r2(0.0), _pearsonCorrelation(0.0) {}

Model::Model(std::istream& is) : _slope(0.0), _intercept(0.0), _r2(0.0), _pearsonCorrelation(0.0) {
    double x,y;
    std::vector<Point> data;
    while (is >> x >> y) {
        data.push_back(Point(x, y));
    }
    Train(data);
}

void Model::Train(const std::vector<Point>& data) {
    if (data.size() < 2) {
        throw std::invalid_argument(
            "At least two points are required to train the model."
        );
    }

    double sumX = 0.0;
    double sumY = 0.0;

    for (const Point& point : data) {
        sumX += point.GetX();
        sumY += point.GetY();
    }

    double meanX = sumX / data.size();
    double meanY = sumY / data.size();

    double numerator = 0.0;
    double denominator = 0.0;

    for (const Point& point : data) {
        double dx = point.GetX() - meanX;
        double dy = point.GetY() - meanY;

        numerator += dx * dy;
        denominator += dx * dx;
    }

    if (denominator == 0.0) {
        throw std::invalid_argument(
            "Cannot perform linear regression when all x values are equal."
        );
    }

    _slope = numerator / denominator;
    _intercept = meanY - _slope * meanX;

    //
    // Calculate R^2
    //

    double ssResidual = 0.0;
    double ssTotal = 0.0;

    for (const Point& point : data) {
        double predictedY = Predict(point.GetX());

        ssResidual +=
            std::pow(point.GetY() - predictedY, 2);

        ssTotal +=
            std::pow(point.GetY() - meanY, 2);
    }

    if (ssTotal == 0.0) {
        _r2 = 1.0;
    } else {
        _r2 = 1.0 - (ssResidual / ssTotal);
    }

    //
    // Calculate Pearson correlation
    //

    double sumXY = 0.0;
    double sumXX = 0.0;
    double sumYY = 0.0;

    for (const Point& point : data) {
        double dx = point.GetX() - meanX;
        double dy = point.GetY() - meanY;

        sumXY += dx * dy;
        sumXX += dx * dx;
        sumYY += dy * dy;
    }

    double correlationDenominator =
        std::sqrt(sumXX * sumYY);

    if (correlationDenominator == 0.0) {
        _pearsonCorrelation = 0.0;
    } else {
        _pearsonCorrelation =
            sumXY / correlationDenominator;
    }
}
double Model::Predict(double x) const {
    return _slope * x + _intercept;
}
std::string Model::ToString() const {
    return "Model: y = " + std::to_string(_slope) + "x + " + std::to_string(_intercept) + ", R^2 = " + std::to_string(_r2) + ", Pearson correlation = " + std::to_string(_pearsonCorrelation);
}
double Model::R2() const {
    return _r2;
}
double Model::PearsonCorrelation() const {
    return _pearsonCorrelation;
}
