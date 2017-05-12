#ifndef _INCLUDES_H
#define _INCLUDES_H

#include <stdio.h>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>

#pragma GCC optimize("-O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

#define DEBUGPRINT(format, ...) fprintf(stderr, format, ##__VA_ARGS__)
#ifdef _INPUT
#define DEBUGPRINTSTDIN(format, ...)                                                                                   \
  fprintf(stderr, "IN\n");                                                                                             \
  fprintf(stderr, format, ##__VA_ARGS__);                                                                              \
  fprintf(stderr, "/IN\n")
#else
#define DEBUGPRINTSTDIN(format, ...) DEBUGPRINT(format, ##__VA_ARGS__)
#endif  //  _INPUT
#define ll long long

typedef std::chrono::high_resolution_clock Clock;
using FpSeconds = std::chrono::duration<float, std::chrono::seconds::period>;
using FpMilliSeconds = std::chrono::duration<float, std::chrono::milliseconds::period>;

#endif  // _INCLUDES_H


#ifndef _TelephoneNumbers_H__
#define _TelephoneNumbers_H__

namespace TelephoneNumbers
{
  void main();
}

#endif  // !_TelephoneNumbers_H__

#ifndef _TREE_H
#define _TREE_H
#include <vector>
#ifndef _MemoryUtils_H__
#define _MemoryUtils_H__

template <typename Interface>
inline void SafeDeleteArray(Interface** ppArrayToDelete)
{
  if (*ppArrayToDelete != NULL)
  {
    delete[](*ppArrayToDelete);
    (*ppArrayToDelete) = NULL;
  }
}

template <typename Interface>
inline void SafeDelete(Interface** ppInterfaceToDelete)
{
  if (*ppInterfaceToDelete != NULL)
  {
    delete (*ppInterfaceToDelete);
    (*ppInterfaceToDelete) = NULL;
  }
}

#endif  // !_MemoryUtils_H__


namespace Common
{
  template <class T>
  class cTreeNode
  {
  public:
    cTreeNode(const T& data);
    ~cTreeNode();
    cTreeNode* const GetChild(const T& value) const;
    cTreeNode* const AddChild(const T& value);

  private:
    T m_data;
    std::vector<cTreeNode*> m_children;
  };

  template <class T>
  cTreeNode<T>::cTreeNode(const T& data)
    : m_data(data)
  {
  }

  template <class T>
  cTreeNode<T>::~cTreeNode()
  {
    for (auto iter = m_children.begin(); iter != m_children.end(); iter++)
    {
      SafeDelete(*iter);
    }
  }

  template <class T>
  cTreeNode<T>* const cTreeNode<T>::GetChild(const T& value) const
  {
    for (auto iter = m_children.begin(); iter != m_children.end(); iter++)
    {
      if ((*iter)->m_data == value)
      {
        return *iter;
      }
    }
    return nullptr;
  }

  template <class T>
  cTreeNode<T>* const cTreeNode<T>::AddChild(const T& value)
  {
    cTreeNode* pNode = new cTreeNode(value);
    m_children.push_back(pNode);
    return pNode;
  }
}
#endif  // !_TREE_H


using namespace std;
using namespace TelephoneNumbers;
using namespace Common;

void TelephoneNumbers::main()
{
  int N;
  cin >> N;
  cin.ignore();

  cTreeNode<int>* pRoot = new cTreeNode<int>(-1);
  cTreeNode<int>* pCurrentNode = nullptr;
  cTreeNode<int>* pTempNode = nullptr;
  int count = 0;

  for (int i = 0; i < N; i++)
  {
    string telephone;
    cin >> telephone;
    cin.ignore();

    pCurrentNode = pRoot;

    for (int i = 0; i < telephone.length(); i++)
    {
      int digit = telephone[i] - '0';
      pTempNode = pCurrentNode->GetChild(digit);
      if (pTempNode == nullptr)
      {
        count++;
        pTempNode = pCurrentNode->AddChild(digit);
      }
      pCurrentNode = pTempNode;
    }
  }

  cout << count << endl;
}


using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  TelephoneNumbers::main();

}

