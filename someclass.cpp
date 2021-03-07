#include "someclass.h"
#include <QDebug>

SomeClass::SomeClass(QObject *parent)
    : QObject(parent)
    , m_someVar("123")
{
    qDebug() << "I'm being created!";
}

void SomeClass::anotherFunction()
{
    qDebug() << "Another function!";
}

QString SomeClass::getSomeVar()
{
    return m_someVar;
}

void SomeClass::callMe()
{
    qDebug() << "I'm being called!";
}

QString SomeClass::someVar()
{
    return m_someVar;
}

void SomeClass::setSomeVar(QString newVar)
{
    if ( m_someVar != newVar )
    {
        m_someVar = newVar;
        emit someVarChanged();
    }
}
