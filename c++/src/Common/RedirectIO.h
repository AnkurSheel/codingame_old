#ifndef _REDIRECTIO_H
#define _REDIRECTIO_H

#include <iosfwd>

namespace Common
{
  void RedirectCin(std::istream& stream);
  void RedirectCout(std::ostream& stream);
  void RedirectCerr(std::ostream& stream);
  void ResetCin();
  void ResetCout();
  void ResetCerr();
}
#endif  // !_REDIRECTIO_H
