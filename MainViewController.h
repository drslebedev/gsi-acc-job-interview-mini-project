#ifndef MainViewController_H
#define MainViewController_H

#include <QtWidgets>
#include "MainView.h"
#include "MainModel.h"

class MainViewController {

public:

    void setView(MainView* mainView) {
        view = mainView;
        if (view != nullptr) {
            mainView->setOpenFileCallback(
              [this](){
                const auto filepath { QFileDialog::getOpenFileName(nullptr, "Open Data File", "", "Data Files (*.csv)") };
                processFileChange(filepath.toStdString());
            });
        }
    }

private:

    void processFileChange(std::string filepath) {
        model.update(filepath);
        if (view != nullptr) {
            auto series(createLineSeries(model.getDataProvider().table()));
            auto seriesAlgo(createLineSeries(model.getRollingAverage()));
            series.insert(end(series), begin(seriesAlgo), end(seriesAlgo));
            view->update(series);
        }
    }

    std::vector<QLineSeries*> createLineSeries(const MainModel::DataProvider_t::DataTable_t& data) {
        std::vector<QLineSeries*> res;
        transform(cbegin(data), cend(data), back_inserter(res), [this](const auto& v){
            return createLineSeries(v);
        } );
        return res;
    }

    QLineSeries* createLineSeries(const MainModel::DataProvider_t::DataColumn_t& data) {
        QLineSeries* series = new QLineSeries();
        int count = 0;
        for (const auto c : data) {
            series->append(count, c);
            count++;
        }
        return series;
    }
    
private:

    MainModel model;
    MainView* view { nullptr };
};

#endif