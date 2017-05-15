class ListOfPlane{
private:
    vector<Plane> vecPlane;
    unsigned int numbOfPlane;
public:
    void appened();
    void remove();
    void setPlane(vector<Plane> _vecPlane,unsigned int numb);
    vector<Plane> getPlane();
    unsigned int getNumbPlane();
}
