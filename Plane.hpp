class Plane{
private:
    std::string name;
    int topSpeed;
    int topAltitude;
    int topDistance;
public:
    Plane(std::string _name,int _topSpeed,int _topAltitude,int _topDistance);
    std::string getName();
    int getCruiseSpeed();
    int getTopAltitude();
    int getTopDistance();
}
