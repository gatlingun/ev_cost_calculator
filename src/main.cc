#include "gui/cost_comparison_window.h"

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    CostComparisonWindow window;
    window.show();
    return application.exec();
}
