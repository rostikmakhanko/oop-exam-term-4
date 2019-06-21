#include "organization.h"

Organization::Organization()
{

}

Organization::Organization(QString name, int employee_count)
{
    this->name=name;
    this->employee_count=employee_count;
}
