#ifndef BOX_H
#define BOX_H
class Box
{
public:
	Box(double lv=1.0,double wv=1.0,double hv=1.0);
	double volume() const;
	~Box();

private:
	double length;
	double width;
	double height; 
};

//Box::Box()
//{
//}
//

#endif // !BOX_H
