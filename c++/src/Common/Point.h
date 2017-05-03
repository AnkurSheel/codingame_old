#include <iosfwd>
#ifndef Point_H__
#define Point_H__

template <typename T>
class cPoint
{
public:
  cPoint(T x, T y);
  cPoint(const cPoint<T>& other);
  T Dot(cPoint other) const { return m_x * other.m_x + m_y * other.m_y; }
  T GetX() const { return m_x; }
  T GetY() const { return m_y; }
  cPoint Negate() { return cPoint(-m_x, -m_y); }
  cPoint Ortho() { return cPoint(-m_y, m_x); }
  cPoint operator+(const cPoint& other) const { return cPoint(m_x + other.m_x, m_y + other.m_y); }
  cPoint operator-(const cPoint& other) const { return cPoint(m_x - other.m_x, m_y - other.m_y); }
  cPoint operator*(double factor) const { return cPoint(m_x * factor, m_y * factor); }
  void operator+=(const cPoint& other);
  void operator-=(const cPoint& other);
  void operator*=(double factor);
  bool operator==(const cPoint<T>& other) const;
  bool operator!=(const cPoint<T>& other) const;
  T DistanceSquared(const cPoint& coord) const;
  double Distance(const cPoint& coord) const;
  cPoint RotateInDegree(double degree);
  cPoint RotateInRadian(double radians) const;
  double AngleInDegree() const;
  double AngleInRadian() const;
  cPoint GetDirection(const cPoint& inVec) const;
  T LengthSquared() const;
  double Length() const;
  cPoint Normalize() const;
  void NormalizeInplace();

private:
  static double toDegrees(double radians) { return radians * 180.0 / M_PI; }
  static double toRadians(double degrees) { return degrees * M_PI / 180.0; }
private:
  T m_x;
  T m_y;
};

template <typename T>
cPoint<T>::cPoint(T x, T y)
  : m_x(x)
  , m_y(y)
{
}
template <typename T>
cPoint<T>::cPoint(const cPoint<T>& other)
  : m_x(other.m_x)
  , m_y(other.m_y)
{
}
template <typename T>
void cPoint<T>::operator+=(const cPoint& other)
{
  m_x += other.m_x;
  m_y += other.m_y;
}

template <typename T>
void cPoint<T>::operator-=(const cPoint& other)
{
  m_x -= other.m_x;
  m_y -= other.m_y;
}

template <typename T>
void cPoint<T>::operator*=(double factor)
{
  m_x *= factor;
  m_y *= factor;
}

template <typename T>
T cPoint<T>::DistanceSquared(const cPoint& coord) const
{
  T dx = coord.m_x - m_x;
  T dy = coord.m_y - m_y;
  return dx * dx + dy * dy;
}

template <typename T>
double cPoint<T>::Distance(const cPoint& coord) const
{
  return sqrt(DistanceSquared(coord));
}

template <typename T>
cPoint<T> cPoint<T>::RotateInDegree(double degree)
{
  return RotateInRadian(toRadians(degree));
}

template <typename T>
cPoint<T> cPoint<T>::RotateInRadian(double radians) const
{
  double l = Length();
  double angle = AngleInRadian();
  angle += radians;
  cPoint result(cos(angle), sin(angle));
  result *= l;
  return result;
}

template <typename T>
double cPoint<T>::AngleInDegree() const
{
  return toDegrees(AngleInRadian());
}

template <typename T>
double cPoint<T>::AngleInRadian() const
{
  return atan2(m_y, m_x);
}

template <typename T>
bool cPoint<T>::operator==(const cPoint<T>& other) const
{
  return (isEqual(m_x, other.x) && isEqual(m_y, other.y));
}

template <typename T>
bool cPoint<T>::operator!=(const cPoint<T>& other) const
{
  return (!(isEqual(m_x, other.x) && isEqual(m_y, other.y)));
}

template <typename T>
cPoint<T> cPoint<T>::GetDirection(const cPoint& inVec) const
{
  cPoint vec(inVec.x - m_x, inVec.y - m_y);
  vec.NormalizeInplace();
  return vec;
}

template <typename T>
double cPoint<T>::Length() const
{
  return sqrt(LengthSquared());
}
/**
* @return the square of the length of the point
*/
template <typename T>
T cPoint<T>::LengthSquared() const
{
  return m_x * m_x + m_y * m_y;
}

template <typename T>
cPoint<T> cPoint<T>::Normalize() const
{
  cPoint result(*this);
  result.NormalizeInplace();
  return result;
}

template <typename T>
void cPoint<T>::NormalizeInplace()
{
  double l = Length();
  if (l > 0)
  {
    m_x /= l;
    m_y /= l;
  }
  else
  {
    m_x = 0;
    m_y = 0;
  }
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const cPoint<T>& point)
{
  os << "[" << point.GetX() << "," << point.GetY() << "]";
  return os;
}

#endif  // Point_H__
