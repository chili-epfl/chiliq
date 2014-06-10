#ifndef CONFIGFINDER_H
#define CONFIGFINDER_H

#include <QObject>
#include <QVariantMap>
#include <QMatrix4x4>

class ConfigFinder : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantMap tags READ tags WRITE setTags)
    Q_PROPERTY(QVariantMap config READ config NOTIFY configChanged)

public:
    explicit ConfigFinder(QObject *parent = 0);

    QVariantMap tags() {
        qDebug("who calls me ???");
        return m_tags;
    }

    void setTags(QVariantMap tags) {
        if (m_knownTags.isEmpty() && !tags.isEmpty()) {
            QString firstKnown = tags.firstKey();
            m_knownTags.append(firstKnown);
            m_config.insert(firstKnown, tags.first().value<QMatrix4x4>().column(3));
        }

        QString knownTag;
        QString newTag;
        for (auto tagId : tags.keys()) {
            if (m_knownTags.contains(tagId)) {
                knownTag = tagId;
            } else {
                newTag = tagId;
            }
        }
        if (!newTag.isEmpty() && !knownTag.isEmpty()) {
            qDebug("Attaching " + newTag.toLatin1() + " to " + knownTag.toLatin1());
            m_knownTags.append(newTag);

            m_config.insert(newTag, tags[newTag].value<QMatrix4x4>().column(3));
            emit configChanged(m_config);
        }
    }

    QVariantMap config() { return m_config; }

signals:
    void configChanged(QVariantMap config);

public slots:

private:
    QVariantMap m_tags;
    QVariantMap m_config;
    QStringList m_knownTags;

};

#endif // CONFIGFINDER_H
