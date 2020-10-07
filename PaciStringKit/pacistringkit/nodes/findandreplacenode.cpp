#include "findandreplacenode.h"

#include "warlock/logicpool.h"

namespace paci::psk {

bool FindAndReplaceNode::check_pass(
  [[maybe_unused]] const std::string& s) const {
  warlock::LogicPool p { m_searchFor != "", m_replaceTo != "" };
  return p.allRight();
}

void FindAndReplaceNode::do_it(std::string& s) const {
  auto pos = s.find(m_searchFor);
  while (pos != std::string::npos) {
    s.replace(pos, m_searchFor.length(), m_replaceTo);
    if (! m_replaceAll)
      return;
    pos = s.find(m_searchFor);
  }
}

} // namespace paci::psk
