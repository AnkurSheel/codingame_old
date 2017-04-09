#include "RedirectIO.h"
#include <iostream>
#include "../Common/Includes.h"
using namespace std;

streambuf* cinbuf = nullptr;
streambuf* coutbuf = nullptr;
streambuf* cerrbuf = nullptr;

void RedirectIO::RedirectCin(istream& stream)
{
  cinbuf = cin.rdbuf();
  ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin.rdbuf(stream.rdbuf());
}

void RedirectIO::RedirectCout(ostream& stream)
{
  ios_base::sync_with_stdio(false);
  cout.rdbuf(stream.rdbuf());
}

void RedirectIO::RedirectCerr(std::ostream& stream)
{
  cerrbuf = cerr.rdbuf();
  ios_base::sync_with_stdio(false);
  std::cerr.tie(0);
  std::cerr.rdbuf(stream.rdbuf());
}

void RedirectIO::ResetCin()
{
  cin.rdbuf(cinbuf);
}

void RedirectIO::ResetCout()
{
  cout.rdbuf(coutbuf);
}

void RedirectIO::ResetCerr()
{
  cerr.rdbuf(cerrbuf);
}
