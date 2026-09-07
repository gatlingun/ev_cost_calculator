#include "cost_comparison_window.h"

#include "eletric_vehicle.h"
#include "gas_vehicle.h"

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QLocale>
#include <QVBoxLayout>

namespace {
QDoubleSpinBox* makeInput(double value, const QString& suffix) {
    auto* input = new QDoubleSpinBox;
    input->setRange(0.01, 999.99);
    input->setDecimals(2);
    input->setSingleStep(0.01);
    input->setValue(value);
    input->setSuffix(suffix);
    return input;
}
}  // namespace

CostComparisonWindow::CostComparisonWindow()
    : mpgInput_(makeInput(40.5, " mpg")),
      gasPriceInput_(makeInput(4.10, " / gallon")),
      electricityPriceInput_(makeInput(0.35, " / kWh")),
      milesPerKwhInput_(makeInput(3.0, " miles / kWh")),
      tripMilesInput_(makeInput(25.0, " miles")),
      gasCostLabel_(new QLabel),
      evCostLabel_(new QLabel) {
    setWindowTitle("EV Cost Calculator");

    auto* inputs = new QFormLayout;
    inputs->addRow("MPG:", mpgInput_);
    inputs->addRow("Cost per gallon:", gasPriceInput_);
    inputs->addRow("Cost per kWh:", electricityPriceInput_);
    inputs->addRow("Miles per kWh:", milesPerKwhInput_);
    inputs->addRow("Trip miles:", tripMilesInput_);

    auto* layout = new QVBoxLayout(this);
    layout->addLayout(inputs);
    layout->addWidget(gasCostLabel_);
    layout->addWidget(evCostLabel_);

    const auto update = [this] { updateCosts(); };
    connect(mpgInput_, qOverload<double>(&QDoubleSpinBox::valueChanged), this, update);
    connect(gasPriceInput_, qOverload<double>(&QDoubleSpinBox::valueChanged), this, update);
    connect(electricityPriceInput_, qOverload<double>(&QDoubleSpinBox::valueChanged), this, update);
    connect(milesPerKwhInput_, qOverload<double>(&QDoubleSpinBox::valueChanged), this, update);
    connect(tripMilesInput_, qOverload<double>(&QDoubleSpinBox::valueChanged), this, update);
    updateCosts();
}

void CostComparisonWindow::updateCosts() {
    const double tripMiles = tripMilesInput_->value();
    const GasVehicle gasVehicle(mpgInput_->value(), gasPriceInput_->value());
    const EletricVehicle evVehicle(milesPerKwhInput_->value(), electricityPriceInput_->value());
    const QLocale locale;

    gasCostLabel_->setText("Cost for " + QString::number(tripMiles) + " trip in gas car: " +
                           locale.toCurrencyString(gasVehicle.trip_cost(tripMiles)));
    evCostLabel_->setText("Cost for " + QString::number(tripMiles) + " trip in EV car: " +
                          locale.toCurrencyString(evVehicle.trip_cost(tripMiles)));
}
