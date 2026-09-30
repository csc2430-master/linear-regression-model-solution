#include "point.h"
#include <vector>
#include <istream>

class Model {
public:
    Model();
    Model(std::istream& is);
    void Train(const std::vector<Point>& data);
    double Predict(double x) const;
    std::string ToString() const;
    double R2() const;
    double PearsonCorrelation() const;
private:
    double _slope;
    double _intercept;
    double _r2;
    double _pearsonCorrelation;
};