/*------------------------------------------------------
Workshop 10 part 1
Module: Employee
Version 1.0
Author : Fardad Soleimanloo  22/04/01
Revision History
-----------------------------------------------------------
Date       Reason
----------------------------------------------------------- */
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#include "Displayable.h"
namespace sdds{
  class Employee :public Displayable{
    int m_empno{};
    char m_name[41]{};
    int m_officeNo{};
    void set(int empno, const char* name, int officNo);
  public:
     Employee();
    Employee(int empno, const char* name, int officNo);
    std::ostream& display(std::ostream& os)const;
    bool operator==(const Employee& E)const;
  };
}
#endif 