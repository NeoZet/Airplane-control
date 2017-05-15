class ListOfPoint{
private:
    vector<Point> vecPoint;
    unsigned int numbOfPoint;
public:
    ListOfPoint(vector<Point> _vecP,unsigned int nop);
    void appened();
    void remove();
    void setVecPoint(vector<Point> _vecP,unsigned int numb);
    vector<Point> getVecPoint();
    unsigned int getNumbPoint();
}
