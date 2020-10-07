#ifndef BASENODE_H
#define BASENODE_H

#include "../PaciStringKit_global.h"

#include <string>

namespace paci::psk {

class BaseNode {
protected:
  BaseNode* m_prevNode { nullptr };
  BaseNode* m_nextNode { nullptr };

  int m_missionIndex { 0 };

  virtual bool check_pass(const std::string& s) const;

  virtual void do_it(std::string& s) const = 0;

public:
  BaseNode();
  virtual ~BaseNode();

  void process(std::string& s) const;

  int missionIndex();
  void setMissionIndex(int x);

  BaseNode* prevNode() const;
  BaseNode* nextNode() const;

  bool isHead() const;
  bool isTail() const;

  void setPrevNode(BaseNode* node);
  void setNextNode(BaseNode* node);

  BaseNode* head();
  BaseNode* tail();

  void appendToTail(BaseNode* node);
  void prependToHead(BaseNode* node);

  std::string startProcess(const std::string& s) const;
};

} // namespace paci::psk

#define PSK_PROP(type, name, val)                                      \
protected:                                                             \
  type m_##name { val };                                               \
                                                                       \
public:                                                                \
  type name() const { return m_##name; }                               \
  void set_##name(const type& x) {                                     \
    if (m_##name != x)                                                 \
      m_##name = x;                                                    \
  }

#endif // BASENODE_H
