#include "point.h"
#include "automutex.h"

namespace test
{
  Point::Point(int x, int y):m_x(x),m_y(y)
  {
    pthread_mutext_init(&m_point_mutex, NULL);	
  }
  ~Point::Point()
  {
    pthread_mutex_destroy(&m_point_mutex);
  }
  void setPoint(int x, int y)
  {
    AutoMutex(m_point_mutex);  
    m_x = x;
    m_y = y;
  }
}
