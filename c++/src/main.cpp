#include "Common\Includes.h"
#ifdef _LOCAL
#include <fstream>
#include "Common\RedirectIO.h"
#endif  // _LOCAL

using namespace std;

int main(int argc, char** argv)
{
#ifdef _LOCAL
  static ifstream stream = ifstream("in.txt");
  RedirectIO::RedirectCin(stream);
#endif  // _LOCAL

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");

#ifdef _LOCAL
  RedirectIO::ResetCin();
#endif  // _LOCAL
}
