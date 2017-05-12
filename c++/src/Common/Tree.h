#ifndef _TREE_H
#define _TREE_H
#include <vector>
#include "MemoryUtils.h"

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