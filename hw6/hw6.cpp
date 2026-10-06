class Point {
private:
  float x,y;
  float r,phi; // REDUNDANT
public:
  Point(float in_x,float in_y) {
    x = in_x; y= in_y; r = ... phi = ... ; };
  float distance_to_origin() {
    return r; // sqrt( x*x + y*y );
  };
  float angle() {
    return phi; // std::atan(y/x);
  };
};

int main() {
  Point p1(1.0,1.0);
  float d = p1.distance_to_origin();
  float a = p1.angle( );

  return 0;
}    std::println("for n = {},e{},n,e);
}
int halfway(Point p, Point Q){
  (p.x - Q.x)/2;
  (p.y - q.y)/2
int scale
    
