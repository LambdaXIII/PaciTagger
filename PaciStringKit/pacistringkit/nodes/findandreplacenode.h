#ifndef FINDANDREPLACENODE_H
#define FINDANDREPLACENODE_H

#include "../PaciStringKit_global.h"
#include "basenode.h"

namespace paci::psk {

class PACISTRINGKITSHARED_EXPORT FindAndReplaceNode: public BaseNode {
  PSK_PROP(std::string, searchFor, "")
  PSK_PROP(std::string, replaceTo, "")
  PSK_PROP(bool, replaceAll, true)

protected:
  bool check_pass(const std::string& s) const override;
void  do_it(std::string &s) const override;
};

} // namespace paci::psk
#endif // FINDANDREPLACENODE_H
