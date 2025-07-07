#include <string>

class Country {
    public:
    int gdp = 0;
    Country() = default;
    Country(const std::string &name, int gdp, int gold_bars, int pop_of_aliens);
        virtual int get_gdp() {return gdp;};
    virtual ~Country() = default; //destructor - needed even if they do not work
    private: //derived classes cant access
        int gold_bars;
    protected: //derived classes can access 
        int pop_of_aliens;
};

class State final : public Country { //final indicates that this class cant be inherited from
    public:
        int get_gdp() override {
            return 1000000; // Example GDP value for a state
        }
};




STOPPED on VIRTUAL FUNCTIONS pg. 604