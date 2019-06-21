#ifndef PROJECT_H
#define PROJECT_H
#include<QVector>
#include"component.h"

class Project
{
private:
    QVector<Component> body;//all code of the project

public:
    Project();

    QVector<Component> get_body()
    {
        return body;
    }

};

#endif // PROJECT_H
