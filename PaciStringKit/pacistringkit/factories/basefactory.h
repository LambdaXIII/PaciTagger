#ifndef BASEFACTORY_H
#define BASEFACTORY_H

#include "../PaciStringKit_global.h"
#include "../nodes/basenode.h"

#include <QObject>
#include <QString>
#include <QVariant>
#include <string>

#define PSK_FA_PROP(type, name, defval)                                \
protected:                                                             \
  Q_PROPERTY(                                                          \
    type name READ name WRITE set_##name NOTIFY name##Changed)         \
public:                                                                \
  type name() const {                                                  \
    auto a = m_dataMap.value(#name, QVariant());                       \
    if (a.isNull())                                                    \
      return defval;                                                   \
    return a.value<type>();                                            \
  }                                                                    \
  void set_##name(const type& x) {                                     \
    if (name() == x)                                                   \
      return;                                                          \
    m_dataMap[#name] = QVariant::fromValue<type>(x);                   \
    emit name##Changed(x);                                             \
  }                                                                    \
  Q_SIGNAL void name##Changed(const type& x);

namespace paci::psk {

class BaseFactory: public QObject {
  Q_OBJECT
protected:
  QVariantMap m_dataMap;
  PSK_FA_PROP(QString, content, "")

  QString m_sampleText;
  Q_PROPERTY(QString sampleText READ sampleText WRITE setSampleText
      NOTIFY sampleTextUpdated)

public:
  explicit BaseFactory(QObject* parent = nullptr);
  void copyFrom(BaseFactory* other);

  virtual BaseNode* makeNode() const = 0;

  Q_SLOT void setSampleText(const QString& s);
  Q_SIGNAL void sampleTextUpdated(const QString& s);
  QString sampleText() const { return m_sampleText; }
};

} // namespace paci::psk

#endif // BASEFACTORY_H
