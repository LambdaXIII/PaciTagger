#include "basenode.h"
namespace paci::psk {
bool BaseNode::check_pass([[maybe_unused]] const std::string& s) const {
  return true;
}

BaseNode::BaseNode() {
}

BaseNode::~BaseNode() {
  if (nextNode() != nullptr)
    delete nextNode();
}

void BaseNode::process(std::string& s) const {
  if (! check_pass(s))
    return;
  do_it(s);
}

int BaseNode::missionIndex() {
  if (isHead())
    return m_missionIndex;
  return head()->missionIndex();
}

void BaseNode::setMissionIndex(int x) {
  if (missionIndex() == x)
    return;

  if (isHead())
    m_missionIndex = x;
  head()->setMissionIndex(x);
}

BaseNode* BaseNode::prevNode() const {
  return m_prevNode;
}

BaseNode* BaseNode::nextNode() const {
  return m_nextNode;
}

bool BaseNode::isHead() const {
  return m_prevNode == nullptr;
}

bool BaseNode::isTail() const {
  return m_nextNode == nullptr;
}

void BaseNode::setPrevNode(BaseNode* node) {
  if (node == m_prevNode)
    return;
  m_prevNode = node;
  node->setNextNode(this);
}

void BaseNode::setNextNode(BaseNode* node) {
  if (node == m_nextNode)
    return;
  m_nextNode = node;
  node->setPrevNode(this);
}

BaseNode* BaseNode::head() {
  if (isHead())
    return this;
  return prevNode()->head();
}

BaseNode* BaseNode::tail() {
  if (isTail())
    return this;
  return nextNode()->tail();
}

void BaseNode::appendToTail(BaseNode* node) {
  auto a = this->tail();
  a->setNextNode(node);
  node->setPrevNode(a);
}

void BaseNode::prependToHead(BaseNode* node) {
  auto a = this->head();
  node->setNextNode(a);
  a->setPrevNode(node);
}

std::string BaseNode::startProcess(const std::string& s) const {
  auto a = s;
  auto current_node = this;
  while (current_node != nullptr) {
    current_node->process(a);
    current_node = current_node->nextNode();
  }
  return a;
}

} // namespace paci::psk
