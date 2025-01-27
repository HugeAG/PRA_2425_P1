#include "ListArray.h"
#ifndef DRAWING_H
#define DRAWING_H

class Drawing {
        private:
                List<Shape*>* shapes;
        public:
		Drawing(){
			shapes = new ListArray<Shape*>();
		}
                
		~Drawing(){
			for(int i = 0; i < shapes->n; i++){
				delete shapes[i];
			}
		}
                
		void add_front(Shape* shape){
			shapes->prepend(shape);
		}
                
		void add_back(Shape* shape){
			shapes->apend(shape);
		}
                
		void print_all(){
			for(int i = 0; i < shapes->n; i++){
				Shape* figura = shapes->get(i); 
				figura->print();
			}
		}

		double get_area_all_circles(){
			double area = 0;
			for(int i = 0; i < shapes->n; i++){
				Shape* figura = shapes->get(i);
				Circle* circulo = dynamic_cast<Circle*>(figura);
				if(circulo){
					area = area + circulo->area();
				}
			}
			return area;
		}

		void move_squares(double incX, double incY){
			for(int i = 0; i < shapes->n; i++){
                	Shape* figura = shapes->get(i);
                	Square* cuadrado = dynamic_cast<Square*>(figura); 
                	if(cuadrado){
				cuadrado->translate(incX, incY);
			}
		}
		}

};

#endif