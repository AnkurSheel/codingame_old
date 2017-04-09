#ifndef _REDIRECTIO_H
#define _REDIRECTIO_H

#include <iosfwd>

namespace RedirectIO
{
  void RedirectCin(std::istream& stream);
  void RedirectCout(std::ostream& stream);
  void ResetCin();
  void ResetCout();
}
#endif  // !_REDIRECTIO_H
