#ifndef interface_hpp
#define interface_hpp

#include "owner.hpp"

void main_menu(Owner&, Warehouse&, std::vector<std::string*>&, std::vector<std::string*>&);
void ow_menu1(Owner&, Warehouse&, std::vector<std::string*>&, std::vector<std::string*>&);
void ow_menu2(Owner&, Warehouse&, std::vector<std::string*>&, std::vector<std::string*>&);
void em_menu1(Owner&, Warehouse&);
void em_menu2(Employee*, Bookshop*, Warehouse&);
void cu_menu1(Owner&, std::vector<std::string*>&, std::vector<std::string*>&);


#endif // interface

