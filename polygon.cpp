/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include "polygon.h"

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {
  
  // verificando se todo ponto de rhs está dentro de lhs
  for (const Point& p: (const std::vector<Point>&)rhs){
      if(!lhs.contains(p)){
          return false;
      }
  }
  //aqui fazemos o contrário
  for (const Point& p: (const std::vector<Point>&)lhs){
      if(!rhs.contains(p)){
          return false;
      }
  }
  return true;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {

  return    p.x >= this->limits[0].x &&
            p.y >= this->limits[0].y &&
            p.x <= this->limits[1].x &&
            p.y <= this->limits[1].y;
}

Point::Point(int xx, int yy): x(xx), y(yy) {
    
    this->limits.push_back(*this);

}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
    
    int botLeftXX   =   x0  <=  x1  ?   x0:x1;
    int topRightXX  =   x0  >   x1  ?   x0:x1;
    int botLeftYY   =   y0  <=  y1  ?   y0:y1;
    int topRightYY  =   y0  >   y1  ?   y0:y1;
    
    Point bottom_left   (botLeftXX, botLeftYY);
    Point top_right     (topRightXX, topRightYY);
    
    this->limits.push_back(bottom_left);
    this->limits.push_back(top_right);
    
}