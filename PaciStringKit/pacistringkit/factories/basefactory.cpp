#include "basefactory.h"

namespace paci::psk {

BaseFactory::BaseFactory(QObject* parent)
  : QObject(parent) {
}

void BaseFactory::copyFrom(BaseFactory* other) {
  for (const auto& key : m_dataMap.keys()) {
    if (other->m_dataMap.contains(key))
      m_dataMap[key] = other->m_dataMap[key];
  }
}

void BaseFactory::setSampleText(const QString& s) {
  auto node = makeNode();
  auto str = s.toStdString();
  node->process(str);
  auto new_str = QString::fromStdString(str);
  if (new_str != m_sampleText) {
    m_sampleText = new_str;
    emit sampleTextUpdated(new_str);
  }
  delete node;
}

} // namespace paci::psk
