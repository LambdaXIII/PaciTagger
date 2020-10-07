#ifndef INSERTNODE_H
#define INSERTNODE_H

#include "basenode.h"

namespace paci::psk {

class PACISTRINGKITSHARED_EXPORT InsertNode: public BaseNode {
  PSK_PROP(int, insertPoint, 0)
  PSK_PROP(std::string, content, "")
protected:
  void do_it(std::string& s) const override;
  bool check_pass(const std::string& s) const override;

public:
  const static int PREPEND_POINT = 0;
  const static int APPEND_POINT = -1;
};

} // namespace paci::psk

#endif // INSERTNODE_H
