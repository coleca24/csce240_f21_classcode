// Copyright 2021 Casey Cole
// Single level inheritance Vehicle, Car
// Multi-level Vehicle, Car, Tesla
// Multiple inheritance Vehicle, FourWheels, Car
// Multi-Path Graphic, Barchart (graphic), LineChart (graphic), 
// HybridChart (bar,line)
//    class scope resolution LineChart::res
//    virtual base class (variables shared between base classes) 
//        : virtual public Graphic
// Revisit function overriding... now with polymorphism
#include <cstdlib> 
#include <iostream> 

using std::cout;
using std::endl;

class Graphics{
	
	public : 
		Graphics(){
			resolution = 0;
		}
		virtual void print(){
			cout << "Graphics" << endl;
		}
		int resolution;
};
class BarChart : virtual public Graphics {
	public : 
		BarChart(){
			numBars = 10;
		}
		void print(){
			cout << "Barchart" << endl; 
		}
		int numBars; 
};

class LineChart : virtual public Graphics {
	public : 
		LineChart() {
			numPoints = 50;
		}
		void print(){
			cout << "LineChart" << endl;
		}
		int numPoints; 
};

class BarLineChart : public LineChart, public BarChart{
	public: 
		BarLineChart() {
		}
		void print(){
			cout << "LineBar" << endl;
		}
};

//~ void fun(Graphics * g){
	
//~ }

int main(int argc, char** argv) 
{
	BarLineChart b; 
	//cout << b.LineChart::resolution << endl;
	//~ cout << b.resolution << endl; 
	//~ cout << b.numPoints << endl; 
	//~ cout << b.numBars << endl;
	
	Graphics * g = new LineChart; 
	g->print();
	return 0;
}
