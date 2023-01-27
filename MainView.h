#ifndef MainView_H
#define MainView_H

#include <QChartView>
#include <QLineSeries>
#include <QtWidgets>

class MainView : public QBoxLayout
{
    Q_OBJECT

  public:
    using openFileCallback_t = std::function<void(void)>;

    MainView()
        : QBoxLayout(QBoxLayout::Direction::TopToBottom)
    {
        createUI();
    }

    void setOpenFileCallback(const openFileCallback_t& callback) { openFileCallback = callback; }

    void update(const std::vector<QLineSeries*>& series)
    {
        QChart* c = chartView->chart();
        c->removeAllSeries();
        for (auto s : series) {
            c->addSeries(s);
        }
    }

  private slots:

    void openFileClicked() { openFileCallback(); }

  private:
    QChartView* chartView{ nullptr };
    openFileCallback_t openFileCallback{ nullptr };

    void createUI()
    {
        QPushButton* button = new QPushButton("Open file");
        connect(button, SIGNAL(clicked()), this, SLOT(openFileClicked()));

        QChart* chart = new QChart();
        chart->legend()->hide();
        chart->createDefaultAxes();
        chart->setTitle("Chart");

        chartView = new QChartView();
        chartView->setChart(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        this->addWidget(chartView);
        this->addWidget(button);
    }
};

#endif