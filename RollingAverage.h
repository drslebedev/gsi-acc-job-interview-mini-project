#ifndef RollingAverage_H
#define RollingAverage_H

std::vector<double> makeRollingAverage(const std::vector<double>& inVec, int windowSize = 100)
{
    int count = 0;
    double sum = 0;
    std::vector<double> outVec;
    outVec.resize(inVec.size());
    for (size_t i = 0; i < inVec.size(); i++) {
        sum += std::abs(inVec[i]);
        if (count < windowSize) {
            count++;
            outVec[i] = sum / count;
            continue;
        }
        sum -= std::abs(inVec[i - windowSize]);
        outVec[i] = sum / count;
    }
    return outVec;
}

#endif