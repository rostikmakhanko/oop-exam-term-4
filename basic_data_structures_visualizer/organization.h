#ifndef ORGANIZATION_H
#define ORGANIZATION_H
#include<QString>

class Organization
{
private:
    QString name;
    int employee_count;

public:
    Organization();

    QString get_name()
    {
        return name;
    }

    int get_employee_count()
    {
        return employee_count;
    }

    void set_name(QString name)
    {
        this->name=name;
    }

    void set_employee_count(int employee_count)
    {
        this->employee_count=employee_count;
    }
};

#endif // ORGANIZATION_H
