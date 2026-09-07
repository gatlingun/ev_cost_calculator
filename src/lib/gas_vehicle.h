/* Gas Vehicle Class */

class GasVehicle {
    public:
        GasVehicle(double mpg, double cost_per_gallon) : mpg(mpg), cost_per_gallon(cost_per_gallon) {};

        double trip_cost(double miles) const {
            return (miles / mpg) * cost_per_gallon;
        }

    private:
        double mpg;
        double cost_per_gallon;
};
