#ifndef LISTING_H_INCLUDED
#define LISTING_H_INCLUDED

int list_employees(LinkedList*);
int show_employee(Employee*);

int order_by_id(void*, void*);
int order_by_name(void*, void*);
int order_by_workhours(void*, void*);
int order_by_salary(void*, void*);


#endif /* LISTING_H_ */
