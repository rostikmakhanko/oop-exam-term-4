#ifndef COMPONENT_H
#define COMPONENT_H
#include<QVector>
#include<QString>

class Component
{
private:
    QVector<QString> code;

public:
    Component();

    QVector<QString> get_code()
    {
        return  code;
    }

    void add_line(QString line)
    {
        code.push_back(line);
    }

    void change_line(int i,QString new_line)
    {
        if (i>=code.size()) return;
        code[i]=new_line;
    }
};

#endif // COMPONENT_H
