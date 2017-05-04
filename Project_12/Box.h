#ifndef BOX_H
#define BOX_H
class Box
{
	public:
		//Box();
		~Box();
		Box(double lengthValue=1.0,double widthValue=1.0,double heightValue=1.0);
		//function to calculate the volume of a box
		double volume() const;
		//Friend function
		friend double boxSurface(const Box& theBox);
		friend class Carton;
		int compareVolume(const Box& otherBox);
		int getObjectCount() const { return objectCount;};
		//申明为const的对象，只能调用也申明为const的成员函数。const成员函数不会修改调用它的对象
		double getLength() const;
		double getWidth() const;
		double getHeight() const;
		bool operator<(const Box& aBox) const {
			return volume() < aBox.volume();
		}
	private:
		static int objectCount;
		mutable double length;
		double width;
		double height;
};

//Box::Box()
//{
//}
//
//Box::~Box()
//{
//}
#endif // !BOX_H
