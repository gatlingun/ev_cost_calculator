/* Eletric Vehicle class */

class EletricVehicle{
    public:
        EletricVehicle(double miles_per_kwh, double cost_per_kwh) : miles_per_kwh(miles_per_kwh), cost_per_kwh(cost_per_kwh){};

        double trip_cost(double miles){
            return (miles / miles_per_kwh) * cost_per_kwh;
        }

    private:
        double miles_per_kwh;
        double cost_per_kwh;
};