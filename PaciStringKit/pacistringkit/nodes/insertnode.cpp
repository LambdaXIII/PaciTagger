#include "insertnode.h"

namespace paci::psk {

void InsertNode::do_it(std::string& s) const {
  if (m_insertPoint <= APPEND_POINT || m_insertPoint >= int(s.size()))
    s.append(m_content);

  s.insert(m_insertPoint, m_content);
}

bool InsertNode::check_pass(
  [[maybe_unused]] const std::string& s) const {
  if (m_content == "")
    return false;
  return true;
}

} // namespace paci::psk
