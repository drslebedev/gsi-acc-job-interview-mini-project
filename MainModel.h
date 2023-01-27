#ifndef MainModel_H
#define MainModel_H

#include "CSVSource.h"
#include "DataProvider.h"
#include "RollingAverage.h"

class MainModel
{

  public:
    using DataProvider_t = DataProvider<double>;

    void update(std::string filepath)
    {
        dataProvider.fill<CSVSource>(filepath);

        rollingAverage.clear();
        for (const auto& data : dataProvider.table()) {
            rollingAverage.push_back(makeRollingAverage(data));
        }
    }

    const DataProvider_t& getDataProvider() const { return dataProvider; }

    const DataProvider_t::DataTable_t& getRollingAverage() const { return rollingAverage; }

  private:
    DataProvider_t::DataTable_t rollingAverage;
    DataProvider_t dataProvider;
};

#endif