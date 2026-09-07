#pragma once

#include <QWidget>

class QLabel;
class QDoubleSpinBox;

class CostComparisonWindow : public QWidget {
public:
    CostComparisonWindow();

private:
    void updateCosts();

    QDoubleSpinBox* mpgInput_;
    QDoubleSpinBox* gasPriceInput_;
    QDoubleSpinBox* electricityPriceInput_;
    QDoubleSpinBox* milesPerKwhInput_;
    QDoubleSpinBox* tripMilesInput_;
    QLabel* gasCostLabel_;
    QLabel* evCostLabel_;
};
