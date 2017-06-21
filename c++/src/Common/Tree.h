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
    cTreeNode(cTreeNode* const pParent, const T& data);
    ~cTreeNode();
    T GetData() const { return m_data; }
    cTreeNode* GetParent() const { return m_pParent; }
    cTreeNode* const GetChild(const T& value) const;
    cTreeNode* const AddChild(const T& value);

  private:
    T m_data;
    cTreeNode* m_pParent;
    std::vector<cTreeNode*> m_children;
  };

  template <class T>
  cTreeNode<T>::cTreeNode(cTreeNode* const pParent, const T& data)
    : m_data(data)
    , m_pParent(pParent)
  {
  }

  template <class T>
  cTreeNode<T>::~cTreeNode()
  {
    for (auto iter = m_children.begin(); iter != m_children.end(); iter++)
    {
      SafeDelete(*iter);
    }
    m_pParent = nullptr;
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
    cTreeNode* pNode = new cTreeNode(this, value);
    m_children.push_back(pNode);
    return pNode;
  }
}
#endif  // !_TREE_H
