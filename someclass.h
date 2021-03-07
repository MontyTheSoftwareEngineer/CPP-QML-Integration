#ifndef SOMECLASS_H
#define SOMECLASS_H

#include <QObject>

class SomeClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString someVar READ someVar WRITE setSomeVar NOTIFY someVarChanged)
public:
    explicit SomeClass(QObject *parent = nullptr);
    Q_INVOKABLE void anotherFunction();
    Q_INVOKABLE QString getSomeVar();
    QString someVar();
signals:
    void someVarChanged();

public slots:
    void setSomeVar( QString );
    void callMe();

private:
    QString m_someVar;

};

#endif // SOMECLASS_H
