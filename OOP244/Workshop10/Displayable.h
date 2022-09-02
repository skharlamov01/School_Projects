/*------------------------------------------------------
Workshop 10 part 1
Module: Displayable
Version 1.0
Author : Fardad Soleimanloo  22/04/01
Revision History
-----------------------------------------------------------
Date       Reason
----------------------------------------------------------- */
#ifndef SDDS_DISPLAYABLE_H_
#define SDDS_DISPLAYABLE_H_
#include <iostream>
namespace sdds{
  class Displayable{
  public:
    virtual std::ostream& display(std::ostream& os)const = 0;
  };

  std::ostream& operator<<(std::ostream& os, const Displayable& D);
}

#endif
