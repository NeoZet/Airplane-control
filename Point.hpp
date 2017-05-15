class Point{
private:
    std::string name;
    std:: pair<float,float> coord;
    std::string specifier;
public:
   Point(std::string _name,pair<float,float> _coord);
   void defineSpecifier();
   std::string getName();
   std::pair<float,float> getCoord();
   std::string getSpecifier();
}
